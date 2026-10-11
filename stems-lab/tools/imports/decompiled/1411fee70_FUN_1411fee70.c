// FUN_1411fee70 @ 1411fee70
// calls: [WriteFile]

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_1411fee70(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  HANDLE hProcess;
  
  FUN_14117f080(&DAT_142119450,&DAT_142b27300,param_3,param_4,0x1411fee7a);
  hProcess = GetCurrentProcess();
                    /* WARNING: Could not recover jumptable at 0x0001411feea2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TerminateProcess(hProcess,1);
  return;
}


