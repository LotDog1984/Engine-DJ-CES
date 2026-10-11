// FUN_140cc8270 @ 140cc8270
// calls: [WriteFile, CreateFileW]

undefined1 FUN_140cc8270(undefined8 *param_1,undefined8 param_2,undefined8 *param_3,int param_4)

{
  longlong *plVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  longlong **pplVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  longlong *plVar10;
  void *_Memory;
  void *pvVar11;
  undefined1 uVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  longlong **pplVar15;
  undefined1 local_f8;
  longlong *local_e8;
  longlong *plStack_e0;
  longlong *local_d8;
  longlong **local_c8;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  void *local_b8;
  undefined8 local_b0;
  longlong lStack_a8;
  longlong *local_a0;
  longlong *local_98;
  longlong **local_90;
  void *local_88 [3];
  ulonglong local_70;
  void *local_68 [2];
  longlong local_58;
  ulonglong local_50;
  undefined1 local_48 [32];
  
  FUN_140cc78e0(local_68);
  if (local_58 == 0) {
    uVar12 = 0;
  }
  else {
    local_c8 = (longlong **)*param_3;
    uStack_c0 = *(undefined4 *)(param_3 + 1);
    uStack_bc = *(undefined4 *)((longlong)param_3 + 0xc);
    if (param_4 == 1) {
      pplVar7 = (longlong **)FUN_140ccc130(&local_b8);
      bVar5 = true;
      bVar4 = false;
      bVar3 = false;
    }
    else {
      FUN_140ccbf60(local_48,&local_c8);
      local_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      plVar8 = (longlong *)FUN_141981f80(0x20);
      local_d8 = plVar8 + 4;
      local_c8 = &local_e8;
      puVar14 = local_48;
      local_90 = &local_e8;
      local_e8 = plVar8;
      plStack_e0 = plVar8;
      local_a0 = plVar8;
      do {
        local_98 = plVar8;
        FUN_1402aa5d0(plVar8,puVar14);
        plVar8 = plVar8 + 4;
        local_98 = plVar8;
        puVar14 = puVar14 + 0x20;
      } while (puVar14 != &stack0xffffffffffffffd8);
      plStack_e0 = plVar8;
      pplVar7 = &local_e8;
      bVar5 = false;
      bVar4 = true;
      bVar3 = true;
    }
    pplVar15 = (longlong **)pplVar7[2];
    local_c8 = pplVar15;
    pplVar7[2] = (longlong *)0x0;
    plVar8 = pplVar7[1];
    pplVar7[1] = (longlong *)0x0;
    plVar1 = *pplVar7;
    *pplVar7 = (longlong *)0x0;
    plVar13 = plStack_e0;
    local_a0 = plVar1;
    local_98 = plVar8;
    local_90 = pplVar15;
    if ((bVar3) && (plVar10 = local_e8, local_e8 != (longlong *)0x0)) {
      for (; plVar10 != plVar13; plVar10 = plVar10 + 4) {
        if (0xf < (ulonglong)plVar10[3]) {
          pvVar11 = (void *)*plVar10;
          _Memory = pvVar11;
          if ((0xfff < plVar10[3] + 1U) &&
             (_Memory = *(void **)((longlong)pvVar11 + -8),
             0x1f < (ulonglong)((longlong)pvVar11 + (-8 - (longlong)_Memory)))) goto LAB_140cc8440;
          free(_Memory);
        }
        plVar10[2] = 0;
        plVar10[3] = 0xf;
        *(undefined1 *)plVar10 = 0;
      }
      plVar13 = local_e8;
      if ((0xfff < ((longlong)local_d8 - (longlong)local_e8 & 0xffffffffffffffe0U)) &&
         (plVar13 = (longlong *)local_e8[-1],
         (undefined1 *)0x1f < (undefined1 *)((longlong)local_e8 + (-8 - (longlong)plVar13)))) {
LAB_140cc8440:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(plVar13);
      local_e8 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
    }
    if (bVar4) {
      _eh_vector_destructor_iterator_(local_48,0x20,1,FUN_14029c3e0);
    }
    plVar13 = plVar1;
    if ((bVar5) && (local_b8 != (void *)0x0)) {
      FUN_14029c160(local_b8,local_b0,&local_b8);
      pvVar11 = local_b8;
      if ((0xfff < (lStack_a8 - (longlong)local_b8 & 0xffffffffffffffe0U)) &&
         (pvVar11 = *(void **)((longlong)local_b8 + -8),
         0x1f < (ulonglong)((longlong)local_b8 + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar11);
      local_b8 = (void *)0x0;
      local_b0 = 0;
      lStack_a8 = 0;
    }
    for (; plVar13 != plVar8; plVar13 = plVar13 + 4) {
      cVar6 = FUN_140cc8fb0(plVar13);
      lVar2 = plVar13[2];
      if (cVar6 == '\0') {
        if (0x7fffffffffffffffU - lVar2 < 0x1a) {
                    /* WARNING: Subroutine does not return */
          FUN_14029da10();
        }
        plVar10 = plVar13;
        if (0xf < (ulonglong)plVar13[3]) {
          plVar10 = (longlong *)*plVar13;
        }
        FUN_14029f6d0(local_88,local_f8,plVar13,"Error creating directory: ",0x1a,plVar10,lVar2);
        if (0xf < local_70) {
          pvVar11 = local_88[0];
          if ((0xfff < local_70 + 1) &&
             (pvVar11 = *(void **)((longlong)local_88[0] + -8),
             0x1f < (ulonglong)((longlong)local_88[0] + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pvVar11);
        }
LAB_140cc8700:
        uVar12 = 0;
        pplVar15 = local_c8;
        goto LAB_140cc85e3;
      }
      if (0x7fffffffffffffffU - lVar2 < (ulonglong)param_1[2]) {
                    /* WARNING: Subroutine does not return */
        FUN_14029da10();
      }
      plVar10 = plVar13;
      if (0xf < (ulonglong)plVar13[3]) {
        plVar10 = (longlong *)*plVar13;
      }
      puVar9 = param_1;
      if (0xf < (ulonglong)param_1[3]) {
        puVar9 = (undefined8 *)*param_1;
      }
      FUN_14029f6d0(local_88,local_f8,plVar13,plVar10,lVar2,puVar9,param_1[2]);
      cVar6 = FUN_140cca360(local_88,local_68,300);
      if (0xf < local_70) {
        pvVar11 = local_88[0];
        if ((0xfff < local_70 + 1) &&
           (pvVar11 = *(void **)((longlong)local_88[0] + -8),
           0x1f < (ulonglong)((longlong)local_88[0] + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar11);
      }
      if (cVar6 == '\0') goto LAB_140cc8700;
      pplVar15 = local_c8;
    }
    uVar12 = 1;
LAB_140cc85e3:
    if (plVar1 != (longlong *)0x0) {
      FUN_14029c160(plVar1,plVar8,&local_a0);
      plVar8 = plVar1;
      if ((0xfff < ((longlong)pplVar15 - (longlong)plVar1 & 0xffffffffffffffe0U)) &&
         (plVar8 = (longlong *)plVar1[-1],
         0x1f < (ulonglong)((longlong)plVar1 + (-8 - (longlong)plVar8)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(plVar8);
    }
  }
  if (0xf < local_50) {
    pvVar11 = local_68[0];
    if ((0xfff < local_50 + 1) &&
       (pvVar11 = *(void **)((longlong)local_68[0] + -8),
       0x1f < (ulonglong)((longlong)local_68[0] + (-8 - (longlong)pvVar11)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar11);
  }
  return uVar12;
}


