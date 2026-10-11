// FUN_140dd61c0 @ 140dd61c0
// calls: [MoveFileExW, CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_140dd61c0(longlong param_1)

{
  void *pvVar1;
  undefined8 uVar2;
  char cVar3;
  uint *puVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  char ****ppppcVar9;
  ulonglong uVar10;
  undefined8 ****ppppuVar11;
  void *pvVar12;
  char ****ppppcVar13;
  undefined **ppuVar14;
  longlong lVar15;
  undefined1 local_res8 [8];
  ulonglong local_2a8;
  undefined **ppuStack_2a0;
  ulonglong local_298;
  undefined8 ***local_290;
  undefined8 uStack_288;
  longlong local_280;
  ulonglong uStack_278;
  void *local_270;
  undefined8 uStack_268;
  longlong local_260;
  ulonglong uStack_258;
  undefined8 ***local_250;
  undefined8 uStack_248;
  longlong local_240;
  ulonglong uStack_238;
  void *local_230;
  undefined8 uStack_228;
  undefined8 local_220;
  ulonglong uStack_218;
  char ***local_210;
  undefined8 uStack_208;
  ulonglong local_200;
  ulonglong local_1f8;
  void *local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  ulonglong uStack_1d8;
  undefined1 local_1d0;
  undefined7 uStack_1cf;
  longlong local_1c0;
  ulonglong uStack_1b8;
  undefined1 local_1b0 [32];
  undefined1 local_190 [32];
  undefined1 local_170 [248];
  basic_ios<char,std::char_traits<char>_> local_78 [96];
  
  FUN_140e49ac0(*(undefined8 *)(param_1 + 0x208));
  local_2a8 = 0;
  ppuStack_2a0 = (undefined **)0x0;
  local_298 = 0;
  FUN_1402a5d70(&local_1f0,param_1 + 0x88);
  FUN_140dd42b0(param_1,&local_1d0);
  puVar4 = (uint *)FUN_141974de0(local_res8,&local_1d0,&local_2a8);
  if (*puVar4 < 2) {
    cVar3 = FUN_141973350(&local_1d0,0,&local_2a8);
    if (cVar3 != '\0') goto LAB_140dd624b;
  }
  else {
LAB_140dd624b:
    pcVar5 = tmpnam((char *)0x0);
    local_210 = (char ***)0x0;
    uStack_208 = 0;
    local_200 = 0;
    local_1f8 = 0;
    lVar15 = -1;
    do {
      lVar15 = lVar15 + 1;
    } while (pcVar5[lVar15] != '\0');
    FUN_14029be90(&local_210,pcVar5);
    ppppcVar13 = &local_210;
    if (0xf < local_1f8) {
      ppppcVar13 = (char ****)local_210;
    }
    if (local_200 == 0) {
LAB_140dd62c9:
      uVar10 = 0xffffffffffffffff;
    }
    else {
      lVar15 = -1;
      if (local_200 - 1 != -1) {
        lVar15 = local_200 - 1;
      }
      for (ppppcVar9 = (char ****)((longlong)ppppcVar13 + lVar15); *(char *)ppppcVar9 != '\\';
          ppppcVar9 = (char ****)((longlong)ppppcVar9 + -1)) {
        if (ppppcVar9 == ppppcVar13) goto LAB_140dd62c9;
      }
      uVar10 = (longlong)ppppcVar9 - (longlong)ppppcVar13;
    }
    local_290 = (undefined8 ****)0x0;
    uStack_288 = 0;
    local_280 = 0;
    uStack_278 = 0;
    if (local_200 < uVar10) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a6430();
    }
    lVar15 = -1;
    if (local_200 - uVar10 != -1) {
      lVar15 = local_200 - uVar10;
    }
    ppppcVar13 = &local_210;
    if (0xf < local_1f8) {
      ppppcVar13 = (char ****)local_210;
    }
    FUN_14029be90(&local_290,(char *)((longlong)ppppcVar13 + uVar10),lVar15);
    uStack_268 = 0;
    local_260 = _DAT_141cb0070;
    uStack_258 = _UNK_141cb0078;
    local_270 = (void *)0x0;
    if (local_280 != 0) {
      ppppuVar11 = &local_290;
      if (0xf < uStack_278) {
        ppppuVar11 = (undefined8 ****)local_290;
      }
      lVar15 = (longlong)ppppuVar11 + local_280;
      ppppuVar11 = &local_290;
      if (0xf < uStack_278) {
        ppppuVar11 = (undefined8 ****)local_290;
      }
      uVar6 = FUN_14196e970();
      FUN_141971270(ppppuVar11,lVar15,&local_270,uVar6);
    }
    FUN_1402a5d70(local_1b0,&local_1d0);
    FUN_14196e520(local_1b0,&local_270);
    puVar7 = (undefined8 *)FUN_14196fa80(local_1b0,local_190);
    uStack_248 = 0;
    local_240 = _DAT_141ac9b00;
    uStack_238 = _UNK_141ac9b08;
    local_250 = (undefined8 ****)0x0;
    lVar15 = puVar7[2];
    if (lVar15 != 0) {
      if (7 < (ulonglong)puVar7[3]) {
        puVar7 = (undefined8 *)*puVar7;
      }
      uVar6 = FUN_14196e970();
      FUN_141971350(puVar7,(longlong)puVar7 + lVar15 * 2,&local_250,uVar6);
    }
    FUN_1402a29e0(local_190);
    uStack_228 = 0;
    local_220 = _DAT_141cb0070;
    uStack_218 = _UNK_141cb0078;
    local_230 = (void *)0x0;
    if (local_240 != 0) {
      ppppuVar11 = &local_250;
      if (0xf < uStack_238) {
        ppppuVar11 = (undefined8 ****)local_250;
      }
      lVar15 = (longlong)ppppuVar11 + local_240;
      ppppuVar11 = &local_250;
      if (0xf < uStack_238) {
        ppppuVar11 = (undefined8 ****)local_250;
      }
      uVar6 = FUN_14196e970();
      FUN_141971270(ppppuVar11,lVar15,&local_230,uVar6);
    }
    if (0xf < uStack_238) {
      ppppuVar11 = (undefined8 ****)local_250;
      if ((0xfff < uStack_238 + 1) &&
         (ppppuVar11 = (undefined8 ****)local_250[-1],
         0x1f < (ulonglong)((longlong)local_250 + (-8 - (longlong)ppppuVar11)))) goto LAB_140dd6528;
      free(ppppuVar11);
    }
    local_240 = _DAT_141ac9b00;
    uStack_238 = _UNK_141ac9b08;
    local_250 = (undefined8 ***)((ulonglong)local_250 & 0xffffffffffffff00);
    FUN_1402a29e0(local_1b0);
    if (7 < uStack_258) {
      pvVar12 = local_270;
      if ((0xfff < uStack_258 * 2 + 2) &&
         (pvVar12 = *(void **)((longlong)local_270 + -8),
         0x1f < (ulonglong)((longlong)local_270 + (-8 - (longlong)pvVar12)))) goto LAB_140dd6528;
      free(pvVar12);
    }
    local_260 = _DAT_141cb0070;
    uStack_258 = _UNK_141cb0078;
    local_270 = (void *)((ulonglong)local_270 & 0xffffffffffff0000);
    if (0xf < uStack_278) {
      ppppuVar11 = (undefined8 ****)local_290;
      if ((0xfff < uStack_278 + 1) &&
         (ppppuVar11 = (undefined8 ****)local_290[-1],
         0x1f < (ulonglong)((longlong)local_290 + (-8 - (longlong)ppppuVar11)))) {
LAB_140dd6528:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppuVar11);
    }
    FUN_141974850(&local_1f0,&local_230,&local_2a8);
    uVar10 = uStack_1d8;
    uVar2 = local_1e0;
    uVar6 = uStack_1e8;
    pvVar12 = local_1f0;
    if (((local_298 & 1) == 0) || ((local_298 == 1 && ((int)local_2a8 == 0)))) {
      local_1f0 = local_230;
      uStack_1e8 = uStack_228;
      local_1e0 = local_220;
      uStack_1d8 = uStack_218;
      local_230 = pvVar12;
      uStack_228 = uVar6;
      local_220 = uVar2;
      uStack_218 = uVar10;
    }
    if (7 < uStack_218) {
      pvVar12 = local_230;
      if ((0xfff < uStack_218 * 2 + 2) &&
         (pvVar12 = *(void **)((longlong)local_230 + -8),
         0x1f < (ulonglong)((longlong)local_230 + (-8 - (longlong)pvVar12)))) goto LAB_140dd6603;
      free(pvVar12);
    }
    local_220 = _DAT_141cb0070;
    uStack_218 = _UNK_141cb0078;
    local_230 = (void *)((ulonglong)local_230 & 0xffffffffffff0000);
    if (0xf < local_1f8) {
      ppppcVar13 = (char ****)local_210;
      if ((0xfff < local_1f8 + 1) &&
         (ppppcVar13 = (char ****)local_210[-1],
         (char *)0x1f < (char *)((longlong)local_210 + (-8 - (longlong)ppppcVar13)))) {
LAB_140dd6603:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppcVar13);
    }
  }
  FUN_1402a29e0(&local_1d0);
  FUN_1419741e0(&local_1f0,&local_2a8);
  if (((local_298 & 1) == 0) || ((local_298 == 1 && ((int)local_2a8 == 0)))) {
    FUN_1402a29e0(&local_1f0);
    uVar6 = 1;
  }
  else {
    uStack_268 = 0;
    local_260 = _DAT_141ac9b00;
    uStack_258 = _UNK_141ac9b08;
    local_270 = (void *)0x0;
    lVar15 = FUN_1404ddb00(param_1,local_170,&local_270);
    lVar15 = lVar15 + 0x10;
    FUN_1402b8060(lVar15,"Failed to remove ");
    puVar8 = (undefined8 *)FUN_141956400(&local_1d0,&local_1f0);
    puVar7 = puVar8 + 2;
    if (0xf < (ulonglong)puVar8[3]) {
      puVar8 = (undefined8 *)*puVar8;
    }
    FUN_1402b8440(lVar15,puVar8,*puVar7);
    FUN_1402b8060(lVar15,&DAT_141d8349c);
    if (local_298 == 1) {
      (**(code **)(*ppuStack_2a0 + 0x10))();
    }
    else {
      ppuVar14 = &PTR_vftable_1428e1958;
      if (local_298 != 0) {
        ppuVar14 = ppuStack_2a0;
      }
      (**(code **)(*ppuVar14 + 0x28))(ppuVar14,&local_290,local_2a8 & 0xffffffff);
    }
    ppppuVar11 = &local_290;
    if (0xf < uStack_278) {
      ppppuVar11 = (undefined8 ****)local_290;
    }
    FUN_1402b8440(lVar15,ppppuVar11,local_280);
    if (0xf < uStack_278) {
      ppppuVar11 = (undefined8 ****)local_290;
      if ((0xfff < uStack_278 + 1) &&
         (ppppuVar11 = (undefined8 ****)local_290[-1],
         0x1f < (ulonglong)((longlong)local_290 + (-8 - (longlong)ppppuVar11)))) goto LAB_140dd67fa;
      free(ppppuVar11);
    }
    local_280 = _DAT_141ac9b00;
    uStack_278 = _UNK_141ac9b08;
    local_290 = (undefined8 ***)((ulonglong)local_290 & 0xffffffffffffff00);
    if (0xf < uStack_1b8) {
      pvVar1 = (void *)CONCAT71(uStack_1cf,local_1d0);
      pvVar12 = pvVar1;
      if ((0xfff < uStack_1b8 + 1) &&
         (pvVar12 = *(void **)((longlong)pvVar1 + -8),
         0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)pvVar12)))) goto LAB_140dd67fa;
      free(pvVar12);
    }
    local_1c0 = _DAT_141ac9b00;
    uStack_1b8 = _UNK_141ac9b08;
    local_1d0 = 0;
    FUN_1404d7140(local_78);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_78)
    ;
    if (0xf < uStack_258) {
      pvVar12 = local_270;
      if ((0xfff < uStack_258 + 1) &&
         (pvVar12 = *(void **)((longlong)local_270 + -8),
         0x1f < (ulonglong)((longlong)local_270 + (-8 - (longlong)pvVar12)))) {
LAB_140dd67fa:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar12);
    }
    FUN_1402a29e0(&local_1f0);
    uVar6 = 0;
  }
  return uVar6;
}


