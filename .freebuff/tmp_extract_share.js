// One-off helper: pull the React-Router turbo-stream payload out of a saved
// ChatGPT share page so the conversation text can be inspected.
const fs = require('fs');

const html = fs.readFileSync(process.argv[2], 'utf8');
const re = /streamController\.enqueue\("((?:[^"\\]|\\.)*)"\)/g;
let m;
let out = '';
while ((m = re.exec(html)) !== null) {
  try {
    out += JSON.parse('"' + m[1] + '"');
  } catch {
    out += m[1];
  }
}
fs.writeFileSync(process.argv[3], out, 'utf8');
console.log('payload chars:', out.length);
