// FUN_141973350 @ 141973350
// calls: [CreateFileW]

ulonglong FUN_141973350(LPCWSTR param_1,LPCWSTR param_2,undefined8 *param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined8 uVar3;
  int *piVar4;
  LPCWSTR pWVar5;
  undefined1 local_res10 [8];
  undefined1 local_28 [16];
  undefined8 local_18;
  
  if (param_3 != (undefined8 *)0x0) {
    local_18 = 0;
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
  }
  if (param_2 == (LPCWSTR)0x0) {
    pWVar5 = param_1;
    if (7 < *(ulonglong *)(param_1 + 0xc)) {
      pWVar5 = *(LPCWSTR *)param_1;
    }
    BVar1 = CreateDirectoryW(pWVar5,(LPSECURITY_ATTRIBUTES)0x0);
    uVar3 = CONCAT44(extraout_var_00,BVar1);
  }
  else {
    pWVar5 = param_1;
    if (7 < *(ulonglong *)(param_1 + 0xc)) {
      pWVar5 = *(LPCWSTR *)param_1;
    }
    if (7 < *(ulonglong *)(param_2 + 0xc)) {
      param_2 = *(LPCWSTR *)param_2;
    }
    BVar1 = CreateDirectoryExW(param_2,pWVar5,(LPSECURITY_ATTRIBUTES)0x0);
    uVar3 = CONCAT44(extraout_var,BVar1);
  }
  if ((int)uVar3 != 0) {
    return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  DVar2 = GetLastError();
  piVar4 = (int *)FUN_141974de0(local_res10,param_1,local_28);
  if (*piVar4 != 3) {
    piVar4 = (int *)FUN_141978c40(DVar2,param_1,param_3,"boost::filesystem::create_directory");
  }
  return (ulonglong)piVar4 & 0xffffffffffffff00;
}


