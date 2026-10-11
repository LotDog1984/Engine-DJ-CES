// FUN_141962dc0 @ 141962dc0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_141962dc0(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  void *pvVar2;
  bool bVar3;
  void *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  void *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  bVar3 = 0x103 < *(ulonglong *)(param_1 + 0x10);
  if (bVar3) {
    uStack_50 = 0;
    local_48 = _DAT_141cb0070;
    uStack_40 = _UNK_141cb0078;
    local_58 = (void *)0x0;
    uVar1 = FUN_14196e970();
    FUN_141971270(&DAT_141fce908,0,&local_58,uVar1);
    FUN_14196e520(&local_58,param_1);
    local_38 = local_58;
    uStack_30 = uStack_50;
    local_28 = local_48;
    uStack_20 = uStack_40;
    local_48 = _DAT_141cb0070;
    uStack_40 = _UNK_141cb0078;
    local_58 = (void *)((ulonglong)local_58 & 0xffffffffffff0000);
    param_1 = FUN_141970cb0(&local_38);
  }
  FUN_1419736d0(param_1,param_2,param_3);
  if (bVar3) {
    if (7 < uStack_20) {
      pvVar2 = local_38;
      if ((0xfff < uStack_20 * 2 + 2) &&
         (pvVar2 = *(void **)((longlong)local_38 + -8),
         0x1f < (ulonglong)((longlong)local_38 + (-8 - (longlong)pvVar2)))) goto LAB_141962f17;
      free(pvVar2);
    }
    local_28 = _DAT_141cb0070;
    uStack_20 = _UNK_141cb0078;
    local_38 = (void *)((ulonglong)local_38 & 0xffffffffffff0000);
  }
  if ((bVar3) && (7 < uStack_40)) {
    pvVar2 = local_58;
    if ((0xfff < uStack_40 * 2 + 2) &&
       (pvVar2 = *(void **)((longlong)local_58 + -8),
       0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)pvVar2)))) {
LAB_141962f17:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar2);
  }
  return;
}


