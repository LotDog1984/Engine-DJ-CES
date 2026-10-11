// FUN_1412c9b00 @ 1412c9b00
// calls: [CreateFileW]

/* WARNING: Type propagation algorithm not settling */

undefined8 * FUN_1412c9b00(undefined8 *param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  short sVar2;
  short *psVar3;
  longlong lVar4;
  wchar_t *pwVar5;
  code **ppcVar6;
  char cVar7;
  wchar_t wVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  _Locimp *p_Var11;
  ctype<wchar_t> *this;
  int *piVar12;
  DWORD_PTR DVar13;
  void *pvVar14;
  LPCWSTR pszPath;
  void *pvVar15;
  longlong *plVar16;
  undefined8 *******pppppppuVar17;
  short *psVar18;
  ulonglong uVar19;
  longlong *plVar20;
  wchar_t *pwVar21;
  wchar_t *pwVar22;
  ulonglong uVar23;
  longlong lVar24;
  wchar_t *pwVar25;
  wchar_t *pwVar26;
  wchar_t *pwVar27;
  wchar_t *local_res20;
  uint in_stack_fffffffffffffe78;
  undefined1 local_178 [12];
  undefined4 uStack_16c;
  ulonglong local_168;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  wchar_t **local_138;
  code *local_130;
  LPWCH pWStack_128;
  longlong *local_120;
  undefined8 uStack_118;
  longlong local_110;
  longlong *plStack_108;
  longlong *local_100;
  longlong *local_f8;
  longlong local_f0;
  undefined4 local_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined8 local_d8;
  ulonglong uStack_d0;
  short *local_c8;
  code **local_c0;
  wchar_t *local_b0;
  wchar_t *pwStack_a8;
  wchar_t *local_a0;
  undefined8 *******local_98 [2];
  undefined8 local_88;
  ulonglong local_80;
  
  pwVar26 = (wchar_t *)0x0;
  local_130 = (code *)0x0;
  pWStack_128 = (LPWCH)0x0;
  local_120 = (longlong *)0x0;
  uStack_118 = 0;
  local_110 = 0;
  plStack_108 = (longlong *)0x0;
  pWStack_128 = GetEnvironmentStringsW();
  local_130 = FreeEnvironmentStringsW;
  FUN_1412c5c10(&local_120,pWStack_128);
  local_res20 = L"PATHEXT";
  lVar24 = *local_120;
  plVar16 = local_120;
  while (lVar24 != 0) {
    plVar16 = plVar16 + 1;
    lVar24 = *plVar16;
  }
  stack0xfffffffffffffe90 = (_Locimp *)&local_130;
  local_178._0_8_ = local_120;
  local_138 = &local_res20;
  ppcVar6 = &local_130;
  plStack_108 = local_120;
  plVar20 = local_120;
  while (plVar20 != plVar16) {
    psVar3 = (short *)*plVar20;
    sVar2 = *psVar3;
    psVar18 = psVar3;
    while ((sVar2 != 0x3d && (sVar2 != 0))) {
      psVar18 = psVar18 + 1;
      sVar2 = *psVar18;
    }
    local_158 = (LPCWSTR)0x0;
    uStack_150 = 0;
    local_148 = 0;
    uStack_140 = 0;
    if (psVar3 == psVar18) {
      uStack_140 = 7;
      local_158 = (LPCWSTR)0x0;
    }
    else {
      FUN_1402a7200(&local_158,psVar3,(longlong)psVar18 - (longlong)psVar3 >> 1);
    }
    local_c8 = psVar18 + 1;
    local_e8 = (undefined4)local_158;
    uStack_e4 = local_158._4_4_;
    uStack_e0 = (undefined4)uStack_150;
    uStack_dc = uStack_150._4_4_;
    local_d8 = local_148;
    uStack_d0 = uStack_140;
    local_c0 = &local_130;
    cVar7 = FUN_1412c5230(&local_138,&local_e8);
    if (7 < uStack_d0) {
      pvVar15 = (void *)CONCAT44(uStack_e4,local_e8);
      pvVar14 = pvVar15;
      if ((0xfff < uStack_d0 * 2 + 2) &&
         (pvVar14 = *(void **)((longlong)pvVar15 + -8),
         0x1f < (ulonglong)((longlong)pvVar15 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
    if (cVar7 != '\0') break;
    plVar20 = plVar20 + 1;
    local_178._0_8_ = plVar20;
    ppcVar6 = (code **)stack0xfffffffffffffe90;
  }
  local_178._8_4_ = (int)ppcVar6;
  local_178._0_8_ = plVar20;
  uStack_16c = (int)((ulonglong)ppcVar6 >> 0x20);
  uVar9 = FUN_1412c4ef0(local_178,&local_e8);
  FUN_1412cab30(uVar9,&local_100);
  FUN_1402a29e0(&local_e8);
  plVar20 = local_f8;
  plVar16 = local_100;
  uVar23 = ((longlong)local_f8 - (longlong)local_100 >> 5) * 2 + 1;
  local_b0 = (wchar_t *)0x0;
  pwStack_a8 = (wchar_t *)0x0;
  local_a0 = (wchar_t *)0x0;
  if (0x7ffffffffffffff < uVar23) {
                    /* WARNING: Subroutine does not return */
    FUN_1402a2a50();
  }
  uVar19 = uVar23 * 0x20;
  if (uVar19 != 0) {
    if (uVar19 < 0x1000) {
      pwVar26 = (wchar_t *)FUN_141981f80(uVar19);
    }
    else {
      if (uVar19 + 0x27 <= uVar19) {
                    /* WARNING: Subroutine does not return */
        FUN_14029d880();
      }
      lVar24 = FUN_141981f80();
      if (lVar24 == 0) goto LAB_1412ca330;
      pwVar26 = (wchar_t *)(lVar24 + 0x27U & 0xffffffffffffffe0);
      *(longlong *)(pwVar26 + -4) = lVar24;
    }
  }
  lVar24 = uVar23 * 0x10;
  pwVar27 = pwVar26;
  do {
    pwVar27[0] = L'\0';
    pwVar27[1] = L'\0';
    pwVar27[2] = L'\0';
    pwVar27[3] = L'\0';
    pwVar27[4] = L'\0';
    pwVar27[5] = L'\0';
    pwVar27[6] = L'\0';
    pwVar27[7] = L'\0';
    pwVar27[8] = L'\0';
    pwVar27[9] = L'\0';
    pwVar27[10] = L'\0';
    pwVar27[0xb] = L'\0';
    pwVar27[0xc] = L'\a';
    pwVar27[0xd] = L'\0';
    pwVar27[0xe] = L'\0';
    pwVar27[0xf] = L'\0';
    *pwVar27 = L'\0';
    pwVar27 = pwVar27 + 0x10;
    uVar23 = uVar23 - 1;
  } while (uVar23 != 0);
  pwVar21 = pwVar26 + 0x10;
  in_stack_fffffffffffffe78 = in_stack_fffffffffffffe78 & 0xffffff00;
  local_b0 = pwVar26;
  pwStack_a8 = pwVar27;
  local_a0 = pwVar26 + lVar24;
  puVar10 = (undefined8 *)
            FUN_1412c3d60(&local_138,plVar16,plVar20,pwVar21,in_stack_fffffffffffffe78);
  FUN_1412c3f20(&local_138,plVar16,plVar20,*puVar10,in_stack_fffffffffffffe78 & 0xffffff00);
  pwVar5 = pwVar26;
  pwVar25 = pwVar26 + lVar24;
  if (plVar16 != plVar20) {
    lVar24 = (longlong)pwVar26 + (0x20 - (longlong)plVar16);
    plVar20 = plVar16 + 3;
    do {
      pwVar25 = (wchar_t *)(plVar20 + -3);
      if (pwVar21 != pwVar25) {
        uVar23 = *(ulonglong *)(lVar24 + (longlong)plVar20);
        if (7 < uVar23) {
          pvVar14 = *(void **)pwVar21;
          pvVar15 = pvVar14;
          if ((0xfff < uVar23 * 2 + 2) &&
             (pvVar15 = *(void **)((longlong)pvVar14 + -8),
             0x1f < (ulonglong)((longlong)pvVar14 + (-8 - (longlong)pvVar15)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pvVar15);
        }
        *(undefined8 *)((longlong)pwVar26 + (0x18 - (longlong)plVar16) + (longlong)plVar20) = 0;
        *(undefined8 *)(lVar24 + (longlong)plVar20) = 7;
        *pwVar21 = L'\0';
        lVar4 = plVar20[-2];
        *(undefined8 *)pwVar21 = *(undefined8 *)pwVar25;
        *(longlong *)(pwVar21 + 4) = lVar4;
        lVar4 = *plVar20;
        *(longlong *)(pwVar21 + 8) = plVar20[-1];
        *(longlong *)(pwVar21 + 0xc) = lVar4;
        plVar20[-1] = 0;
        *plVar20 = 7;
        *pwVar25 = L'\0';
      }
      pwVar21 = pwVar21 + 0x10;
      plVar1 = plVar20 + 1;
      plVar20 = plVar20 + 4;
      pwVar25 = local_a0;
    } while (plVar1 != local_f8);
  }
  for (; pwVar5 != pwVar27; pwVar5 = pwVar5 + 0x10) {
    p_Var11 = std::locale::_Init(true);
    stack0xfffffffffffffe90 = p_Var11;
    if (*(ulonglong *)(pwVar5 + 0xc) < 8) {
      pwVar21 = pwVar5 + *(longlong *)(pwVar5 + 8);
      pwVar22 = pwVar5;
    }
    else {
      pwVar21 = *(wchar_t **)pwVar5 + *(longlong *)(pwVar5 + 8);
      pwVar22 = *(wchar_t **)pwVar5;
    }
    if (pwVar22 != pwVar21) {
      do {
        wVar8 = *pwVar22;
        this = (ctype<wchar_t> *)FUN_14081c820(local_178);
        wVar8 = std::ctype<wchar_t>::tolower(this,wVar8);
        *pwVar22 = wVar8;
        pwVar22 = pwVar22 + 1;
      } while (pwVar22 != pwVar21);
      p_Var11 = stack0xfffffffffffffe90;
    }
    if ((p_Var11 != (_Locimp *)0x0) &&
       (puVar10 = (undefined8 *)(**(code **)(*(longlong *)p_Var11 + 0x10))(p_Var11),
       puVar10 != (undefined8 *)0x0)) {
      (**(code **)*puVar10)(puVar10,1);
    }
  }
  lVar4 = param_3[1];
  for (lVar24 = *param_3; lVar24 != lVar4; lVar24 = lVar24 + 0x20) {
    FUN_1403a32e0(&local_e8,lVar24,param_2);
    for (pwVar21 = pwVar26; pwVar21 != pwVar27; pwVar21 = pwVar21 + 0x10) {
      FUN_1402a5d70(local_98,pwVar21);
      FUN_1402a5d70(&local_158,&local_e8);
      pppppppuVar17 = local_98;
      if (7 < local_80) {
        pppppppuVar17 = local_98[0];
      }
      FUN_1402a64e0(&local_158,pppppppuVar17,local_88);
      _local_178 = ZEXT816(0);
      local_168 = 0;
      piVar12 = (int *)FUN_141974de0(&local_138);
      if ((((local_168 & 1) == 0) || ((local_168 == 1 && (local_178._0_4_ == 0)))) &&
         (*piVar12 == 2)) {
        pszPath = (LPCWSTR)&local_158;
        if (7 < uStack_140) {
          pszPath = local_158;
        }
        DVar13 = SHGetFileInfoW(pszPath,0,(SHFILEINFOW *)0x0,0,0x2000);
        if (DVar13 != 0) {
          *param_1 = local_158;
          param_1[1] = uStack_150;
          *(undefined4 *)(param_1 + 2) = (undefined4)local_148;
          *(undefined4 *)((longlong)param_1 + 0x14) = local_148._4_4_;
          *(undefined4 *)(param_1 + 3) = (undefined4)uStack_140;
          *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_140._4_4_;
          local_148 = 0;
          uStack_140 = 7;
          local_158 = (LPCWSTR)((ulonglong)local_158 & 0xffffffffffff0000);
          FUN_1402a29e0(&local_158);
          FUN_1402a29e0(local_98);
          FUN_1402a29e0(&local_e8);
          pwVar21 = pwVar26;
          if (pwVar26 != (wchar_t *)0x0) goto LAB_1412ca190;
          goto LAB_1412ca21f;
        }
      }
      FUN_1402a29e0(&local_158);
      FUN_1402a29e0(local_98);
    }
    FUN_1402a29e0(&local_e8);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 7;
  *(undefined2 *)param_1 = 0;
  pwVar21 = pwVar26;
  if (pwVar26 != (wchar_t *)0x0) {
    for (; pwVar21 != pwVar27; pwVar21 = pwVar21 + 0x10) {
      FUN_1402a29e0(pwVar21);
    }
    pwVar27 = pwVar26;
    if ((0xfff < ((longlong)pwVar25 - (longlong)pwVar26 & 0xffffffffffffffe0U)) &&
       (pwVar27 = *(wchar_t **)(pwVar26 + -4),
       0x1f < (ulonglong)((longlong)pwVar26 + (-8 - (longlong)pwVar27)))) {
LAB_1412ca330:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pwVar27);
  }
  plVar16 = local_100;
  if (local_100 != (longlong *)0x0) {
    for (; plVar16 != local_f8; plVar16 = plVar16 + 4) {
      FUN_1402a29e0(plVar16);
    }
    plVar16 = local_100;
    if ((0xfff < (local_f0 - (longlong)local_100 & 0xffffffffffffffe0U)) &&
       (plVar16 = (longlong *)local_100[-1],
       0x1f < (ulonglong)((longlong)local_100 + (-8 - (longlong)plVar16)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(plVar16);
  }
  if (local_120 != (longlong *)0x0) {
    plVar16 = local_120;
    if ((0xfff < (ulonglong)((local_110 - (longlong)local_120 >> 3) * 8)) &&
       (plVar16 = (longlong *)local_120[-1],
       0x1f < (ulonglong)((longlong)local_120 + (-8 - (longlong)plVar16)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(plVar16);
    local_120 = (longlong *)0x0;
    uStack_118 = 0;
    local_110 = 0;
  }
  goto LAB_1412ca396;
LAB_1412ca190:
  do {
    if (7 < *(ulonglong *)(pwVar21 + 0xc)) {
      pvVar14 = *(void **)pwVar21;
      pvVar15 = pvVar14;
      if ((0xfff < *(ulonglong *)(pwVar21 + 0xc) * 2 + 2) &&
         (pvVar15 = *(void **)((longlong)pvVar14 + -8),
         0x1f < (ulonglong)((longlong)pvVar14 + (-8 - (longlong)pvVar15)))) goto LAB_1412ca2c8;
      free(pvVar15);
    }
    pwVar21[8] = L'\0';
    pwVar21[9] = L'\0';
    pwVar21[10] = L'\0';
    pwVar21[0xb] = L'\0';
    pwVar21[0xc] = L'\a';
    pwVar21[0xd] = L'\0';
    pwVar21[0xe] = L'\0';
    pwVar21[0xf] = L'\0';
    *pwVar21 = L'\0';
    pwVar21 = pwVar21 + 0x10;
  } while (pwVar21 != pwVar27);
  pwVar27 = pwVar26;
  if ((0xfff < ((longlong)pwVar25 - (longlong)pwVar26 & 0xffffffffffffffe0U)) &&
     (pwVar27 = *(wchar_t **)(pwVar26 + -4),
     0x1f < (ulonglong)((longlong)pwVar26 + (-8 - (longlong)pwVar27)))) {
LAB_1412ca2c8:
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
  free(pwVar27);
LAB_1412ca21f:
  plVar16 = local_100;
  if (local_100 != (longlong *)0x0) {
    for (; plVar16 != local_f8; plVar16 = plVar16 + 4) {
      if (7 < (ulonglong)plVar16[3]) {
        pvVar14 = (void *)*plVar16;
        pvVar15 = pvVar14;
        if ((0xfff < plVar16[3] * 2 + 2U) &&
           (pvVar15 = *(void **)((longlong)pvVar14 + -8),
           0x1f < (ulonglong)((longlong)pvVar14 + (-8 - (longlong)pvVar15)))) goto LAB_1412ca2c1;
        free(pvVar15);
      }
      plVar16[2] = 0;
      plVar16[3] = 7;
      *(undefined2 *)plVar16 = 0;
    }
    plVar16 = local_100;
    if ((0xfff < (local_f0 - (longlong)local_100 & 0xffffffffffffffe0U)) &&
       (plVar16 = (longlong *)local_100[-1],
       0x1f < (ulonglong)((longlong)local_100 + (-8 - (longlong)plVar16)))) {
LAB_1412ca2c1:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(plVar16);
  }
  if (local_120 != (longlong *)0x0) {
    plVar16 = local_120;
    if ((0xfff < (ulonglong)((local_110 - (longlong)local_120 >> 3) * 8)) &&
       (plVar16 = (longlong *)local_120[-1],
       0x1f < (ulonglong)((longlong)local_120 + (-8 - (longlong)plVar16)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(plVar16);
    local_120 = (longlong *)0x0;
    uStack_118 = 0;
    local_110 = 0;
  }
LAB_1412ca396:
  if (pWStack_128 != (LPWCH)0x0) {
    (*local_130)();
  }
  return param_1;
}


