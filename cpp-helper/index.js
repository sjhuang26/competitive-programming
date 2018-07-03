const program = require('commander');
const fs = require('fs');
const util = require('util');
const chokidar = require('chokidar');
const path = require('path');
const mkdirp = require('mkdirp');
const prm = util.promisify;
const child_process = require('child_process');
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
const INPUT_FILE_TEMPLATE = `FOOBAR`;

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

  async log(content) {
    await this.line(`%% ${content} %%`);
    return this;
  }

  async logInline(content) {
    await this.append(`%% ${content} %%`);
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

class Instance {
  constructor(sourceFile) {
    this.name = path.basename(sourceFile).split('.')[0];
    this.sourceFile = new File(sourceFile);
    this.sourceDirectory = new InstanceDirectory(this.sourceFile.parent(), this.name);
    this.tempDirectory = new InstanceDirectory(this.sourceDirectory.directory(TEMP_DIRECTORY_NAME), this.name);
    this.inputFile = this.sourceDirectory.getFile('in');
    this.buildOpen = true;
    this.ready = false;

    this.status = this.sourceDirectory.getFile('out');
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
  }

  watch(file, event) {
    chokidar.watch(file.path, {
      ignored: /(^|[\/\\])\../
    }).on('all', event.bind(this));
  }

  async build() {
    await this.compile();
    await this.run();
  }

  async run() {
    this.log('running');
    await this.status.log('running...');
    let data;
    try {
      let input = await this.sourceDirectory.getFile('in').read();
      data = (await this.runCommand(`cd ${this.tempDirectory.baseName()} && ${this.tempDirectory.getFile('cpp.exe').baseName()} < ..\\${this.sourceDirectory.getFile('in').baseName()}`, {
        timeout: OUTPUT_TIMEOUT,
        maxBuffer: MAX_OUTPUT_SIZE
      })).stdout;
    } catch (e) {
      this.fail(undefined, e);
      if (e.process !== undefined && e.process.killed === true) {
        this.log(`run killed (output over limits, may be truncated)`);
        this.status.log(`run killed (output over limits, may be truncated)`);
        data = e.stdout;
      } else {
        this.log('run failed');
        this.status.log('run failed');
        throw e;
      }
    }
    await this.status.log('START');
    await this.status.append(data);
    await this.status.log('END');
    this.log('run finished');
  }

  async compile() {
    this.log('cleaning');
    this.log('cleaning finished');

    this.log('compiling');
    let data = '';
    await this.status.log('compiling...');
    try {
      await this.runCommand(`g++ ${this.sourceFile.path} -o ${this.tempDirectory.getFile('cpp.exe').path} > ${this.tempDirectory.getFile('compiler.out').path} 2>&1`);
      this.log('compile finished');
    } catch (e) {
      this.log('compile failed');
      data = await this.tempDirectory.getFile('compiler.out').read();
      if (data !== '') {
        await this.status.log('compile failed:');
        await this.status.append(data);
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
      await this.stopOutputProcess();
      await this.status.clear();
      callback.call(this);
    } catch (e) {
      this.fail('build operation failed', e);
    } finally {
      this.buildOpen = true;
    }
  }

  log(...content) {
    console.log(`[${this.name}@${this.sourceFile.path}]`, ...content);
  }

  logDebug(...content) {
    if (DEBUG_MODE) this.log(`[DEBUG]`, ...content);
  }

  fail(message, error) {
    if (message !== undefined) this.log(message);
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
