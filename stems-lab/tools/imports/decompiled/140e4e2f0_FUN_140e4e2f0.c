// FUN_140e4e2f0 @ 140e4e2f0
// calls: [CreateFileW]

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong *******
FUN_140e4e2f0(longlong *******param_1,longlong *param_2,longlong ******param_3,char param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  void *pvVar3;
  bool bVar4;
  bool bVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  longlong ******pppppplVar12;
  undefined8 uVar13;
  longlong lVar14;
  int *piVar15;
  longlong *plVar16;
  undefined8 *puVar17;
  undefined4 *puVar18;
  undefined8 uVar19;
  longlong *******ppppppplVar20;
  undefined8 *puVar21;
  longlong *******ppppppplVar22;
  undefined8 uVar23;
  longlong *******ppppppplVar24;
  void *pvVar25;
  undefined8 *******pppppppuVar26;
  undefined8 **ppuVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  longlong *local_res10;
  char local_4f8 [8];
  undefined8 local_4f0;
  longlong *******local_4e8;
  char local_4e0;
  int local_4dc;
  undefined8 local_4d8;
  longlong *plStack_4d0;
  longlong local_4c8;
  longlong *******local_4b8;
  longlong *******ppppppplStack_4b0;
  undefined8 local_4a8;
  longlong *******local_498;
  longlong *******ppppppplStack_490;
  undefined8 *local_488;
  undefined8 uStack_480;
  longlong *******local_478;
  longlong *******ppppppplStack_470;
  longlong local_468;
  undefined4 local_460;
  undefined4 uStack_45c;
  undefined4 uStack_458;
  undefined4 uStack_454;
  longlong *local_450;
  undefined8 uStack_448;
  undefined8 *local_440;
  longlong *plStack_438;
  longlong local_430;
  ulonglong uStack_428;
  undefined1 local_420;
  undefined7 uStack_41f;
  undefined8 local_410;
  ulonglong uStack_408;
  undefined1 local_400;
  undefined7 uStack_3ff;
  undefined8 local_3f0;
  ulonglong uStack_3e8;
  void *local_3e0 [3];
  ulonglong local_3c8;
  undefined8 *******local_3c0;
  longlong lStack_3b8;
  longlong local_3b0;
  ulonglong uStack_3a8;
  undefined1 local_3a0 [32];
  longlong ******local_380;
  longlong *local_378;
  undefined1 local_370 [32];
  undefined8 local_350;
  undefined8 uStack_348;
  ulonglong local_340;
  undefined8 *local_338;
  undefined8 *puStack_330;
  longlong local_328;
  undefined1 local_320 [8];
  longlong local_318;
  undefined1 local_310 [16];
  longlong local_300;
  longlong local_2f0 [7];
  longlong *local_2b8;
  undefined1 local_2a8 [256];
  undefined1 local_1a8 [368];
  
  local_4f0 = local_4f0 & 0xffffffff00000000;
  local_2b8 = (longlong *)0x0;
  puVar17 = *(undefined8 **)(*param_2 + 0x40);
  local_res10 = param_2;
  if (puVar17 != (undefined8 *)0x0) {
    local_2b8 = (longlong *)(**(code **)*puVar17)(puVar17,local_2f0);
  }
  local_4f0 = CONCAT44(local_4f0._4_4_,0x40);
  ppppppplStack_490 = (longlong *******)0x0;
  local_488 = (undefined8 *)0x0;
  uStack_480 = 0xf;
  local_498 = (longlong *******)0x0;
  local_4e8 = (longlong *******)&local_498;
  *param_1 = (longlong ******)librarian::LoggingObject::vftable;
  local_478 = param_1 + 1;
  param_1[8] = (longlong ******)0x0;
  if (local_2b8 != (longlong *)0x0) {
    pppppplVar12 = (longlong ******)(**(code **)*local_2b8)(0,local_478);
    param_1[8] = pppppplVar12;
  }
  FUN_1402aa5d0(param_1 + 9,&local_498);
  if (0xf < uStack_480) {
    ppppppplVar24 = local_498;
    if ((0xfff < uStack_480 + 1) &&
       (ppppppplVar24 = (longlong *******)local_498[-1],
       0x1f < (ulonglong)((longlong)local_498 + (-8 - (longlong)ppppppplVar24)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppppplVar24);
  }
  *param_1 = (longlong ******)librarian::DatabaseConnectionInterface::vftable;
  *(undefined4 *)(param_1 + 0xd) = 0;
  if (local_2b8 != (longlong *)0x0) {
    (**(code **)(*local_2b8 + 0x20))
              (local_2b8,CONCAT71((int7)((ulonglong)local_2f0 >> 8),local_2b8 != local_2f0));
  }
  param_1[0xe] = (longlong ******)0x0;
  param_1[0xf] = (longlong ******)0x0;
  *param_1 = (longlong ******)librarian::DatabaseConnectionSqlite::vftable;
  uVar13 = FUN_140a6f2d0(*param_2);
  ppppppplVar24 = param_1 + 0x10;
  FUN_14041f360(uVar13,ppppppplVar24);
  param_1[0x14] = (longlong ******)0x0;
  param_1[0x15] = (longlong ******)0x0;
  uVar28 = 0x40;
  if (param_2[1] != 0) {
    param_1[0x14] = (longlong ******)*param_2;
    pppppplVar12 = (longlong ******)param_2[1];
    param_1[0x15] = pppppplVar12;
    LOCK();
    piVar15 = (int *)((longlong)pppppplVar12 + 0xc);
    *piVar15 = *piVar15 + 1;
    UNLOCK();
    uVar28 = (uint)local_4f0;
  }
  param_1[0x16] = (longlong ******)0x0;
  *(undefined1 *)(param_1 + 0x17) = 0;
  param_1[0x18] = param_3;
  local_350 = 0;
  uStack_348 = 0;
  local_340 = 0;
  FUN_140dd3550(*param_2,&local_380);
  uVar30 = 0x41;
  if ((param_4 == '\0') && (cVar8 = FUN_140dd5260(*param_2), cVar8 == '\0')) {
    bVar4 = false;
    bVar5 = false;
    cVar8 = FUN_140dc6ce0(ppppppplVar24);
    if (cVar8 != '\0') goto LAB_140e4e58c;
    ppppppplStack_490 = (longlong *******)0x0;
    local_488 = (undefined8 *)_DAT_141cb0070;
    uStack_480 = _UNK_141cb0078;
    local_498 = (longlong *******)0x0;
    pppppplVar12 = param_1[0x12];
    if (pppppplVar12 != (longlong ******)0x0) {
      ppppppplVar22 = ppppppplVar24;
      if (&DAT_0000000f < param_1[0x13]) {
        ppppppplVar22 = (longlong *******)*ppppppplVar24;
        ppppppplVar24 = (longlong *******)*ppppppplVar24;
      }
      uVar13 = FUN_14196e970();
      FUN_141971270(ppppppplVar24,(longlong)ppppppplVar22 + (longlong)pppppplVar12,&local_498,uVar13
                   );
    }
    lVar14 = FUN_141973520(&local_498,&local_350);
    if ((lVar14 != 0) &&
       ((uVar28 = 0x41, (local_340 & 1) == 0 ||
        ((local_340 == 1 && (uVar28 = 0x41, (int)local_350 == 0)))))) goto LAB_140e4e58c;
    local_4f8[0] = '\0';
    uVar28 = 0x41;
  }
  else {
    bVar4 = true;
LAB_140e4e58c:
    bVar5 = bVar4;
    local_4f8[0] = '\x01';
  }
  ppuVar27 = (undefined8 **)0x0;
  if ((uVar28 & 1) != 0) {
    uVar28 = uVar28 & 0xfffffffe;
    FUN_1402a29e0(&local_498);
  }
  uVar29 = uVar28;
  if (local_4f8[0] == '\0') {
    uVar13 = FUN_140dd39d0(*param_2,&local_460);
    uVar29 = uVar28 | 2;
    local_4f0 = CONCAT44(local_4f0._4_4_,uVar28) | 2;
    piVar15 = (int *)FUN_141974de0(&local_478,uVar13,&local_350);
    if (*piVar15 == 3) goto LAB_140e4e604;
    uVar13 = FUN_140dd39d0(*param_2,local_3e0);
    uVar29 = uVar28 | 6;
    local_4f0 = CONCAT44(local_4f0._4_4_,uVar28) | 6;
    cVar8 = FUN_141972f10(uVar13,&local_350);
    if (cVar8 != '\0') goto LAB_140e4e604;
    bVar4 = true;
  }
  else {
LAB_140e4e604:
    bVar4 = false;
  }
  if ((uVar29 & 4) != 0) {
    uVar29 = uVar29 & 0xfffffffb;
    FUN_1402a29e0(local_3e0);
  }
  if ((uVar29 & 2) != 0) {
    uVar29 = uVar29 & 0xfffffffd;
    FUN_1402a29e0(&local_460);
  }
  if (bVar4) {
    uVar13 = FUN_1405abe00(&local_350,&local_498);
    uVar19 = FUN_141956310(&local_420,param_1 + 0x10);
    uVar19 = FUN_1402baf90(&local_400,"Unable to create parent directory for: ",uVar19);
    uVar19 = FUN_14029e990(&local_460,uVar19,&DAT_141d733ac);
    uVar13 = FUN_14029e960(local_3e0,uVar19,uVar13);
    FUN_14029e990(&local_4b8,uVar13,&DAT_141d25488);
    FUN_14029c3e0(local_3e0);
    FUN_14029c3e0(&local_460);
    FUN_14029c3e0(&local_400);
    FUN_14029c3e0(&local_420);
    FUN_14029c3e0(&local_498);
    FUN_1406e9ad0(&local_4d8,0x6d,&local_4b8);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_4d8,(ThrowInfo *)&DAT_14288da78);
  }
  ppppppplStack_4b0 = (longlong *******)local_4f8;
  local_4a8 = &local_350;
  uStack_480 = CONCAT71(uStack_480._1_7_,1);
  local_4b8 = param_1;
  local_498 = param_1;
  ppppppplStack_490 = ppppppplStack_4b0;
  local_488 = local_4a8;
  iVar9 = std::uncaught_exceptions();
  uStack_480 = CONCAT44(iVar9,(undefined4)uStack_480);
  local_4e8 = param_1;
  if (bVar5) {
    plVar16 = (longlong *)FUN_140e53670(&local_420,param_1 + 0x10);
    uVar29 = uVar29 | 0x10;
  }
  else {
    plVar16 = (longlong *)FUN_1402aa5d0(&local_400);
    uVar29 = uVar29 | 8;
  }
  local_4f0 = CONCAT44(local_4f0._4_4_,uVar29);
  local_3c0 = (undefined8 *******)*plVar16;
  lStack_3b8 = plVar16[1];
  local_3b0 = plVar16[2];
  uStack_3a8 = plVar16[3];
  plVar16[2] = 0;
  plVar16[3] = 0xf;
  *(undefined1 *)plVar16 = 0;
  uVar6 = _UNK_141ac9b08;
  uVar13 = _DAT_141ac9b00;
  uVar28 = uVar29;
  if ((uVar29 & 0x10) != 0) {
    uVar28 = uVar29 & 0xffffffef;
    local_4f0 = CONCAT44(local_4f0._4_4_,uVar29) & 0xffffffffffffffef;
    if (0xf < uStack_408) {
      pvVar3 = (void *)CONCAT71(uStack_41f,local_420);
      pvVar25 = pvVar3;
      if ((0xfff < uStack_408 + 1) &&
         (pvVar25 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar25)))) goto LAB_140e4e768;
      free(pvVar25);
    }
    local_410 = uVar13;
    uStack_408 = uVar6;
    local_420 = 0;
  }
  uVar29 = uVar28;
  if ((uVar28 & 8) != 0) {
    uVar29 = uVar28 & 0xfffffff7;
    local_4f0 = CONCAT44(local_4f0._4_4_,uVar28) & 0xfffffffffffffff7;
    if (0xf < uStack_3e8) {
      pvVar3 = (void *)CONCAT71(uStack_3ff,local_400);
      pvVar25 = pvVar3;
      if ((0xfff < uStack_3e8 + 1) &&
         (pvVar25 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar25)))) {
LAB_140e4e768:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar25);
    }
    local_3f0 = uVar13;
    uStack_3e8 = uVar6;
    local_400 = 0;
  }
  uVar28 = uVar29;
  if ((!bVar5) && (cVar8 = FUN_140dc6920(local_380), cVar8 != '\0')) {
    plVar16 = (longlong *)FUN_140dc2670(local_380,&local_478);
    uVar28 = uVar29 | 0x20;
    local_4f0 = CONCAT44(local_4f0._4_4_,uVar29) | 0x20;
    if ((*plVar16 != 0) && (ppuVar27 = &DAT_142b22c90, 0xf < DAT_142b22ca8)) {
      ppuVar27 = (undefined8 **)DAT_142b22c90;
    }
  }
  ppppppplVar24 = ppppppplStack_470;
  ppppppplVar22 = param_1;
  if (((uVar28 & 0x20) != 0) && (ppppppplStack_470 != (longlong *******)0x0)) {
    LOCK();
    ppppppplVar22 = ppppppplStack_470 + 1;
    iVar9 = *(int *)ppppppplVar22;
    *(int *)ppppppplVar22 = *(int *)ppppppplVar22 + -1;
    UNLOCK();
    ppppppplVar22 = local_4e8;
    if (iVar9 == 1) {
      (*(code *)**ppppppplStack_470)(ppppppplStack_470);
      LOCK();
      piVar15 = (int *)((longlong)ppppppplVar24 + 0xc);
      iVar9 = *piVar15;
      *piVar15 = *piVar15 + -1;
      UNLOCK();
      ppppppplVar22 = local_4e8;
      if (iVar9 == 1) {
        (*(code *)(*ppppppplVar24)[1])(ppppppplVar24);
        ppppppplVar22 = local_4e8;
      }
    }
  }
  if ((!bVar5) || (param_4 != '\0')) {
    uVar30 = 0x42;
  }
  if ((local_4f8[0] == '\0') || (param_4 != '\0')) {
    uVar28 = 4;
  }
  else {
    uVar28 = 0;
  }
  pppppppuVar26 = &local_3c0;
  if (0xf < uStack_3a8) {
    pppppppuVar26 = local_3c0;
  }
  ppppppplVar24 = param_1 + 0x16;
  iVar9 = thunk_FUN_140fbd870(pppppppuVar26,ppppppplVar24,uVar30 | uVar28,ppuVar27);
  if (iVar9 != 0) {
    uVar13 = FUN_140f8dd30(ppppppplVar22[0x16]);
    uVar19 = FUN_1402bcb10(&local_4d8,iVar9);
    uVar23 = FUN_141956310(&local_4b8,ppppppplVar22 + 0x10);
    uVar23 = FUN_1402baf90(&local_460,"Unable to open connection: ",uVar23);
    uVar23 = FUN_14029e990(local_3e0,uVar23," with error(");
    uVar19 = FUN_14029e960(local_370,uVar23,uVar19);
    uVar19 = FUN_14029e990(local_3a0,uVar19,&DAT_141d8b980);
    FUN_14029e990(&local_400,uVar19,uVar13);
    FUN_14029c3e0(local_3a0);
    FUN_14029c3e0(local_370);
    FUN_14029c3e0(local_3e0);
    FUN_14029c3e0(&local_460);
    FUN_14029c3e0(&local_4b8);
    FUN_14029c3e0(&local_4d8);
    FUN_1406e9ad0(&local_420,0x62,&local_400);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_420,(ThrowInfo *)&DAT_14288da78);
  }
  iVar9 = FUN_140f8c060(*ppppppplVar24,FUN_140e53d50,param_1);
  if (iVar9 != 0) {
    uVar13 = FUN_140f8dd30(ppppppplVar22[0x16]);
    uVar19 = FUN_1402bcb10(&local_4d8,iVar9);
    uVar23 = FUN_141956310(&local_4b8,ppppppplVar22 + 0x10);
    uVar23 = FUN_1402baf90(&local_460,"Unable to open connection: ",uVar23);
    uVar23 = FUN_14029e990(local_3e0,uVar23," with error(");
    uVar19 = FUN_14029e960(local_370,uVar23,uVar19);
    uVar19 = FUN_14029e990(local_3a0,uVar19,&DAT_141d8b980);
    FUN_14029e990(&local_400,uVar19,uVar13);
    FUN_14029c3e0(local_3a0);
    FUN_14029c3e0(local_370);
    FUN_14029c3e0(local_3e0);
    FUN_14029c3e0(&local_460);
    FUN_14029c3e0(&local_4b8);
    FUN_14029c3e0(&local_4d8);
    FUN_1406e9ad0(&local_420,0x62,&local_400);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_420,(ThrowInfo *)&DAT_14288da78);
  }
  iVar9 = FUN_140f720b0(*ppppppplVar24,"REGEXP",2,5,0,FUN_140e544d0,0,0,0);
  if (iVar9 != 0) {
    uVar13 = FUN_140f8dd30(ppppppplVar22[0x16]);
    uVar19 = FUN_1402bcb10(&local_4d8,iVar9);
    uVar23 = FUN_141956310(&local_4b8,ppppppplVar22 + 0x10);
    uVar23 = FUN_1402baf90(&local_460,"Unable to open connection: ",uVar23);
    uVar23 = FUN_14029e990(local_3e0,uVar23," with error(");
    uVar19 = FUN_14029e960(local_370,uVar23,uVar19);
    uVar19 = FUN_14029e990(local_3a0,uVar19,&DAT_141d8b980);
    FUN_14029e990(&local_400,uVar19,uVar13);
    FUN_14029c3e0(local_3a0);
    FUN_14029c3e0(local_370);
    FUN_14029c3e0(local_3e0);
    FUN_14029c3e0(&local_460);
    FUN_14029c3e0(&local_4b8);
    FUN_14029c3e0(&local_4d8);
    FUN_1406e9ad0(&local_420,0x62,&local_400);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_420,(ThrowInfo *)&DAT_14288da78);
  }
  uVar11 = 1;
  uVar28 = FUN_140f72110(*ppppppplVar24,"GET_STEMS_STATUS",0xffffffff,5,param_1,FUN_140e52680,
                         FUN_140e52570,FUN_140e53160,_guard_check_icall,0);
  plVar16 = (longlong *)(ulonglong)uVar28;
  if (uVar28 != 0) {
LAB_140e4fa14:
    uVar13 = FUN_140f8dd30(ppppppplVar22[0x16]);
    uVar19 = FUN_1402bcb10(&local_4d8,(ulonglong)plVar16 & 0xffffffff);
    uVar23 = FUN_141956310(&local_4b8,ppppppplVar22 + 0x10);
    uVar23 = FUN_1402baf90(&local_460,"Unable to open connection: ",uVar23);
    uVar23 = FUN_14029e990(local_3e0,uVar23," with error(");
    uVar19 = FUN_14029e960(local_370,uVar23,uVar19);
    uVar19 = FUN_14029e990(local_3a0,uVar19,&DAT_141d8b980);
    FUN_14029e990(&local_400,uVar19,uVar13);
    FUN_14029c3e0(local_3a0);
    FUN_14029c3e0(local_370);
    FUN_14029c3e0(local_3e0);
    FUN_14029c3e0(&local_460);
    FUN_14029c3e0(&local_4b8);
    FUN_14029c3e0(&local_4d8);
    FUN_1406e9ad0(&local_420,0x62,&local_400);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_420,(ThrowInfo *)&DAT_14288da78);
  }
  FUN_140e4ddb0(&local_4e8,FUN_140f720b0,*ppppppplVar24,"GET_ALBUM_ART",0xffffffff,
                CONCAT44(uVar11,1),param_1,FUN_140e51730,0,0,0);
  FUN_140e4ddb0(&local_4e8,FUN_140f720b0,*ppppppplVar24,"GET_ALBUM_ART_SIZE",1,1,param_1,
                FUN_140e52080,0,0,0);
  FUN_140e4ddb0(&local_4e8,FUN_140f720b0,*ppppppplVar24,"GET_RGB_OVERVIEW",0xffffffff,5,param_1,
                FUN_140e52280,0,0,0);
  FUN_140e4ddb0(&local_4e8,FUN_140f720b0,*ppppppplVar24,"GET_RGB_OVERVIEW_SIZE",1,5,param_1,
                FUN_140e52460,0,0,0);
  if (param_4 != '\0') {
    local_4e8 = (longlong *******)0x0;
    local_478 = (longlong *******)&local_4e8;
    ppppppplStack_470 = (longlong *******)CONCAT71(ppppppplStack_470._1_7_,1);
    ppppppplVar24 = param_1 + 0x10;
    if ((longlong ******)0xf < param_1[0x13]) {
      ppppppplVar24 = (longlong *******)param_1[0x10];
    }
    iVar9 = thunk_FUN_140fbd870(ppppppplVar24,&local_4e8,1,0);
    if (iVar9 != 0) {
      uVar13 = FUN_140f8dd30(ppppppplVar22[0x16]);
      uVar19 = FUN_1402bcb10(&local_420,iVar9);
      uVar23 = FUN_141956310(&local_400,ppppppplVar22 + 0x10);
      uVar23 = FUN_1402baf90(&local_460,"Unable to open connection: ",uVar23);
      uVar23 = FUN_14029e990(local_3e0,uVar23," with error(");
      uVar19 = FUN_14029e960(local_370,uVar23,uVar19);
      uVar19 = FUN_14029e990(local_3a0,uVar19,&DAT_141d8b980);
      FUN_14029e990(&local_4b8,uVar19,uVar13);
      FUN_14029c3e0(local_3a0);
      FUN_14029c3e0(local_370);
      FUN_14029c3e0(local_3e0);
      FUN_14029c3e0(&local_460);
      FUN_14029c3e0(&local_400);
      FUN_14029c3e0(&local_420);
      FUN_1406e9ad0(&local_4d8,0x62,&local_4b8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_4d8,(ThrowInfo *)&DAT_14288da78);
    }
    local_4f0 = FUN_140f79040(param_1[0x16],&DAT_14202c470,local_4e8,&DAT_14202c470);
    if (local_4f0 == 0) {
      uVar13 = FUN_140f8dd30(param_1[0x16]);
      uVar19 = FUN_141956310(&local_400,param_1 + 0x10);
      uVar19 = FUN_1402baf90(&local_460,"Unable to init backup to memory ",uVar19);
      uVar19 = FUN_14029e990(local_3e0,uVar19," error ");
      FUN_14029e990(&local_420,uVar19,uVar13);
      FUN_14029c3e0(local_3e0);
      FUN_14029c3e0(&local_460);
      FUN_14029c3e0(&local_400);
      FUN_1406e9ad0(&local_4b8,0x62,&local_420);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_4b8,(ThrowInfo *)&DAT_14288da78);
    }
    local_440 = &local_4f0;
    plStack_438 = (longlong *)CONCAT71(plStack_438._1_7_,1);
    iVar9 = FUN_140f791f0(local_4f0,0xffffffff);
    if (iVar9 != 0x65) {
      uVar13 = FUN_140f8dd30(param_1[0x16]);
      uVar19 = FUN_1402bcb10(&local_4d8,iVar9);
      uVar23 = FUN_141956310(&local_4b8,param_1 + 0x10);
      uVar23 = FUN_1402baf90(&local_420,"Unable to backup demo db to memory ",uVar23);
      uVar23 = FUN_14029e990(&local_400,uVar23," error(");
      uVar19 = FUN_14029e960(&local_460,uVar23,uVar19);
      uVar19 = FUN_14029e990(local_3e0,uVar19,&DAT_141d8b980);
      FUN_14029e990(local_370,uVar19,uVar13);
      FUN_14029c3e0(local_3e0);
      FUN_14029c3e0(&local_460);
      FUN_14029c3e0(&local_400);
      FUN_14029c3e0(&local_420);
      FUN_14029c3e0(&local_4b8);
      FUN_14029c3e0(&local_4d8);
      FUN_1406e9ad0(local_3a0,0x62,local_370);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_3a0,(ThrowInfo *)&DAT_14288da78);
    }
    puVar17 = (undefined8 *)FUN_140dfd420(param_1,&local_4d8,"PRAGMA foreign_keys = ON");
    local_4b8 = (longlong *******)0x0;
    ppppppplStack_4b0 = (longlong *******)0x0;
    local_4a8 = (undefined8 *)0x0;
    FUN_140e3d380(*puVar17,&local_4b8);
    FUN_140374c10(&local_4b8);
    plVar16 = plStack_4d0;
    if (plStack_4d0 != (longlong *)0x0) {
      LOCK();
      plVar1 = plStack_4d0 + 1;
      lVar14 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + -1;
      UNLOCK();
      if ((int)lVar14 == 1) {
        (**(code **)*plStack_4d0)(plStack_4d0);
        LOCK();
        piVar15 = (int *)((longlong)plVar16 + 0xc);
        iVar9 = *piVar15;
        *piVar15 = *piVar15 + -1;
        UNLOCK();
        if (iVar9 == 1) {
          (**(code **)(*plVar16 + 8))(plVar16);
        }
      }
    }
    FUN_140f79980(local_4f0);
    FUN_140f8ad20(local_4e8);
  }
  ppppppplVar24 = (longlong *******)0x0;
  if (!bVar5) {
    cVar8 = FUN_140dc6930(local_380,param_1 + 0x10);
    if (cVar8 != '\0') {
      FUN_140f73680(param_1[0x16],FUN_140e543f0,param_1);
    }
    FUN_140f73880(param_1[0x16],FUN_140e54720,param_1);
    ppppppplStack_4b0 = &local_380;
    local_4a8 = (undefined8 *)CONCAT71(local_4a8._1_7_,1);
    local_4b8 = param_1;
    local_478 = param_1;
    ppppppplStack_470 = ppppppplStack_4b0;
    iVar9 = std::uncaught_exceptions();
    local_4a8 = (undefined8 *)CONCAT44(iVar9,(undefined4)local_4a8);
    if (local_4f8[0] == '\0') {
      puVar17 = (undefined8 *)FUN_140dfd420(param_1,&local_4d8,"BEGIN IMMEDIATE TRANSACTION");
      local_440 = (undefined8 *)0x0;
      plStack_438 = (undefined8 *)0x0;
      local_430 = 0;
      FUN_140e3d380(*puVar17,&local_440);
      plVar16 = plStack_438;
      puVar17 = local_440;
      if (local_440 != (undefined8 *)0x0) {
        for (; puVar17 != plVar16; puVar17 = puVar17 + 5) {
          FUN_1402a22d0(puVar17);
        }
        puVar17 = local_440;
        if ((0xfff < (ulonglong)(((local_430 - (longlong)local_440) / 0x28) * 0x28)) &&
           (puVar17 = (undefined8 *)local_440[-1],
           0x1f < (ulonglong)((longlong)local_440 + (-8 - (longlong)puVar17)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(puVar17);
        local_440 = (undefined8 *)0x0;
        plStack_438 = (undefined8 *)0x0;
        local_430 = 0;
      }
      if (plStack_4d0 != (longlong *)0x0) {
        LOCK();
        plVar16 = plStack_4d0 + 1;
        lVar14 = *plVar16;
        *(int *)plVar16 = (int)*plVar16 + -1;
        UNLOCK();
        if ((int)lVar14 == 1) {
          (**(code **)*plStack_4d0)(plStack_4d0);
          LOCK();
          piVar15 = (int *)((longlong)plStack_4d0 + 0xc);
          iVar9 = *piVar15;
          *piVar15 = *piVar15 + -1;
          UNLOCK();
          if (iVar9 == 1) {
            (**(code **)(*plStack_4d0 + 8))(plStack_4d0);
          }
        }
      }
      local_4e0 = '\x01';
      local_4e8 = param_1;
      local_4dc = std::uncaught_exceptions();
      puVar18 = (undefined4 *)FUN_140e46c00();
      local_460 = *puVar18;
      uStack_45c = puVar18[1];
      uStack_458 = puVar18[2];
      uStack_454 = puVar18[3];
      local_450 = *(longlong **)(puVar18 + 4);
      uStack_448 = *(undefined8 *)(puVar18 + 6);
      uVar19 = FUN_1402bcb10(local_3e0,puVar18[6] & 0x3fffffff);
      puVar17 = (undefined8 *)FUN_1402bbe30(uVar19,0,"PRAGMA user_version = ",0x16);
      local_440 = (undefined8 *)*puVar17;
      plStack_438 = (longlong *)puVar17[1];
      local_430 = puVar17[2];
      uStack_428 = puVar17[3];
      puVar17[2] = 0;
      puVar17[3] = 0xf;
      *(undefined1 *)puVar17 = 0;
      if ((*param_1)[1] == (longlong *****)FUN_140e54950) {
        cVar8 = FUN_1402b5df0(param_1 + 0x17,5);
      }
      else {
        cVar8 = (*(code *)(*param_1)[1])(param_1);
      }
      if (cVar8 != '\0') {
        FUN_140492f70(local_3a0,100);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_3a0,(ThrowInfo *)&DAT_14288da78);
      }
      ppppppplVar20 = (longlong *******)FUN_141981f80(0xb8);
      ppppppplVar22 = ppppppplVar24;
      if (ppppppplVar20 != (longlong *******)0x0) {
        *ppppppplVar20 = (longlong ******)0x0;
        ppppppplVar20[1] = (longlong ******)0x0;
        *(undefined4 *)(ppppppplVar20 + 1) = 1;
        *(undefined4 *)((longlong)ppppppplVar20 + 0xc) = 1;
        *ppppppplVar20 = (longlong ******)std::_Ref_count_obj2<librarian::StatementSqlite>::vftable;
        local_478 = ppppppplVar20;
        FUN_140e5d580(ppppppplVar20 + 2,param_1,&local_440);
        ppppppplVar22 = ppppppplVar20;
      }
      if (ppppppplVar22 != (longlong *******)0xfffffffffffffff0) {
        ppppppplVar24 = ppppppplVar22 + 0xf;
      }
      local_4d8 = (void *)0x0;
      plStack_4d0 = (void *)0x0;
      local_4c8 = 0;
      local_478 = ppppppplVar24;
      ppppppplStack_470 = ppppppplVar22;
      FUN_140e3d380(0,&local_4d8);
      plVar16 = plStack_4d0;
      pvVar25 = local_4d8;
      if (local_4d8 != (void *)0x0) {
        for (; pvVar25 != plVar16; pvVar25 = (void *)((longlong)pvVar25 + 0x28)) {
          FUN_1402a22d0(pvVar25);
        }
        pvVar25 = local_4d8;
        if ((0xfff < (ulonglong)(((local_4c8 - (longlong)local_4d8) / 0x28) * 0x28)) &&
           (pvVar25 = *(void **)((longlong)local_4d8 + -8),
           0x1f < (ulonglong)((longlong)local_4d8 + (-8 - (longlong)pvVar25)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar25);
        local_4d8 = (void *)0x0;
        plStack_4d0 = (void *)0x0;
        local_4c8 = 0;
      }
      if (ppppppplVar22 != (longlong *******)0x0) {
        LOCK();
        ppppppplVar24 = ppppppplVar22 + 1;
        iVar9 = *(int *)ppppppplVar24;
        *(int *)ppppppplVar24 = *(int *)ppppppplVar24 + -1;
        UNLOCK();
        if (iVar9 == 1) {
          (*(code *)**ppppppplVar22)(ppppppplVar22);
          LOCK();
          piVar15 = (int *)((longlong)ppppppplVar22 + 0xc);
          iVar9 = *piVar15;
          *piVar15 = *piVar15 + -1;
          UNLOCK();
          if (iVar9 == 1) {
            (*(code *)(*ppppppplVar22)[1])(ppppppplVar22);
          }
        }
      }
      if (0xf < uStack_428) {
        puVar17 = local_440;
        if ((0xfff < uStack_428 + 1) &&
           (puVar17 = (undefined8 *)local_440[-1],
           0x1f < (ulonglong)((longlong)local_440 + (-8 - (longlong)puVar17)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(puVar17);
      }
      local_430 = uVar13;
      uStack_428 = uVar6;
      local_440 = (undefined8 *)((ulonglong)local_440 & 0xffffffffffffff00);
      if (0xf < local_3c8) {
        pvVar25 = local_3e0[0];
        if ((0xfff < local_3c8 + 1) &&
           (pvVar25 = *(void **)((longlong)local_3e0[0] + -8),
           0x1f < (ulonglong)((longlong)local_3e0[0] + (-8 - (longlong)pvVar25)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar25);
      }
      plVar16 = local_res10;
      local_4d8 = (void *)CONCAT44(uStack_454,uStack_458);
      plStack_4d0 = local_450;
      uVar11 = FUN_140dd2740(*local_res10);
      FUN_140e610b0(&local_338,&local_4d8,uVar11);
      puVar7 = puStack_330;
      for (puVar17 = local_338; puVar17 != puVar7; puVar17 = puVar17 + 2) {
        local_4d8 = (void *)*puVar17;
        plStack_4d0 = (longlong *)puVar17[1];
        puVar21 = (undefined8 *)FUN_140dfd4e0(param_1,&local_440,&local_4d8);
        local_478 = (longlong *******)0x0;
        ppppppplStack_470 = (longlong *******)0x0;
        local_468 = 0;
        FUN_140e3d380(*puVar21,&local_478);
        ppppppplVar22 = ppppppplStack_470;
        ppppppplVar24 = local_478;
        if (local_478 != (longlong *******)0x0) {
          for (; ppppppplVar24 != ppppppplVar22; ppppppplVar24 = ppppppplVar24 + 5) {
            FUN_1402a22d0(ppppppplVar24);
          }
          ppppppplVar24 = local_478;
          if ((0xfff < (ulonglong)(((local_468 - (longlong)local_478) / 0x28) * 0x28)) &&
             (ppppppplVar24 = (longlong *******)local_478[-1],
             0x1f < (ulonglong)((longlong)local_478 + (-8 - (longlong)ppppppplVar24)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(ppppppplVar24);
          local_478 = (longlong *******)0x0;
          ppppppplStack_470 = (longlong *******)0x0;
          local_468 = 0;
        }
        plVar1 = plStack_438;
        if (plStack_438 != (longlong *)0x0) {
          LOCK();
          plVar2 = plStack_438 + 1;
          lVar14 = *plVar2;
          *(int *)plVar2 = (int)*plVar2 + -1;
          UNLOCK();
          if ((int)lVar14 == 1) {
            (**(code **)*plStack_438)(plStack_438);
            LOCK();
            piVar15 = (int *)((longlong)plVar1 + 0xc);
            iVar9 = *piVar15;
            *piVar15 = *piVar15 + -1;
            UNLOCK();
            if (iVar9 == 1) {
              (**(code **)(*plVar1 + 8))(plVar1);
            }
          }
        }
      }
      FUN_140da7040(local_2a8);
      FUN_140dab140(local_2a8);
      FUN_140dac5a0(local_2a8,local_460);
      iVar9 = FUN_140dac340(local_2a8,param_1);
      if (iVar9 != 0) {
        FUN_140492f70(local_3a0,iVar9);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_3a0,(ThrowInfo *)&DAT_14288da78);
      }
      uVar19 = FUN_140dd3b20(&local_4d8,param_1);
      FUN_140e61350(local_320,&local_338,uVar19);
      if (local_4d8 != (void *)0x0) {
        FUN_14029c160(local_4d8,plStack_4d0,&local_4d8);
        pvVar25 = local_4d8;
        if ((0xfff < (local_4c8 - (longlong)local_4d8 & 0xffffffffffffffe0U)) &&
           (pvVar25 = *(void **)((longlong)local_4d8 + -8),
           0x1f < (ulonglong)((longlong)local_4d8 + (-8 - (longlong)pvVar25)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar25);
        local_4d8 = (void *)0x0;
        plStack_4d0 = (longlong *)0x0;
        local_4c8 = 0;
      }
      if ((local_318 != 0) || (local_300 != 0)) {
        uVar13 = FUN_14029c4c0(local_370);
        uVar13 = FUN_140dbd060(param_1,local_1a8,uVar13);
        uVar13 = FUN_140c886c0(uVar13,"Database creation failure");
        uVar13 = FUN_140c886c0(uVar13,"\nVersion:  ");
        uVar13 = FUN_140e4dcd0(uVar13,&local_460);
        ppppppplVar22 = (longlong *******)FUN_140c886c0(uVar13,"\nPath:     ");
        uVar13 = FUN_1402a2c60(plVar16);
        uVar13 = FUN_140a6f2d0(uVar13);
        uVar13 = FUN_141956400(local_3a0,uVar13);
        uVar13 = FUN_140dacc70(ppppppplVar22,uVar13);
        uVar13 = FUN_140c886c0(uVar13,"\nExpected: ");
        uVar13 = FUN_140e4dd80(uVar13,local_320);
        uVar13 = FUN_140c886c0(uVar13,"\nLocal:    ");
        FUN_140dacc70(uVar13,local_310);
        FUN_14029c3e0(local_3a0);
        FUN_140db5e60(local_1a8);
        FUN_14029c3e0(local_370);
        FUN_140e4e130(&local_res10);
        goto LAB_140e4fa14;
      }
      FUN_14029c3e0(local_310);
      FUN_140da7520(local_2a8);
      if (local_338 != (undefined8 *)0x0) {
        puVar17 = local_338;
        if ((0xfff < (local_328 - (longlong)local_338 & 0xfffffffffffffff0U)) &&
           (puVar17 = (undefined8 *)local_338[-1],
           0x1f < (ulonglong)((longlong)local_338 + (-8 - (longlong)puVar17)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(puVar17);
        local_338 = (undefined8 *)0x0;
        puStack_330 = (undefined8 *)0x0;
        local_328 = 0;
      }
      if ((local_4e0 != '\0') && (iVar9 = std::uncaught_exceptions(), iVar9 <= local_4dc)) {
        FUN_140e51030(&local_4e8);
      }
      if ((char)local_4a8 != '\0') {
        iVar9 = std::uncaught_exceptions();
        if (iVar9 <= local_4a8._4_4_) {
          FUN_140e50d80(&local_4b8);
        }
      }
      if (uStack_3a8 < 0x10) {
LAB_140e4f34c:
        local_3b0 = uVar13;
        uStack_3a8 = uVar6;
        local_3c0 = (undefined8 *******)((ulonglong)local_3c0 & 0xffffffffffffff00);
        if ((char)uStack_480 != '\0') {
          iVar9 = std::uncaught_exceptions();
          if (uStack_480._4_4_ < iVar9) {
            FUN_140e503a0(&local_498);
          }
        }
        FUN_1402a0280(&local_380);
        return param_1;
      }
      pppppppuVar26 = local_3c0;
      if ((uStack_3a8 + 1 < 0x1000) ||
         (pppppppuVar26 = (undefined8 *******)local_3c0[-1],
         (ulonglong)((longlong)local_3c0 + (-8 - (longlong)pppppppuVar26)) < 0x20)) {
        free(pppppppuVar26);
        goto LAB_140e4f34c;
      }
      goto LAB_140e4f340;
    }
    iVar10 = std::uncaught_exceptions();
    if (iVar10 <= iVar9) {
      FUN_140e50d80(&local_4b8);
    }
  }
  if (0xf < uStack_3a8) {
    pppppppuVar26 = local_3c0;
    if ((0xfff < uStack_3a8 + 1) &&
       (pppppppuVar26 = (undefined8 *******)local_3c0[-1],
       0x1f < (ulonglong)((longlong)local_3c0 + (-8 - (longlong)pppppppuVar26)))) {
LAB_140e4f340:
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pppppppuVar26);
  }
  local_3c0 = (undefined8 *******)((ulonglong)local_3c0 & 0xffffffffffffff00);
  local_3b0 = uVar13;
  uStack_3a8 = uVar6;
  if ((char)uStack_480 != '\0') {
    iVar9 = std::uncaught_exceptions();
    if (uStack_480._4_4_ < iVar9) {
      FUN_140e503a0(&local_498);
    }
  }
  if (local_378 != (longlong *)0x0) {
    LOCK();
    plVar16 = local_378 + 1;
    lVar14 = *plVar16;
    *(int *)plVar16 = (int)*plVar16 + -1;
    UNLOCK();
    if ((int)lVar14 == 1) {
      (**(code **)*local_378)(local_378);
      LOCK();
      piVar15 = (int *)((longlong)local_378 + 0xc);
      iVar9 = *piVar15;
      *piVar15 = *piVar15 + -1;
      UNLOCK();
      if (iVar9 == 1) {
        (**(code **)(*local_378 + 8))(local_378);
      }
    }
  }
  return param_1;
}


