// Ghidra headless script: for the imported functions that build a .stems file (FFmpeg mux,
// rename into place) and launch the stem processor (CreateProcessW, pipes, WriteFile/ReadFile),
// list every real caller (following the IAT thunk each import goes through) and decompile it.
// Output: <outdir>/callers.txt and <outdir>/decompiled/*.c (outdir = script arg 0).
// @category EngineDJ

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;

import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;

public class DumpImportCallers extends GhidraScript {

    private static final String[] IMPORTS = {
        "avformat_alloc_output_context2", "avio_open", "avformat_write_header",
        "av_interleaved_write_frame", "av_write_frame", "av_write_trailer",
        "avformat_new_stream", "avcodec_find_encoder", "avcodec_send_frame",
        "avcodec_receive_packet", "avcodec_parameters_from_context",
        "CreateProcessW", "CreatePipe", "WriteFile", "ReadFile",
        "MoveFileExW", "MoveFileExA", "CreateFileW", "CreateFileMappingW"
    };

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = args.length > 0 ? args[0] : "import-dump";
        File dec = new File(outDir, "decompiled");
        dec.mkdirs();

        Map<Function, Set<String>> callers = new LinkedHashMap<>();
        try (PrintWriter out = new PrintWriter(new File(outDir, "callers.txt"))) {
            for (String name : IMPORTS) {
                // Hop 1: sites that reference the external import (these are the IAT thunks).
                Set<Function> thunks = new LinkedHashSet<>();
                SymbolIterator si = currentProgram.getSymbolTable().getSymbols(name);
                while (si.hasNext()) {
                    Symbol s = si.next();
                    if (!s.isExternal()) continue;
                    ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(s.getAddress());
                    while (refs.hasNext()) {
                        Reference r = refs.next();
                        Function t = currentProgram.getFunctionManager()
                                         .getFunctionContaining(r.getFromAddress());
                        if (t != null) thunks.add(t);
                    }
                }
                // Hop 2: the real code that calls each thunk.
                int n = 0;
                for (Function t : thunks) {
                    ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(t.getEntryPoint());
                    while (refs.hasNext()) {
                        Reference r = refs.next();
                        Function f = currentProgram.getFunctionManager()
                                         .getFunctionContaining(r.getFromAddress());
                        if (f == null || f.equals(t)) continue;
                        n++;
                        callers.computeIfAbsent(f, k -> new LinkedHashSet<>()).add(name);
                        out.println(name + "\t" + f.getEntryPoint() + "\t" + f.getName());
                    }
                }
                println(name + ": " + thunks.size() + " thunk(s), " + n + " caller site(s)");
            }
        }

        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (Map.Entry<Function, Set<String>> e : callers.entrySet()) {
            if (monitor.isCancelled()) break;
            Function f = e.getKey();
            DecompileResults res = di.decompileFunction(f, 120, monitor);
            String body = (res != null && res.decompileCompleted())
                ? res.getDecompiledFunction().getC()
                : "// decompile failed: " + (res == null ? "null" : res.getErrorMessage());
            String fname = f.getEntryPoint() + "_" + f.getName().replaceAll("[^A-Za-z0-9_.-]", "_");
            try (PrintWriter pw = new PrintWriter(new File(dec, fname + ".c"))) {
                pw.println("// " + f.getName() + " @ " + f.getEntryPoint());
                pw.println("// calls: " + e.getValue());
                pw.println(body);
            }
        }
        di.dispose();
        println("callers: " + callers.size());
    }
}
