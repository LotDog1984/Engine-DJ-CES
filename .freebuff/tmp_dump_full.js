// Dump long string literals with index + full text so the share conversation can be read in order.
const fs = require('fs');
const s = fs.readFileSync(process.argv[2], 'utf8');
const re = /"(?:[^"\\]|\\.){30,}"/g;
let m, i = 0;
const lines = [];
while ((m = re.exec(s)) !== null) {
  let val;
  try { val = JSON.parse(m[0]); } catch { val = m[0]; }
  lines.push(`===== [${i}] off=${m.index} len=${val.length}\n${val}\n`);
  i++;
}
fs.writeFileSync(process.argv[3], lines.join('\n'), 'utf8');
console.log('items:', i);
