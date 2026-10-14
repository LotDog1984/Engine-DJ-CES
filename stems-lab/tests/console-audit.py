"""Who has a console - and is it on screen?  Asked of the processes themselves, from outside.

`AttachConsole(pid)` + `GetConsoleWindow()` answers for a process we did not start, without
injecting anything into it: `none` means no console we can attach to, `hidden` a console whose
window is not on screen (CREATE_NO_WINDOW looks like this), and `visible` is the pop-up that must
never appear while a stem job runs. Watch mode reports every process as it is created, with its
parent, so anything a job starts is attributed to something specific instead of guessed at.

What this cannot see: a **pseudo console** (a Windows Terminal session, which is what this machine
gives any new console) cannot be attached to, so such a process reports `none` even when its window
is on screen. For the engine there is a better answer - it reports its own console in
`engine\engine.log` (`describe_console()` in `engine_service.py`), which is a direct
`GetConsoleWindow()` + `IsWindowVisible()` from inside the process. Use this tool to see *what* a
job starts and *whether it exists at all*; use the engine's line for whether a window is showing.

    .venv/Scripts/python.exe tests/console-audit.py --watch 120 --out tests/sandbox/console-watch.txt
    .venv/Scripts/python.exe tests/console-audit.py --filter python,audio-separator,ffmpeg
"""
from __future__ import annotations

import argparse
import ctypes
import os
import pathlib
import sys
import time

if os.name != "nt":
    raise SystemExit("windows only")

kernel32 = ctypes.WinDLL("kernel32", use_last_error=True)
user32 = ctypes.WinDLL("user32", use_last_error=True)


class PROCESSENTRY32(ctypes.Structure):
    _fields_ = [("dwSize", ctypes.c_uint32), ("cntUsage", ctypes.c_uint32),
                ("th32ProcessID", ctypes.c_uint32),
                ("th32DefaultHeapID", ctypes.POINTER(ctypes.c_ulong)),
                ("th32ModuleID", ctypes.c_uint32), ("cntThreads", ctypes.c_uint32),
                ("th32ParentProcessID", ctypes.c_uint32), ("pcPriClassBase", ctypes.c_long),
                ("dwFlags", ctypes.c_uint32), ("szExeFile", ctypes.c_char * 260)]


TH32CS_SNAPPROCESS = 0x00000002


def processes() -> dict[int, tuple[str, int]]:
    """{pid: (exe name, parent pid)} - the whole process table, via the toolhelp snapshot."""
    snapshot = kernel32.CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)
    if snapshot == -1:
        return {}
    out: dict[int, tuple[str, int]] = {}
    entry = PROCESSENTRY32()
    entry.dwSize = ctypes.sizeof(PROCESSENTRY32)
    try:
        more = kernel32.Process32First(snapshot, ctypes.byref(entry))
        while more:
            name = entry.szExeFile.decode("mbcs", "replace")
            out[int(entry.th32ProcessID)] = (name, int(entry.th32ParentProcessID))
            more = kernel32.Process32Next(snapshot, ctypes.byref(entry))
    finally:
        kernel32.CloseHandle(snapshot)
    return out


def console_state(pid: int) -> str:
    """none | hidden | visible - the console this process would write to, seen from outside."""
    kernel32.FreeConsole()          # a probe cannot attach while it has a console of its own
    if not kernel32.AttachConsole(pid):
        return "none"
    try:
        hwnd = kernel32.GetConsoleWindow()
        if not hwnd:
            return "hidden"          # a console, but no window to put on screen
        return "visible" if user32.IsWindowVisible(hwnd) else "hidden"
    finally:
        kernel32.FreeConsole()


def describe(pid: int, name: str, parent: int, table: dict[int, tuple[str, int]]) -> str:
    parent_name = table.get(parent, ("<gone>", 0))[0]
    return f"pid {pid:>7} {name:<26} parent {parent:>7} {parent_name:<24} console {console_state(pid)}"


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--watch", type=float, default=0.0,
                    help="seconds to keep watching for newly created processes")
    ap.add_argument("--poll", type=float, default=0.15, help="seconds between polls")
    ap.add_argument("--filter", default="", help="only report processes whose name contains one of "
                                                 "these comma separated fragments")
    ap.add_argument("--out", type=pathlib.Path, help="also append everything here")
    args = ap.parse_args()
    needles = [n.strip().lower() for n in args.filter.split(",") if n.strip()]

    def say(line: str) -> None:
        print(line, flush=True)
        if args.out:
            with args.out.open("a", encoding="utf-8") as fh:
                fh.write(line + "\n")

    def interesting(name: str) -> bool:
        return not needles or any(n in name.lower() for n in needles)

    table = processes()
    if args.watch <= 0:
        say(f"{len(table)} processes")
        visible = 0
        for pid, (name, parent) in sorted(table.items()):
            if not interesting(name):
                continue
            state = console_state(pid)
            visible += state == "visible"
            say(f"pid {pid:>7} {name:<26} console {state}")
        say(f"visible consoles: {visible}")
        return 0

    say(f"watching for {args.watch:g}s (poll {args.poll:g}s); "
        f"{len(table)} processes already running")
    seen = set(table)
    started_with = len(seen)
    offenders: dict[int, str] = {}
    deadline = time.time() + args.watch
    while time.time() < deadline:
        table = processes()
        for pid, (name, parent) in table.items():
            if pid in seen or not interesting(name):
                continue
            seen.add(pid)
            state = console_state(pid)
            if state == "visible":
                offenders[pid] = name
            say(f"NEW  {describe(pid, name, parent, table)}")
        time.sleep(args.poll)

    say(f"new processes seen: {len(seen) - started_with}")
    if offenders:
        say("VISIBLE CONSOLES APPEARED:")
        for pid, name in offenders.items():
            say(f"  pid {pid} {name}")
    else:
        say("no process was seen with a console window on screen")
    return 1 if offenders else 0


if __name__ == "__main__":
    sys.exit(main())
