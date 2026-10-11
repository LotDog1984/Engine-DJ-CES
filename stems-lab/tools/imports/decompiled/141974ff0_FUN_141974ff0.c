// FUN_141974ff0 @ 141974ff0
// calls: [CreateFileW]

int * FUN_141974ff0(int *param_1,LPCWSTR param_2,undefined8 *param_3)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  LPCWSTR lpFileName;
  int iVar4;
  uint uVar5;
  int local_res10;
  
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0;
  }
  lpFileName = param_2;
  if (7 < *(ulonglong *)(param_2 + 0xc)) {
    lpFileName = *(LPCWSTR *)param_2;
  }
  DVar2 = GetFileAttributesW(lpFileName);
  if (DVar2 == 0xffffffff) {
    FUN_141973d50(param_1,param_2,param_3);
  }
  else {
    iVar3 = FUN_141973a90(param_2,DVar2);
    if ((DVar2 >> 10 & 1) == 0) {
      uVar5 = DVar2 & 0x10;
      iVar4 = iVar3;
      if (uVar5 != 0) {
        iVar4 = local_res10;
        local_res10 = iVar3;
      }
      *param_1 = (uVar5 != 0) + 2;
      if (uVar5 == 0) {
        local_res10 = iVar4;
      }
    }
    else {
      cVar1 = FUN_1419735e0(param_2);
      iVar4 = iVar3;
      if (cVar1 != '\0') {
        iVar4 = local_res10;
        local_res10 = iVar3;
      }
      iVar3 = 4;
      if (cVar1 == '\0') {
        iVar3 = 9;
        local_res10 = iVar4;
      }
      *param_1 = iVar3;
    }
    param_1[1] = local_res10;
  }
  return param_1;
}


