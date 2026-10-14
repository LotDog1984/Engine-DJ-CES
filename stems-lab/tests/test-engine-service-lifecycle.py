"""The service's lifetime: one engine per machine, and it goes away with the app that needed it.

Two bugs, both seen on 2026-10-14 after a 13-track batch, and both about a service that nobody was
watching:

  * a batch of shims starts in the same instant, and every one of them saw "no engine.port yet", so
    each started a service of its own. engine.log has the evidence from the real machine: two
    "[serve] listening" lines in the same second, i.e. two python processes holding a full set of
    models, one of them never used again. The service now prefers one port (DEFAULT_PORT) and a
    service that cannot take it checks that an engine is answering there and then exits - without
    loading anything.
  * nothing ever stopped a service. A resident process outliving the app keeps its models on the
    GPU and its files open, which is what "something is still using the engine" was. The first shim
    now hands over the pid of the app that started it (--watch-pid) and the service stops when that
    app is gone. A service started by hand stops when nobody has asked it anything for
    --idle-exit-minutes (default 60). STEMS_KEEP_ENGINE=1 disables both for a debugging run.

This suite checks the policy as a unit (Lifespan) and then the real service as a subprocess. It
needs no models and no audio: everything it covers happens before a separation would.

usage: .venv\\Scripts\\python.exe tests\\test-engine-service-lifecycle.py
"""
import json
import os
import pathlib
import socket
import subprocess
import sys
import tempfile
import threading
import time

LAB = pathlib.Path(__file__).resolve().parent.parent
SERVICE = LAB / "engine" / "engine_service.py"
sys.path.insert(0, str(LAB))
sys.path.insert(0, str(LAB / "engine"))

import engine_service  # noqa: E402  (needs the lab on sys.path, like the service does)

CHECKS = []


def check(name, ok, detail=""):
    CHECKS.append(ok)
    print(("PASS  " if ok else "FAIL  ") + name + (f"   [{detail}]" if detail else ""))


def free_port() -> int:
    s = socket.socket()
    s.bind(("127.0.0.1", 0))
    port = s.getsockname()[1]
    s.close()
    return port


class Engine:
    """One real engine_service.py process, isolated to its own port, log, cache and port file."""

    def __init__(self, tmp: pathlib.Path, port: int, tag: str = "", idle_minutes: float = 0.0,
                 extra_args=(), env_extra=None):
        self.tmp = tmp
        self.port = port
        stem = f"engine-{port}" + (f"-{tag}" if tag else "")
        self.port_file = tmp / f"{stem}.port"
        self.log_file = tmp / f"{stem}.log"
        self.proc = None
        self.args = [sys.executable, str(SERVICE), "--port", str(port),
                     "--idle-exit-minutes", str(idle_minutes)] + list(extra_args)
        self.env_extra = dict(env_extra or {})
        self.env = None

    def start(self):
        env = dict(os.environ)
        env.update({
            "STEMS_PORT_FILE": str(self.port_file),
            "STEMS_LOG_FILE": str(self.log_file),
            "STEMS_STREAM_LOG": str(self.tmp / "stdstream.log"),
            "STEMS_CACHE_DIR": str(self.tmp / "cache"),
        })
        env.update(self.env_extra)
        env.pop("STEMS_KEEP_ENGINE", None)
        self.env = env
        self.proc = subprocess.Popen(self.args, cwd=str(LAB), env=env,
                                     stdin=subprocess.DEVNULL,
                                     stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return self

    def log(self) -> str:
        """Everything this service has logged - the test's only view of its reasoning.

        Each engine has its own log file (STEMS_LOG_FILE), so this is only ever its own lines.
        """
        return self.log_file.read_text(encoding="utf-8", errors="replace") if self.log_file.exists() else ""

    def send(self, request: str, timeout: float = 3.0):
        try:
            with socket.create_connection(("127.0.0.1", self.port), timeout=timeout) as c:
                c.settimeout(timeout)
                c.sendall(request.encode("utf-8") + b"\n")
                data = b""
                while not data.endswith(b"\n"):
                    chunk = c.recv(4096)
                    if not chunk:
                        break
                    data += chunk
            return json.loads(data.decode("utf-8"))
        except (OSError, ValueError):
            return None

    def ping(self):
        return self.send('{"cmd":"ping"}', timeout=1.0)

    def wait_ready(self, seconds: float = 30.0):
        deadline = time.time() + seconds
        while time.time() < deadline:
            reply = self.ping()
            if reply and reply.get("ok"):
                return reply
            if self.proc.poll() is not None:
                return None
            time.sleep(0.2)
        return None

    def wait_exit(self, seconds: float = 25.0):
        try:
            return self.proc.wait(timeout=seconds)
        except subprocess.TimeoutExpired:
            return None

    def kill(self):
        if self.proc and self.proc.poll() is None:
            self.proc.kill()
            try:
                self.proc.wait(timeout=10)
            except subprocess.TimeoutExpired:
                pass

    def port_file_text(self):
        return self.port_file.read_text(encoding="utf-8").strip() if self.port_file.exists() else None


def main() -> int:
    # ---- the policy, as a unit -------------------------------------------------------------
    fake = {"t": 1000.0, "alive": True}
    watched = engine_service.Lifespan(
        watch_pid=4242, idle_minutes=1.0,
        clock=lambda: fake["t"], alive=lambda pid: fake["alive"])

    check("a watched app that is alive keeps the engine up", watched.stop_reason() is None)
    watched.job_started()
    fake["alive"] = False
    reason = watched.stop_reason() or ""
    check("when the app is gone the engine stops - a job in flight does not hold it forever",
          "is gone" in reason and "4242" in reason, reason)

    fake["t"] += 61.0
    fake["alive"] = True
    idle = engine_service.Lifespan(watch_pid=None, idle_minutes=1.0,
                                   clock=lambda: fake["t"], alive=lambda pid: True)
    idle.last_request = fake["t"] - 61.0
    check("an engine nobody asks anything stops when the idle window passes",
          "idle for" in (idle.stop_reason() or ""), idle.stop_reason())
    idle.touch()
    check("and a request resets that window", idle.stop_reason() is None)

    kept = engine_service.Lifespan(watch_pid=4242, idle_minutes=0.0001, keep=True,
                                   clock=lambda: fake["t"], alive=lambda pid: False)
    check("STEMS_KEEP_ENGINE=1 disables both rules (a debugging run)",
          kept.stop_reason() is None, str(kept.stop_reason()))

    drained = engine_service.Lifespan(watch_pid=None, idle_minutes=0.0)
    drained.job_started()
    threading.Timer(0.3, drained.job_finished).start()
    check("a job in flight is waited for before the process ends",
          engine_service.wait_for_jobs(drained, 5.0) is True)
    stuck = engine_service.Lifespan(watch_pid=None, idle_minutes=0.0)
    stuck.job_started()
    check("and a job that will not finish does not hold it open past the bound",
          engine_service.wait_for_jobs(stuck, 0.3) is False)
    check("the bound is a real number of seconds", engine_service.DRAIN_SECONDS > 0)

    # ---- the service itself, as a process --------------------------------------------------
    tmp = pathlib.Path(tempfile.mkdtemp(prefix="engine-lifecycle-"))
    engines = []
    sleeper = None
    try:
        port = free_port()

        # 1. the same port twice: the second service must leave without loading anything
        first = Engine(tmp, port, tag="first").start()
        engines.append(first)
        check("the first service serves", first.wait_ready() is not None)
        check("and it wrote its port file", first.port_file_text() == str(port),
              str(first.port_file_text()))

        second = Engine(tmp, port, tag="second").start()
        engines.append(second)
        code = second.wait_exit(25.0)
        check("a second service on the same port exits by itself", code == 0, f"exit={code}")
        check("it says why, instead of starting a second engine",
              "already serving" in second.log(), second.log().strip())
        check("and it never listened on its own",
              "[serve] listening" not in second.log())
        check("the engine that had the port is untouched", first.ping() is not None)
        check("the file that points at the engine is left correct",
              second.port_file_text() == str(port), str(second.port_file_text()))

        # 2. the app goes away
        sleeper = subprocess.Popen([sys.executable, "-c", "import time; time.sleep(300)"],
                                   stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL,
                                   stderr=subprocess.DEVNULL)
        watched_engine = Engine(tmp, free_port(), tag="watched",
                                extra_args=["--watch-pid", str(sleeper.pid)]).start()
        engines.append(watched_engine)
        reply = watched_engine.wait_ready()
        check("the service serves the app it was told to watch", reply is not None)
        check("and says whose engine it is", (reply or {}).get("watch_pid") == sleeper.pid,
              str((reply or {}).get("watch_pid")))
        check("its ping also names the idle rule in force",
              (reply or {}).get("idle_exit_minutes") == 0, str((reply or {}).get("idle_exit_minutes")))

        sleeper.kill()
        sleeper.wait(timeout=10)
        code = watched_engine.wait_exit(25.0)
        check("it stops when that app is gone", code == 0, f"exit={code}")
        watched_log = watched_engine.log()
        check("it says whose disappearance stopped it",
              f"pid {sleeper.pid}) is gone" in watched_log, watched_log.strip())
        check("it reports the stop in the log",
              "[serve] stopped" in watched_log)
        check("and it takes its port file with it", watched_engine.port_file_text() is None,
              str(watched_engine.port_file_text()))
        check("nothing answers on its port any more", watched_engine.ping() is None)

        # 3. nobody asked for anything for a while
        idle_engine = Engine(tmp, free_port(), tag="idle", idle_minutes=0.05).start()
        engines.append(idle_engine)
        check("the idle service serves first", idle_engine.wait_ready() is not None)
        code = idle_engine.wait_exit(25.0)
        check("an engine nobody asks anything stops by itself", code == 0, f"exit={code}")
        check("and says it was idle", "idle for" in idle_engine.log(),
              idle_engine.log().strip())
        check("its port file goes too", idle_engine.port_file_text() is None)

        # 4. the port file is only ever its own
        stopper = Engine(tmp, free_port(), tag="stop").start()
        engines.append(stopper)
        check("the stopping service serves first", stopper.wait_ready() is not None)
        stopper.port_file.write_text("1", encoding="utf-8")
        reply = stopper.send('{"cmd":"stop"}')
        check("a stop request is answered", bool(reply and reply.get("shutdown")), str(reply))
        code = stopper.wait_exit(25.0)
        check("and it stops", code == 0, f"exit={code}")
        check("it does not remove a port file that is no longer its own",
              stopper.port_file_text() == "1", str(stopper.port_file_text()))
        check("the log names the reason", "(asked to stop)" in stopper.log(),
              stopper.log().strip())
    finally:
        if sleeper and sleeper.poll() is None:
            sleeper.kill()
        for engine in engines:
            engine.kill()

    failed = CHECKS.count(False)
    print()
    print(f"{len(CHECKS) - failed}/{len(CHECKS)} checks passed")
    return 1 if failed else 0


if __name__ == "__main__":
    raise SystemExit(main())
