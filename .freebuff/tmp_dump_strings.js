// Dump long string literals found in the share payload, in order.
const fs = require('fs');
const s = fs.readFileSync(process.argv[2], 'utf8');
const re = /"(?:[^"\\]|\\.){40,}"/g;
const strs = s.match(re) || [];
console.log('long strings:', strs.length);
strs.forEach((x, i) => console.log('---', i, x.slice(0, 400)));
