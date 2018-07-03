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
const SOURCE_FILE_TEMPLATE = `/*

*/
#include<iostream>
using namespace std;
int main() {
cout<<"Hello world!\\n";
return 0;
}
`;

class File {
  constructor(path) {
    this.path = path;
  }

  async read() {
    return await prmReadFile(this.path, 'utf8');
  }

  async write(content) {
    await prmWriteFile(this.path, content);
  }

  async clear() {
    await this.write('');
  }

  async append(content) {
    await prm(fs.appendFile)(this.path, content);
  }

  async log(content) {
    await this.line(`%% ${content} %%`);
  }

  async logInline(content) {
    await this.append(`%% ${content} %%`);
  }

  async line(content) {
    await this.append(content + '\n');
  }
}

class Instance {
  constructor(sourceFile) {
    this.sourceFile = sourceFile;
    this.sourceDirectory = path.dirname(this.sourceFile);
    this.tempDirectory = path.join(this.sourceDirectory, TEMP_DIRECTORY_NAME);
    const nameTokens = path.basename(sourceFile).split('.');
    this.name = nameTokens[0];
    this.buildOpen = true;
    this.ready = false;

    this.status = new File(this.getTempFilePath('out'));
  }

  getTempFilePath(extension) {
    return path.join(this.tempDirectory, this.name + '.' + extension);
  }

  getTempFileName(extension) {
    return this.name + '.' + extension;
  }

  async readTempFile(extension, ...args) {
    return (await prmReadFile(this.getTempFilePath(extension), ...args));
  }

  async init() {
    try {
      await prm(mkdirp)(this.tempDirectory);
      chokidar.watch(this.sourceFile, {
        ignored: /(^|[\/\\])\../
      }).on('all', this.onFileChange.bind(this));
      try {
        await prm(fs.access)(this.sourceFile);
      } catch (e) {
        await prmWriteFile(this.sourceFile, SOURCE_FILE_TEMPLATE);
      }
      this.ready = true;
      this.log('ready');
    } catch (e) {
      this.fail('[FATAL] could not init files', e);
    }
    this.onFileChange();
  }

  async build() {
    if (!this.buildOpen || !this.ready) return;
    this.buildOpen = false;
    try {
      let data = '';
      await this.stopOutputProcess();
      await this.status.clear();
      this.log('compiling');
      await this.status.log('compiling...');
      try {
        await this.runCommand(`g++ ${this.sourceFile} -o ${this.getTempFilePath('cpp.exe')} > ${this.getTempFilePath('compiler.out')} 2>&1`);
      } catch (e) {
        this.log('compile failed');
        data = await this.readTempFile('compiler.out');
        if (data !== '') {
          await this.status.log('compile failed:');
          await this.status.append(data);
        }
        throw e;
      }
      this.log('running');
      await this.status.log('running...');
      try {
        data = (await this.runCommand(`cd ${TEMP_DIRECTORY_NAME} && ${this.getTempFileName('cpp.exe')}`, {
          timeout: OUTPUT_TIMEOUT,
          maxBuffer: MAX_OUTPUT_SIZE
        })).stdout;
      } catch (e) {
        this.fail(undefined, e);
        if (e.process.killed === true) {
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
      this.log('build finished');
    } catch (e) {
      this.fail('build failed', e);
    } finally {
      this.buildOpen = true;
    }
  }

  async onFileChange(event, path) {
    this.logDebug(`file event: event=${event}, path=${path}`);
    await this.build();
  }

  log(...content) {
    console.log(`[${this.name}@${this.sourceFile}]`, ...content);
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
  if (DEBUG_MODE) {
    console.log('[INFO]', 'debug mode on');
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
.action(run);
program.parse(process.argv);
