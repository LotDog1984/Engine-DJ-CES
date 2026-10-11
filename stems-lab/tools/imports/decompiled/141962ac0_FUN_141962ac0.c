// FUN_141962ac0 @ 141962ac0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_141962ac0(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  void *pvVar4;
  bool bVar5;
  undefined4 local_res8 [2];
  void *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  void *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  local_res8[0] = 0;
  bVar5 = 0x103 < *(ulonglong *)(param_1 + 0x10);
  if (bVar5) {
    uStack_40 = 0;
    local_38 = _DAT_141cb0070;
    uStack_30 = _UNK_141cb0078;
    local_48 = (void *)0x0;
    uVar2 = FUN_14196e970();
    FUN_141971270(&DAT_141fce908,0,&local_48,uVar2);
    FUN_14196e520(&local_48,param_1);
    local_28 = local_48;
    uStack_20 = uStack_40;
    local_18 = local_38;
    uStack_10 = uStack_30;
    local_38 = _DAT_141cb0070;
    uStack_30 = _UNK_141cb0078;
    local_48 = (void *)((ulonglong)local_48 & 0xffffffffffff0000);
    param_1 = FUN_141970cb0(&local_28);
  }
  puVar3 = (uint *)FUN_141974de0(local_res8,param_1,param_2);
  uVar1 = *puVar3;
  if (bVar5) {
    if (7 < uStack_10) {
      pvVar4 = local_28;
      if ((0xfff < uStack_10 * 2 + 2) &&
         (pvVar4 = *(void **)((longlong)local_28 + -8),
         0x1f < (ulonglong)((longlong)local_28 + (-8 - (longlong)pvVar4)))) goto LAB_141962c16;
      free(pvVar4);
    }
    local_18 = _DAT_141cb0070;
    uStack_10 = _UNK_141cb0078;
    local_28 = (void *)((ulonglong)local_28 & 0xffffffffffff0000);
  }
  if ((bVar5) && (7 < uStack_30)) {
    pvVar4 = local_48;
    if ((0xfff < uStack_30 * 2 + 2) &&
       (pvVar4 = *(void **)((longlong)local_48 + -8),
       0x1f < (ulonglong)((longlong)local_48 + (-8 - (longlong)pvVar4)))) {
LAB_141962c16:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar4);
  }
  return 1 < uVar1;
}


