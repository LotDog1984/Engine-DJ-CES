"""Two shims asking for the same track must not separate it twice.

The bug this covers: Engine DJ (or the user) retried a track while the first job was still
running. Both requests hashed to the same cache key and both wrote the same `_tmp` scratch and
the same stem files, and whichever finished first deleted the other's scratch on the way out -
so the retry never finished at all, while both jobs ran at half speed for sharing the CPU.

`handle_separate` now holds one lock per cache key: the second request waits for the first and
is answered from the render the first one leaves behind. Different tracks still run in parallel.

usage: .venv\\Scripts\\python.exe tests\\test-engine-service-concurrency.py
"""
import pathlib
import sys
import tempfile
import threading
import time

LAB = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(LAB))
sys.path.insert(0, str(LAB / "engine"))

import engine_service  # noqa: E402  (needs the lab on sys.path, like the service does)

CHECKS = []


def check(name, ok, detail=""):
    CHECKS.append(ok)
    print(("PASS  " if ok else "FAIL  ") + name + (f"   [{detail}]" if detail else ""))


def main() -> int:
    tmp = pathlib.Path(tempfile.mkdtemp(prefix="engine-concurrency-"))
    engine_service.CACHE_DIR = tmp / "cache"
    engine_service.CACHE_DIR.mkdir(parents=True, exist_ok=True)

    same = tmp / "mix.wav"
    same.write_bytes(b"only the hash of this file matters in the test")

    logs = []
    engine_service.log = logs.append

    calls = []
    spans = {}
    guard = threading.Lock()

    def fake_separate_track(path, start, end, outdir):
        began = time.time()
        with guard:
            calls.append(path.name)
        outdir.mkdir(parents=True, exist_ok=True)
        stems = {}
        for name in ("vocals", "drums", "bass", "other"):
            target = outdir / f"{name}.wav"
            target.write_bytes(b"stem")
            stems[name] = str(target)
        time.sleep(0.6)  # long enough for the other callers to arrive
        with guard:
            spans.setdefault(path.name, []).append((began, time.time()))
        return {"stems": stems, "sample_rate": 44100, "seconds": 1.0, "elapsed_s": 0.6,
                "realtime_factor": 0.6, "cached": False}

    engine_service.separate_track = fake_separate_track

    # ---- the same track, three callers at once ----
    results = {}
    lock = threading.Lock()

    def call(index, path):
        reply = engine_service.handle_separate({"path": str(path)}, None)
        with lock:
            results[index] = reply

    threads = [threading.Thread(target=call, args=(i, same)) for i in range(3)]
    for t in threads:
        t.start()
    for t in threads:
        t.join()

    check("the same track was separated exactly once", len(calls) == 1, f"separations={len(calls)}")
    check("every caller got all four stems",
          all(r.get("ok") and len(r.get("stems", {})) == 4 for r in results.values()))
    check("the callers that waited were served from cache",
          sum(1 for r in results.values() if r.get("cached")) == 2,
          "cached=" + str([bool(r.get("cached")) for r in results.values()]))
    check("the waiting path was really taken",
          any("[queue]" in line for line in logs))

    # ---- a later call for the same track needs no work at all ----
    after = engine_service.handle_separate({"path": str(same)}, None)
    check("a later call is a cache hit", after.get("cached") is True)
    check("and it separated nothing", len(calls) == 1, f"separations={len(calls)}")

    # ---- two DIFFERENT tracks at the same time must still be able to overlap ----
    track_a = tmp / "track-a.wav"
    track_a.write_bytes(b"track a")
    track_b = tmp / "track-b.wav"
    track_b.write_bytes(b"track b")
    pair = [threading.Thread(target=call, args=(20, track_a)),
            threading.Thread(target=call, args=(21, track_b))]
    for t in pair:
        t.start()
    for t in pair:
        t.join()
    check("both new tracks separated", len(calls) == 3, f"separations={len(calls)}")

    span_a = spans.get("track-a.wav", [])
    span_b = spans.get("track-b.wav", [])
    overlap = bool(span_a and span_b
                   and span_a[0][0] < span_b[0][1] and span_b[0][0] < span_a[0][1])
    check("different tracks separate concurrently", overlap)

    failed = CHECKS.count(False)
    print()
    print(f"{len(CHECKS) - failed}/{len(CHECKS)} checks passed")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
