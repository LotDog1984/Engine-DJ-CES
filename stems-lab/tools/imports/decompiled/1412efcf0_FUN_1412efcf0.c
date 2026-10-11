// FUN_1412efcf0 @ 1412efcf0
// calls: [CreateFileW]

/* WARNING: Removing unreachable block (ram,0x0001412f0d1b) */
/* WARNING: Removing unreachable block (ram,0x0001412f0f0c) */
/* WARNING: Removing unreachable block (ram,0x0001412f1576) */
/* WARNING: Removing unreachable block (ram,0x0001412f180d) */
/* WARNING: Removing unreachable block (ram,0x0001412f122f) */
/* WARNING: Removing unreachable block (ram,0x0001412f0df9) */
/* WARNING: Removing unreachable block (ram,0x0001412f0870) */
/* WARNING: Removing unreachable block (ram,0x0001412f1953) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1412efcf0(longlong *param_1)

{
  size_t _Size;
  longlong lVar1;
  void *pvVar2;
  longlong ******pppppplVar3;
  ulonglong uVar4;
  longlong ******pppppplVar5;
  longlong *plVar6;
  char cVar7;
  DWORD DVar8;
  int iVar9;
  BOOL BVar10;
  longlong lVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  char ******ppppppcVar14;
  longlong *plVar15;
  longlong *******ppppppplVar16;
  longlong *******ppppppplVar17;
  undefined8 *puVar18;
  longlong *******ppppppplVar19;
  void *pvVar20;
  wchar_t *******pppppppwVar21;
  LPCWSTR lpApplicationName;
  LPWSTR ******pppppppWVar22;
  ulonglong uVar23;
  longlong *plVar24;
  char *******pppppppcVar25;
  ulonglong uVar26;
  longlong *******ppppppplVar27;
  uint uVar28;
  uint uVar29;
  longlong *******ppppppplVar30;
  bool bVar31;
  longlong ******pppppplVar32;
  undefined8 local_res18;
  DWORD local_res20;
  undefined8 in_stack_fffffffffffffa58;
  undefined8 in_stack_fffffffffffffa60;
  undefined4 uVar33;
  wchar_t *******local_578;
  ulonglong uStack_570;
  longlong ******local_568;
  ulonglong uStack_560;
  longlong *******local_558;
  longlong *******ppppppplStack_550;
  longlong *******local_548;
  ulonglong uStack_540;
  LPWSTR ******local_538;
  undefined8 uStack_530;
  longlong ******local_528;
  ulonglong uStack_520;
  wchar_t *******local_518;
  longlong ******pppppplStack_510;
  longlong *******local_508;
  char *******local_500;
  undefined8 uStack_4f8;
  longlong ******local_4f0;
  ulonglong uStack_4e8;
  undefined2 local_4e0;
  undefined6 uStack_4de;
  longlong ******local_4d0;
  ulonglong uStack_4c8;
  longlong *******local_4c0;
  longlong local_4b8;
  undefined1 local_4b0;
  undefined1 uStack_4af;
  undefined6 uStack_4ae;
  longlong ******local_4a0;
  ulonglong uStack_498;
  longlong *******local_488;
  longlong ******pppppplStack_480;
  undefined8 local_478;
  undefined4 local_470;
  _STARTUPINFOW local_468;
  longlong *******ppppppplStack_400;
  _PROCESS_INFORMATION local_3f8;
  undefined1 local_3e0 [280];
  undefined1 local_2c8 [80];
  undefined4 local_278;
  undefined1 local_274 [564];
  
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffa58 >> 0x20);
  local_res18 = (ulonglong *)((ulonglong)local_res18 & 0xffffffff00000000);
  cVar7 = FUN_1412f8530();
  bVar31 = cVar7 != '\0';
  if (bVar31) {
    lVar11 = FUN_1412fa530(local_3e0,
                           "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                           ,
                           "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                           ,0x1a6,CONCAT44(uVar33,4));
    local_res18 = (ulonglong *)CONCAT44(local_res18._4_4_,1);
    uVar12 = FUN_1402b8060(lVar11 + 8,"Check failed: !IsThreadInLoaderLock()");
    FUN_1402b8060(uVar12,&DAT_1423b9148);
  }
  uVar28 = (uint)bVar31;
  if (bVar31) {
    uVar28 = 0;
    FUN_1412fa7a0(local_3e0);
  }
  uVar4 = _UNK_141cb0078;
  pppppplVar3 = _DAT_141cb0070;
  uStack_530 = 0;
  local_528 = _DAT_141cb0070;
  uStack_520 = _UNK_141cb0078;
  local_538 = (LPWSTR ******)0x0;
  FUN_1412f7ee0(*param_1,&local_538);
  ppppppplVar16 = *(longlong ********)(*param_1 + 0xb8);
  for (ppppppplVar19 = *(longlong ********)(*param_1 + 0xb0); ppppppplVar19 != ppppppplVar16;
      ppppppplVar19 = ppppppplVar19 + 4) {
    local_518 = (wchar_t *******)ppppppplVar19;
    if ((longlong ******)0xf < ppppppplVar19[3]) {
      local_518 = (wchar_t *******)*ppppppplVar19;
    }
    pppppplStack_510 = ppppppplVar19[2];
    local_488 = (longlong *******)local_518;
    pppppplStack_480 = pppppplStack_510;
    uVar12 = FUN_1412fb2c0(&local_4e0,&local_488);
    FUN_1412f7ee0(uVar12,&local_538);
    FUN_1402a29e0(&local_4e0);
  }
  if (*(longlong *)(*param_1 + 0x30) != 0) {
    local_578 = (wchar_t *******)0x6573616261746164;
    uStack_570 = 0;
    local_568 = _DAT_141cb6990;
    uStack_560 = _UNK_141cb6998;
    uVar12 = FUN_1412ef4d0(&local_4e0,&local_578);
    FUN_1412f7ee0(uVar12,&local_538);
    FUN_1402a29e0(&local_4e0);
    FUN_14029c3e0(&local_578);
  }
  if (*(longlong *)(*param_1 + 0x50) != 0) {
    local_4f0 = (longlong ******)_DAT_141ac9b20;
    uStack_4e8 = _UNK_141ac9b28;
    local_500 = (char *******)s_metrics_dir_1423b9540._0_8_;
    uStack_4f8 = (ulonglong)CONCAT12(s_metrics_dir_1423b9540[10],s_metrics_dir_1423b9540._8_2_);
    uVar12 = FUN_1412ef4d0(&local_4e0,&local_500,*param_1 + 0x40);
    FUN_1412f7ee0(uVar12,&local_538);
    FUN_1402a29e0(&local_4e0);
    if (0xf < uStack_4e8) {
      FUN_14029d7d0(&local_500,local_500);
    }
    local_4f0 = _DAT_141ac9b00;
    uStack_4e8 = _UNK_141ac9b08;
    local_500 = (char *******)((ulonglong)local_500 & 0xffffffffffffff00);
  }
  lVar11 = *param_1;
  if (*(longlong *)(lVar11 + 0x70) != 0) {
    local_518 = (wchar_t *******)(lVar11 + 0x60);
    if (0xf < *(ulonglong *)(lVar11 + 0x78)) {
      local_518 = *(wchar_t ********)(lVar11 + 0x60);
    }
    pppppplStack_510 = *(longlong *******)(lVar11 + 0x70);
    uVar12 = FUN_1412fb2c0(&local_4b0,&local_518);
    uStack_570 = 0;
    local_568 = _DAT_141daf560;
    uStack_560 = _UNK_141daf568;
    local_578 = (wchar_t *******)(ulonglong)(uint3)DAT_141f6b814;
    uVar12 = FUN_1412ef4d0(&local_4e0,&local_578,uVar12);
    FUN_1412f7ee0(uVar12,&local_538);
    FUN_1402a29e0(&local_4e0);
    FUN_14029c3e0(&local_578);
    FUN_1402a29e0(&local_4b0);
  }
  lVar11 = *param_1;
  pppppplVar32 = _DAT_141d2ff30;
  uVar23 = _UNK_141d2ff38;
  if (*(longlong *)(lVar11 + 0x90) != 0) {
    local_518 = (wchar_t *******)(lVar11 + 0x80);
    if (0xf < *(ulonglong *)(lVar11 + 0x98)) {
      local_518 = *(wchar_t ********)(lVar11 + 0x80);
    }
    pppppplStack_510 = *(longlong *******)(lVar11 + 0x90);
    uVar12 = FUN_1412fb2c0(&local_4b0,&local_518);
    uVar23 = _UNK_141d2ff38;
    pppppplVar32 = _DAT_141d2ff30;
    local_568 = _DAT_141d2ff30;
    uStack_560 = _UNK_141d2ff38;
    local_578 = (wchar_t *******)s_http_proxy_1423b9550._0_8_;
    uStack_570 = (ulonglong)(ushort)s_http_proxy_1423b9550._8_2_;
    uVar12 = FUN_1412ef4d0(&local_4e0,&local_578,uVar12);
    FUN_1412f7ee0(uVar12,&local_538);
    FUN_1402a29e0(&local_4e0);
    FUN_14029c3e0(&local_578);
    FUN_1402a29e0(&local_4b0);
  }
  plVar24 = (longlong *)**(longlong **)(*param_1 + 0xa0);
  local_res18 = (ulonglong *)((ulonglong)local_res18 & 0xffffffffffffff00);
  cVar7 = *(char *)((longlong)plVar24 + 0x19);
  while (cVar7 == '\0') {
    _Size = plVar24[6];
    if (_Size == 0x7fffffffffffffff) {
                    /* WARNING: Subroutine does not return */
      FUN_14029da10();
    }
    local_res18 = (ulonglong *)(plVar24 + 4);
    if (0xf < (ulonglong)plVar24[7]) {
      local_res18 = (ulonglong *)plVar24[4];
    }
    local_500 = (char *******)0x0;
    uStack_4f8 = 0;
    local_4f0 = (longlong ******)0x0;
    uStack_4e8 = 0;
    uVar23 = _Size + 1;
    uVar26 = 0xf;
    pppppppcVar25 = (char *******)&local_500;
    if (0xf < uVar23) {
      uVar26 = uVar23 | 0xf;
      if (uVar26 < 0x8000000000000000) {
        if (uVar26 < 0x16) {
          uVar26 = 0x16;
        }
        if (uVar26 == 0xffffffffffffffff) {
          pppppppcVar25 = (char *******)0x0;
          local_500 = pppppppcVar25;
        }
        else {
          if (0xfff < uVar26 + 1) {
            uVar13 = uVar26 + 0x28;
            if (uVar13 <= uVar26 + 1) {
                    /* WARNING: Subroutine does not return */
              FUN_14029d880();
            }
            goto LAB_1412f0179;
          }
          pppppppcVar25 = (char *******)FUN_141981f80();
          local_500 = pppppppcVar25;
        }
      }
      else {
        uVar26 = 0x7fffffffffffffff;
        uVar13 = 0x8000000000000027;
LAB_1412f0179:
        ppppppcVar14 = (char ******)FUN_141981f80(uVar13);
        if (ppppppcVar14 == (char ******)0x0) goto LAB_1412f0679;
        pppppppcVar25 = (char *******)((longlong)ppppppcVar14 + 0x27U & 0xffffffffffffffe0);
        pppppppcVar25[-1] = ppppppcVar14;
        local_500 = pppppppcVar25;
      }
    }
    local_4f0 = (longlong ******)uVar23;
    uStack_4e8 = uVar26;
    memcpy(pppppppcVar25,local_res18,_Size);
    *(undefined1 *)((longlong)pppppppcVar25 + _Size) = 0x3d;
    *(undefined1 *)((longlong)pppppppcVar25 + uVar23) = 0;
    plVar15 = plVar24 + 8;
    if (0xf < (ulonglong)plVar24[0xb]) {
      plVar15 = (longlong *)*plVar15;
    }
    plVar15 = (longlong *)FUN_1402a2ae0(&local_500,plVar15,plVar24[10]);
    local_558 = (longlong *******)*plVar15;
    ppppppplStack_550 = (longlong *******)plVar15[1];
    local_548 = (longlong *******)plVar15[2];
    uStack_540 = plVar15[3];
    plVar15[2] = 0;
    plVar15[3] = 0xf;
    *(undefined1 *)plVar15 = 0;
    uVar28 = uVar28 | 0x3000;
    local_518 = (wchar_t *******)&local_558;
    if (0xf < uStack_540) {
      local_518 = (wchar_t *******)local_558;
    }
    pppppplStack_510 = (longlong ******)local_548;
    local_488 = (longlong *******)local_518;
    pppppplStack_480 = (longlong ******)local_548;
    uVar12 = FUN_1412fb2c0(&local_4e0,&local_488);
    local_568 = (longlong ******)0xa;
    uStack_560 = 0xf;
    local_578 = (wchar_t *******)s_annotation_1423b9560._0_8_;
    uStack_570 = (ulonglong)(ushort)s_annotation_1423b9560._8_2_;
    uVar12 = FUN_1412ef4d0(&local_4b0,&local_578,uVar12);
    FUN_1412f7ee0(uVar12,&local_538);
    if (7 < uStack_498) {
      pvVar2 = (void *)CONCAT62(uStack_4ae,CONCAT11(uStack_4af,local_4b0));
      pvVar20 = pvVar2;
      if ((0xfff < uStack_498 * 2 + 2) &&
         (pvVar20 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar20)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar20);
    }
    local_4a0 = (longlong ******)0x0;
    uStack_498 = 7;
    local_4b0 = 0;
    uStack_4af = 0;
    if (0xf < uStack_560) {
      pppppppwVar21 = local_578;
      if ((0xfff < uStack_560 + 1) &&
         (pppppppwVar21 = (wchar_t *******)local_578[-1],
         0x1f < (ulonglong)((longlong)local_578 + (-8 - (longlong)pppppppwVar21)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppwVar21);
    }
    local_568 = (longlong ******)0x0;
    uStack_560 = 0xf;
    local_578 = (wchar_t *******)((ulonglong)local_578 & 0xffffffffffffff00);
    if (7 < uStack_4c8) {
      pvVar2 = (void *)CONCAT62(uStack_4de,local_4e0);
      pvVar20 = pvVar2;
      if ((0xfff < uStack_4c8 * 2 + 2) &&
         (pvVar20 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar20)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar20);
    }
    local_4d0 = (longlong ******)0x0;
    uStack_4c8 = 7;
    local_4e0 = 0;
    if (0xf < uStack_540) {
      ppppppplVar19 = local_558;
      if ((0xfff < uStack_540 + 1) &&
         (ppppppplVar19 = (longlong *******)local_558[-1],
         0x1f < (ulonglong)((longlong)local_558 + (-8 - (longlong)ppppppplVar19)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppppplVar19);
    }
    local_548 = (longlong *******)0x0;
    uStack_540 = 0xf;
    local_558 = (longlong *******)((ulonglong)local_558 & 0xffffffffffffff00);
    if (0xf < uStack_4e8) {
      pppppppcVar25 = local_500;
      if ((0xfff < uStack_4e8 + 1) &&
         (pppppppcVar25 = (char *******)local_500[-1],
         0x1f < (ulonglong)((longlong)local_500 + (-8 - (longlong)pppppppcVar25)))) {
LAB_1412f0679:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppcVar25);
    }
    local_4f0 = (longlong ******)0x0;
    uStack_4e8 = 0xf;
    local_500 = (char *******)((ulonglong)local_500 & 0xffffffffffffff00);
    plVar15 = (longlong *)plVar24[2];
    if (*(char *)((longlong)plVar15 + 0x19) == '\0') {
      cVar7 = *(char *)(*plVar15 + 0x19);
      plVar24 = plVar15;
      plVar15 = (longlong *)*plVar15;
      while (cVar7 == '\0') {
        cVar7 = *(char *)(*plVar15 + 0x19);
        plVar24 = plVar15;
        plVar15 = (longlong *)*plVar15;
      }
    }
    else {
      cVar7 = *(char *)(plVar24[1] + 0x19);
      plVar6 = (longlong *)plVar24[1];
      plVar15 = plVar24;
      while ((plVar24 = plVar6, cVar7 == '\0' && (plVar15 == (longlong *)plVar24[2]))) {
        cVar7 = *(char *)(plVar24[1] + 0x19);
        plVar6 = (longlong *)plVar24[1];
        plVar15 = plVar24;
      }
    }
    pppppplVar32 = _DAT_141d2ff30;
    uVar23 = _UNK_141d2ff38;
    cVar7 = *(char *)((longlong)plVar24 + 0x19);
  }
  uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffa60 >> 0x20);
  ppppppplVar19 = (longlong *******)0x0;
  lVar1 = *(longlong *)(*param_1 + 0xd0);
  pppppplVar5 = local_568;
  uVar26 = uStack_560;
  for (lVar11 = *(longlong *)(*param_1 + 200); uStack_560 = uVar23, local_568 = pppppplVar32,
      lVar11 != lVar1; lVar11 = lVar11 + 0x20) {
    local_568 = (longlong ******)0xa;
    uStack_560 = 0xf;
    uStack_570 = (ulonglong)(ushort)s_attachment_141f5f5a0._8_2_;
    local_578 = (wchar_t *******)s_attachment_141f5f5a0._0_8_;
    uVar12 = FUN_1412ef4d0(&local_4e0,&local_578,lVar11);
    FUN_1412f7ee0(uVar12,&local_538);
    if (7 < uStack_4c8) {
      pvVar2 = (void *)CONCAT62(uStack_4de,local_4e0);
      pvVar20 = pvVar2;
      if ((0xfff < uStack_4c8 * 2 + 2) &&
         (pvVar20 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar20)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar20);
    }
    local_4d0 = (longlong ******)0x0;
    uStack_4c8 = 7;
    local_4e0 = 0;
    if (0xf < uStack_560) {
      pppppppwVar21 = local_578;
      if ((0xfff < uStack_560 + 1) &&
         (pppppppwVar21 = (wchar_t *******)local_578[-1],
         0x1f < (ulonglong)((longlong)local_578 + (-8 - (longlong)pppppppwVar21)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppwVar21);
    }
    uVar33 = (undefined4)((ulonglong)in_stack_fffffffffffffa60 >> 0x20);
    local_568 = (longlong ******)0x0;
    uStack_560 = 0xf;
    local_578 = (wchar_t *******)((ulonglong)local_578 & 0xffffffffffffff00);
    pppppplVar32 = _DAT_141d2ff30;
    uVar23 = _UNK_141d2ff38;
    pppppplVar5 = local_568;
    uVar26 = uStack_560;
  }
  if (*(longlong *)(*param_1 + 0xf0) != 0) {
    uStack_570 = (ulonglong)(ushort)s_screenshot_1423b9570._8_2_;
    local_578 = (wchar_t *******)s_screenshot_1423b9570._0_8_;
    uVar12 = FUN_1412ef4d0(&local_4e0,&local_578);
    FUN_1412f7ee0(uVar12,&local_538);
    if (7 < uStack_4c8) {
      pvVar2 = (void *)CONCAT62(uStack_4de,local_4e0);
      pvVar20 = pvVar2;
      if ((0xfff < uStack_4c8 * 2 + 2) &&
         (pvVar20 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar20)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar20);
    }
    local_4d0 = pppppplVar3;
    uStack_4c8 = uVar4;
    local_4e0 = 0;
    if (0xf < uStack_560) {
      pppppppwVar21 = local_578;
      if ((0xfff < uStack_560 + 1) &&
         (pppppppwVar21 = (wchar_t *******)local_578[-1],
         0x1f < (ulonglong)((longlong)local_578 + (-8 - (longlong)pppppppwVar21)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppwVar21);
    }
    local_568 = _DAT_141ac9b00;
    uStack_560 = _UNK_141ac9b08;
    local_578 = (wchar_t *******)((ulonglong)local_578 & 0xffffffffffffff00);
    pppppplVar5 = local_568;
    uVar26 = uStack_560;
  }
  uStack_560 = uVar26;
  local_568 = pppppplVar5;
  if (*(char *)(*param_1 + 0x100) != '\0') {
    local_578 = (wchar_t *******)0x0;
    uStack_570 = 0;
    local_568 = (longlong ******)0x0;
    uStack_560 = 0;
    FUN_1402a7200(&local_578,L"--wait-for-upload",0x11);
    FUN_1412f7ee0(&local_578,&local_538);
    if (7 < uStack_560) {
      pppppppwVar21 = local_578;
      if ((0xfff < uStack_560 * 2 + 2) &&
         (pppppppwVar21 = (wchar_t *******)local_578[-1],
         0x1f < (ulonglong)((longlong)local_578 + (-8 - (longlong)pppppppwVar21)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppwVar21);
    }
    local_568 = pppppplVar3;
    uStack_560 = uVar4;
    local_578 = (wchar_t *******)((ulonglong)local_578 & 0xffffffffffff0000);
  }
  DVar8 = GetCurrentProcessId();
  ppppppplVar16 = OpenProcess(0x101041,1,DVar8);
  local_508 = ppppppplVar16;
  if (ppppppplVar16 == (longlong *******)0x0) {
    DVar8 = GetLastError();
    lVar11 = FUN_1412fa700(local_3e0,
                           "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                           ,
                           "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                           ,0x1da,2,CONCAT44(uVar33,DVar8));
    local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 2);
    FUN_1402b8060(lVar11 + 8,"OpenProcess");
    local_res18 = (ulonglong *)CONCAT44(local_res18._4_4_,uVar28);
    FUN_1412fa820(local_3e0);
    if (7 < uStack_520) {
      pppppppWVar22 = local_538;
      if ((0xfff < uStack_520 * 2 + 2) &&
         (pppppppWVar22 = (LPWSTR ******)local_538[-1],
         0x1f < (ulonglong)((longlong)local_538 + (-8 - (longlong)pppppppWVar22)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppWVar22);
    }
    local_538 = (LPWSTR ******)((ulonglong)local_538 & 0xffffffffffff0000);
    goto LAB_1412f1831;
  }
  uVar12 = *(undefined8 *)(*param_1 + 0x128);
  FUN_1412f8430(local_2c8,DAT_1429402f0,DAT_142940304,DAT_14294030c,uVar12,ppppppplVar16,
                &DAT_142b29320,&DAT_142b29340,&DAT_142b29358);
  uVar33 = (undefined4)((ulonglong)uVar12 >> 0x20);
  FUN_1412f8470(local_2c8,&local_4b0);
  local_500 = (char *******)0x0;
  uStack_4f8 = 0;
  local_500 = (char *******)FUN_141981f80(0x20);
  uVar12 = s___initial_client_data__1423b95b8._8_8_;
  local_4f0 = (longlong ******)_DAT_141d4cf10;
  uStack_4e8 = _UNK_141d4cf18;
  *local_500 = (char ******)s___initial_client_data__1423b95b8._0_8_;
  local_500[1] = (char ******)uVar12;
  *(undefined4 *)(local_500 + 2) = s___initial_client_data__1423b95b8._16_4_;
  *(undefined2 *)((longlong)local_500 + 0x14) = s___initial_client_data__1423b95b8._20_2_;
  *(char *)((longlong)local_500 + 0x16) = '\0';
  FUN_14029f4d0(&local_578,(ulonglong)param_1 & 0xff);
  uVar29 = uVar28 | 0x400;
  local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x400);
  local_518 = (wchar_t *******)&local_578;
  if (0xf < uStack_560) {
    local_518 = local_578;
  }
  pppppplStack_510 = local_568;
  uVar12 = FUN_1412fb2c0(&local_4e0,&local_518);
  FUN_1412f7ee0(uVar12,&local_538);
  if (7 < uStack_4c8) {
    pvVar2 = (void *)CONCAT62(uStack_4de,local_4e0);
    pvVar20 = pvVar2;
    if ((0xfff < uStack_4c8 * 2 + 2) &&
       (pvVar20 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar20)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar20);
  }
  local_4d0 = pppppplVar3;
  uStack_4c8 = uVar4;
  local_4e0 = 0;
  if (0xf < uStack_560) {
    pppppppwVar21 = local_578;
    if ((0xfff < uStack_560 + 1) &&
       (pppppppwVar21 = (wchar_t *******)local_578[-1],
       0x1f < (ulonglong)((longlong)local_578 + (-8 - (longlong)pppppppwVar21)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pppppppwVar21);
  }
  local_568 = _DAT_141ac9b00;
  uStack_560 = _UNK_141ac9b08;
  local_578 = (wchar_t *******)((ulonglong)local_578 & 0xffffffffffffff00);
  if (0xf < uStack_4e8) {
    pppppppcVar25 = local_500;
    if ((0xfff < uStack_4e8 + 1) &&
       (pppppppcVar25 = (char *******)local_500[-1],
       (char *)0x1f < (char *)((longlong)local_500 + (-8 - (longlong)pppppppcVar25)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pppppppcVar25);
  }
  local_4f0 = _DAT_141ac9b00;
  uStack_4e8 = _UNK_141ac9b08;
  local_500 = (char *******)((ulonglong)local_500 & 0xffffffffffffff00);
  if (0xf < uStack_498) {
    pvVar2 = (void *)CONCAT62(uStack_4ae,CONCAT11(uStack_4af,local_4b0));
    pvVar20 = pvVar2;
    if ((0xfff < uStack_498 + 1) &&
       (pvVar20 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar20)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar20);
  }
  local_4b0 = 0;
  local_468.cb = 0;
  local_468._4_4_ = 0;
  local_468.lpReserved = (LPWSTR)0x0;
  local_468.lpDesktop = (LPWSTR)0x0;
  local_468.lpTitle = (LPWSTR)0x0;
  local_468.dwX = 0;
  local_468.dwY = 0;
  local_468.dwXSize = 0;
  local_468.dwYSize = 0;
  local_468.dwXCountChars = 0;
  local_468.dwYCountChars = 0;
  local_468.wShowWindow = 0;
  local_468.cbReserved2 = 0;
  local_468._68_4_ = 0;
  local_468.lpReserved2 = (LPBYTE)0x0;
  local_468.hStdInput = (HANDLE)0x0;
  local_468.hStdOutput = (HANDLE)0x0;
  local_468.hStdError = (HANDLE)0x0;
  ppppppplStack_400 = (longlong *******)0x0;
  local_468.dwFillAttribute = 0;
  local_468.dwFlags = 0x100;
  local_4a0 = _DAT_141ac9b00;
  uStack_498 = _UNK_141ac9b08;
  local_468.hStdInput = GetStdHandle(0xfffffff6);
  local_468.hStdOutput = GetStdHandle(0xfffffff5);
  local_468.hStdError = GetStdHandle(0xfffffff4);
  local_558 = (longlong *******)0x0;
  ppppppplStack_550 = (longlong *******)0x0;
  local_548 = (longlong *******)0x0;
  local_518 = (wchar_t *******)0x0;
  local_4c0 = (longlong *******)0x0;
  lVar11 = *(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8);
  local_4b8 = lVar11;
  if ((*(int *)(lVar11 + 0x160) < DAT_142b293a0) &&
     (FUN_141982544(&DAT_142b293a0), DAT_142b293a0 == -1)) {
    DAT_142b29398 = (code *)FUN_1412f83d0(L"kernel32.dll","::InitializeProcThreadAttributeList");
    _Init_thread_footer(&DAT_142b293a0);
  }
  if ((*(int *)(lVar11 + 0x160) < DAT_142b293b0) &&
     (FUN_141982544(&DAT_142b293b0), DAT_142b293b0 == -1)) {
    if (DAT_142b29398 == (code *)0x0) {
      DAT_142b293a8 = (code *)0x0;
    }
    else {
      DAT_142b293a8 = (code *)FUN_1412f83d0(L"kernel32.dll","::UpdateProcThreadAttribute");
    }
    _Init_thread_footer(&DAT_142b293b0);
  }
  if ((DAT_142b29398 == (code *)0x0) || (DAT_142b293a8 == (code *)0x0)) {
    local_res20 = 0;
    local_468.cb = 0x68;
    ppppppplVar17 = ppppppplVar19;
    ppppppplVar27 = ppppppplVar19;
    ppppppplVar30 = local_558;
  }
  else {
    local_res20 = 0x80000;
    local_468.cb = 0x70;
    iVar9 = (*DAT_142b29398)(0,1,0,&local_488);
    if (iVar9 != 0) {
      lVar11 = FUN_1412fa530(local_3e0,
                             "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                             ,
                             "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                             ,0x20b,CONCAT44(uVar33,2));
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x404);
      FUN_1402b8060(lVar11 + 8,
                    "InitializeProcThreadAttributeList (size) succeeded, expected failure");
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x400);
      FUN_1412fa7a0(local_3e0);
      FUN_1412f5370(ppppppplVar16);
      local_508 = (longlong *******)0x0;
      if (7 < uStack_520) {
        FUN_1402a2220(&local_538,local_538);
      }
      local_538 = (LPWSTR ******)((ulonglong)local_538 & 0xffffffffffff0000);
      goto LAB_1412f1831;
    }
    DVar8 = GetLastError();
    if (DVar8 != 0x7a) {
      DVar8 = GetLastError();
      lVar11 = FUN_1412fa700(local_3e0,
                             "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                             ,
                             "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                             ,0x20f,2,DVar8);
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x408);
      FUN_1402b8060(lVar11 + 8,"InitializeProcThreadAttributeList (size)");
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x400);
      FUN_1412fa820(local_3e0);
      FUN_1412f5370(ppppppplVar16);
      local_508 = (longlong *******)0x0;
      if (7 < uStack_520) {
        FUN_1402a2220(&local_538,local_538);
      }
      local_538 = (LPWSTR ******)((ulonglong)local_538 & 0xffffffffffff0000);
      goto LAB_1412f1831;
    }
    ppppppplVar17 = (longlong *******)thunk_FUN_141981f80(local_488);
    local_518 = (wchar_t *******)ppppppplVar17;
    ppppppplStack_400 = ppppppplVar17;
    iVar9 = (*DAT_142b29398)(ppppppplVar17,1,0,&local_488);
    ppppppplVar19 = ppppppplStack_400;
    if (iVar9 == 0) {
      DVar8 = GetLastError();
      lVar11 = FUN_1412fa700(local_3e0,
                             "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                             ,
                             "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                             ,0x21a,2,DVar8);
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x410);
      FUN_1402b8060(lVar11 + 8,"InitializeProcThreadAttributeList");
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x400);
      FUN_1412fa820(local_3e0);
      if (ppppppplVar17 != (longlong *******)0x0) {
        free(ppppppplVar17);
      }
      FUN_1412f5370(ppppppplVar16);
      local_508 = (longlong *******)0x0;
      if (7 < uStack_520) {
        FUN_1402a2220(&local_538,local_538);
      }
      local_538 = (LPWSTR ******)((ulonglong)local_538 & 0xffffffffffff0000);
      goto LAB_1412f1831;
    }
    local_4c0 = ppppppplStack_400;
    local_res18 = (ulonglong *)0x8;
    local_558 = (longlong *******)FUN_1402bd760(&local_558,&local_res18);
    local_548 = local_558 + 8;
    if (local_558 == local_548) {
      ppppppplStack_550 = local_558;
      FUN_1412ee720(&local_558,local_558,&DAT_1429402f0);
    }
    else {
      *local_558 = DAT_1429402f0;
      ppppppplStack_550 = local_558 + 1;
    }
    if (ppppppplStack_550 == local_548) {
      FUN_1412ee720(&local_558,ppppppplStack_550,&DAT_142940304);
    }
    else {
      *ppppppplStack_550 = DAT_142940304;
      ppppppplStack_550 = ppppppplStack_550 + 1;
    }
    if (ppppppplStack_550 == local_548) {
      FUN_1412ee720(&local_558,ppppppplStack_550,&DAT_14294030c);
    }
    else {
      *ppppppplStack_550 = DAT_14294030c;
      ppppppplStack_550 = ppppppplStack_550 + 1;
    }
    if (ppppppplStack_550 == local_548) {
      FUN_1412ee720(&local_558,ppppppplStack_550,*param_1 + 0x128);
    }
    else {
      *ppppppplStack_550 = *(longlong *******)(*param_1 + 0x128);
      ppppppplStack_550 = ppppppplStack_550 + 1;
    }
    if (ppppppplStack_550 == local_548) {
      FUN_1412ee720(&local_558,ppppppplStack_550,&local_508);
      ppppppplVar16 = local_508;
    }
    else {
      *ppppppplStack_550 = (longlong ******)ppppppplVar16;
      ppppppplStack_550 = ppppppplStack_550 + 1;
    }
    FUN_1412eef50(&local_558,local_468.hStdInput);
    FUN_1412eef50(&local_558,local_468.hStdOutput);
    FUN_1412eef50(&local_558,local_468.hStdError);
    ppppppplVar30 = local_558;
    iVar9 = (*DAT_142b293a8)(ppppppplStack_400,0,0x20002,local_558,
                             (longlong)ppppppplStack_550 - (longlong)local_558 & 0xfffffffffffffff8,
                             0,0);
    ppppppplVar27 = local_548;
    if (iVar9 == 0) {
      DVar8 = GetLastError();
      lVar11 = FUN_1412fa700(local_3e0,
                             "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                             ,
                             "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                             ,0x234,2,DVar8);
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x420);
      FUN_1402b8060(lVar11 + 8,"UpdateProcThreadAttribute");
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x400);
      FUN_1412fa820(local_3e0);
      if (ppppppplVar19 != (longlong *******)0x0) {
        if ((*(int *)(local_4b8 + 0x160) < DAT_142b29390) &&
           (FUN_141982544(&DAT_142b29390), DAT_142b29390 == -1)) {
          DAT_142b29388 = (code *)FUN_1412f83d0(L"kernel32.dll","::DeleteProcThreadAttributeList",1)
          ;
          _Init_thread_footer(&DAT_142b29390);
        }
        (*DAT_142b29388)(ppppppplVar19);
        local_4c0 = (longlong *******)0x0;
      }
      if (ppppppplVar17 != (longlong *******)0x0) {
        free(ppppppplVar17);
      }
      if (ppppppplVar30 != (longlong *******)0x0) {
        deallocate(&local_558,ppppppplVar30,(longlong)local_548 - (longlong)ppppppplVar30 >> 3);
        local_558 = (longlong *******)0x0;
        ppppppplStack_550 = (longlong *******)0x0;
        local_548 = (longlong *******)0x0;
      }
      if (ppppppplVar16 != (longlong *******)0x0) {
        FUN_1412f5370(ppppppplVar16);
        local_508 = (longlong *******)0x0;
      }
      if (7 < uStack_520) {
        FUN_1402a2220(&local_538,local_538);
      }
      local_538 = (LPWSTR ******)((ulonglong)local_538 & 0xffffffffffff0000);
      goto LAB_1412f1831;
    }
  }
  puVar18 = (undefined8 *)*param_1;
  if ((ulonglong)puVar18[2] < 0xc) {
LAB_1412f1304:
    bVar31 = false;
  }
  else {
    uVar23 = puVar18[2] - 0xc;
    local_578 = (wchar_t *******)0x0;
    uStack_570 = 0;
    local_568 = (longlong ******)0x0;
    uStack_560 = 0;
    if ((ulonglong)puVar18[2] < uVar23) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a6430();
    }
    if (7 < (ulonglong)puVar18[3]) {
      puVar18 = (undefined8 *)*puVar18;
    }
    FUN_1402a7200(&local_578,(longlong)puVar18 + uVar23 * 2);
    uVar29 = uVar28 | 0x4440;
    local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) | 0x4440);
    pppppppwVar21 = (wchar_t *******)&local_578;
    if (7 < uStack_560) {
      pppppppwVar21 = local_578;
    }
    iVar9 = _wcsicmp((wchar_t *)pppppppwVar21,L"rundll32.exe");
    if (iVar9 != 0) goto LAB_1412f1304;
    bVar31 = true;
  }
  if ((uVar29 & 0x40) != 0) {
    local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar29) & 0xffffffffffffffbf);
    if (7 < uStack_560) {
      pppppppwVar21 = local_578;
      if ((0xfff < uStack_560 * 2 + 2) &&
         (pppppppwVar21 = (wchar_t *******)local_578[-1],
         0x1f < (ulonglong)((longlong)local_578 + (-8 - (longlong)pppppppwVar21)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppwVar21);
    }
    local_568 = pppppplVar3;
    uStack_560 = uVar4;
    local_578 = (wchar_t *******)((ulonglong)local_578 & 0xffffffffffff0000);
    uVar29 = uVar29 & 0xffffffbf;
  }
  lpApplicationName = (LPCWSTR)0x0;
  pppppppWVar22 = (LPWSTR ******)&local_538;
  if (7 < uStack_520) {
    pppppppWVar22 = local_538;
  }
  if ((!bVar31) &&
     (lpApplicationName = (LPCWSTR)*param_1, 7 < *(ulonglong *)(lpApplicationName + 0xc))) {
    lpApplicationName = *(LPCWSTR *)lpApplicationName;
  }
  BVar10 = CreateProcessW(lpApplicationName,(LPWSTR)pppppppWVar22,(LPSECURITY_ATTRIBUTES)0x0,
                          (LPSECURITY_ATTRIBUTES)0x0,1,local_res20,(LPVOID)0x0,(LPCWSTR)0x0,
                          &local_468,&local_3f8);
  if (BVar10 == 0) {
    DVar8 = GetLastError();
    lVar11 = FUN_1412fa700(local_3e0,
                           "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                           ,
                           "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                           ,0x256,2,DVar8);
    local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar29) | 0x80);
    FUN_1402b8060(lVar11 + 8,"CreateProcess");
    local_res18 = (ulonglong *)CONCAT44(local_res18._4_4_,uVar29);
    FUN_1412fa820(local_3e0);
    if (ppppppplVar19 != (longlong *******)0x0) {
      if ((*(int *)(local_4b8 + 0x160) < DAT_142b29390) &&
         (FUN_141982544(&DAT_142b29390), DAT_142b29390 == -1)) {
        DAT_142b29388 = (code *)FUN_1412f83d0(L"kernel32.dll","::DeleteProcThreadAttributeList",1);
        _Init_thread_footer(&DAT_142b29390);
      }
      (*DAT_142b29388)(ppppppplVar19);
      ppppppplVar19 = (longlong *******)0x0;
      local_4c0 = (longlong *******)0x0;
    }
    if (ppppppplVar17 != (longlong *******)0x0) {
      free(ppppppplVar17);
    }
    if (ppppppplVar30 != (longlong *******)0x0) {
      ppppppplVar17 = ppppppplVar30;
      if ((0xfff < (ulonglong)(((longlong)ppppppplVar27 - (longlong)ppppppplVar30 >> 3) * 8)) &&
         (ppppppplVar17 = (longlong *******)ppppppplVar30[-1],
         0x1f < (ulonglong)((longlong)ppppppplVar30 + (-8 - (longlong)ppppppplVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppppplVar17);
      local_558 = (longlong *******)0x0;
      ppppppplStack_550 = (longlong *******)0x0;
      local_548 = ppppppplVar19;
    }
    if (ppppppplVar16 != (longlong *******)0x0) {
      FUN_1412f5370(ppppppplVar16);
      local_508 = ppppppplVar19;
    }
    if (7 < uStack_520) {
      pppppppWVar22 = local_538;
      if ((0xfff < uStack_520 * 2 + 2) &&
         (pppppppWVar22 = (LPWSTR ******)local_538[-1],
         0x1f < (ulonglong)((longlong)local_538 + (-8 - (longlong)pppppppWVar22))))
      goto LAB_1412f1937;
      free(pppppppWVar22);
    }
    local_538 = (LPWSTR ******)CONCAT62(local_538._2_6_,(short)ppppppplVar19);
  }
  else {
    BVar10 = CloseHandle(local_3f8.hThread);
    uVar28 = uVar29;
    if (BVar10 == 0) {
      DVar8 = GetLastError();
      lVar11 = FUN_1412fa700(local_3e0,
                             "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                             ,
                             "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                             ,0x25b,1,DVar8);
      uVar28 = uVar29 | 0x100;
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar29) | 0x100);
      FUN_1402b8060(lVar11 + 8);
    }
    uVar29 = uVar28;
    if ((uVar28 >> 8 & 1) != 0) {
      uVar29 = uVar28 & 0xfffffeff;
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) & 0xfffffffffffffeff);
      FUN_1412fa820(local_3e0);
    }
    BVar10 = CloseHandle(local_3f8.hProcess);
    uVar28 = uVar29;
    if (BVar10 == 0) {
      DVar8 = GetLastError();
      lVar11 = FUN_1412fa700(local_3e0,
                             "bool __cdecl crashpad::`anonymous-namespace\'::StartHandlerProcess(class std::unique_ptr<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData,struct std::default_delete<struct crashpad::`anonymous namespace\'::BackgroundHandlerStartThreadData> >)"
                             ,
                             "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                             ,0x25e,1,DVar8);
      uVar28 = uVar29 | 0x200;
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar29) | 0x200);
      FUN_1402b8060(lVar11 + 8);
    }
    if ((uVar28 >> 9 & 1) != 0) {
      local_res18 = (ulonglong *)(CONCAT44(local_res18._4_4_,uVar28) & 0xfffffffffffffdff);
      FUN_1412fa820(local_3e0);
    }
    lVar11 = *param_1;
    if (*(longlong *)(lVar11 + 0x128) != -1) {
      thunk_FUN_1412f5560();
    }
    *(undefined8 *)(lVar11 + 0x128) = 0xffffffffffffffff;
    memset(local_274,0,0x208);
    local_278 = 4;
    local_478 = 0;
    local_470 = 0;
    cVar7 = FUN_1412f8910(*param_1 + 0x108,&local_278,&local_478);
    if (cVar7 != '\0') {
      if (ppppppplVar19 != (longlong *******)0x0) {
        if ((*(int *)(local_4b8 + 0x160) < DAT_142b29390) &&
           (FUN_141982544(&DAT_142b29390), DAT_142b29390 == -1)) {
          DAT_142b29388 = (code *)FUN_1412f83d0(L"kernel32.dll","::DeleteProcThreadAttributeList",1)
          ;
          _Init_thread_footer(&DAT_142b29390);
        }
        (*DAT_142b29388)(ppppppplVar19);
        ppppppplVar19 = (longlong *******)0x0;
        local_4c0 = (longlong *******)0x0;
      }
      if (ppppppplVar17 != (longlong *******)0x0) {
        free(ppppppplVar17);
      }
      if (ppppppplVar30 != (longlong *******)0x0) {
        deallocate(&local_558,ppppppplVar30,(longlong)ppppppplVar27 - (longlong)ppppppplVar30 >> 3);
        local_558 = (longlong *******)0x0;
        ppppppplStack_550 = (longlong *******)0x0;
        local_548 = ppppppplVar19;
      }
      if (ppppppplVar16 != (longlong *******)0x0) {
        FUN_1412f5370(ppppppplVar16);
        local_508 = ppppppplVar19;
      }
      if (7 < uStack_520) {
        pppppppWVar22 = local_538;
        if ((0xfff < uStack_520 * 2 + 2) &&
           (pppppppWVar22 = (LPWSTR ******)local_538[-1],
           0x1f < (ulonglong)((longlong)local_538 + (-8 - (longlong)pppppppWVar22))))
        goto LAB_1412f1937;
        free(pppppppWVar22);
      }
      local_538 = (LPWSTR ******)CONCAT62(local_538._2_6_,(short)ppppppplVar19);
      uStack_520 = uVar4;
      local_528 = pppppplVar3;
      DAT_142b29350 = 1;
      if (*param_1 != 0) {
        FUN_1412eed50(*param_1,1);
      }
      return 1;
    }
    if (ppppppplVar19 != (longlong *******)0x0) {
      if ((*(int *)(local_4b8 + 0x160) < DAT_142b29390) &&
         (FUN_141982544(&DAT_142b29390), DAT_142b29390 == -1)) {
        DAT_142b29388 = (code *)FUN_1412f83d0(L"kernel32.dll","::DeleteProcThreadAttributeList",1);
        _Init_thread_footer(&DAT_142b29390);
      }
      (*DAT_142b29388)(ppppppplVar19);
      ppppppplVar19 = (longlong *******)0x0;
      local_4c0 = (longlong *******)0x0;
    }
    if (ppppppplVar17 != (longlong *******)0x0) {
      free(ppppppplVar17);
    }
    if (ppppppplVar30 != (longlong *******)0x0) {
      deallocate(&local_558,ppppppplVar30,(longlong)ppppppplVar27 - (longlong)ppppppplVar30 >> 3);
      local_558 = (longlong *******)0x0;
      ppppppplStack_550 = (longlong *******)0x0;
      local_548 = ppppppplVar19;
    }
    if (ppppppplVar16 != (longlong *******)0x0) {
      FUN_1412f5370(ppppppplVar16);
      local_508 = ppppppplVar19;
    }
    if (7 < uStack_520) {
      pppppppWVar22 = local_538;
      if ((0xfff < uStack_520 * 2 + 2) &&
         (pppppppWVar22 = (LPWSTR ******)local_538[-1],
         0x1f < (ulonglong)((longlong)local_538 + (-8 - (longlong)pppppppWVar22)))) {
LAB_1412f1937:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppWVar22);
    }
    local_538 = (LPWSTR ******)CONCAT62(local_538._2_6_,(short)ppppppplVar19);
  }
LAB_1412f1831:
  uStack_520 = uVar4;
  local_528 = pppppplVar3;
  DAT_142b29350 = 2;
  if (*param_1 != 0) {
    FUN_1412eed50(*param_1,1);
  }
  return 0;
}


