// Minimal PE reader: sections, imports, and a few embedded-payload probes.
const fs = require('fs');
const path = process.argv[2];
const fd = fs.openSync(path, 'r');
const size = fs.fstatSync(fd).size;

function readAt(off, len) {
  const b = Buffer.alloc(len);
  fs.readSync(fd, b, 0, len, off);
  return b;
}

const dos = readAt(0, 64);
if (dos.toString('ascii', 0, 2) !== 'MZ') throw new Error('not MZ');
const e_lfanew = dos.readUInt32LE(0x3c);
const pe = readAt(e_lfanew, 4);
if (pe.toString('ascii', 0, 4) !== 'PE\0\0') throw new Error('not PE');
const coff = readAt(e_lfanew + 4, 20);
const machine = coff.readUInt16LE(0);
const nSections = coff.readUInt16LE(2);
const timestamp = coff.readUInt32LE(4);
const sizeOptHdr = coff.readUInt16LE(16);
const chars = coff.readUInt16LE(18);
const opt = readAt(e_lfanew + 24, sizeOptHdr);
const magic = opt.readUInt16LE(0);
const is64 = magic === 0x20b;
const subsystem = opt.readUInt16LE(is64 ? 0x5c : 0x5c - 0x10 + 0x10);
const entryPoint = opt.readUInt32LE(16);
const imageBase = is64 ? Number(opt.readBigUInt64LE(24)) : opt.readUInt32LE(28);
const dllChars = opt.readUInt16LE(is64 ? 0x46 + 24 - 0x38 + 0x38 : 0x46);
const numberOfRva = opt.readUInt32LE(is64 ? 108 : 92);
const dataDir = e_lfanew + 24 + (is64 ? 112 : 96);

console.log(`file: ${path}`);
console.log(`size: ${size} bytes (${(size / 1048576).toFixed(1)} MiB)`);
console.log(`machine: 0x${machine.toString(16)}  sections: ${nSections}  timestamp: ${timestamp} (${new Date(timestamp * 1000).toISOString().slice(0, 10)})`);
console.log(`optional magic: 0x${magic.toString(16)}  imageBase: 0x${imageBase.toString(16)}  entry: 0x${entryPoint.toString(16)}  subsystem: ${subsystem}  dllChars: 0x${dllChars.toString(16)}  dataDirs: ${numberOfRva}`);

const secOff = e_lfanew + 24 + sizeOptHdr;
const sections = [];
for (let i = 0; i < nSections; i++) {
  const s = readAt(secOff + i * 40, 40);
  const name = s.toString('ascii', 0, 8).replace(/\0+$/, '');
  sections.push({
    name,
    vsize: s.readUInt32LE(8),
    vaddr: s.readUInt32LE(12),
    rawSize: s.readUInt32LE(16),
    rawPtr: s.readUInt32LE(20),
    flags: s.readUInt32LE(36),
  });
}
console.log('\n[sections]');
for (const s of sections) {
  const pct = ((s.rawSize / size) * 100).toFixed(1);
  console.log(`  ${s.name.padEnd(9)} va=0x${s.vaddr.toString(16).padStart(6, '0')} vsize=${String(s.vsize).padStart(10)} raw=${String(s.rawSize).padStart(10)} (${pct.padStart(5)}%) at 0x${s.rawPtr.toString(16)} flags=0x${s.flags.toString(16)}`);
}

function rvaToOff(rva) {
  for (const s of sections) {
    if (rva >= s.vaddr && rva < s.vaddr + Math.max(s.vsize, s.rawSize)) return s.rawPtr + (rva - s.vaddr);
  }
  return -1;
}

// Import directory (dir index 1) / export (0) / resource (2)
const dirs = [];
for (let i = 0; i < Math.min(numberOfRva, 16); i++) {
  const e = readAt(dataDir + i * 8, 8);
  dirs.push({ rva: e.readUInt32LE(0), size: e.readUInt32LE(4) });
}
const names = ['export', 'import', 'resource', 'exception', 'security', 'basereloc', 'debug', 'arch', 'globalptr', 'tls', 'loadcfg', 'boundimport', 'iat', 'delayimport', 'clr', 'reserved'];
console.log('\n[data directories]');
dirs.forEach((d, i) => { if (d.rva) console.log(`  ${names[i].padEnd(12)} rva=0x${d.rva.toString(16)} size=${d.size}`); });

// Imports
const impOff = rvaToOff(dirs[1].rva);
if (impOff >= 0) {
  console.log('\n[imports]');
  for (let i = 0; ; i++) {
    const d = readAt(impOff + i * 20, 20);
    const oft = d.readUInt32LE(0);
    const nameRva = d.readUInt32LE(12);
    if (!oft && !nameRva) break;
    const no = rvaToOff(nameRva);
    const dll = readAt(no, 64).toString('ascii').split('\0')[0];
    const count = [];
    const thunkRva = oft || d.readUInt32LE(16);
    let tOff = rvaToOff(thunkRva);
    let n = 0;
    while (tOff >= 0 && n < 100000) {
      const v = is64 ? readAt(tOff, 8).readBigUInt64LE(0) : BigInt(readAt(tOff, 4).readUInt32LE(0));
      if (v === 0n) break;
      const hi = is64 ? v & 0x8000000000000000n : 0x80000000n & v;
      if (hi === 0n || hi === 0x8000000000000000n) { /* named */ }
      n++;
      tOff += is64 ? 8 : 4;
    }
    console.log(`  ${dll}  (${n} imports)`);
  }
}
fs.closeSync(fd);
