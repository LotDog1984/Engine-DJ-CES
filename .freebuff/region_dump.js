// dump hex+ascii of a region, plus printable strings found in it
const fs = require('fs');
const file = process.argv[2];
const start = Number(process.argv[3]);
const len = Number(process.argv[4]);
const mode = process.argv[5] || 'both';
const fd = fs.openSync(file, 'r');
const b = Buffer.alloc(len);
fs.readSync(fd, b, 0, len, start);
fs.closeSync(fd);

if (mode === 'hex' || mode === 'both') {
  for (let i = 0; i < len; i += 16) {
    const row = b.subarray(i, Math.min(i + 16, len));
    const hex = [...row].map((x) => x.toString(16).padStart(2, '0')).join(' ');
    const asc = [...row].map((x) => (x >= 32 && x < 127 ? String.fromCharCode(x) : '.')).join('');
    console.log(`0x${(start + i).toString(16).padStart(8, '0')}  ${hex.padEnd(47)}  ${asc}`);
  }
}
if (mode === 'strings' || mode === 'both') {
  console.log('--- strings ---');
  let cur = '';
  let curStart = 0;
  for (let i = 0; i < len; i++) {
    const c = b[i];
    if (c >= 32 && c < 127) {
      if (!cur) curStart = i;
      cur += String.fromCharCode(c);
    } else {
      if (cur.length >= 5) console.log(`0x${(start + curStart).toString(16)} (${curStart}) ${cur}`);
      cur = '';
    }
  }
  if (cur.length >= 5) console.log(`0x${(start + curStart).toString(16)} (${curStart}) ${cur}`);
}
