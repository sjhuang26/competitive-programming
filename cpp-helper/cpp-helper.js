const program = require('commander');
const fs = require('fs');
const util = require('util');
const chokidar = require('chokidar');
const path = require('path');
const mkdirp = require('mkdirp');
const child_process = require('child_process');

const fileInterface = require('./file-interface');

const prm = util.promisify;
const prmWriteFile = prm(fs.writeFile);
const prmReadFile = prm(fs.readFile);
const exec = prm(child_process.exec);

let DEBUG_MODE = false;
const TEMP_DIRECTORY_NAME = '.generated';
const MAX_OUTPUT_SIZE = 1000 * 10;
const OUTPUT_TIMEOUT = 500;
let RESET_ALL = false;
const SOURCE_FILE_TEMPLATE = `/*

*/
#include<iostream>
#include<string>
using namespace std;
int main() {
string x;cin>>x;
cout<<"Hello world! The input is "<<x<<'\\n';
return 0;
}
`;
const INPUT_FILE_TEMPLATE = `pause=false
stopOnError=true
inputs:0=
%%%
FOOBAR
%%%
inputs:1=
%%%
FOOBAR2
%%%
`;

class FileSystem {
  constructor(path) {
    this.path = path;
  }

  file(name) {
    return new File(path.join(this.path, name));
  }

  directory(name) {
    return new Directory(path.join(this.path, name));
  }

  parent() {
    return new Directory(path.dirname(this.path));
  }

  baseName() {
    return path.basename(this.path);
  }

  mixin(constructorFunction, ...args) {
    return new constructorFunction(this, ...args);
  }
}

class File extends FileSystem {
  constructor(path) {
    super(path);
  }

  async access() {
    await prm(fs.access)(this.path);
    return this;
  }

  async template(template = '', forceTemplate = false) {
    try {
      if (forceTemplate) throw '';
      await this.access();
    } catch (e) {
      await this.write(template);
    }
    return this;
  }

  async read() {
    return await prmReadFile(this.path, 'utf8');
  }

  async write(content) {
    await prmWriteFile(this.path, content);
    return this;
  }

  async clear() {
    await this.write('');
    return this;
  }

  async append(content) {
    await prm(fs.appendFile)(this.path, content);
    return this;
  }

  async line(content) {
    await this.append(content + '\n');
    return this;
  }
}

class Directory extends FileSystem {
  constructor(path) {
    super(path);
  }

  async make() {
    await prm(mkdirp)(this.path);
    return this;
  }
}

class InstanceDirectory extends Directory {
  constructor(directory, name) {
    super(directory.path);
    this.name = name;
  }

  getFileName(extension) {
    return this.name + '.' + extension;
  }

  getFile(extension) {
    return this.file(this.getFileName(extension));
  }
}

class InterfacedFile extends File {
  constructor(file, displayMode, onBeforePushState) {
    super(file.path);
    this.state = {};
    this.displayMode = displayMode;
    this.displayMode.log = 'blockRaw';
    this.displayMode.timestamp = 'normal';
    this.onBeforePushState = onBeforePushState || (function() {});
  }

  async pullState() {
    this.state = fileInterface.fileToJSON(await this.read());
    return this;
  }

  async pushState(state) {
    if (state !== undefined) this.state = state;
    const date = new Date();
    this.state.timestamp = date.getHours() + ':' + date.getMinutes() + ':' + date.getSeconds();
    this.onBeforePushState(this.state);
    await this.write(fileInterface.jsonToFile(this.state, this.displayMode));
    return this;
  }

  async log(content) {
    if (this.state.log === undefined) this.state.log = '';
    this.state.log += content + '\n';
    await this.pushState();
  }

  async clearLog() {
    this.state.log = '';
    await this.pushState();
  }
}

class Instance {
  constructor(sourceFile) {
    this.name = path.basename(sourceFile).split('.')[0];
    this.sourceFile = new File(sourceFile);
    this.sourceDirectory = this.sourceFile.parent().mixin(InstanceDirectory, this.name);
    this.tempDirectory = this.sourceDirectory.directory(TEMP_DIRECTORY_NAME).mixin(InstanceDirectory, this.name);
    this.inputFile = this.tempDirectory.getFile('in').mixin(InterfacedFile, {
      inputs: 'blockRaw',
      pause: 'normal',
      stopOnError: 'normal'
    });

    this.buildOperationCount = 0;

    this.buildOpen = true;
    this.ready = false;

    this.outputFile = this.tempDirectory.getFile('out').mixin(InterfacedFile, {
      outputs: 'blockRaw',
      compileError: 'blockRaw',
      buildOperationCount: 'normal'
    }, this.onBeforePushState.bind(this));
  }

  onBeforePushState(state) {
    state.buildOperationCount = this.buildOperationCount;
  }

  async init() {
    try {
      await this.tempDirectory.make();
      this.watch(this.sourceFile, this.onSourceFileChange);
      this.watch(this.inputFile, this.onInputFileChange);
      await this.sourceFile.template(SOURCE_FILE_TEMPLATE, RESET_ALL);
      await this.inputFile.template(INPUT_FILE_TEMPLATE, RESET_ALL);
      this.ready = true;
      this.log('ready');
    } catch (e) {
      this.fail('[FATAL] could not init files', e);
    }
    this.onSourceFileChange();
    this.onInputFileChange();
  }

  async safeLog(message) {
    try {
      this.outputFile.log(message);
    } catch (e) {
      this.fail(e);
    }
  }

  watch(file, event) {
    chokidar.watch(file.path, {
    }).on('all', event.bind(this));
  }

  async build() {
    await this.compile();
    await this.run();
  }

  async run() {
    this.log('running');
    await this.outputFile.log('running...');
    let data;
    let rawData;
    try {
      let inputs = (await this.inputFile.pullState()).state.inputs;
      this.outputFile.state.outputs = [];
      this.outputFile.pushState();
      if (!Array.isArray(inputs)) {
        inputs = [inputs];
      }
      for (let i = 0; i < inputs.length; ++i) {
        try {
          const input = inputs[i];
          this.log(`running case ${i + 1} of ${inputs.length}`);
          this.outputFile.log(`running case ${i + 1} of ${inputs.length}...`);
          await this.tempDirectory.getFile('cpp.in').write(input);
          rawData = (await this.runCommand(`cd ${this.tempDirectory.path} && ${this.tempDirectory.getFile('cpp.exe').baseName()} < ${this.tempDirectory.getFile('cpp.in').baseName()}`, {
            timeout: OUTPUT_TIMEOUT,
            maxBuffer: MAX_OUTPUT_SIZE
          }));
        } catch (e) {
          rawData = e;
          if (e.code === 3221225477) {
            // SEGFAULT
            this.log('run killed (segfault)');
            this.outputFile.log('run killed (segfault)');
            if (this.inputFile.state.stopOnError === 'true') {
              throw 'safe';
            }
          } else if (e.process !== undefined && e.process.killed === true) {
            // OUTPUT OVER LIMITS
            this.log(`run killed (output over limits, may be truncated)`);
            this.outputFile.log(`run killed (output over limits, may be truncated)`);
            if (this.inputFile.state.stopOnError === 'true') {
              throw 'safe';
            }
          } else {
            throw e;
          }
        } finally {
          this.outputFile.state.outputs.push(rawData.stdout + rawData.stderr);
          await this.outputFile.pushState();
        }
      }
    } catch (e) {
      if (e !== 'safe') {
        this.log('run failed (unknown reason)');
        await this.outputFile.log('run failed (unknown reason)');
        throw e;
      } else {
        this.log('stopped on error (as specified in input)');
        await this.outputFile.log('stopped on error (as specified in input)');
      }
    }
    this.log('run finished');
  }

  async compile() {
    this.log('compiling');
    let data = '';
    await this.outputFile.log('compiling...');
    try {
      await this.runCommand(`g++ ${this.sourceFile.path} -o ${this.tempDirectory.getFile('cpp.exe').path} > ${this.tempDirectory.getFile('compiler.out').path} 2>&1`);
      data = await this.tempDirectory.getFile('compiler.out').read();
      if (data !== '') throw new Error('compile failed');
      delete this.outputFile.state.compileError;
      this.log('compile finished');
    } catch (e) {
      this.log('compile failed');
      if (data == '') {
        await this.outputFile.log('compile failed (unknown reason).');
      } else {
        await this.outputFile.log('compile failed (compile error).');
        this.outputFile.state.compileError = data;
        this.outputFile.pushState();
      }
      throw e;
    }
  }

  async onSourceFileChange() {
    this.logDebug(`file event: source file change`);
    await this.doBuildOperation(this.build);
  }

  async onInputFileChange() {
    this.logDebug(`file event: input file change`);
    await this.doBuildOperation(this.run);
  }

  async doBuildOperation(callback) {
    if (!this.buildOpen || !this.ready) {
      this.logDebug('build operation rejected (resources locked)');
      return;
    }
    this.buildOpen = false;
    try {
      await this.inputFile.pullState();
      if (this.inputFile.state.pause === 'true') {
        this.log('build operations paused');
        await this.outputFile.clearLog();
        await this.outputFile.log('build operations paused');
        return;
      }
      ++this.buildOperationCount;
      this.log(`** BUILD OPERATION STARTED (#${this.buildOperationCount}) **`);
      await this.stopOutputProcess();
      await this.outputFile.clearLog();
      await callback.call(this);
      this.log('build operation finished');
      await this.outputFile.log('done!');
    } catch (e) {
      this.fail('build operation failed', e);
      await this.safeLog('build operation failed');
    } finally {
      this.buildOpen = true;
    }
  }

  log(...content) {
    console.log(`[${this.name}]`, ...content);
  }

  logDebug(...content) {
    if (DEBUG_MODE) this.log(`[DEBUG]`, ...content);
  }

  fail(message, error) {
    if (message !== undefined) {
      this.log(message);
    }
    this.logDebug('full error:');
    this.logDebug(error);
    this.logDebug('full error (JSON):');
    this.logDebug(JSON.stringify(error));
  }

  async stopOutputProcess() {
    try {
      await this.runCommand(`taskkill /F /IM ${this.name}.cpp.exe /T`);
    } catch (e) {
      // silently fail
      this.fail(undefined, e);
    }
  }

  runCommand(command, options) {
    this.logDebug(`running command ${command}`);
    return new Promise((resolve, reject) => {
      let process;
      process = child_process.exec(command, options, (err, stdout, stderr) => {
        if (err) {
          err.stdout = stdout;
          err.stderr = stderr;
          err.process = process;
          reject(err);
        } else {
          resolve({
            err: err,
            stdout: stdout,
            stderr: stderr,
            process: process
          });
        }
      });
    });
  }
}

let run = async (sourceFiles, options) => {
  DEBUG_MODE = options.debug;
  RESET_ALL = options.reset;
  if (DEBUG_MODE) {
    console.log('[INFO]', 'debug mode on');
  }
  if (RESET_ALL) {
    console.log('[INFO]', 'resetting all files');
  }
  let instances = [];
  for (sourceFile of sourceFiles) {
    instances.push(new Instance(sourceFile));
  }
  for (instance of instances) {
    instance.init();
  }
};

program
.arguments('<sourceFiles...>')
.option('-d, --debug', 'Add debug output')
.option('-r, --reset', 'Reset all files to template')
.action(run);
program.parse(process.argv);
