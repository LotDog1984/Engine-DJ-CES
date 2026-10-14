"""Point a copy of the end-to-end suite at what is *installed*, not at this repo's lab.

The suite normally drives `stems-lab\\shim\\stems-processor.exe` against the lab it lives in. This
copy drives the shim Engine DJ actually spawns (the live `bin`), against the lab `engine.json`
points at, so a run proves the installed pair rather than the sources.

    .venv/Scripts/python.exe tests/patch-e2e-live.py
    powershell -ExecutionPolicy Bypass -File tests/sandbox/e2e-live.ps1
"""
import pathlib
import sys

LAB = pathlib.Path(__file__).resolve().parent.parent
BIN = pathlib.Path.home() / "AppData/Local/AIR Music Technology/EnginePrime/bin"


def main() -> int:
    import json
    import re
    config = BIN / "engine.json"
    live_lab = pathlib.Path(json.loads(config.read_text(encoding="utf-8"))["lab"])
    if not live_lab.is_dir():
        print(f"engine.json points at a folder that is not there: {live_lab}")
        return 1

    harness = (LAB / "tests" / "test-engine-end-to-end.ps1").read_text(encoding="utf-8")
    harness = harness.replace("$LabRoot = Split-Path -Parent $PSScriptRoot",
                              f"# Installed pair, not the sources.\n$LabRoot = '{live_lab}'")
    harness = harness.replace("$Shim    = Join-Path $LabRoot 'shim\\stems-processor.exe'",
                              f"$Shim    = '{BIN / 'stems-processor.exe'}'")
    harness = harness.replace("$Scratch = Join-Path $PSScriptRoot 'sandbox\\e2e'",
                              "$Scratch = Join-Path $PSScriptRoot 'sandbox\\e2e-live'")
    out = LAB / "tests" / "sandbox" / "e2e-live.ps1"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(harness, encoding="utf-8")
    print(f"installed shim : {BIN / 'stems-processor.exe'}")
    print(f"lab it uses    : {live_lab}")
    print(f"written        : {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
