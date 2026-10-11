// FUN_140dd05e0 @ 140dd05e0
// calls: [CreateFileW]

bool FUN_140dd05e0(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  uint *puVar3;
  void *_Memory;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 local_res8 [8];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  void *local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong uStack_18;
  
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  puVar4 = (undefined8 *)(param_1 + 0x88);
  puVar5 = puVar4;
  if (7 < *(ulonglong *)(param_1 + 0xa0)) {
    puVar5 = (undefined8 *)*puVar4;
  }
  lVar2 = FUN_14196fa40(puVar4);
  puVar5 = (undefined8 *)((longlong)puVar5 + lVar2 * 2);
  if (7 < *(ulonglong *)(param_1 + 0xa0)) {
    puVar4 = (undefined8 *)*puVar4;
  }
  local_30 = (void *)0x0;
  uStack_28 = 0;
  local_20 = 0;
  uStack_18 = 0;
  if (puVar4 == puVar5) {
    uStack_18 = 7;
    local_30 = (void *)0x0;
  }
  else {
    FUN_1402a7200(&local_30,puVar4,(longlong)puVar5 - (longlong)puVar4 >> 1);
  }
  puVar3 = (uint *)FUN_141974de0(local_res8,&local_30,&local_48);
  uVar1 = *puVar3;
  if (7 < uStack_18) {
    _Memory = local_30;
    if ((0xfff < uStack_18 * 2 + 2) &&
       (_Memory = *(void **)((longlong)local_30 + -8),
       0x1f < (ulonglong)((longlong)local_30 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  return uVar1 < 2;
}


