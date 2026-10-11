// Copy the embedded ONNX ModelProto out of the exe into a standalone file.
const fs = require('fs');
const src = process.argv[2];
const off = Number(process.argv[3]);
const len = Number(process.argv[4]);
const dst = process.argv[5];

const fd = fs.openSync(src, 'r');
const out = fs.openSync(dst, 'w');
const CHUNK = 1 << 24;
const b = Buffer.alloc(CHUNK);
let written = 0;
while (written < len) {
  const want = Math.min(CHUNK, len - written);
  const n = fs.readSync(fd, b, 0, want, off + written);
  if (n <= 0) throw new Error('short read');
  fs.writeSync(out, b, 0, n);
  written += n;
}
fs.closeSync(out);

const head = Buffer.alloc(24);
fs.readSync(fd, head, 0, 24, off);
const tail = Buffer.alloc(16);
fs.readSync(fd, tail, 0, 16, off + len - 16);
fs.closeSync(fd);
console.log(`wrote ${written} bytes (${(written / 1048576).toFixed(1)} MiB) to ${dst}`);
console.log('head:', head.toString('hex', 0, 20), '|', head.toString('latin1', 4, 20).replace(/[^\x20-\x7e]/g, '.'));
console.log('tail:', tail.toString('hex'));
