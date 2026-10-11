// FUN_1412eb3d0 @ 1412eb3d0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1412eb3d0(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  void *pvVar3;
  longlong lVar4;
  longlong lVar5;
  void *local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  ulonglong uStack_98;
  void *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  ulonglong uStack_78;
  undefined1 local_70 [32];
  undefined1 local_50 [32];
  undefined1 local_30 [40];
  
  local_b0 = (void *)0x0;
  uStack_a8 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  lVar4 = -1;
  lVar5 = -1;
  do {
    lVar5 = lVar5 + 1;
  } while (L"metadata"[lVar5] != L'\0');
  FUN_1402a7200(&local_b0);
  FUN_1412f9330(param_1 + 8,local_70,&local_b0);
  if (7 < uStack_98) {
    pvVar3 = local_b0;
    if ((0xfff < uStack_98 * 2 + 2) &&
       (pvVar3 = *(void **)((longlong)local_b0 + -8),
       0x1f < (ulonglong)((longlong)local_b0 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar3);
  }
  local_a0 = _DAT_141cb0070;
  uStack_98 = _UNK_141cb0078;
  local_b0 = (void *)((ulonglong)local_b0 & 0xffffffffffff0000);
  uVar1 = FUN_1412f4b00(param_1,local_30);
  local_90 = (void *)0x0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  do {
    lVar4 = lVar4 + 1;
  } while (L"reports"[lVar4] != L'\0');
  FUN_1402a7200(&local_90,L"reports",lVar4);
  uVar2 = FUN_1412f9330(param_1 + 8,local_50,&local_90);
  FUN_1412ebdb0(param_2,local_70,uVar2,uVar1);
  thunk_FUN_1402a29e0(local_50);
  if (7 < uStack_78) {
    pvVar3 = local_90;
    if ((0xfff < uStack_78 * 2 + 2) &&
       (pvVar3 = *(void **)((longlong)local_90 + -8),
       0x1f < (ulonglong)((longlong)local_90 + (-8 - (longlong)pvVar3)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar3);
  }
  local_80 = _DAT_141cb0070;
  uStack_78 = _UNK_141cb0078;
  local_90 = (void *)((ulonglong)local_90 & 0xffffffffffff0000);
  thunk_FUN_1402a29e0(local_30);
  thunk_FUN_1402a29e0(local_70);
  return param_2;
}


