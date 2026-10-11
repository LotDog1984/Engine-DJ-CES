// FUN_141050fa0 @ 141050fa0
// calls: [CreateFileW]

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_141050fa0(undefined8 param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  wchar_t *_Filename;
  ulonglong uVar5;
  void *pvVar6;
  char *pcVar7;
  int *piVar8;
  int _FileHandle;
  int *piVar9;
  int *piVar10;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined2 local_74;
  ushort local_72;
  ulonglong local_48;
  
  local_48 = DAT_142955700 ^ (ulonglong)auStack_98;
  piVar4 = (int *)0x0;
  piVar10 = (int *)0x0;
  bVar1 = false;
  FUN_141055770();
  if (param_2[7] == 0) {
    _setmode(0,0x8000);
    piVar8 = (int *)&DAT_141cafc56;
    piVar9 = piVar4;
    piVar10 = piVar4;
  }
  else if (param_2[7] == 1) {
    uVar3 = FUN_14108ab80();
    piVar9 = (int *)(ulonglong)uVar3;
    FUN_140ed6720(uVar3);
    piVar8 = param_2 + 8;
    if ((int)uVar3 < 0) {
      piVar10 = _errno();
      FUN_1410557b0(param_1,*piVar10,"Failed to open \'%s\'",param_2 + 8);
      return 0xffffffe2;
    }
  }
  else {
    piVar10 = param_2 + 8;
    uVar3 = _wopen((wchar_t *)(param_2 + 8),0x8000);
    piVar9 = (int *)(ulonglong)uVar3;
    piVar8 = piVar4;
    if ((int)uVar3 < 0) {
      piVar4 = _errno();
      if ((*piVar4 == 2) &&
         (_Filename = (wchar_t *)FUN_14108b230(piVar10), _Filename != (wchar_t *)0x0)) {
        uVar3 = _wopen(_Filename,0x8000);
        piVar9 = (int *)(ulonglong)uVar3;
        free(_Filename);
        if (-1 < (int)uVar3) goto LAB_141050ff3;
      }
      piVar4 = _errno();
      FUN_1410557b0(param_1,*piVar4,"Failed to open \'%S\'",piVar10);
      return 0xffffffe2;
    }
  }
LAB_141050ff3:
  _FileHandle = (int)piVar9;
  iVar2 = FUN_14108aaa0(piVar9,&local_78);
  if (iVar2 == 0) {
    if ((local_72 & 0xf000) == 0x8000) {
      FUN_1410500f0(param_1,local_78,local_74);
      uVar5 = 0x10000;
      bVar1 = true;
      if (0x10000 < *(ulonglong *)(param_2 + 2)) {
        do {
          if (0x3ffffff < uVar5) break;
          uVar5 = uVar5 * 2;
        } while (uVar5 < *(ulonglong *)(param_2 + 2));
      }
      *(ulonglong *)(param_2 + 2) = uVar5;
    }
    pvVar6 = malloc(*(size_t *)(param_2 + 2));
    if (pvVar6 != (void *)0x0) {
      *(void **)(param_2 + 4) = pvVar6;
      *(ushort *)(param_2 + 6) = local_72;
      *param_2 = _FileHandle;
      if (bVar1) {
        *(undefined1 *)((longlong)param_2 + 0x1a) = 1;
      }
      return 0;
    }
    FUN_1410557b0(param_1,0xc,"No memory");
  }
  else {
    if (param_2[7] == 2) {
      pcVar7 = "Can\'t stat \'%S\'";
      piVar8 = piVar10;
    }
    else {
      pcVar7 = "Can\'t stat \'%s\'";
    }
    piVar10 = _errno();
    FUN_1410557b0(param_1,*piVar10,pcVar7,piVar8);
  }
  if (1 < _FileHandle + 1U) {
    _close(_FileHandle);
  }
  return 0xffffffe2;
}


