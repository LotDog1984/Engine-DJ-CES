// FUN_140cc7fa0 @ 140cc7fa0
// calls: [ReadFile, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140cc7fa0(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  void *pvVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  void *pvVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  void *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  undefined1 local_28;
  undefined7 uStack_27;
  undefined8 local_18;
  ulonglong uStack_10;
  
  local_58 = *param_3;
  uStack_50 = param_3[1];
  uVar2 = FUN_140ccbf60(&local_28,&local_58);
  puVar3 = param_2 + 2;
  if (0xf < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  puVar3 = (undefined8 *)FUN_1402a2ae0(uVar2,param_2,*puVar3);
  local_48 = (void *)*puVar3;
  uStack_40 = puVar3[1];
  local_38 = puVar3[2];
  uStack_30 = puVar3[3];
  puVar3[2] = 0;
  puVar3[3] = 0xf;
  *(undefined1 *)puVar3 = 0;
  if (0xf < uStack_10) {
    pvVar1 = (void *)CONCAT71(uStack_27,local_28);
    pvVar4 = pvVar1;
    if ((0xfff < uStack_10 + 1) &&
       (pvVar4 = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar4);
  }
  local_18 = _DAT_141ac9b00;
  uStack_10 = _UNK_141ac9b08;
  local_28 = 0;
  FUN_140cc9520(param_1,&local_48,300);
  if (0xf < uStack_30) {
    pvVar4 = local_48;
    if ((0xfff < uStack_30 + 1) &&
       (pvVar4 = *(void **)((longlong)local_48 + -8),
       0x1f < (ulonglong)((longlong)local_48 + (-8 - (longlong)pvVar4)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar4);
  }
  return param_1;
}


