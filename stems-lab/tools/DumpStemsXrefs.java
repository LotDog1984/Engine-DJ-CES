// Ghidra headless script: locate stem-file and stem-processor strings in Engine DJ.exe,
// then decompile every function that references one of them.
// Output: <outdir>/strings.txt and <outdir>/decompiled/*.c (outdir = script arg 0).
// @category EngineDJ

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.StringDataInstance;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.ReferenceManager;

import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;

public class DumpStemsXrefs extends GhidraScript {

    private static final String[] NEEDLES = {
        ".stems", "stems_temp", "stems-processor", "preparing=", "\"cmd\"",
        "separate", "stemsRenderingIsRunning", "renderStems", "Stems Support"
    };

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args.length > 0 ? args[0] : "stems-dump";
        File dec = new File(outDir, "decompiled");
        dec.mkdirs();

        // 1. Collect every defined string that matches a needle.
        Map<Address, String> hits = new LinkedHashMap<>();
        DataIterator it = currentProgram.getListing().getDefinedData(true);
        while (it.hasNext() && !monitor.isCancelled()) {
            Data d = it.next();
            if (!d.hasStringValue()) continue;
            Object v = d.getValue();
            if (v == null) continue;
            String s = v.toString();
            for (String n : NEEDLES) {
                if (s.contains(n)) { hits.put(d.getAddress(), s); break; }
            }
        }

        // 2. Functions referencing those strings.
        ReferenceManager rm = currentProgram.getReferenceManager();
        Map<Function, Set<String>> users = new LinkedHashMap<>();
        try (PrintWriter out = new PrintWriter(new File(outDir, "strings.txt"))) {
            for (Map.Entry<Address, String> e : hits.entrySet()) {
                out.println(e.getKey() + "\t" + e.getValue().replace("\n", "\\n"));
                ReferenceIterator refs = rm.getReferencesTo(e.getKey());
                while (refs.hasNext()) {
                    Reference r = refs.next();
                    Function f = currentProgram.getFunctionManager()
                                     .getFunctionContaining(r.getFromAddress());
                    if (f == null) continue;
                    users.computeIfAbsent(f, k -> new LinkedHashSet<>()).add(e.getValue());
                }
            }
        }

        // 3. Decompile each referencing function.
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        try (PrintWriter idx = new PrintWriter(new File(outDir, "index.txt"))) {
            for (Map.Entry<Function, Set<String>> e : users.entrySet()) {
                if (monitor.isCancelled()) break;
                Function f = e.getKey();
                idx.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + e.getValue());
                DecompileResults res = di.decompileFunction(f, 120, monitor);
                String body = (res != null && res.decompileCompleted())
                    ? res.getDecompiledFunction().getC()
                    : "// decompile failed: " + (res == null ? "null" : res.getErrorMessage());
                String name = f.getEntryPoint().toString() + "_" + f.getName()
                    .replaceAll("[^A-Za-z0-9_.-]", "_");
                try (PrintWriter pw = new PrintWriter(new File(dec, name + ".c"))) {
                    pw.println("// " + f.getName() + " @ " + f.getEntryPoint());
                    pw.println("// strings: " + e.getValue());
                    pw.println(body);
                }
            }
        }
        di.dispose();
        println("strings: " + hits.size() + "  functions: " + users.size());
    }
}
