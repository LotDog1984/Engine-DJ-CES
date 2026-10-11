// StemsEngineSwitch - a small window that flips Engine DJ between its own stems
// processor and the custom one, so nothing has to be typed into a terminal.
//
// It is a front end for stems-lab\engine-switch.ps1, which is the tested piece:
// every button click runs that script and shows its output verbatim. The script
// does the renaming, the hashing and the rollback; this window only chooses the
// mode and reports what happened.
//
//   --selftest <outfile>   run headless, write a report, exit 0/1 (used by tests)
using System;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Reflection;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

static class Program
{
    [STAThread]
    static int Main(string[] args)
    {
        if (args.Length >= 2 && args[0] == "--selftest")
            return SelfTest(args[1]);

        Application.EnableVisualStyles();
        Application.SetCompatibleTextRenderingDefault(false);
        Application.Run(new MainForm());
        return 0;
    }

    // ---------------------------------------------------------------- script --

    internal static string ScriptPath()
    {
        string appDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
        return Path.GetFullPath(Path.Combine(appDir, "..", "engine-switch.ps1"));
    }

    internal class ScriptResult
    {
        public string Output;
        public int ExitCode;
    }

    internal static ScriptResult RunScript(string mode, bool liveTarget, bool force, bool json)
    {
        var result = new ScriptResult();
        string script = ScriptPath();
        if (!File.Exists(script))
        {
            result.ExitCode = 1;
            result.Output = "engine-switch.ps1 not found at " + script;
            return result;
        }

        var psi = new ProcessStartInfo("powershell.exe");
        var a = new StringBuilder();
        a.Append("-NoProfile -ExecutionPolicy Bypass -File \"").Append(script).Append("\"");
        a.Append(" -Engine ").Append(mode);
        a.Append(" -Target ").Append(liveTarget ? "live" : "project");
        if (force) a.Append(" -Force");
        if (json) a.Append(" -Json");
        psi.Arguments = a.ToString();
        psi.UseShellExecute = false;
        psi.CreateNoWindow = true;
        psi.RedirectStandardOutput = true;
        psi.RedirectStandardError = true;

        try
        {
            using (var p = Process.Start(psi))
            {
                Task<string> outTask = p.StandardOutput.ReadToEndAsync();
                Task<string> errTask = p.StandardError.ReadToEndAsync();
                p.WaitForExit();
                string output = outTask.Result;
                string err = errTask.Result;
                result.ExitCode = p.ExitCode;
                if (!string.IsNullOrEmpty(err)) output = output + Environment.NewLine + err;
                result.Output = output;
                return result;
            }
        }
        catch (Exception e)
        {
            result.ExitCode = 1;
            result.Output = "could not run PowerShell: " + e.Message;
            return result;
        }
    }

    // Turning a button into a script mode. The one twist: on a brand new setup there
    // is no recorded baseline, and the switch deliberately refuses to guess which file
    // is the original. So the first click on "ORIGINAL" records the baseline instead.
    internal static string ResolveMode(string requested, string engine)
    {
        if (requested == "vendor" && engine == "unknown") return "adopt";
        return requested;
    }

    // Minimal reader for the flat JSON that -Status -Json emits. We produce that
    // JSON ourselves, so a regex is enough and avoids extra dependencies.
    internal static string JsonString(string json, string key)
    {
        if (json == null) return null;
        var m = Regex.Match(json, "\"" + Regex.Escape(key) + "\"\\s*:\\s*\"((?:\\\\.|[^\"\\\\])*)\"");
        return m.Success ? Regex.Unescape(m.Groups[1].Value) : null;
    }

    internal static string JsonRaw(string json, string key)
    {
        if (json == null) return null;
        var m = Regex.Match(json, "\"" + Regex.Escape(key) + "\"\\s*:\\s*(\\[[^\\]]*\\]|null|[^,}\\s]+)");
        return m.Success ? m.Groups[1].Value : null;
    }

    // ------------------------------------------------------------- selftest --

    static int SelfTest(string reportPath)
    {
        var sb = new StringBuilder();
        int failures = 0;

        Action<string, bool, string> check = delegate (string name, bool ok, string detail)
        {
            if (!ok) failures++;
            sb.AppendLine((ok ? "PASS  " : "FAIL  ") + name + (string.IsNullOrEmpty(detail) ? "" : "   [" + detail + "]"));
        };

        string script = ScriptPath();
        check("engine-switch.ps1 resolves next to the app", File.Exists(script), script);

        ScriptResult r = RunScript("status", true, false, true);
        string json = r.Output;
        check("status -Json exits 0", r.ExitCode == 0, "exit=" + r.ExitCode + " " + json);

        string engine = JsonString(json, "engine");
        string bin = JsonString(json, "bin");
        string baseline = JsonString(json, "baselineHash");
        string active = JsonString(json, "activeHash");
        string liveBin = JsonString(json, "liveBin");
        string appRunning = JsonRaw(json, "appRunning");

        check("json parses and reports an engine", engine != null && engine.Length > 0, "engine=" + engine);
        check("json reports the live bin directory", bin != null && liveBin != null && bin == liveBin, "bin=" + bin);
        check("json reports the active processor hash", active != null && active.Length == 32, "active=" + active);
        check("json reports appRunning as an array", appRunning != null && appRunning.StartsWith("["), "appRunning=" + appRunning);
        sb.AppendLine("engine=" + engine + " baseline=" + (baseline ?? "(none)") + " active=" + active);
        sb.AppendLine("appRunning=" + appRunning);

        ScriptResult r2 = RunScript("status", false, false, false);
        string human = r2.Output;
        check("human status exits 0 for the project copy", r2.ExitCode == 0, "exit=" + r2.ExitCode);
        check("human status names the engine", human != null && human.Contains("engine:"), human);

        check("first click on ORIGINAL records the baseline", ResolveMode("vendor", "unknown") == "adopt", ResolveMode("vendor", "unknown"));
        check("ORIGINAL restores once a baseline exists", ResolveMode("vendor", "vendor") == "vendor", ResolveMode("vendor", "vendor"));
        check("CUSTOM is passed straight through", ResolveMode("custom", "vendor") == "custom", ResolveMode("custom", "vendor"));

        sb.AppendLine();
        sb.AppendLine(failures == 0 ? "ALL CHECKS PASSED" : failures + " CHECK(S) FAILED");
        File.WriteAllText(reportPath, sb.ToString());
        return failures == 0 ? 0 : 1;
    }
}

class MainForm : Form
{
    Label lblEngine;
    Label lblDetail;
    Button btnOriginal;
    Button btnCustom;
    Label lblOriginalHint;
    Label lblCustomHint;
    ComboBox cmbTarget;
    CheckBox chkForce;
    Button btnRefresh;
    TextBox txtLog;
    StatusStrip strip;
    ToolStripStatusLabel stripLabel;
    bool busy;
    string currentEngine = "unknown";

    public MainForm()
    {
        Text = "Stems Engine Switch";
        ClientSize = new Size(700, 560);
        MinimumSize = new Size(700, 520);
        StartPosition = FormStartPosition.CenterScreen;
        Font = new Font("Segoe UI", 9F);
        BackColor = Color.FromArgb(250, 250, 252);

        // ---- header
        var header = new Panel();
        header.Dock = DockStyle.Top;
        header.Height = 108;
        header.Padding = new Padding(16, 12, 16, 8);
        header.BackColor = Color.White;

        var lblCaption = new Label();
        lblCaption.Text = "Stems engine in use";
        lblCaption.ForeColor = Color.FromArgb(110, 110, 120);
        lblCaption.Dock = DockStyle.Top;
        lblCaption.Height = 20;

        lblEngine = new Label();
        lblEngine.Text = "reading...";
        lblEngine.Font = new Font("Segoe UI", 17F, FontStyle.Bold);
        lblEngine.Dock = DockStyle.Top;
        lblEngine.Height = 38;

        lblDetail = new Label();
        lblDetail.Text = "";
        lblDetail.ForeColor = Color.FromArgb(90, 90, 100);
        lblDetail.Dock = DockStyle.Fill;

        header.Controls.Add(lblDetail);
        header.Controls.Add(lblEngine);
        header.Controls.Add(lblCaption);

        // ---- buttons
        var buttons = new Panel();
        buttons.Dock = DockStyle.Top;
        buttons.Height = 132;
        buttons.Padding = new Padding(16, 10, 16, 8);

        btnOriginal = new Button();
        btnOriginal.Text = "Use ORIGINAL stems";
        btnOriginal.Font = new Font("Segoe UI", 11F, FontStyle.Bold);
        btnOriginal.Size = new Size(316, 62);
        btnOriginal.Location = new Point(16, 10);
        btnOriginal.FlatStyle = FlatStyle.Flat;
        btnOriginal.BackColor = Color.FromArgb(225, 234, 245);
        btnOriginal.Click += delegate { Go("vendor"); };

        btnCustom = new Button();
        btnCustom.Text = "Use CUSTOM stems";
        btnCustom.Font = new Font("Segoe UI", 11F, FontStyle.Bold);
        btnCustom.Size = new Size(316, 62);
        btnCustom.Location = new Point(346, 10);
        btnCustom.FlatStyle = FlatStyle.Flat;
        btnCustom.BackColor = Color.FromArgb(224, 241, 224);
        btnCustom.Click += delegate { Go("custom"); };

        lblOriginalHint = new Label();
        lblOriginalHint.Text = "Engine DJ's own processor";
        lblOriginalHint.ForeColor = Color.FromArgb(110, 110, 120);
        lblOriginalHint.Location = new Point(18, 76);
        lblOriginalHint.Size = new Size(300, 20);

        lblCustomHint = new Label();
        lblCustomHint.Text = "Your replacement engine";
        lblCustomHint.ForeColor = Color.FromArgb(110, 110, 120);
        lblCustomHint.Location = new Point(348, 76);
        lblCustomHint.Size = new Size(300, 20);

        buttons.Controls.Add(btnOriginal);
        buttons.Controls.Add(btnCustom);
        buttons.Controls.Add(lblOriginalHint);
        buttons.Controls.Add(lblCustomHint);

        // ---- options
        var options = new Panel();
        options.Dock = DockStyle.Top;
        options.Height = 48;
        options.Padding = new Padding(16, 6, 16, 6);
        options.BackColor = Color.White;

        var lblTarget = new Label();
        lblTarget.Text = "Apply to:";
        lblTarget.Location = new Point(16, 14);
        lblTarget.Size = new Size(62, 20);

        cmbTarget = new ComboBox();
        cmbTarget.DropDownStyle = ComboBoxStyle.DropDownList;
        cmbTarget.Location = new Point(82, 11);
        cmbTarget.Size = new Size(250, 24);
        cmbTarget.Items.Add("Engine DJ (live install)");
        cmbTarget.Items.Add("Project copy (practice only)");
        cmbTarget.SelectedIndex = 0;

        chkForce = new CheckBox();
        chkForce.Text = "Force (use if Engine DJ stays open)";
        chkForce.Location = new Point(348, 12);
        chkForce.Size = new Size(240, 22);

        btnRefresh = new Button();
        btnRefresh.Text = "Refresh";
        btnRefresh.Location = new Point(596, 10);
        btnRefresh.Size = new Size(80, 26);
        btnRefresh.Click += delegate { RefreshState(false); };

        options.Controls.Add(lblTarget);
        options.Controls.Add(cmbTarget);
        options.Controls.Add(chkForce);
        options.Controls.Add(btnRefresh);

        // ---- log
        txtLog = new TextBox();
        txtLog.Multiline = true;
        txtLog.ReadOnly = true;
        txtLog.ScrollBars = ScrollBars.Both;
        txtLog.WordWrap = false;
        txtLog.Dock = DockStyle.Fill;
        txtLog.BackColor = Color.FromArgb(30, 30, 34);
        txtLog.ForeColor = Color.FromArgb(226, 226, 232);
        txtLog.Font = new Font("Consolas", 8.5F);
        txtLog.BorderStyle = BorderStyle.None;

        var logHost = new Panel();
        logHost.Dock = DockStyle.Fill;
        logHost.Padding = new Padding(16, 8, 16, 8);
        logHost.Controls.Add(txtLog);

        strip = new StatusStrip();
        stripLabel = new ToolStripStatusLabel("ready");
        strip.Items.Add(stripLabel);
        strip.SizingGrip = false;

        Controls.Add(logHost);
        Controls.Add(options);
        Controls.Add(buttons);
        Controls.Add(header);
        Controls.Add(strip);

        Load += delegate { RefreshState(false); };
    }

    bool LiveTarget { get { return cmbTarget.SelectedIndex == 0; } }

    void SetBusy(bool on, string message)
    {
        busy = on;
        btnOriginal.Enabled = !on;
        btnCustom.Enabled = !on;
        btnRefresh.Enabled = !on;
        cmbTarget.Enabled = !on;
        chkForce.Enabled = !on;
        UseWaitCursor = on;
        stripLabel.Text = message;
    }

    async void RefreshState(bool afterAction)
    {
        SetBusy(true, "reading current state...");
        try
        {
            Program.ScriptResult r = await Task.Run(() => Program.RunScript("status", LiveTarget, false, true));
            if (r.ExitCode != 0) { ShowFailure("could not read the current state", r.Output); return; }
            ApplyStatus(r.Output, afterAction);
            SetBusy(false, "ready");
        }
        catch (Exception e)
        {
            ShowFailure("unexpected error", e.Message);
        }
    }

    async void Go(string mode)
    {
        bool toCustom = mode == "custom";

        if (toCustom && currentEngine == "unknown")
        {
            MessageBox.Show(
                "First-time setup: click \"Set up ORIGINAL stems\" once.\n\n"
                + "That records which file is Engine DJ's original processor, which is the "
                + "restore point the switch needs before it will touch anything.",
                "Stems Engine Switch", MessageBoxButtons.OK, MessageBoxIcon.Information);
            return;
        }

        string resolved = Program.ResolveMode(mode, currentEngine);
        string what = resolved == "adopt" ? "original baseline" : (toCustom ? "custom" : "original");

        if (chkForce.Checked)
        {
            var answer = MessageBox.Show(
                "Force is on. The switch will modify files even if Engine DJ is running.\n\nContinue?",
                "Stems Engine Switch", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (answer != DialogResult.Yes) return;
        }

        SetBusy(true, "switching to " + what + " stems...");
        txtLog.Text = "";
        try
        {
            bool force = chkForce.Checked;
            Program.ScriptResult r = await Task.Run(() => Program.RunScript(resolved, LiveTarget, force, false));
            txtLog.Text = r.Output;
            if (r.ExitCode != 0)
            {
                ShowFailure("switch to " + what + " stems did not complete", "");
                SetBusy(false, "no change made");
                return;
            }
            Program.ScriptResult r2 = await Task.Run(() => Program.RunScript("status", LiveTarget, false, true));
            ApplyStatus(r2.Output, true);
            SetBusy(false, toCustom ? "now using custom stems" : "back on the original stems");
        }
        catch (Exception e)
        {
            ShowFailure("unexpected error", e.Message);
        }
    }

    void ApplyStatus(string json, bool afterAction)
    {
        string engine = Program.JsonString(json, "engine");
        currentEngine = engine;
        string bin = Program.JsonString(json, "bin");
        string baseline = Program.JsonString(json, "baselineHash");
        string active = Program.JsonString(json, "activeHash");
        string appRunning = Program.JsonRaw(json, "appRunning");
        bool running = appRunning != null && appRunning.Replace(" ", "") != "[]";

        string text;
        Color colour;
        switch (engine)
        {
            case "vendor":
                text = "ORIGINAL STEMS  (Engine DJ's processor)";
                colour = Color.FromArgb(31, 78, 140);
                break;
            case "custom":
                text = "CUSTOM STEMS  (replacement engine)";
                colour = Color.FromArgb(28, 122, 55);
                break;
            case "none":
                text = "NO PROCESSOR PRESENT";
                colour = Color.FromArgb(160, 40, 40);
                break;
            default:
                text = "NOT SET UP YET";
                colour = Color.FromArgb(160, 110, 20);
                break;
        }
        lblEngine.Text = text;
        lblEngine.ForeColor = colour;

        string hint = ShortHash(bin) + "\n";
        if (engine == "vendor") hint += "Restore point: everything is stock.\n";
        if (engine == "custom") hint += "The original is preserved alongside as stems-processor.vendor.exe.\n";
        if (engine == "unknown") hint += "Click \"Use ORIGINAL stems\" once to record the stock baseline, then switch to custom.\n";
        hint += "active " + ShortHash(active) + "   baseline " + ShortHash(baseline);
        if (running) hint += "\nEngine DJ is open - close it before switching.";
        lblDetail.Text = hint;

        btnOriginal.Font = new Font("Segoe UI", 11F, engine == "vendor" ? FontStyle.Bold : FontStyle.Regular);
        btnCustom.Font = new Font("Segoe UI", 11F, engine == "custom" ? FontStyle.Bold : FontStyle.Regular);
        btnOriginal.FlatAppearance.BorderSize = engine == "vendor" ? 3 : 1;
        btnCustom.FlatAppearance.BorderSize = engine == "custom" ? 3 : 1;
        btnOriginal.Text = engine == "unknown" ? "Set up ORIGINAL stems" : "Use ORIGINAL stems";
        lblOriginalHint.Text = engine == "vendor" ? "in use now"
            : (engine == "unknown" ? "first-time: records the original, then you can switch" : "Engine DJ's own processor");
        lblCustomHint.Text = engine == "custom" ? "in use now" : "Your replacement engine";

        if (!afterAction && string.IsNullOrEmpty(txtLog.Text))
            txtLog.Text = "Engine: " + engine + Environment.NewLine
                + "Folder: " + bin + Environment.NewLine
                + "Active: " + active + Environment.NewLine
                + "Baseline: " + (baseline ?? "(not recorded yet)") + Environment.NewLine;
    }

    static string ShortHash(string hash)
    {
        if (string.IsNullOrEmpty(hash)) return "(none)";
        return hash.Substring(0, 8) + "...";
    }

    void ShowFailure(string title, string detail)
    {
        lblEngine.Text = title.ToUpperInvariant();
        lblEngine.ForeColor = Color.FromArgb(170, 40, 40);
        if (!string.IsNullOrEmpty(detail)) txtLog.Text = detail;
        SetBusy(false, "failed - see the log below");
    }
}
