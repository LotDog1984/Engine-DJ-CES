"""Annotated disassembly windows around references to the stems-processor
protocol strings, to recover the stdin/stdout message grammar."""
import struct, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_64, CS_OP_MEM, CS_OP_IMM, CS_OP_REG

PATH = r"bin/stems-processor.exe"
INTEREST = ["preparing", "session", "numChannels", "sampleRate", "maxBlockSize",
            "highQuality", "numThreads", "initialising", "invalid string position",
            "0123456789-+Ee", "Cannot prepare", "--stem", "--hostVersion"]

data = open(PATH, "rb").read()

# ---- PE headers ----
e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
nsec = struct.unpack_from("<H", data, e_lfanew + 6)[0]
optsize = struct.unpack_from("<H", data, e_lfanew + 20)[0]
image_base = struct.unpack_from("<Q", data, e_lfanew + 24 + 24)[0]
secs = []
for i in range(nsec):
    off = e_lfanew + 24 + optsize + i * 40
    name = data[off:off + 8].rstrip(b"\0").decode()
    vsize, va, rawsize, rawptr = struct.unpack_from("<IIII", data, off + 8)
    secs.append((name, va, vsize, rawptr, rawsize))
    print(f"section {name:8} va=0x{va:x} vsize={vsize} raw=0x{rawptr:x} rawsize={rawsize}")

def va_to_off(va):
    rva = va - image_base
    for name, sva, vsize, rawptr, rawsize in secs:
        if sva <= rva < sva + max(vsize, rawsize):
            return rawptr + (rva - sva)
    return None

def cstr(va, maxlen=160):
    off = va_to_off(va)
    if off is None or off >= len(data):
        return None
    end = data.find(b"\0", off, off + maxlen)
    if end < 0:
        return None
    s = data[off:end]
    if len(s) < 2 or any(c < 0x20 or c > 0x7E for c in s):
        return None
    return s.decode("ascii")

# ---- imports (IAT slot VA -> name) ----
def rva_to_off(rva):
    for name, sva, vsize, rawptr, rawsize in secs:
        if sva <= rva < sva + max(vsize, rawsize):
            return rawptr + (rva - sva)
    return None

iat = {}
dir_rva, dir_size = struct.unpack_from("<II", data, e_lfanew + 24 + 112 + 1 * 8 + 0) if False else (0, 0)
# import dir = index 1 of data directory
dd = e_lfanew + 24 + (112 if struct.unpack_from("<H", data, e_lfanew + 24)[0] == 0x20B else 96)
imp_rva, imp_size = struct.unpack_from("<II", data, dd + 8)
p = rva_to_off(imp_rva)
while True:
    oft, tstamp, fwd, name_rva, first_thunk = struct.unpack_from("<IIIII", data, p)
    if not name_rva:
        break
    dll = data[rva_to_off(name_rva):data.find(b"\0", rva_to_off(name_rva))].decode()
    thunk = oft or first_thunk
    t = rva_to_off(thunk)
    slot_va = image_base + first_thunk
    i = 0
    while True:
        val = struct.unpack_from("<Q", data, t)[0]
        if val == 0:
            break
        if not (val >> 63):
            n = rva_to_off(val)
            fname = data[n + 2:data.find(b"\0", n + 2)].decode()
            iat[slot_va + i * 8] = f"{dll}!{fname}"
        i += 1
        t += 8
    p += 20

# ---- disassemble .text ----
text = next(s for s in secs if s[0] == ".text")
tva, tvsize, traw, trawsize = text[1], text[2], text[3], text[4]
code = data[traw:traw + trawsize]
md = Cs(CS_ARCH_X86, CS_MODE_64)
md.detail = True
base = image_base + tva

insns = []           # (address, size, mnemonic, op_str, ripref target or None, iat name or None)
idx_of = {}
for ins in md.disasm(code, base):
    target = None
    iatname = None
    for op in ins.operands:
        if op.type == CS_OP_MEM and op.mem.base == 0 and (op.mem.index == 0):
            # rip-relative in capstone: mem.base == X86_REG_RIP
            pass
    try:
        import capstone.x86 as x86
        for op in ins.operands:
            if op.type == CS_OP_MEM and op.mem.base == x86.X86_REG_RIP:
                target = ins.address + ins.size + op.mem.disp
                if target in iat:
                    iatname = iat[target]
    except Exception:
        pass
    idx_of[ins.address] = len(insns)
    insns.append((ins.address, ins.size, ins.mnemonic, ins.op_str, target, iatname))

print(f"instructions: {len(insns)}")

hits = []
for i, (addr, size, mn, ops, target, iatname) in enumerate(insns):
    if target is None:
        continue
    s = cstr(target, 40)
    if s and any(s.startswith(k) for k in INTEREST):
        hits.append((i, s))

print(f"protocol-string references: {len(hits)}")
for i, s in hits:
    print(f"  {hex(insns[i][0])} -> {s!r}")

def window(center_idx, before=45, after=45):
    lo = max(0, center_idx - before)
    hi = min(len(insns), center_idx + after)
    start_addr = insns[lo][0]
    start_off = start_addr - base
    sub = code[start_off:start_off + sum(x[1] for x in insns[lo:hi]) + 32]
    out = []
    for ins in md.disasm(sub, start_addr):
        ann = ""
        for op in ins.operands:
            try:
                import capstone.x86 as x86
                if op.type == CS_OP_MEM and op.mem.base == x86.X86_REG_RIP:
                    t = ins.address + ins.size + op.mem.disp
                    if t in iat:
                        ann = f"   ; {iat[t]}"
                    else:
                        s = cstr(t, 60)
                        if s:
                            ann = f"   ; {t - image_base:#x} {s!r}"
            except Exception:
                pass
        out.append(f"{ins.address - image_base:#010x}  {ins.mnemonic:8} {ins.op_str}{ann}")
        if len(out) > (hi - lo):
            break
    return out

for i, s in hits:
    print("\n" + "=" * 100)
    print(f"### context for {s!r} at rva {insns[i][0] - image_base:#x}")
    print("\n".join(window(i)))
