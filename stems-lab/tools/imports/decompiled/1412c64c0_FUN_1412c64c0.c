// FUN_1412c64c0 @ 1412c64c0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_1412c64c0(undefined4 *param_1,undefined8 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint *puVar7;
  void **ppvVar8;
  void *pvVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  void *pvVar12;
  void *pvVar13;
  ulonglong *local_res18 [2];
  ulonglong local_e8;
  ulonglong uStack_e0;
  longlong local_d8;
  void *local_d0;
  void *pvStack_c8;
  longlong local_c0;
  ulonglong uStack_b8;
  undefined4 local_b0;
  void *local_a8 [4];
  ulonglong local_88;
  ulonglong local_80;
  ulonglong *local_78;
  
  uVar10 = 0;
  local_b0 = 0;
  lVar6 = FUN_14196fa10(param_2);
  if ((lVar6 == 0) || (lVar6 = FUN_14196f7d0(param_2,&local_e8), *(longlong *)(lVar6 + 8) == 0)) {
    FUN_1412c89f0(&local_d0);
    pvVar13 = pvStack_c8;
    pvVar9 = local_d0;
    local_e8 = 0;
    uStack_e0 = 0;
    local_d8 = 0;
    uVar11 = (longlong)pvStack_c8 - (longlong)local_d0 >> 5;
    uVar5 = uStack_e0;
    if (uVar11 != 0) {
      if (0x7ffffffffffffff < uVar11) {
                    /* WARNING: Subroutine does not return */
        FUN_1402a2a50();
      }
      uVar11 = uVar11 * 0x20;
      if (uVar11 != 0) {
        if (uVar11 < 0x1000) {
          uVar10 = FUN_141981f80(uVar11);
        }
        else {
          if (uVar11 + 0x27 <= uVar11) {
                    /* WARNING: Subroutine does not return */
            FUN_14029d880();
          }
          lVar6 = FUN_141981f80();
          if (lVar6 == 0) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          uVar10 = lVar6 + 0x27U & 0xffffffffffffffe0;
          *(longlong *)(uVar10 - 8) = lVar6;
        }
      }
      local_d8 = uVar11 + uVar10;
      local_res18[0] = &local_e8;
      local_78 = &local_e8;
      local_e8 = uVar10;
      uStack_e0 = uVar10;
      local_88 = uVar10;
      for (pvVar12 = pvVar9; uVar5 = uVar10, local_80 = uVar10, pvVar12 != pvVar13;
          pvVar12 = (void *)((longlong)pvVar12 + 0x20)) {
        FUN_1402a5d70(uVar10,pvVar12);
        uVar10 = uVar10 + 0x20;
      }
    }
    uStack_e0 = uVar5;
    local_res18[0] = &local_e8;
    FUN_1412c9b00(local_a8,param_2,&local_e8);
    FUN_140374cd0(&local_e8);
    FUN_1402ac5a0(param_2,local_a8);
    FUN_1402a29e0(local_a8);
    pvVar12 = pvVar9;
    if (pvVar9 != (void *)0x0) {
      for (; pvVar12 != pvVar13; pvVar12 = (void *)((longlong)pvVar12 + 0x20)) {
        FUN_1402a29e0(pvVar12);
      }
      pvVar13 = pvVar9;
      if ((0xfff < (local_c0 - (longlong)pvVar9 & 0xffffffffffffffe0U)) &&
         (pvVar13 = *(void **)((longlong)pvVar9 + -8),
         0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar13)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar13);
    }
  }
  puVar7 = (uint *)FUN_141974de0(local_res18,param_2,0);
  uVar10 = _UNK_141cb0078;
  lVar6 = _DAT_141cb0070;
  bVar1 = *puVar7 < 2;
  if (bVar1) {
    pvStack_c8 = (void *)0x0;
    local_c0 = _DAT_141cb0070;
    uStack_b8 = _UNK_141cb0078;
    local_d0 = (void *)0x0;
    ppvVar8 = &local_d0;
  }
  else {
    FUN_1402a5d70(local_a8,param_2);
    ppvVar8 = local_a8;
  }
  uVar2 = *(undefined4 *)((longlong)ppvVar8 + 4);
  uVar3 = *(undefined4 *)(ppvVar8 + 1);
  uVar4 = *(undefined4 *)((longlong)ppvVar8 + 0xc);
  *param_1 = *(undefined4 *)ppvVar8;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  pvVar9 = ppvVar8[3];
  *(void **)(param_1 + 4) = ppvVar8[2];
  *(void **)(param_1 + 6) = pvVar9;
  ppvVar8[2] = (void *)0x0;
  ppvVar8[3] = (void *)0x7;
  *(undefined2 *)ppvVar8 = 0;
  if (bVar1) {
    if (7 < uStack_b8) {
      pvVar9 = local_d0;
      if ((0xfff < uStack_b8 * 2 + 2) &&
         (pvVar9 = *(void **)((longlong)local_d0 + -8),
         0x1f < (ulonglong)((longlong)local_d0 + (-8 - (longlong)pvVar9)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar9);
      lVar6 = _DAT_141cb0070;
      uVar10 = _UNK_141cb0078;
    }
    local_d0 = (void *)((ulonglong)local_d0 & 0xffffffffffff0000);
    local_c0 = lVar6;
    uStack_b8 = uVar10;
  }
  if (!bVar1) {
    FUN_1402a29e0(local_a8);
  }
  FUN_1402a29e0(param_2);
  return param_1;
}


