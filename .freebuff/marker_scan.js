// Streaming ASCII marker scan with byte offsets (capped per marker).
const fs = require('fs');
const file = process.argv[2];
const markers = JSON.parse(process.argv[3]);
const maxPer = Number(process.argv[4] || 8);

const fd = fs.openSync(file, 'r');
const size = fs.fstatSync(fd).size;
const CHUNK = 1 << 22;
const overlap = 64;
const buf = Buffer.alloc(CHUNK + overlap);
const found = new Map(markers.map((m) => [m, []]));
let pos = 0;
let carry = 0;
while (pos < size) {
  const want = Math.min(CHUNK, size - pos);
  const read = fs.readSync(fd, buf, carry, want, pos);
  const total = carry + read;
  for (const m of markers) {
    const list = found.get(m);
    if (list.length >= maxPer) continue;
    const needle = Buffer.from(m, 'latin1');
    let idx = buf.indexOf(needle, 0);
    while (idx !== -1 && idx < total - needle.length) {
      const abs = pos - carry + idx;
      if (!list.includes(abs) && list.length < maxPer) list.push(abs);
      idx = buf.indexOf(needle, idx + 1);
    }
  }
  if (read <= 0) break;
  // carry the tail so markers spanning chunk boundaries are caught
  buf.copy(buf, 0, total - overlap, total);
  carry = overlap;
  pos += read;
}
fs.closeSync(fd);
for (const [m, list] of found) {
  console.log(`${m.padEnd(28)} ${list.length ? list.map((o) => '0x' + o.toString(16)).join(' ') : '-'}`);
}
