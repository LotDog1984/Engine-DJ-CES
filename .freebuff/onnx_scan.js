// Minimal ONNX (protobuf) reader working on the embedded model blob inside
// stems-processor.exe, without copying the multi-hundred-MB weight payloads.
const fs = require('fs');

const file = process.argv[2];
const start = Number(process.argv[3]);
const buf = fs.readFileSync(file);
let p = start;

function varint() {
  let result = 0n;
  let shift = 0n;
  while (true) {
    const b = buf[p++];
    result |= BigInt(b & 0x7f) << shift;
    if ((b & 0x80) === 0) break;
    shift += 7n;
  }
  return result;
}
function skipField(wire) {
  if (wire === 0) { varint(); }
  else if (wire === 1) { p += 8; }
  else if (wire === 2) { const l = Number(varint()); p += l; }
  else if (wire === 5) { p += 4; }
  else throw new Error('wire ' + wire + ' @' + p);
}
function readStr() {
  const l = Number(varint());
  const s = buf.toString('utf8', p, p + l);
  p += l;
  return s;
}
function readLen() { return Number(varint()); }

const out = { initializers: [], nodes: [], opCounts: {}, inputs: [], outputs: [], meta: {} };

function parseTensor(end, tag) {
  const t = { dims: [], dtype: null, name: '', rawBytes: 0, floatCount: 0 };
  while (p < end) {
    const key = Number(varint());
    const field = key >> 3;
    const wire = key & 7;
    if (field === 1 && wire === 0) t.dims.push(Number(varint()));
    else if (field === 1 && wire === 2) { const l = readLen(); while (p < p + l) t.dims.push(Number(varint())); }
    else if (field === 2 && wire === 0) t.dtype = Number(varint());
    else if (field === 4 && wire === 2) { const l = readLen(); t.floatCount = l / 4; p += l; }
    else if (field === 8 && wire === 2) t.name = readStr();
    else if ((field === 9 || field === 10) && wire === 2) { const l = readLen(); t.rawBytes = (t.rawBytes || 0) + l; t.rawField = t.rawField || field; p += l; }
    // NOTE: this exporter writes the tensor payload in field 9 (older ONNX raw_data slot),
    // while modern ONNX uses 10. Treat both as raw payload bytes.
    else skipField(wire);
  }
  if (tag) out.initializers.push(t);
  else out.initializers.push(t);
}

function parseTensorShape(end) {
  const dims = [];
  while (p < end) {
    const key = Number(varint());
    const field = key >> 3;
    const wire = key & 7;
    if (field === 1 && wire === 2) {
      const e = p + readLen();
      let val = null, param = null;
      while (p < e) {
        const k2 = Number(varint());
        const f2 = k2 >> 3, w2 = k2 & 7;
        if (f2 === 1 && w2 === 0) val = Number(varint());
        else if (f2 === 2 && w2 === 2) param = readStr();
        else skipField(w2);
      }
      dims.push(val !== null ? val : (param ?? '?'));
    } else skipField(wire);
  }
  return dims;
}

function parseTypeProto(end) {
  while (p < end) {
    const key = Number(varint());
    const field = key >> 3;
    const wire = key & 7;
    if (field === 1 && wire === 2) { // tensor_type
      const e = p + readLen();
      let elemType = null, shape = null;
      while (p < e) {
        const k2 = Number(varint());
        const f2 = k2 >> 3, w2 = k2 & 7;
        if (f2 === 1 && w2 === 0) elemType = Number(varint());
        else if (f2 === 2 && w2 === 2) { const e2 = p + readLen(); shape = parseTensorShape(e2); }
        else skipField(w2);
      }
      return { elemType, shape };
    }
    skipField(wire);
  }
  return null;
}

function parseValueInfo(end) {
  const vi = { name: '', type: null };
  while (p < end) {
    const key = Number(varint());
    const field = key >> 3;
    const wire = key & 7;
    if (field === 1 && wire === 2) vi.name = readStr();
    else if (field === 2 && wire === 2) { const e = p + readLen(); vi.type = parseTypeProto(e); }
    else skipField(wire);
  }
  return vi;
}

function parseNode(end) {
  const n = { inputs: [], outputs: [], name: '', op: '', domain: '', attrs: {} };
  while (p < end) {
    const key = Number(varint());
    const field = key >> 3;
    const wire = key & 7;
    if (field === 1 && wire === 2) n.inputs.push(readStr());
    else if (field === 2 && wire === 2) n.outputs.push(readStr());
    else if (field === 3 && wire === 2) n.name = readStr();
    else if (field === 4 && wire === 2) n.op = readStr();
    else if (field === 5 && wire === 2) { const e = p + readLen(); parseAttribute(e, n); }
    else if (field === 7 && wire === 2) n.domain = readStr();
    else skipField(wire);
  }
  out.nodes.push(n);
  out.opCounts[n.op] = (out.opCounts[n.op] || 0) + 1;
}

function parseAttribute(end, n) {
  let name = '', sval = null, ival = null, floats = [];
  let ints = [];
  while (p < end) {
    const key = Number(varint());
    const field = key >> 3;
    const wire = key & 7;
    if (field === 1 && wire === 2) name = readStr();
    else if (field === 2 && wire === 2) { floats = []; const l = readLen(); const e2 = p + l; while (p < e2) { floats.push(buf.readFloatLE(p)); p += 4; } }
    else if (field === 3 && wire === 0) ival = Number(varint());
    else if (field === 4 && wire === 2) sval = readStr();
    else if (field === 7 && wire === 2) { const e3 = p + readLen(); ints = []; while (p < e3) ints.push(Number(varint())); }
    else skipField(wire);
  }
  n.attrs[name] = { i: ival, s: sval, ints, floats };
}

const DTYPES = { 1: 'float32', 2: 'uint8', 3: 'int8', 4: 'uint16', 5: 'int16', 6: 'int32', 7: 'int64', 9: 'bool', 10: 'float16', 11: 'float64', 12: 'uint32', 13: 'uint64' };

console.log(`ONNX blob at 0x${start.toString(16)} (file size ${buf.length})`);

// --- ModelProto ---
let graphEnd = null;
while (true) {
  const key = Number(varint());
  const field = key >> 3;
  const wire = key & 7;
  if (field === 1 && wire === 0) out.meta.ir_version = Number(varint());
  else if (field === 2 && wire === 2) out.meta.producer_name = readStr();
  else if (field === 3 && wire === 2) out.meta.producer_version = readStr();
  else if (field === 4 && wire === 2) out.meta.domain = readStr();
  else if (field === 5 && wire === 0) out.meta.model_version = Number(varint());
  else if (field === 6 && wire === 2) out.meta.doc_string = readStr();
  else if (field === 8 && wire === 2) { const e = p + readLen(); const opset = []; while (p < e) { const k2 = Number(varint()); const f2 = k2 >> 3, w2 = k2 & 7; if (f2 === 1 && w2 === 2) opset.push(readStr()); else if (f2 === 2 && w2 === 0) opset.push('v' + Number(varint())); else skipField(w2); } out.meta.opset = opset; }
  else if (field === 14 && wire === 2) { const e = p + readLen(); let k = '', v = ''; while (p < e) { const k2 = Number(varint()); const f2 = k2 >> 3, w2 = k2 & 7; if (f2 === 1 && w2 === 2) k = readStr(); else if (f2 === 2 && w2 === 2) v = readStr(); else skipField(w2); } out.meta[k] = v; }
  else if (field === 7 && wire === 2) { graphEnd = p + readLen(); break; }
  else skipField(wire);
}

console.log('meta:', JSON.stringify(out.meta));

// --- GraphProto ---
let initBytes = 0;
while (p < graphEnd) {
  const key = Number(varint());
  const field = key >> 3;
  const wire = key & 7;
  if (field === 1 && wire === 2) { const e = p + readLen(); parseNode(e); }
  else if (field === 2 && wire === 2) readStr();
  else if (field === 5 && wire === 2) { const e = p + readLen(); const before = p; parseTensor(e, true); out.initializers[out.initializers.length - 1].off = before; initBytes += p - before; }
  else if (field === 11 && wire === 2) { const e = p + readLen(); out.inputs.push(parseValueInfo(e)); }
  else if (field === 12 && wire === 2) { const e = p + readLen(); out.outputs.push(parseValueInfo(e)); }
  else if (field === 13 && wire === 2) { const e = p + readLen(); parseValueInfo(e); }
  else skipField(wire);
}

console.log(`\nnodes: ${out.nodes.length}, initializers: ${out.initializers.length}, graph bytes: ${graphEnd - start}`);

// resume ModelProto parsing after the graph (opset_import, metadata_props, ...)
while (p < buf.length) {
  const key = Number(varint());
  const field = key >> 3;
  const wire = key & 7;
  if (field === 8 && wire === 2) { const e = p + readLen(); const opset = []; while (p < e) { const k2 = Number(varint()); const f2 = k2 >> 3, w2 = k2 & 7; if (f2 === 1 && w2 === 2) opset.push(readStr()); else if (f2 === 2 && w2 === 0) opset.push('v' + Number(varint())); else skipField(w2); } out.meta.opset = opset; }
  else if (field === 14 && wire === 2) { const e = p + readLen(); let k = '', v = ''; while (p < e) { const k2 = Number(varint()); const f2 = k2 >> 3, w2 = k2 & 7; if (f2 === 1 && w2 === 2) k = readStr(); else if (f2 === 2 && w2 === 2) v = readStr(); else skipField(w2); } out.meta[k] = v; }
  else skipField(wire);
}
console.log(`post-graph parse ended at ${p} of ${buf.length} (${p === buf.length ? 'EXACT EOF' : 'MISMATCH: leftover ' + (buf.length - p) + ' bytes'})`);
console.log('meta after graph:', JSON.stringify(out.meta));

if (process.env.SHOW_INIT) {
  console.log('\n[first 4 initializers raw layout]');
  for (const t of out.initializers.slice(0, 4)) {
    console.log(`  off=0x${(t.off || 0).toString(16)} name=${t.name} dims=${t.dims.join('x')} dtype=${DTYPES[t.dtype] || t.dtype} rawBytes=${t.rawBytes} rawField=${t.rawField} floatCount=${t.floatCount}`);
    console.log('    ' + buf.toString('hex', t.off, Math.min(t.off + 96, buf.length)).replace(/(..)/g, '$1 ').trim());
  }
  const last = out.initializers[out.initializers.length - 1];
  console.log(`  LAST initializer off=0x${(last.off || 0).toString(16)} name=${last.name} dims=${last.dims.join('x')} rawBytes=${last.rawBytes}`);
}

const top = [...out.initializers].sort((a, b) => (b.rawBytes || 0) - (a.rawBytes || 0)).slice(0, 10);
console.log('\n[10 largest initializers]');
let weightBytes = 0;
for (const t of out.initializers) weightBytes += t.rawBytes || 0;
top.forEach((t) => console.log(`  ${String(t.rawBytes).padStart(12)} B (${(t.rawBytes / 1048576).toFixed(1)} MiB)  ${t.name}[${t.dims.join('x')}]${DTYPES[t.dtype] || t.dtype}`));
console.log(`  total raw weight bytes: ${weightBytes} (${(weightBytes / 1048576).toFixed(1)} MiB)`);

const shapes = (v) => v.map((x) => `${x.name}${x.type ? `:${DTYPES[x.type.elemType] || x.type.elemType}[${(x.type.shape || []).join(',')}]` : ''}`).join('  |  ');
console.log('\n[graph inputs] ' + shapes(out.inputs));
console.log('[graph outputs] ' + shapes(out.outputs));

console.log('\n[op histogram]');
Object.entries(out.opCounts).sort((a, b) => b[1] - a[1]).forEach(([k, v]) => console.log(`  ${k.padEnd(28)} ${v}`));

console.log('\n[first 60 nodes]');
out.nodes.slice(0, 60).forEach((n) => console.log(`  ${n.op.padEnd(20)} ${n.name}  (${n.inputs.join(',')}) -> ${n.outputs.join(',')}`));

console.log('\n[suspicious node attrs]');
out.nodes.filter((n) => ['Conv', 'ConvTranspose', 'Resize', 'Constant', 'Slice', 'Reshape'].includes(n.op)).slice(0, 25).forEach((n) => console.log(`  ${n.op} ${n.name} ${JSON.stringify(n.attrs).slice(0, 160)}`));

// initializers: show names with shapes grouped by prefix
console.log('\n[initializers by name prefix]');
const byPrefix = {};
for (const t of out.initializers) {
  const pref = t.name.split('.')[0].replace(/[0-9]+$/, '#');
  byPrefix[pref] = byPrefix[pref] || { count: 0, bytes: 0, sample: [] };
  byPrefix[pref].count++;
  byPrefix[pref].bytes += t.rawBytes || t.floatCount * 4;
  if (byPrefix[pref].sample.length < 4) byPrefix[pref].sample.push(`${t.name}[${t.dims.join('x')}]${DTYPES[t.dtype] || t.dtype}`);
}
let total = 0;
for (const [k, v] of Object.entries(byPrefix).sort((a, b) => b[1].bytes - a[1].bytes)) {
  total += v.bytes;
  console.log(`  ${k.padEnd(24)} n=${String(v.count).padStart(5)} ${(v.bytes / 1048576).toFixed(1).padStart(8)} MiB   ${v.sample.join('  ')}`);
}
console.log(`  TOTAL initializer weight bytes: ${(total / 1048576).toFixed(1)} MiB`);
