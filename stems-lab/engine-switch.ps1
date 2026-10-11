<#
engine-switch.ps1 - choose between Engine DJ's stock stems processor and a custom one.

Design rules:
  * Rename-only. The stock 415 MB binary is never copied, rewritten or deleted;
    switching engines moves the *name*, not the bytes.
  * Nothing except <bin>\stems-processor*.exe and the small <bin>\engine.json it writes
    (the lab location the installed shim should use) is ever touched. The sibling
    NNPredictionDispatcher_on.dll is deliberately left alone.
  * Everything is hashed before and after, and the layout is repaired if a step
    fails. A processor file is always left behind, so the app can still run.
  * Idempotent: running the same mode twice is a no-op.
  * A custom install records where the lab lives (engine.json next to the installed shim), so
    the project folder can be copied somewhere else and the shim still finds it.

Usage (from the project root):
  powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1
  powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1 -Engine custom
  powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1 -Engine vendor
  powershell -ExecutionPolicy Bypass -File stems-lab\engine-switch.ps1 -Engine custom -WhatIf

Targets:
  -Target live     %LOCALAPPDATA%\AIR Music Technology\EnginePrime\bin   (what Engine DJ uses)
  -Target project  <project>\bin                                         (the spare copy)
  -Target auto     live if it exists, otherwise project  (default)
  -Path <dir>      explicit bin directory, used for sandbox rehearsal
#>
[CmdletBinding()]
param(
    [ValidateSet('status', 'custom', 'vendor', 'adopt')]
    [string]$Engine = 'status',

    [ValidateSet('auto', 'live', 'project')]
    [string]$Target = 'auto',

    # Binary to install for -Engine custom. Defaults to stems-lab\shim\stems-processor.exe
    [string]$CustomExe,

    [string]$Path,

    # Advanced: relocate the bookkeeping files (used by the test harness so a
    # sandbox run cannot pollute the real state).
    [string]$StateFile,
    [string]$LogFile,

    # Machine-readable status on stdout, for the switch app. Nothing else is
    # written to stdout in this mode so the output stays parseable.
    [switch]$Json,

    [switch]$WhatIf,
    [switch]$Force
)

$ErrorActionPreference = 'Stop'
$script:Quiet = [bool]$Json

$LabRoot   = $PSScriptRoot
$ProjRoot  = Split-Path -Parent $LabRoot
if (-not $StateFile) { $StateFile = Join-Path $LabRoot 'switch-state.json' }
if (-not $LogFile)   { $LogFile   = Join-Path $LabRoot 'switch-log.txt' }

$VendorName = 'stems-processor.vendor.exe'
$ActiveName = 'stems-processor.exe'
$LabConfigName = 'engine.json'

if (-not $CustomExe) { $CustomExe = Join-Path $LabRoot 'shim\stems-processor.exe' }

# ---------------------------------------------------------------- helpers ----

function Log([string]$level, [string]$message) {
    $line = "{0} [{1}] {2}" -f (Get-Date).ToString('yyyy-MM-dd HH:mm:ss'), $level, $message
    if (-not $script:Quiet) { Write-Host $line }
    try { Add-Content -LiteralPath $LogFile -Value $line -Encoding UTF8 } catch { }
}

function HashOf([string]$file) {
    if (-not (Test-Path -LiteralPath $file -PathType Leaf)) { return $null }
    return (Get-FileHash -LiteralPath $file -Algorithm MD5).Hash.ToLowerInvariant()
}

function SizeOf([string]$file) {
    if (-not (Test-Path -LiteralPath $file -PathType Leaf)) { return $null }
    return (Get-Item -LiteralPath $file).Length
}

function Human([object]$bytes) {
    if ($null -eq $bytes) { return '-' }
    $b = [double]$bytes
    foreach ($u in 'B', 'KB', 'MB', 'GB') {
        if ($b -lt 1024) { return ('{0:0.##} {1}' -f $b, $u) }
        $b = $b / 1024
    }
    return ('{0:0.##} TB' -f $b)
}

function Dash([object]$v) { if ($null -eq $v) { return '-' } return [string]$v }

function Get-LabConfig([string]$binDir) {
    # The installed shim finds its lab through engine.json beside it (see Lab() in StemsShim.cs).
    # This reads back what is recorded there, or $null if there is no file.
    $cfg = Join-Path $binDir $LabConfigName
    if (-not (Test-Path -LiteralPath $cfg)) { return $null }
    try { return [string]((Get-Content -LiteralPath $cfg -Raw | ConvertFrom-Json).lab) } catch { return $null }
}

function Ensure-LabConfig([string]$binDir) {
    # Records this project folder as the lab the installed shim should use, so a copied project
    # works from wherever it now lives. Refreshed on every custom switch when it has changed.
    if ((Get-LabConfig $binDir) -eq $LabRoot) {
        Log 'INFO' ("lab location already recorded in " + $LabConfigName)
        return
    }
    if ($WhatIf) {
        Log 'WHATIF' ("would record the lab location in {0}: {1}" -f (Join-Path $binDir $LabConfigName), $LabRoot)
        return
    }
    $json = '{"lab": "' + $LabRoot.Replace('\', '\\') + '"}'
    Set-Content -LiteralPath (Join-Path $binDir $LabConfigName) -Value $json -Encoding ASCII
    Log 'OK' ("recorded the lab location in {0}" -f (Join-Path $binDir $LabConfigName))
}

# Records deserialised from JSON are PSCustomObjects: assigning a property that
# is not already on them throws, so every write goes through here.
function Set-Prop($obj, [string]$name, $value) {
    if ($obj.PSObject.Properties.Name -contains $name) { $obj.$name = $value }
    else { $obj | Add-Member -MemberType NoteProperty -Name $name -Value $value -Force }
    return $obj
}

function Get-State {
    if (Test-Path -LiteralPath $StateFile) {
        try {
            $s = Get-Content -LiteralPath $StateFile -Raw | ConvertFrom-Json
            if (-not ($s.PSObject.Properties.Name -contains 'targets') -or $null -eq $s.targets) {
                return [pscustomobject]@{ version = 1; targets = @() }
            }
            return [pscustomobject]@{ version = 1; targets = @($s.targets) }
        } catch { }
    }
    return [pscustomobject]@{ version = 1; targets = @() }
}

function Save-State($state) {
    ConvertTo-Json -InputObject $state -Depth 8 | Set-Content -LiteralPath $StateFile -Encoding UTF8
}

function Get-TargetState($state, [string]$binDir) {
    $key = $binDir.ToLowerInvariant()
    foreach ($t in @($state.targets)) {
        if ($t -and ([string]$t.bin).ToLowerInvariant() -eq $key) { return $t }
    }
    return $null
}

function Set-TargetState($state, [string]$binDir, $value) {
    $key = $binDir.ToLowerInvariant()
    $list = @($state.targets)
    for ($i = 0; $i -lt $list.Count; $i++) {
        if ($list[$i] -and ([string]$list[$i].bin).ToLowerInvariant() -eq $key) {
            $list[$i] = $value
            $state.targets = $list
            return $state
        }
    }
    $state.targets = @($list + $value)
    return $state
}

function App-Running {
    $running = @()
    foreach ($n in @('Engine DJ', 'stems-processor')) {
        $p = Get-Process -Name $n -ErrorAction SilentlyContinue
        if ($p) { $running += ("{0}({1})" -f $n, (($p | ForEach-Object { $_.Id }) -join ',')) }
    }
    return $running
}

# The property that actually matters: the app must always find a processor.
# If a step died halfway, fail back to the stock file rather than to nothing.
function Repair-Layout([string]$binDir, [string]$stage) {
    $active = Join-Path $binDir $ActiveName
    $backup = Join-Path $binDir $VendorName

    if ((Test-Path -LiteralPath $active) -and -not (Test-Path -LiteralPath $backup)) { return }

    if (-not (Test-Path -LiteralPath $active)) {
        if (Test-Path -LiteralPath $backup) {
            Log 'WARN' "$stage left no active processor - putting the stock file back under $ActiveName"
            Rename-Item -LiteralPath $backup -NewName $ActiveName -Force
            return
        }
        throw "$stage left the bin directory with no processor at all - restore the component from Engine DJ"
    }
}

# ------------------------------------------------------------------ targets ---

function Resolve-BinDir {
    if ($Path) {
        if (-not (Test-Path -LiteralPath $Path)) { throw "bin directory not found: $Path" }
        return (Resolve-Path -LiteralPath $Path).Path
    }

    $live    = Join-Path $env:LOCALAPPDATA 'AIR Music Technology\EnginePrime\bin'
    $project = Join-Path $ProjRoot 'bin'

    switch ($Target) {
        'live'    { if (-not (Test-Path -LiteralPath $live))    { throw "live bin not found: $live" }       return (Resolve-Path -LiteralPath $live).Path }
        'project' { if (-not (Test-Path -LiteralPath $project)) { throw "project bin not found: $project" } return (Resolve-Path -LiteralPath $project).Path }
        default {
            if (Test-Path -LiteralPath $live)    { return (Resolve-Path -LiteralPath $live).Path }
            if (Test-Path -LiteralPath $project) { return (Resolve-Path -LiteralPath $project).Path }
            throw 'no bin directory found (looked at the live install and the project copy)'
        }
    }
}

# One description of the bin directory, shared by the human and JSON views.
function Get-StatusObject([string]$binDir) {
    $active = Join-Path $binDir $ActiveName
    $backup = Join-Path $binDir $VendorName
    $state  = Get-State
    $ts     = Get-TargetState $state $binDir

    $ah = HashOf $active
    $bh = HashOf $backup
    $vendorHash = $null
    $customHash = $null
    if ($ts) {
        $vendorHash = $ts.vendorHash
        if ($ts.PSObject.Properties.Name -contains 'customHash') { $customHash = $ts.customHash }
    }

    $engine = 'unknown'
    if (-not (Test-Path -LiteralPath $active)) {
        $engine = 'none'
    } elseif ($vendorHash -and $ah -eq $vendorHash) {
        $engine = 'vendor'
    } elseif ($bh -and $ah -eq $bh) {
        $engine = 'vendor'
    } elseif ($vendorHash) {
        $engine = 'custom'
    }

    $dll = Join-Path $binDir 'NNPredictionDispatcher_on.dll'
    return [pscustomobject]@{
        bin           = $binDir
        engine        = $engine
        activeHash    = $ah
        activeSize    = (SizeOf $active)
        backupHash    = $bh
        backupSize    = (SizeOf $backup)
        baselineHash  = $vendorHash
        customHash    = $customHash
        dllHash       = (HashOf $dll)
        dllSize       = (SizeOf $dll)
        liveBin       = (Join-Path $env:LOCALAPPDATA 'AIR Music Technology\EnginePrime\bin')
        lab           = (Get-LabConfig $binDir)
        appRunning    = @(App-Running)
        updatedUtc    = $(if ($ts) { $ts.updatedUtc } else { $null })
    }
}

function Show-Status([string]$binDir) {
    $o = Get-StatusObject $binDir

    $label = 'unknown - no baseline recorded; run -Engine adopt if this is the stock file'
    switch ($o.engine) {
        'vendor' { $label = 'stock (vendor)' }
        'custom' { $label = 'custom' }
        'none'   { $label = 'no processor present' }
    }

    Write-Host ''
    Write-Host "bin:    $binDir"
    Write-Host "engine: $label"
    Write-Host ("  active  {0,10}  {1}  {2}" -f (Human $o.activeSize), (Dash $o.activeHash), $ActiveName)
    Write-Host ("  backup  {0,10}  {1}  {2}" -f (Human $o.backupSize), (Dash $o.backupHash), $VendorName)
    if ($o.baselineHash) { Write-Host ("  baseline vendor hash: {0}" -f $o.baselineHash) }
    if ($o.customHash) { Write-Host ("  recorded custom hash: {0}" -f $o.customHash) }
    if ($o.lab) { Write-Host ("  lab     {0}" -f $o.lab) }
    if ($o.dllHash) { Write-Host ("  companion dll {0,10}  {1}" -f (Human $o.dllSize), $o.dllHash) }
}

# Adopt only *records* which bytes are the stock processor; it never moves a file.
# The rule: if a vendor backup exists, that is the stock binary; otherwise the
# active file is. Nothing is renamed, so adopting cannot break a running setup.
function Adopt([string]$binDir) {
    $active = Join-Path $binDir $ActiveName
    $backup = Join-Path $binDir $VendorName
    $state  = Get-State
    $ts     = Get-TargetState $state $binDir

    $hasActive = Test-Path -LiteralPath $active
    $hasBackup = Test-Path -LiteralPath $backup
    if (-not $hasActive -and -not $hasBackup) { throw "nothing to adopt: no processor in $binDir" }

    if ($hasBackup) {
        $source = $backup
        $label  = $VendorName
    } else {
        $source = $active
        $label  = $ActiveName
    }
    $hash = HashOf $source
    $size = SizeOf $source

    if ($ts -and $ts.vendorHash -eq $hash) {
        Log 'OK' ("baseline already recorded for {0} ({1})" -f $label, $hash)
        return $true
    }
    if ($ts -and $ts.vendorHash -and -not $Force) {
        throw "a different baseline is already recorded ($($ts.vendorHash)). Re-run with -Force to replace it with $hash."
    }

    Log 'INFO' ("recording {0} as the stock baseline ({1}, {2})" -f $label, $hash, (Human $size))
    if ($WhatIf) { Log 'WHATIF' "would record $hash as the stock baseline"; return $true }

    $ts = [pscustomobject]@{
        bin          = $binDir
        vendorHash   = $hash
        vendorSize   = $size
        activeEngine = 'vendor'
        updatedUtc   = (Get-Date).ToUniversalTime().ToString('o')
    }
    $state = Set-TargetState $state $binDir $ts
    Save-State $state
    Log 'OK' 'baseline recorded (no files moved)'
    return $true
}

function Switch-ToVendor([string]$binDir) {
    $active = Join-Path $binDir $ActiveName
    $backup = Join-Path $binDir $VendorName
    $state  = Get-State
    $ts     = Get-TargetState $state $binDir

    if (-not (Test-Path -LiteralPath $backup)) {
        if (-not (Test-Path -LiteralPath $active)) { throw "neither $ActiveName nor $VendorName exists in $binDir" }
        if ($ts -and (HashOf $active) -eq $ts.vendorHash) { Log 'OK' 'already stock (vendor)'; return $true }
        if (-not $ts) { throw "no baseline recorded and no $VendorName to restore from - run -Engine adopt if the active file is the stock processor" }
        throw "no vendor backup to restore ($VendorName is missing) and the active file is not the recorded stock binary. Restore the component from Engine DJ."
    }

    $bh = HashOf $backup
    if ($ts -and $ts.vendorHash -and $bh -ne $ts.vendorHash -and -not $Force) {
        throw "the backup does not match the recorded baseline (expected $($ts.vendorHash), found $bh). Re-run with -Force if you have checked it yourself."
    }

    $ah = HashOf $active
    if ($ah -and $ah -eq $bh) {
        Log 'INFO' 'the active file is byte-identical to the backup - dropping the redundant copy'
        if (-not $WhatIf) { Remove-Item -LiteralPath $active -Force }
    }

    Log 'INFO' "restoring stock: $VendorName -> $ActiveName"
    if ($WhatIf) {
        Log 'WHATIF' "would remove the custom $ActiveName (if present) and rename $VendorName -> $ActiveName"
        return $true
    }

    try {
        if (Test-Path -LiteralPath $active) { Remove-Item -LiteralPath $active -Force }
        Rename-Item -LiteralPath $backup -NewName $ActiveName -Force
        Repair-Layout $binDir 'vendor restore'
    } catch {
        Log 'ERROR' "restore failed: $($_.Exception.Message)"
        return $false
    }

    if ((HashOf $active) -ne $bh) {
        Log 'ERROR' 'verification failed - the active file does not hash to the vendor backup'
        return $false
    }

    if (-not $ts) {
        # restored without ever having adopted: the active file is the baseline now,
        # so record it instead of leaving the bin directory with no baseline at all.
        $ts = [pscustomobject]@{
            bin          = $binDir
            vendorHash   = $bh
            vendorSize   = (SizeOf $active)
            activeEngine = 'vendor'
            updatedUtc   = (Get-Date).ToUniversalTime().ToString('o')
        }
        Log 'INFO' 'recording the restored binary as the stock baseline'
    } else {
        $ts = Set-Prop $ts 'activeEngine' 'vendor'
        $ts = Set-Prop $ts 'updatedUtc'   (Get-Date).ToUniversalTime().ToString('o')
    }
    $state = Set-TargetState $state $binDir $ts
    Save-State $state
    Log 'OK' 'stock engine restored'
    return $true
}

function Switch-ToCustom([string]$binDir, [string]$customExe) {
    $active = Join-Path $binDir $ActiveName
    $backup = Join-Path $binDir $VendorName
    $state  = Get-State
    $ts     = Get-TargetState $state $binDir

    if (-not (Test-Path -LiteralPath $customExe -PathType Leaf)) {
        throw "custom binary not found: $customExe  (put the replacement processor there, or pass -CustomExe <path>)"
    }
    $ch = HashOf $customExe
    $cs = SizeOf $customExe

    if (-not $ts) {
        throw 'no baseline recorded for this bin directory. Run -Engine adopt once while the stock processor is active, then switch to custom.'
    }
    if ($ts.vendorHash -and $ch -eq $ts.vendorHash) {
        throw 'the custom binary is byte-identical to the stock processor - refusing to install the original as the custom engine'
    }

    if (-not (Test-Path -LiteralPath $backup)) {
        if (-not (Test-Path -LiteralPath $active)) { throw "no $ActiveName present to preserve as the vendor backup" }
        if ((HashOf $active) -ne $ts.vendorHash) {
            throw "the active $ActiveName does not match the recorded stock baseline, so it cannot be trusted as the original. Re-run with -Force if you have verified it yourself."
        }
    }

    if ((Test-Path -LiteralPath $active) -and (HashOf $active) -eq $ch -and (Test-Path -LiteralPath $backup)) {
        Log 'OK' 'already on the custom engine'
        Ensure-LabConfig $binDir
        return $true
    }

    Log 'INFO' ("installing custom engine {0} ({1}) from {2}" -f $ch, (Human $cs), $customExe)
    if ($WhatIf) {
        if (-not (Test-Path -LiteralPath $backup)) { Log 'WHATIF' "would rename $ActiveName -> $VendorName" }
        Log 'WHATIF' "would copy $customExe -> $ActiveName"
        Ensure-LabConfig $binDir
        return $true
    }

    try {
        if (-not (Test-Path -LiteralPath $backup)) { Rename-Item -LiteralPath $active -NewName $VendorName -Force }
        Copy-Item -LiteralPath $customExe -Destination $active -Force
        Repair-Layout $binDir 'custom install'
    } catch {
        Log 'ERROR' "install failed: $($_.Exception.Message)"
        return $false
    }

    $now = HashOf $active
    if ($now -ne $ch) { Log 'ERROR' "install verification failed (active hashes to $now, expected $ch)"; return $false }
    if (-not (Test-Path -LiteralPath $backup)) { Log 'ERROR' 'the vendor backup is missing after the switch'; return $false }

    $ts = Set-Prop $ts 'activeEngine' 'custom'
    $ts = Set-Prop $ts 'customHash'   $ch
    $ts = Set-Prop $ts 'customSize'   $cs
    $ts = Set-Prop $ts 'updatedUtc'   (Get-Date).ToUniversalTime().ToString('o')
    $state = Set-TargetState $state $binDir $ts
    Save-State $state
    Ensure-LabConfig $binDir
    Log 'OK' 'custom engine active'
    return $true
}

# ------------------------------------------------------------------- main ----

try {
    $binDir = Resolve-BinDir
} catch {
    Log 'ERROR' $_.Exception.Message
    exit 1
}

$running = App-Running
if ($running.Count -gt 0) {
    $liveBin = Join-Path $env:LOCALAPPDATA 'AIR Music Technology\EnginePrime\bin'
    if ($binDir.ToLowerInvariant() -eq $liveBin.ToLowerInvariant()) {
        Log 'WARN' ("Engine DJ / stems-processor is running: {0}" -f ($running -join ', '))
        if ($Engine -ne 'status' -and -not $Force) {
            Log 'ERROR' 'close Engine DJ before switching the live install. Or pass -Force if you are sure the file is not locked.'
            exit 1
        }
    } else {
        Log 'INFO' ("Engine DJ is running ({0}) but the target is not the live install - continuing" -f ($running -join ', '))
    }
}

switch ($Engine) {
    'status' {
        if ($Json) { ConvertTo-Json -InputObject (Get-StatusObject $binDir) -Compress -Depth 4 }
        else       { Show-Status $binDir }
        exit 0
    }
    'adopt'  { if (Adopt $binDir)          { Show-Status $binDir; exit 0 } else { exit 1 } }
    'vendor' { if (Switch-ToVendor $binDir)  { Show-Status $binDir; exit 0 } else { exit 1 } }
    'custom' { if (Switch-ToCustom $binDir $CustomExe) { Show-Status $binDir; exit 0 } else { exit 1 } }
}
