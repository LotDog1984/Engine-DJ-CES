// FUN_140dd4470 @ 140dd4470
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140dd4470(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint *puVar7;
  longlong *plVar8;
  char cVar9;
  int iVar10;
  longlong lVar11;
  undefined8 *puVar12;
  int *piVar13;
  uint *puVar14;
  undefined8 uVar15;
  uint *puVar16;
  void *pvVar17;
  undefined8 *puVar18;
  bool bVar19;
  uint local_res10;
  undefined8 *local_res18 [2];
  uint *local_238;
  uint *puStack_230;
  ulonglong local_228;
  ulonglong uStack_220;
  undefined8 local_218;
  longlong *plStack_210;
  undefined8 local_208;
  uint *puStack_200;
  ulonglong local_1f8;
  ulonglong uStack_1f0;
  void *local_1e8;
  undefined8 uStack_1e0;
  ulonglong local_1d8;
  ulonglong uStack_1d0;
  void *local_1c8;
  undefined8 uStack_1c0;
  ulonglong local_1b8;
  ulonglong uStack_1b0;
  void *local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  ulonglong local_190;
  void *local_188;
  longlong *plStack_180;
  undefined8 local_178;
  ulonglong uStack_170;
  uint *local_168;
  uint *puStack_160;
  ulonglong local_158;
  ulonglong uStack_150;
  undefined1 local_148 [56];
  undefined1 local_110 [56];
  uint local_d8;
  uint local_b8;
  uint local_98;
  undefined8 local_78;
  
  puVar12 = (undefined8 *)0x0;
  local_238 = (uint *)0x0;
  puStack_230 = (uint *)0x0;
  local_228 = 0;
  cVar9 = FUN_140dd5260();
  uVar6 = _UNK_141cb0078;
  uVar5 = _DAT_141cb0070;
  if (cVar9 == '\0') {
    uStack_1c0 = 0;
    local_1b8 = _DAT_141cb0070;
    uStack_1b0 = _UNK_141cb0078;
    local_1c8 = (void *)0x0;
    puStack_200 = (uint *)0x0;
    local_1f8 = 7;
    uStack_1f0 = 0xf;
    local_208 = (uint *)(ulonglong)
                        CONCAT16(s_Artwork_141f5bd28[6],
                                 CONCAT24(s_Artwork_141f5bd28._4_2_,s_Artwork_141f5bd28._0_4_));
    uVar15 = FUN_14196e970();
    FUN_141971270(&local_208,(longlong)&local_208 + 7,&local_1c8,uVar15);
    if (0xf < uStack_1f0) {
      pvVar17 = local_208;
      if ((0xfff < uStack_1f0 + 1) &&
         (pvVar17 = *(void **)((longlong)local_208 + -8),
         0x1f < (ulonglong)((longlong)local_208 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    FUN_1402a5d70(&local_1e8,param_1 + 0xa8);
    local_res10 = 0x400;
    FUN_14196e520(&local_1e8,&local_1c8);
    if (7 < uStack_1b0) {
      pvVar17 = local_1c8;
      if ((0xfff < uStack_1b0 * 2 + 2) &&
         (pvVar17 = *(void **)((longlong)local_1c8 + -8),
         0x1f < (ulonglong)((longlong)local_1c8 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    cVar9 = FUN_140dc6d30(&local_1e8);
    if (((cVar9 == '\0') &&
        (piVar13 = (int *)FUN_141974de0(local_res18,&local_1e8,&local_238), *piVar13 != 3)) &&
       (cVar9 = FUN_141972f10(&local_1e8,&local_238), cVar9 == '\0')) {
      uVar15 = FUN_1405abe00(&local_238,&local_1c8);
      FUN_1406e9ad0(&local_168,0x6d,uVar15);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_168,(ThrowInfo *)&DAT_14288da78);
    }
    FUN_1402a29e0(&local_1e8);
  }
  else {
    local_218 = 0;
    plStack_210 = (longlong *)0x0;
    lVar11 = *(longlong *)(param_1 + 0x70);
    if (lVar11 == 0) {
LAB_140dd507d:
                    /* WARNING: Subroutine does not return */
      FUN_140409600();
    }
    iVar2 = *(int *)(lVar11 + 8);
    do {
      if (iVar2 == 0) goto LAB_140dd507d;
      LOCK();
      iVar10 = *(int *)(lVar11 + 8);
      bVar19 = iVar2 == iVar10;
      if (bVar19) {
        *(int *)(lVar11 + 8) = iVar2 + 1;
        iVar10 = iVar2;
      }
      UNLOCK();
      iVar2 = iVar10;
    } while (!bVar19);
    local_218 = *(undefined8 *)(param_1 + 0x68);
    plStack_210 = *(longlong **)(param_1 + 0x70);
    lVar11 = FUN_141981f80(200);
    if (lVar11 != 0) {
      puVar12 = (undefined8 *)FUN_140e4e2f0(lVar11,&local_218,0,1);
    }
    local_res10 = 0x300;
    local_res18[0] = puVar12;
    FUN_140dcb6c0(param_1 + 0x238,local_res18);
    if (local_res18[0] != (undefined8 *)0x0) {
      (**(code **)*local_res18[0])(local_res18[0],1);
    }
    plVar8 = plStack_210;
    if (plStack_210 != (longlong *)0x0) {
      LOCK();
      plVar1 = plStack_210 + 1;
      lVar11 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar11 == 1) {
        (**(code **)*plStack_210)(plStack_210);
        LOCK();
        piVar13 = (int *)((longlong)plVar8 + 0xc);
        iVar2 = *piVar13;
        *piVar13 = *piVar13 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (**(code **)(*plVar8 + 8))(plVar8);
        }
      }
    }
  }
  FUN_140dd1b10(param_1,&local_218);
  puVar12 = (undefined8 *)FUN_140dfd420(local_218,&local_1a8,"PRAGMA user_version");
  local_208 = (uint *)0x0;
  puStack_200 = (uint *)0x0;
  local_1f8 = 0;
  FUN_140d2bd40(*puVar12,&local_238,&local_208);
  FUN_140374c10(&local_208);
  plVar8 = uStack_1a0;
  puVar16 = local_238;
  puVar14 = puStack_230;
  if (uStack_1a0 != (longlong *)0x0) {
    LOCK();
    plVar1 = uStack_1a0 + 1;
    lVar11 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      (**(code **)*uStack_1a0)(uStack_1a0);
      LOCK();
      piVar13 = (int *)((longlong)plVar8 + 0xc);
      iVar2 = *piVar13;
      *piVar13 = *piVar13 + -1;
      UNLOCK();
      puVar16 = local_238;
      puVar14 = puStack_230;
      if (iVar2 == 1) {
        (**(code **)(*plVar8 + 8))(plVar8);
        puVar16 = local_238;
        puVar14 = puStack_230;
      }
    }
  }
  for (; puVar7 = puStack_230, puVar16 != puStack_230; puVar16 = puVar16 + 2) {
    puStack_230 = puVar14;
    FUN_140dd3550(param_1,&local_188);
    plVar8 = plStack_180;
    if (local_188 == (void *)0x0) {
      if (plStack_180 != (longlong *)0x0) {
        LOCK();
        plVar1 = plStack_180 + 1;
        lVar11 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar11 == 1) {
          (**(code **)*plStack_180)(plStack_180);
          LOCK();
          piVar13 = (int *)((longlong)plVar8 + 0xc);
          iVar2 = *piVar13;
          *piVar13 = *piVar13 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            (**(code **)(*plVar8 + 8))(plVar8);
          }
        }
      }
      if (local_238 != (uint *)0x0) {
        puVar16 = local_238;
        if (0xfff < (ulonglong)(((longlong)(local_228 - (longlong)local_238) >> 3) * 8)) {
          puVar16 = *(uint **)(local_238 + -2);
          lVar11 = (longlong)local_238 - (longlong)puVar16;
joined_r0x000140dd49a7:
          if (0x1f < lVar11 - 8U) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
LAB_140dd491b:
        free(puVar16);
        local_238 = (uint *)0x0;
        puStack_230 = (uint *)0x0;
        local_228 = 0;
      }
      goto LAB_140dd4ff0;
    }
    puVar14 = (uint *)FUN_140dbacb0(local_188,local_res18);
    plVar8 = plStack_180;
    uVar3 = *puVar16;
    if (uVar3 != (uVar3 & 0x3fffffff)) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a28a0();
    }
    if ((*puVar14 & 0x3fffffff) < (uVar3 & 0x3fffffff)) {
      if (plStack_180 != (longlong *)0x0) {
        LOCK();
        plVar1 = plStack_180 + 1;
        lVar11 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + -1;
        UNLOCK();
        if ((int)lVar11 == 1) {
          (**(code **)*plStack_180)(plStack_180);
          LOCK();
          piVar13 = (int *)((longlong)plVar8 + 0xc);
          iVar2 = *piVar13;
          *piVar13 = *piVar13 + -1;
          UNLOCK();
          if (iVar2 == 1) {
            (**(code **)(*plVar8 + 8))(plVar8);
          }
        }
      }
      if (local_238 != (uint *)0x0) {
        puVar16 = local_238;
        if (0xfff < (ulonglong)(((longlong)(local_228 - (longlong)local_238) >> 3) * 8)) {
          puVar16 = *(uint **)(local_238 + -2);
          lVar11 = (longlong)local_238 - (longlong)puVar16;
          goto joined_r0x000140dd49a7;
        }
        goto LAB_140dd491b;
      }
      goto LAB_140dd4ff0;
    }
    if (plStack_180 != (longlong *)0x0) {
      LOCK();
      plVar1 = plStack_180 + 1;
      lVar11 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar11 == 1) {
        (**(code **)*plStack_180)(plStack_180);
        LOCK();
        piVar13 = (int *)((longlong)plVar8 + 0xc);
        iVar2 = *piVar13;
        *piVar13 = *piVar13 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          (**(code **)(*plVar8 + 8))(plVar8);
        }
      }
    }
    puVar14 = puStack_230;
    puStack_230 = puVar7;
  }
  bVar19 = false;
  puStack_230 = puVar14;
  if (local_238 != (uint *)0x0) {
    puVar16 = local_238;
    if ((0xfff < (ulonglong)(((longlong)(local_228 - (longlong)local_238) >> 3) * 8)) &&
       (puVar16 = *(uint **)(local_238 + -2),
       0x1f < (ulonglong)((longlong)local_238 + (-8 - (longlong)puVar16)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(puVar16);
  }
  FUN_140dd34e0(param_1,local_148,&local_218);
  uVar15 = FUN_1402aa5d0(&local_1e8,local_110);
  uVar15 = FUN_140df7ee0(&local_168,uVar15);
  FUN_1402ac4f0(param_1 + 0xe8,uVar15);
  if (0xf < uStack_150) {
    puVar16 = local_168;
    if ((0xfff < uStack_150 + 1) &&
       (puVar16 = *(uint **)(local_168 + -2),
       0x1f < (ulonglong)((longlong)local_168 + (-8 - (longlong)puVar16)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(puVar16);
  }
  if ((((local_d8 & 0x3ff) == local_d8) && ((local_b8 & 0x3ff) == local_b8)) &&
     ((local_98 & 0x3ff) == local_98)) {
    local_res10 = (local_d8 & 0x3ff) << 0x14 | (local_b8 & 0x3ff) << 10 | local_98 & 0x3ff;
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (!bVar4) {
                    /* WARNING: Subroutine does not return */
    FUN_1402a28a0();
  }
  *(uint *)(param_1 + 0x218) = local_res10;
  *(undefined8 *)(param_1 + 0x230) = local_78;
  iVar2 = *(int *)(param_1 + 0x200);
  if ((iVar2 == 1) || (iVar2 == 0x100)) {
LAB_140dd4ae6:
    bVar4 = true;
  }
  else {
    if (iVar2 == 0x20) {
      puVar12 = (undefined8 *)FUN_140dd3550(param_1,&local_1a8);
      bVar19 = true;
      cVar9 = FUN_140dc6920(*puVar12);
      if (cVar9 != '\0') goto LAB_140dd4ae6;
    }
    bVar4 = false;
  }
  plVar8 = uStack_1a0;
  if ((bVar19) && (uStack_1a0 != (longlong *)0x0)) {
    LOCK();
    plVar1 = uStack_1a0 + 1;
    lVar11 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      (**(code **)*uStack_1a0)(uStack_1a0);
      LOCK();
      piVar13 = (int *)((longlong)plVar8 + 0xc);
      iVar2 = *piVar13;
      *piVar13 = *piVar13 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(*plVar8 + 8))(plVar8);
      }
    }
  }
  if (bVar4) {
    puVar12 = (undefined8 *)FUN_14029c470(param_1 + 0xe8);
    uStack_1e0 = 0;
    local_1d8 = uVar5;
    uStack_1d0 = uVar6;
    local_1e8 = (void *)0x0;
    lVar11 = puVar12[2];
    if (lVar11 != 0) {
      puVar18 = puVar12;
      if (0xf < (ulonglong)puVar12[3]) {
        puVar18 = (undefined8 *)*puVar12;
        puVar12 = (undefined8 *)*puVar12;
      }
      uVar15 = FUN_14196e970();
      FUN_141971270(puVar12,(longlong)puVar18 + lVar11,&local_1e8,uVar15);
    }
    uStack_1c0 = 0;
    local_1b8 = uVar5;
    uStack_1b0 = uVar6;
    local_1c8 = (void *)0x0;
    local_198 = 0xc;
    local_190 = 0xf;
    local_1a8 = (void *)s_OverviewData_14202a330._0_8_;
    uStack_1a0 = (longlong *)(ulonglong)(uint)s_OverviewData_14202a330._8_4_;
    uVar15 = FUN_14196e970();
    FUN_141971270(&local_1a8,(longlong)&uStack_1a0 + 4,&local_1c8,uVar15);
    if (0xf < local_190) {
      pvVar17 = local_1a8;
      if ((0xfff < local_190 + 1) &&
         (pvVar17 = *(void **)((longlong)local_1a8 + -8),
         0x1f < (ulonglong)((longlong)local_1a8 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    puVar12 = (undefined8 *)(param_1 + 0x88);
    puVar18 = puVar12;
    if (7 < *(ulonglong *)(param_1 + 0xa0)) {
      puVar18 = (undefined8 *)*puVar12;
    }
    lVar11 = FUN_14196f640(puVar12);
    puVar18 = (undefined8 *)((longlong)puVar18 + lVar11 * 2);
    if (7 < *(ulonglong *)(param_1 + 0xa0)) {
      puVar12 = (undefined8 *)*puVar12;
    }
    local_208 = (uint *)0x0;
    puStack_200 = (uint *)0x0;
    local_1f8 = 0;
    uStack_1f0 = 0;
    if (puVar12 == puVar18) {
      local_1f8 = uVar5;
      uStack_1f0 = uVar6;
      local_208 = (uint *)0x0;
    }
    else {
      FUN_1402a7200(&local_208,puVar12,(longlong)puVar18 - (longlong)puVar12 >> 1);
    }
    FUN_14196e520(&local_208,&local_1c8);
    local_238 = local_208;
    puStack_230 = puStack_200;
    local_228 = local_1f8;
    uStack_220 = uStack_1f0;
    local_1f8 = uVar5;
    uStack_1f0 = uVar6;
    local_208 = (uint *)((ulonglong)local_208 & 0xffffffffffff0000);
    FUN_14196e520(&local_238,&local_1e8);
    local_168 = local_238;
    puStack_160 = puStack_230;
    local_158 = local_228;
    uStack_150 = uStack_220;
    local_228 = uVar5;
    uStack_220 = uVar6;
    local_238 = (uint *)((ulonglong)local_238 & 0xffffffffffff0000);
    puVar12 = (undefined8 *)FUN_14196fa80(&local_168,&local_1a8);
    plStack_180 = (longlong *)0x0;
    local_178 = _DAT_141ac9b00;
    uStack_170 = _UNK_141ac9b08;
    local_188 = (void *)0x0;
    lVar11 = puVar12[2];
    if (lVar11 != 0) {
      if (7 < (ulonglong)puVar12[3]) {
        puVar12 = (undefined8 *)*puVar12;
      }
      uVar15 = FUN_14196e970();
      FUN_141971350(puVar12,(longlong)puVar12 + lVar11 * 2,&local_188,uVar15);
    }
    FUN_1402a29e0(&local_1a8);
    FUN_1402ac4f0(param_1 + 200,&local_188);
    if (0xf < uStack_170) {
      pvVar17 = local_188;
      if ((0xfff < uStack_170 + 1) &&
         (pvVar17 = *(void **)((longlong)local_188 + -8),
         0x1f < (ulonglong)((longlong)local_188 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    local_178 = _DAT_141ac9b00;
    uStack_170 = _UNK_141ac9b08;
    local_188 = (void *)((ulonglong)local_188 & 0xffffffffffffff00);
    FUN_1402a29e0(&local_168);
    if (7 < uStack_220) {
      puVar16 = local_238;
      if ((0xfff < uStack_220 * 2 + 2) &&
         (puVar16 = *(uint **)(local_238 + -2),
         0x1f < (ulonglong)((longlong)local_238 + (-8 - (longlong)puVar16)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(puVar16);
    }
    local_228 = uVar5;
    uStack_220 = uVar6;
    local_238 = (uint *)((ulonglong)local_238 & 0xffffffffffff0000);
    if (7 < uStack_1f0) {
      pvVar17 = local_208;
      if ((0xfff < uStack_1f0 * 2 + 2) &&
         (pvVar17 = *(void **)((longlong)local_208 + -8),
         0x1f < (ulonglong)((longlong)local_208 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    local_1f8 = uVar5;
    uStack_1f0 = uVar6;
    local_208 = (uint *)((ulonglong)local_208 & 0xffffffffffff0000);
    if (7 < uStack_1b0) {
      pvVar17 = local_1c8;
      if ((0xfff < uStack_1b0 * 2 + 2) &&
         (pvVar17 = *(void **)((longlong)local_1c8 + -8),
         0x1f < (ulonglong)((longlong)local_1c8 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    local_1b8 = uVar5;
    uStack_1b0 = uVar6;
    local_1c8 = (void *)((ulonglong)local_1c8 & 0xffffffffffff0000);
    if (7 < uStack_1d0) {
      pvVar17 = local_1e8;
      if ((0xfff < uStack_1d0 * 2 + 2) &&
         (pvVar17 = *(void **)((longlong)local_1e8 + -8),
         0x1f < (ulonglong)((longlong)local_1e8 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    cVar9 = FUN_140dc6d30(param_1 + 0x88);
    if ((cVar9 == '\0') && (cVar9 = FUN_140dd5260(param_1), cVar9 == '\0')) {
      local_238 = (uint *)0x0;
      puStack_230 = (uint *)0x0;
      local_228 = 0;
      puVar12 = (undefined8 *)(param_1 + 200);
      uStack_1e0 = 0;
      local_1d8 = uVar5;
      uStack_1d0 = uVar6;
      local_1e8 = (void *)0x0;
      lVar11 = *(longlong *)(param_1 + 0xd8);
      if (lVar11 != 0) {
        puVar18 = puVar12;
        if (0xf < *(ulonglong *)(param_1 + 0xe0)) {
          puVar18 = (undefined8 *)*puVar12;
          puVar12 = (undefined8 *)*puVar12;
        }
        uVar15 = FUN_14196e970();
        FUN_141971270(puVar12,(longlong)puVar18 + lVar11,&local_1e8,uVar15);
      }
      FUN_141972f10(&local_1e8,&local_238);
      if (7 < uStack_1d0) {
        pvVar17 = local_1e8;
        if ((0xfff < uStack_1d0 * 2 + 2) &&
           (pvVar17 = *(void **)((longlong)local_1e8 + -8),
           0x1f < (ulonglong)((longlong)local_1e8 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar17);
      }
      if (((local_228 & 1) != 0) && ((local_228 != 1 || ((int)local_238 != 0)))) {
        uVar15 = FUN_1405abe00(&local_238,&local_1e8);
        FUN_1406e9ad0(&local_168,0x6d,uVar15);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_168,(ThrowInfo *)&DAT_14288da78);
      }
    }
  }
  FUN_140da7520(local_148);
LAB_140dd4ff0:
  plVar8 = plStack_210;
  if (plStack_210 != (longlong *)0x0) {
    LOCK();
    plVar1 = plStack_210 + 1;
    lVar11 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      (**(code **)*plStack_210)(plStack_210);
      LOCK();
      piVar13 = (int *)((longlong)plVar8 + 0xc);
      iVar2 = *piVar13;
      *piVar13 = *piVar13 + -1;
      UNLOCK();
      if (iVar2 == 1) {
        (**(code **)(*plStack_210 + 8))();
      }
    }
  }
  return;
}


