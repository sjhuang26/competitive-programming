/*
The syntax is:
param=value
=param=
%%%
100% RAW
TEXT
%%%
param=%%INLINE == RAW == TEXT%%
param[]=array
param=array2
param=array3
*/

function fileToJSON(data) {
  let state = 'p';
  let result = {};
  let param = '';
  let value = '';

  if (data[data.length - 1] !== '\n') data += '\n';

  for (let i = 0; i < data.length; ++i) {
    const c = data[i];
    const c2 = i >= data.length - 1 ? c : c + data[i + 1];
    const c3 = i >= data.length - 2 ? c2 : c2 + data[i + 2];
    if (state == 'p') {
      // PARAM STATE
      if (c == '=') {
        state = 'v';
        value = '';
      } else {
        param += c;
      }
    } else if (state == 'v') {
      // VALUE STATE
      if (c === '\n') {
        if (value != '') {
          if (param.includes(':')) {
            param = param.split(':')[0];
            if (result[param] === undefined) {
              result[param] = [];
            }
            result[param].push(value);
          } else {
            result[param] = value;
          }
          state = 'p';
          param = '';
        }
      } else if (c2 == '%%') {
        state = 'r';
        i += c3 == '%%%' ? 3 : 1;
      } else {
        value += c;
      }
    } else if (state == 'r') {
      // RAW STATE
      if (c2 == '%%') {
        state = 'v';
        i += c3 == '%%%' ? 2 : 1;
      } else {
        value += c;
      }
    }
  }
  return result;
}

function jsonToFile(data, displayMode) {
  let result = '';
  let data2 = {};
  for (let key of Object.keys(data)) {
    const value = data[key];
    if (Array.isArray(value)) {
      for (let i = 0; i < value.length; ++i) {
        const element = value[i];
        data2[key + ':' + i] = element;
      }
    } else {
      data2[key] = value;
    }
  }
  for (let key of Object.keys(data2)) {
    const value = data2[key];
    const key2 = key.split(':')[0];
    if (displayMode[key2] === 'raw') {
      result += key + '=\n%%' + value + '%%\n';
    } else if (displayMode[key2] === 'inlineRaw') {
      result += key + '=%%' + value + '%%\n';
    } else if (displayMode[key2] === 'blockRaw') {
      result += key + '=\n%%%\n' + value + '%%%\n';
    } else if (displayMode[key2] === 'normal') {
      result += key + '=' + value + '\n';
    } else {
      throw new Error(`display mode for '${key}' missing`);
    }
  }
  return result;
}

exports.jsonToFile = jsonToFile;
exports.fileToJSON = fileToJSON;
