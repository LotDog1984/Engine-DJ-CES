// FUN_1419626b0 @ 1419626b0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_1419626b0(longlong param_1,longlong param_2,undefined4 param_3,undefined8 param_4)

{
  void *pvVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  void *pvVar6;
  bool bVar7;
  bool bVar8;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  ulonglong uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined2 local_78;
  undefined2 uStack_76;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  ulonglong uStack_60;
  undefined2 local_58;
  undefined2 uStack_56;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  ulonglong uStack_40;
  
  uVar3 = _UNK_141cb0078;
  uVar2 = _DAT_141cb0070;
  bVar7 = 0x103 < *(ulonglong *)(param_2 + 0x10);
  if (bVar7) {
    uStack_90 = 0;
    local_88 = _DAT_141cb0070;
    uStack_80 = _UNK_141cb0078;
    local_98 = (void *)0x0;
    uVar5 = FUN_14196e970();
    FUN_141971270(&DAT_141fce908,0,&local_98,uVar5);
    FUN_14196e520(&local_98,param_2);
    local_58 = SUB82(local_98,0);
    uStack_56 = (undefined2)((ulonglong)local_98 >> 0x10);
    uStack_54 = local_98._4_4_;
    uStack_50 = (undefined4)uStack_90;
    uStack_4c = uStack_90._4_4_;
    local_48 = local_88;
    uStack_40 = uStack_80;
    local_88 = uVar2;
    uStack_80 = uVar3;
    local_98 = (void *)((ulonglong)local_98 & 0xffffffffffff0000);
    param_2 = FUN_141970cb0(&local_58);
  }
  bVar8 = 0x103 < *(ulonglong *)(param_1 + 0x10);
  if (bVar8) {
    uStack_b0 = 0;
    local_a8 = uVar2;
    uStack_a0 = uVar3;
    local_b8 = (void *)0x0;
    uVar5 = FUN_14196e970();
    FUN_141971270(&DAT_141fce908,0,&local_b8,uVar5);
    FUN_14196e520(&local_b8,param_1);
    local_78 = SUB82(local_b8,0);
    uStack_76 = (undefined2)((ulonglong)local_b8 >> 0x10);
    uStack_74 = local_b8._4_4_;
    uStack_70 = (undefined4)uStack_b0;
    uStack_6c = uStack_b0._4_4_;
    local_68 = local_a8;
    uStack_60 = uStack_a0;
    local_a8 = uVar2;
    uStack_a0 = uVar3;
    local_b8 = (void *)((ulonglong)local_b8 & 0xffffffffffff0000);
    param_1 = FUN_141970cb0(&local_78);
  }
  uVar4 = FUN_141972bb0(param_1,param_2,param_3,param_4);
  if (bVar8) {
    if (7 < uStack_60) {
      pvVar1 = (void *)CONCAT44(uStack_74,CONCAT22(uStack_76,local_78));
      pvVar6 = pvVar1;
      if ((0xfff < uStack_60 * 2 + 2) &&
         (pvVar6 = *(void **)((longlong)pvVar1 + -8),
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar6)))) goto LAB_141962907;
      free(pvVar6);
    }
    local_68 = uVar2;
    uStack_60 = uVar3;
    local_78 = 0;
  }
  if (bVar8) {
    if (7 < uStack_a0) {
      pvVar6 = local_b8;
      if ((0xfff < uStack_a0 * 2 + 2) &&
         (pvVar6 = *(void **)((longlong)local_b8 + -8),
         0x1f < (ulonglong)((longlong)local_b8 + (-8 - (longlong)pvVar6)))) goto LAB_141962907;
      free(pvVar6);
    }
    local_a8 = uVar2;
    uStack_a0 = uVar3;
    local_b8 = (void *)((ulonglong)local_b8 & 0xffffffffffff0000);
  }
  if (bVar7) {
    if (7 < uStack_40) {
      pvVar1 = (void *)CONCAT44(uStack_54,CONCAT22(uStack_56,local_58));
      pvVar6 = pvVar1;
      if ((0xfff < uStack_40 * 2 + 2) &&
         (pvVar6 = *(void **)((longlong)pvVar1 + -8),
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar6)))) goto LAB_141962907;
      free(pvVar6);
    }
    local_48 = uVar2;
    uStack_40 = uVar3;
    local_58 = 0;
  }
  if ((bVar7) && (7 < uStack_80)) {
    pvVar6 = local_98;
    if ((0xfff < uStack_80 * 2 + 2) &&
       (pvVar6 = *(void **)((longlong)local_98 + -8),
       0x1f < (ulonglong)((longlong)local_98 + (-8 - (longlong)pvVar6)))) {
LAB_141962907:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar6);
  }
  return uVar4;
}


