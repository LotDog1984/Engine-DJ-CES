// FUN_140429770 @ 140429770
// calls: [CreateFileW]

/* WARNING: Type propagation algorithm not settling */

void FUN_140429770(QObject *param_1,longlong *param_2,longlong *param_3)

{
  int *piVar1;
  longlong *plVar2;
  ExternalRefCountData *pEVar3;
  int *piVar4;
  QObject *pQVar5;
  QObject *pQVar6;
  char cVar7;
  ulonglong uVar8;
  void **ppvVar9;
  code *pcVar10;
  undefined1 *puVar11;
  void *pvVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  void **ppvVar17;
  ulonglong uVar18;
  void **ppvVar19;
  char cVar20;
  char cVar21;
  char cVar22;
  int iVar23;
  longlong lVar24;
  QSlotObjectBase *pQVar25;
  uint *puVar26;
  QString *pQVar27;
  ExternalRefCountData *pEVar28;
  longlong *plVar29;
  undefined8 *puVar30;
  undefined8 uVar31;
  ExternalRefCountData *pEVar32;
  ExternalRefCountData *pEVar33;
  undefined8 *puVar34;
  void *pvVar35;
  undefined1 *puVar36;
  undefined8 *puVar37;
  longlong *plVar38;
  undefined8 *******pppppppuVar39;
  undefined8 *puVar40;
  QSlotObjectBase *pQVar41;
  undefined8 *******pppppppuVar42;
  ulonglong _Size;
  ulonglong uVar43;
  ExternalRefCountData *pEVar44;
  QMetaTypeInterface **in_stack_fffffffffffffc18;
  void **local_3b0;
  void **local_3a8;
  int *local_3a0;
  ExternalRefCountData *local_398;
  ExternalRefCountData *pEStack_390;
  QMetaTypeInterface *local_388 [2];
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_378 [24];
  undefined1 local_360;
  undefined7 uStack_35f;
  ulonglong local_350;
  ulonglong local_348;
  longlong local_340;
  ExternalRefCountData *local_338;
  ExternalRefCountData *pEStack_330;
  undefined *local_328;
  QString local_320 [24];
  undefined1 local_308;
  undefined1 local_307;
  QObject *local_2f8;
  undefined8 uStack_2f0;
  undefined8 local_2e8;
  undefined8 local_2e0;
  ulonglong local_2d8;
  ExternalRefCountData *local_2d0;
  ExternalRefCountData *local_2c8;
  QObject *local_2c0;
  void **local_2b8;
  int *local_2b0;
  longlong local_2a8;
  void **ppvStack_2a0;
  int *local_298;
  ExternalRefCountData *local_290;
  void **local_288;
  int *local_280;
  QString local_278 [24];
  ExternalRefCountData *local_260;
  ExternalRefCountData *local_258;
  undefined8 local_250;
  ExternalRefCountData *local_248;
  ExternalRefCountData *local_240;
  ExternalRefCountData *local_238;
  ExternalRefCountData *local_230;
  undefined8 *******local_228 [3];
  ulonglong local_210;
  undefined8 local_208;
  undefined4 uStack_200;
  undefined4 uStack_1fc;
  code *local_1f8;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  ExternalRefCountData *local_1e8;
  int *local_1e0;
  ExternalRefCountData *local_1d8;
  ExternalRefCountData *local_1d0;
  code *local_1c8;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  ExternalRefCountData *local_1b8;
  int *local_1b0;
  code *local_1a8;
  undefined4 uStack_1a0;
  undefined4 uStack_19c;
  longlong *local_198;
  longlong *local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  longlong *local_170;
  QObject local_168 [8];
  longlong local_160;
  QObject local_158 [8];
  QObject local_150 [8];
  Connection local_148 [8];
  ExternalRefCountData *local_140;
  undefined8 local_138;
  code *local_128;
  undefined4 local_120;
  undefined4 local_11c;
  code *local_118;
  undefined4 local_110;
  undefined4 local_10c;
  int *local_108;
  undefined4 local_fc;
  QObject local_f8 [16];
  Connection local_e8 [16];
  code *local_d8;
  undefined4 uStack_d0;
  uint uStack_cc;
  code *local_c8;
  undefined4 uStack_c0;
  uint uStack_bc;
  QObject *local_b8;
  ExternalRefCountData *local_b0;
  code *local_a8;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined8 local_98;
  char *pcStack_90;
  code *local_88;
  undefined4 uStack_80;
  uint uStack_7c;
  ExternalRefCountData *local_78;
  char *pcStack_70;
  undefined1 local_60 [8];
  undefined1 local_58 [8];
  ExternalRefCountData *local_50;
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  
  pEVar44 = (ExternalRefCountData *)0x0;
  bVar16 = false;
  bVar15 = false;
  bVar14 = false;
  FUN_1403888a0(param_1 + 0x138,&local_3b0);
  if (local_3b0 != (void **)0x0) {
    FUN_1403b9bd0(local_3b0,&local_340);
    if (local_340 != 0) {
      if (*param_2 != param_2[1]) {
        local_160 = FUN_14130f3e0();
        cVar7 = *(char *)(local_160 + 0x2e8);
        plVar38 = (longlong *)*param_2;
        local_170 = (longlong *)param_2[1];
        while (plVar38 != local_170) {
          if (*plVar38 == 0) {
LAB_140429e0a:
            plVar38 = plVar38 + 2;
          }
          else {
            FUN_140831290(*plVar38,&local_360);
            QString::fromStdString(local_378);
            FUN_14047b450(*(undefined8 *)(param_1 + 0x398),local_278,local_378);
            cVar20 = FUN_1403b9650(local_3b0,local_378);
            cVar21 = FUN_1413c4610(*(undefined8 *)(param_1 + 0x588),local_378);
            cVar22 = FUN_1413c47e0(*(undefined8 *)(param_1 + 0x588),local_378);
            if ((((cVar20 == '\0') || (cVar7 == '\0')) || (cVar21 != '\0')) || (cVar22 != '\0')) {
              FUN_140dda630(*plVar38,local_228,&DAT_1428fed00);
              local_188 = 0;
              uStack_180 = 0;
              local_178 = 0;
              if ((cVar20 == '\0') ||
                 (puVar26 = (uint *)FUN_141974de0(local_40,local_228,&local_188), 1 < *puVar26)) {
                if ((cVar7 == '\0') && (cVar21 = FUN_1406b7090(*plVar38), cVar21 == '\0')) {
                  pppppppuVar42 = local_228;
                  if (7 < local_210) {
                    pppppppuVar42 = local_228[0];
                  }
                  lVar24 = FUN_14196f640(local_228);
                  pppppppuVar42 = (undefined8 *******)((longlong)pppppppuVar42 + lVar24 * 2);
                  pppppppuVar39 = local_228;
                  if (7 < local_210) {
                    pppppppuVar39 = local_228[0];
                  }
                  local_2f8 = (QObject *)0x0;
                  uStack_2f0 = 0;
                  local_2e8 = 0;
                  local_2e0 = 0;
                  if (pppppppuVar39 == pppppppuVar42) {
                    local_2e8 = 0;
                    local_2e0 = 7;
                    local_2f8 = (QObject *)0x0;
                  }
                  else {
                    FUN_1402a7200(&local_2f8,pppppppuVar39,
                                  (longlong)pppppppuVar42 - (longlong)pppppppuVar39 >> 1);
                  }
                  bVar14 = true;
                  puVar26 = (uint *)FUN_141974de0(local_48,&local_2f8,0);
                  if (*puVar26 < 2) goto LAB_140429c4f;
                }
                bVar13 = false;
              }
              else {
LAB_140429c4f:
                bVar13 = true;
              }
              if (bVar14) {
                bVar14 = false;
                FUN_1402a29e0(&local_2f8);
              }
              uVar43 = local_348;
              uVar18 = local_350;
              if (bVar13) {
                puVar34 = *(undefined8 **)(param_1 + 0x5b0);
                puVar40 = (undefined8 *)puVar34[1];
                puVar11 = (undefined1 *)CONCAT71(uStack_35f,local_360);
                cVar20 = *(char *)((longlong)puVar40 + 0x19);
                while (cVar20 == '\0') {
                  puVar37 = puVar40 + 4;
                  puVar36 = &local_360;
                  if (0xf < uVar43) {
                    puVar36 = puVar11;
                  }
                  uVar8 = puVar40[6];
                  if (0xf < (ulonglong)puVar40[7]) {
                    puVar37 = (undefined8 *)*puVar37;
                  }
                  _Size = uVar8;
                  if (uVar18 < uVar8) {
                    _Size = uVar18;
                  }
                  iVar23 = memcmp(puVar37,puVar36,_Size);
                  if (iVar23 == 0) {
                    if (uVar8 < uVar18) goto LAB_140429dc5;
LAB_140429cdf:
                    puVar37 = (undefined8 *)*puVar40;
                    puVar34 = puVar40;
                  }
                  else {
                    if (-1 < iVar23) goto LAB_140429cdf;
LAB_140429dc5:
                    puVar37 = (undefined8 *)puVar40[2];
                  }
                  puVar40 = puVar37;
                  cVar20 = *(char *)((longlong)puVar37 + 0x19);
                }
                if (*(char *)((longlong)puVar34 + 0x19) == '\0') {
                  puVar40 = puVar34 + 4;
                  uVar8 = puVar34[6];
                  if (0xf < (ulonglong)puVar34[7]) {
                    puVar40 = (undefined8 *)*puVar40;
                  }
                  puVar36 = &local_360;
                  if (0xf < uVar43) {
                    puVar36 = puVar11;
                  }
                  uVar43 = uVar18;
                  if (uVar8 < uVar18) {
                    uVar43 = uVar8;
                  }
                  iVar23 = memcmp(puVar36,puVar40,uVar43);
                  if (iVar23 == 0) {
                    if (uVar8 <= uVar18) goto LAB_140429dd7;
                  }
                  else if (-1 < iVar23) {
LAB_140429dd7:
                    FUN_1404281e0(param_1,&local_360,3);
                  }
                }
                FUN_1403b1e60(local_3b0,local_378,1);
                FUN_1402a29e0(local_228);
                QString::~QString(local_278);
                QString::~QString((QString *)local_378);
                if (0xf < local_348) {
                  pvVar12 = (void *)CONCAT71(uStack_35f,local_360);
                  pvVar35 = pvVar12;
                  if ((0xfff < local_348 + 1) &&
                     (pvVar35 = *(void **)((longlong)pvVar12 + -8),
                     0x1f < (ulonglong)((longlong)pvVar12 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
                    _invalid_parameter_noinfo_noreturn();
                  }
                  free(pvVar35);
                }
                goto LAB_140429e0a;
              }
              FUN_1402a29e0(local_228);
              local_398 = (ExternalRefCountData *)CONCAT44(local_398._4_4_,0x6e);
              local_78 = (ExternalRefCountData *)0x12;
              pEStack_330 = (ExternalRefCountData *)
                            QByteArrayView::castHelper("Preparing device \'");
              local_338 = local_78;
              pcStack_70 = (char *)pEStack_330;
              QString::fromUtf8(&local_188,&local_338);
              QString::append((QString *)&local_188,local_278);
              pQVar27 = QString::operator+=((QString *)&local_188,"\'");
              QString::QString((QString *)&local_2f8,pQVar27);
              FUN_140410ce0(&local_3a8,&local_2f8,&local_398);
              QString::~QString((QString *)&local_2f8);
              QString::~QString((QString *)&local_188);
              FUN_140bdf410(local_3a8,2);
              pQVar6 = param_1 + 0x140;
              pEVar28 = (ExternalRefCountData *)FUN_141981f80(0x188);
              pEVar33 = pEVar44;
              local_50 = pEVar28;
              if (pEVar28 != (ExternalRefCountData *)0x0) {
                *(longlong *)pEVar28 = 0;
                *(longlong *)(pEVar28 + 8) = 0;
                *(undefined4 *)(pEVar28 + 8) = 1;
                *(undefined4 *)(pEVar28 + 0xc) = 1;
                *(undefined ***)pEVar28 = std::_Ref_count_obj2<MigrateDatabaseJob>::vftable;
                FUN_1406864f0(pEVar28 + 0x10,local_278,pQVar6,plVar38,cVar20);
                pEVar33 = pEVar28;
              }
              pEVar28 = pEVar33 + 0x10;
              local_2d0 = pEVar28;
              local_2c8 = pEVar33;
              plVar29 = (longlong *)FUN_140dc3420(*(undefined8 *)pQVar6);
              local_208 = FUN_140686760;
              uStack_200 = 0;
              uStack_1fc = local_fc;
              if (pEVar28 != (ExternalRefCountData *)0x0) {
                local_2d8 = __std_type_info_hash(0x14295b168);
                plVar2 = plVar29 + 2;
                local_398 = pEVar28;
                iVar23 = _Mtx_lock(plVar2);
                if (iVar23 != 0) {
                    /* WARNING: Subroutine does not return */
                  std::_Throw_Cpp_error(5);
                }
                if (*(int *)((longlong)plVar29 + 0x5c) == 0x7fffffff) {
                  *(undefined4 *)((longlong)plVar29 + 0x5c) = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
                  std::_Throw_Cpp_error(6);
                }
                puVar34 = (undefined8 *)*plVar29;
                cVar21 = *(char *)((longlong)puVar34[1] + 0x19);
                puVar40 = puVar34;
                puVar37 = (undefined8 *)puVar34[1];
                while (cVar21 == '\0') {
                  if ((ulonglong)puVar37[4] < local_2d8) {
                    puVar30 = (undefined8 *)puVar37[2];
                    puVar37 = puVar40;
                  }
                  else {
                    puVar30 = (undefined8 *)*puVar37;
                  }
                  puVar40 = puVar37;
                  puVar37 = puVar30;
                  cVar21 = *(char *)((longlong)puVar30 + 0x19);
                }
                if (((*(char *)((longlong)puVar40 + 0x19) == '\0') &&
                    ((ulonglong)puVar40[4] <= local_2d8)) && (puVar40 != puVar34)) {
                  FUN_14036fc50(puVar40 + 5,&local_198,&local_398);
                  plVar29 = local_198;
                  if (local_198 != local_190) {
                    do {
                      lVar24 = plVar29[3];
                      if (lVar24 == 0) {
LAB_14042a0c4:
                        bVar13 = false;
                      }
                      else {
                        local_260 = (ExternalRefCountData *)0x0;
                        if (pEVar33 != (ExternalRefCountData *)0x0) {
                          LOCK();
                          *(int *)(pEVar33 + 0xc) = *(int *)(pEVar33 + 0xc) + 1;
                          UNLOCK();
                          local_260 = pEVar33;
                        }
                        bVar15 = true;
                        if (((*(code **)(lVar24 + 0x18) != FUN_140686760) ||
                            (*(int *)(lVar24 + 0x20) != 0)) ||
                           ((local_260 < *(ExternalRefCountData **)(lVar24 + 0x10) ||
                            (*(ExternalRefCountData **)(lVar24 + 0x10) < local_260))))
                        goto LAB_14042a0c4;
                        bVar13 = true;
                      }
                      if ((bVar15) && (bVar15 = false, local_260 != (ExternalRefCountData *)0x0)) {
                        LOCK();
                        pEVar28 = local_260 + 0xc;
                        iVar23 = *(int *)pEVar28;
                        *(int *)pEVar28 = *(int *)pEVar28 + -1;
                        UNLOCK();
                        if (iVar23 == 1) {
                          (**(code **)(*(longlong *)local_260 + 8))(local_260);
                        }
                      }
                      if (bVar13) {
                        _Mtx_unlock(plVar2);
                        goto LAB_14042a356;
                      }
                      plVar29 = (longlong *)*plVar29;
                    } while (plVar29 != local_190);
                  }
                  pEVar28 = (ExternalRefCountData *)FUN_141981f80(0x38);
                  local_230 = pEVar44;
                  if (pEVar28 != (ExternalRefCountData *)0x0) {
                    *(longlong *)pEVar28 = 0;
                    *(longlong *)(pEVar28 + 8) = 0;
                    *(undefined4 *)(pEVar28 + 8) = 1;
                    *(undefined4 *)(pEVar28 + 0xc) = 1;
                    *(undefined ***)pEVar28 =
                         std::
                         _Ref_count_obj2<air::Notifier::Handler<MigrateDatabaseJob,librarian::DatabaseMigrationNotification::Progress>_>
                         ::vftable;
                    *(undefined ***)(pEVar28 + 0x10) =
                         air::Notifier::
                         Handler<MigrateDatabaseJob,librarian::DatabaseMigrationNotification::Progress>
                         ::vftable;
                    *(longlong *)(pEVar28 + 0x18) = 0;
                    *(longlong *)(pEVar28 + 0x20) = 0;
                    if (pEVar33 != (ExternalRefCountData *)0x0) {
                      *(ExternalRefCountData **)(pEVar28 + 0x18) = local_2d0;
                      *(ExternalRefCountData **)(pEVar28 + 0x20) = pEVar33;
                      LOCK();
                      *(int *)(pEVar33 + 0xc) = *(int *)(pEVar33 + 0xc) + 1;
                      UNLOCK();
                    }
                    *(undefined4 *)(pEVar28 + 0x28) = (undefined4)local_208;
                    *(undefined4 *)(pEVar28 + 0x2c) = local_208._4_4_;
                    *(undefined4 *)(pEVar28 + 0x30) = uStack_200;
                    *(undefined4 *)(pEVar28 + 0x34) = uStack_1fc;
                    local_230 = pEVar28;
                  }
                  local_238 = local_230 + 0x10;
                  FUN_140411060(puVar40 + 5,local_58,local_190,&local_398,&local_238);
                  pEVar28 = local_230;
                  if (local_230 != (ExternalRefCountData *)0x0) {
                    LOCK();
                    pEVar32 = local_230 + 8;
                    iVar23 = *(int *)pEVar32;
                    *(int *)pEVar32 = *(int *)pEVar32 + -1;
                    UNLOCK();
                    if (iVar23 == 1) {
                      (*(code *)**(undefined8 **)local_230)(local_230);
                      LOCK();
                      pEVar28 = pEVar28 + 0xc;
                      iVar23 = *(int *)pEVar28;
                      *(int *)pEVar28 = *(int *)pEVar28 + -1;
                      UNLOCK();
                      pEVar28 = local_230;
joined_r0x00014042a33d:
                      if (iVar23 == 1) {
                        (**(code **)(*(longlong *)pEVar28 + 8))();
                      }
                    }
                  }
                }
                else {
                  uVar31 = FUN_140375d80(plVar29,&local_2d8);
                  pEVar28 = (ExternalRefCountData *)FUN_141981f80(0x38);
                  local_240 = pEVar44;
                  if (pEVar28 != (ExternalRefCountData *)0x0) {
                    *(longlong *)pEVar28 = 0;
                    *(longlong *)(pEVar28 + 8) = 0;
                    *(undefined4 *)(pEVar28 + 8) = 1;
                    *(undefined4 *)(pEVar28 + 0xc) = 1;
                    *(undefined ***)pEVar28 =
                         std::
                         _Ref_count_obj2<air::Notifier::Handler<MigrateDatabaseJob,librarian::DatabaseMigrationNotification::Progress>_>
                         ::vftable;
                    *(undefined ***)(pEVar28 + 0x10) =
                         air::Notifier::
                         Handler<MigrateDatabaseJob,librarian::DatabaseMigrationNotification::Progress>
                         ::vftable;
                    *(longlong *)(pEVar28 + 0x18) = 0;
                    *(longlong *)(pEVar28 + 0x20) = 0;
                    if (pEVar33 != (ExternalRefCountData *)0x0) {
                      *(ExternalRefCountData **)(pEVar28 + 0x18) = local_2d0;
                      *(ExternalRefCountData **)(pEVar28 + 0x20) = pEVar33;
                      LOCK();
                      *(int *)(pEVar33 + 0xc) = *(int *)(pEVar33 + 0xc) + 1;
                      UNLOCK();
                    }
                    *(undefined4 *)(pEVar28 + 0x28) = (undefined4)local_208;
                    *(undefined4 *)(pEVar28 + 0x2c) = local_208._4_4_;
                    *(undefined4 *)(pEVar28 + 0x30) = uStack_200;
                    *(undefined4 *)(pEVar28 + 0x34) = uStack_1fc;
                    local_240 = pEVar28;
                  }
                  local_248 = local_240 + 0x10;
                  local_398 = local_2d0;
                  FUN_140410e40(uVar31,local_60,&local_398,&local_248);
                  pEVar28 = local_240;
                  if (local_240 != (ExternalRefCountData *)0x0) {
                    LOCK();
                    pEVar32 = local_240 + 8;
                    iVar23 = *(int *)pEVar32;
                    *(int *)pEVar32 = *(int *)pEVar32 + -1;
                    UNLOCK();
                    if (iVar23 == 1) {
                      (*(code *)**(undefined8 **)local_240)(local_240);
                      LOCK();
                      pEVar28 = pEVar28 + 0xc;
                      iVar23 = *(int *)pEVar28;
                      *(int *)pEVar28 = *(int *)pEVar28 + -1;
                      UNLOCK();
                      pEVar28 = local_240;
                      goto joined_r0x00014042a33d;
                    }
                  }
                }
                _Mtx_unlock(plVar2);
              }
LAB_14042a356:
              local_1f8 = FUN_140427cf0;
              uStack_1f0 = 0xfffffff0;
              uStack_1ec = 0;
              local_d8 = FUN_140bdc890;
              uStack_d0 = 0;
              local_338 = (ExternalRefCountData *)FUN_140bdc890;
              pEStack_330 = (ExternalRefCountData *)((ulonglong)uStack_cc << 0x20);
              pEVar32 = (ExternalRefCountData *)FUN_141981f80(0x20);
              pEVar28 = pEVar44;
              if (pEVar32 != (ExternalRefCountData *)0x0) {
                *(undefined4 *)pEVar32 = 1;
                *(code **)(pEVar32 + 8) = FUN_140380400;
                *(code **)(pEVar32 + 0x10) = local_1f8;
                *(longlong *)(pEVar32 + 0x18) = CONCAT44(uStack_1ec,uStack_1f0);
                pEVar28 = pEVar32;
              }
              in_stack_fffffffffffffc18 =
                   (QMetaTypeInterface **)
                   ((ulonglong)in_stack_fffffffffffffc18 & 0xffffffff00000000);
              QObject::connectImpl
                        (local_168,(void **)local_2d0,(QObject *)&local_338,(void **)param_1,
                         (QSlotObjectBase *)&local_1f8,(ConnectionType)pEVar28,
                         (int *)in_stack_fffffffffffffc18,(QMetaObject *)0x0);
              QMetaObject::Connection::~Connection((Connection *)local_168);
              ppvVar17 = local_3a8;
              if (pEVar33 != (ExternalRefCountData *)0x0) {
                LOCK();
                *(int *)(pEVar33 + 8) = *(int *)(pEVar33 + 8) + 1;
                UNLOCK();
              }
              local_338 = local_2d0;
              local_258 = local_2d0;
              if (pEVar33 != (ExternalRefCountData *)0x0) {
                LOCK();
                *(int *)(pEVar33 + 8) = *(int *)(pEVar33 + 8) + 1;
                UNLOCK();
              }
              local_398 = local_2d0;
              pEStack_390 = pEVar33;
              pEStack_330 = pEVar33;
              FUN_140411440(&local_258,local_2d0,&local_398);
              pEVar32 = pEStack_330;
              if (pEStack_330 != (ExternalRefCountData *)0x0) {
                LOCK();
                pEVar3 = pEStack_330 + 8;
                iVar23 = *(int *)pEVar3;
                *(int *)pEVar3 = *(int *)pEVar3 + -1;
                UNLOCK();
                if (iVar23 == 1) {
                  (*(code *)**(undefined8 **)pEStack_330)(pEStack_330);
                  LOCK();
                  pEVar3 = pEVar32 + 0xc;
                  iVar23 = *(int *)pEVar3;
                  *(int *)pEVar3 = *(int *)pEVar3 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    (**(code **)(*(longlong *)pEVar32 + 8))(pEVar32);
                  }
                }
              }
              local_140 = local_258 + 0xe0;
              if (local_258 == (ExternalRefCountData *)0x0) {
                local_140 = pEVar44;
              }
              local_138 = local_250;
              local_250 = 0;
              local_258 = (ExternalRefCountData *)0x0;
              FUN_140be0730(ppvVar17,&local_140,99);
              if (pEVar33 != (ExternalRefCountData *)0x0) {
                LOCK();
                pEVar32 = pEVar33 + 8;
                iVar23 = *(int *)pEVar32;
                *(int *)pEVar32 = *(int *)pEVar32 + -1;
                UNLOCK();
                if (iVar23 == 1) {
                  (*(code *)**(undefined8 **)pEVar33)(pEVar33);
                  LOCK();
                  pEVar32 = pEVar33 + 0xc;
                  iVar23 = *(int *)pEVar32;
                  *(int *)pEVar32 = *(int *)pEVar32 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    (**(code **)(*(longlong *)pEVar33 + 8))(pEVar33);
                  }
                }
              }
              if (*(char *)(local_160 + 0x288) != '\0') {
                FUN_140410c00(&local_288,plVar38,pQVar6,&local_3b0);
                piVar1 = local_280;
                ppvVar19 = local_288;
                ppvVar17 = local_3b0;
                local_2b8 = local_288;
                local_2b0 = local_280;
                if (local_280 != (int *)0x0) {
                  LOCK();
                  *local_280 = *local_280 + 1;
                  UNLOCK();
                  LOCK();
                  local_280[1] = local_280[1] + 1;
                  UNLOCK();
                }
                local_2a8 = 0;
                ppvStack_2a0 = (void **)0x0;
                ppvVar9 = (void **)param_3[1];
                if (ppvVar9 != (void **)0x0) {
                  local_2a8 = *param_3;
                  LOCK();
                  *(int *)((longlong)ppvVar9 + 0xc) = *(int *)((longlong)ppvVar9 + 0xc) + 1;
                  UNLOCK();
                  ppvStack_2a0 = ppvVar9;
                }
                if (plVar38[1] != 0) {
                  LOCK();
                  piVar4 = (int *)(plVar38[1] + 8);
                  *piVar4 = *piVar4 + 1;
                  UNLOCK();
                }
                piVar4 = (int *)*plVar38;
                pEVar33 = (ExternalRefCountData *)plVar38[1];
                local_c8 = FUN_140bdc890;
                uStack_c0 = 0;
                local_338 = (ExternalRefCountData *)FUN_140bdc890;
                pEStack_330 = (ExternalRefCountData *)((ulonglong)uStack_bc << 0x20);
                local_2c0 = param_1;
                local_298 = piVar4;
                local_290 = pEVar33;
                pEVar32 = (ExternalRefCountData *)FUN_141981f80(0x48);
                pEVar28 = pEVar44;
                if (pEVar32 != (ExternalRefCountData *)0x0) {
                  *(undefined4 *)pEVar32 = 1;
                  *(code **)(pEVar32 + 8) = FUN_140423750;
                  *(QObject **)(pEVar32 + 0x10) = param_1;
                  *(void ***)(pEVar32 + 0x18) = local_2b8;
                  *(int **)(pEVar32 + 0x20) = piVar1;
                  if (piVar1 != (int *)0x0) {
                    LOCK();
                    *piVar1 = *piVar1 + 1;
                    UNLOCK();
                    LOCK();
                    *(int *)(*(longlong *)(pEVar32 + 0x20) + 4) =
                         *(int *)(*(longlong *)(pEVar32 + 0x20) + 4) + 1;
                    UNLOCK();
                  }
                  *(longlong *)(pEVar32 + 0x28) = 0;
                  *(longlong *)(pEVar32 + 0x30) = 0;
                  if (ppvStack_2a0 != (void **)0x0) {
                    *(longlong *)(pEVar32 + 0x28) = local_2a8;
                    *(void ***)(pEVar32 + 0x30) = ppvStack_2a0;
                    LOCK();
                    *(int *)((longlong)ppvStack_2a0 + 0xc) =
                         *(int *)((longlong)ppvStack_2a0 + 0xc) + 1;
                    UNLOCK();
                  }
                  *(longlong *)(pEVar32 + 0x38) = 0;
                  *(longlong *)(pEVar32 + 0x40) = 0;
                  if (pEVar33 != (ExternalRefCountData *)0x0) {
                    LOCK();
                    *(int *)(pEVar33 + 8) = *(int *)(pEVar33 + 8) + 1;
                    UNLOCK();
                  }
                  *(int **)(pEVar32 + 0x38) = piVar4;
                  *(ExternalRefCountData **)(pEVar32 + 0x40) = local_290;
                  pEVar28 = pEVar32;
                }
                in_stack_fffffffffffffc18 =
                     (QMetaTypeInterface **)
                     ((ulonglong)in_stack_fffffffffffffc18 & 0xffffffff00000000);
                QObject::connectImpl
                          (local_158,ppvVar19,(QObject *)&local_338,ppvVar17,(QSlotObjectBase *)0x0,
                           (ConnectionType)pEVar28,(int *)in_stack_fffffffffffffc18,
                           (QMetaObject *)0x0);
                QMetaObject::Connection::~Connection((Connection *)local_158);
                pcVar10 = *(code **)((longlong)local_3a8[0x1c] + 0xc0);
                local_1e8 = (ExternalRefCountData *)(local_288 + 0x1c);
                if (local_288 == (void **)0x0) {
                  local_1e8 = pEVar44;
                }
                local_1e0 = local_280;
                if (local_280 != (int *)0x0) {
                  LOCK();
                  *local_280 = *local_280 + 1;
                  UNLOCK();
                  LOCK();
                  local_280[1] = local_280[1] + 1;
                  UNLOCK();
                }
                (*pcVar10)(local_3a8 + 0x1c,&local_1e8);
                FUN_1404164a0(&local_2c0);
                piVar1 = local_280;
                if (local_280 != (int *)0x0) {
                  LOCK();
                  piVar4 = local_280 + 1;
                  iVar23 = *piVar4;
                  *piVar4 = *piVar4 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    (**(code **)(local_280 + 2))(local_280);
                  }
                  LOCK();
                  iVar23 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    free(piVar1);
                  }
                }
              }
              if (cVar7 == '\0') {
                pEVar33 = (ExternalRefCountData *)FUN_141981f80(0x188);
                if (pEVar33 != (ExternalRefCountData *)0x0) {
                  *(undefined8 *)pEVar33 = 0;
                  *(code **)(pEVar33 + 8) = _guard_check_icall;
                  *(undefined4 *)(pEVar33 + 4) = 1;
                  *(undefined4 *)pEVar33 = 1;
                }
                pQVar5 = (QObject *)(pEVar33 + 0x10);
                local_b0 = pEVar33;
                FUN_14067c640(pQVar5,pQVar6,plVar38,local_278);
                *(code **)(pEVar33 + 8) = FUN_1402ae110;
                local_b8 = pQVar5;
                QtSharedPointer::ExternalRefCountData::setQObjectShared(pEVar33,pQVar5,true);
                pEVar28 = pEVar33 + 0x100;
                if (pQVar5 == (QObject *)0x0) {
                  pEVar28 = pEVar44;
                }
                FUN_1402a8dc0(&local_b8,pEVar28);
                local_1a8 = FUN_140429330;
                uStack_1a0 = 0xfffffff0;
                uStack_19c = 0;
                local_a8 = FUN_140bdc890;
                uStack_a0 = 0;
                local_338 = (ExternalRefCountData *)FUN_140bdc890;
                pEStack_330 = (ExternalRefCountData *)((ulonglong)uStack_9c << 0x20);
                pEVar32 = (ExternalRefCountData *)FUN_141981f80(0x20);
                pEVar28 = pEVar44;
                if (pEVar32 != (ExternalRefCountData *)0x0) {
                  *(undefined4 *)pEVar32 = 1;
                  *(code **)(pEVar32 + 8) = FUN_140380400;
                  *(code **)(pEVar32 + 0x10) = local_1a8;
                  *(longlong *)(pEVar32 + 0x18) = CONCAT44(uStack_19c,uStack_1a0);
                  pEVar28 = pEVar32;
                }
                in_stack_fffffffffffffc18 =
                     (QMetaTypeInterface **)
                     ((ulonglong)in_stack_fffffffffffffc18 & 0xffffffff00000000);
                QObject::connectImpl
                          (local_150,(void **)pQVar5,(QObject *)&local_338,(void **)param_1,
                           (QSlotObjectBase *)&local_1a8,(ConnectionType)pEVar28,
                           (int *)in_stack_fffffffffffffc18,(QMetaObject *)0x0);
                QMetaObject::Connection::~Connection((Connection *)local_150);
                local_1d8 = pEVar33 + 0xf0;
                if (pQVar5 == (QObject *)0x0) {
                  local_1d8 = pEVar44;
                }
                LOCK();
                *(int *)pEVar33 = *(int *)pEVar33 + 1;
                UNLOCK();
                LOCK();
                *(int *)(pEVar33 + 4) = *(int *)(pEVar33 + 4) + 1;
                UNLOCK();
                local_1d0 = pEVar33;
                FUN_140be0730(local_3a8,&local_1d8,1);
                LOCK();
                pEVar32 = pEVar33 + 4;
                iVar23 = *(int *)pEVar32;
                *(int *)pEVar32 = *(int *)pEVar32 + -1;
                UNLOCK();
                if (iVar23 == 1) {
                  if (*(code **)(pEVar33 + 8) == FUN_1402ae110) {
                    (**(code **)(*(longlong *)pQVar5 + 0x18))(pQVar5,0);
                  }
                  else {
                    (**(code **)(pEVar33 + 8))(pEVar33);
                  }
                }
                LOCK();
                iVar23 = *(int *)pEVar33;
                *(int *)pEVar33 = *(int *)pEVar33 + -1;
                UNLOCK();
                if (iVar23 == 1) {
                  free(pEVar33);
                }
              }
              if (cVar20 == '\0') {
                local_98 = 0xd;
                pcStack_90 = "noPromptForDb";
                local_338 = (ExternalRefCountData *)&DAT_0000000d;
                pEStack_330 = (ExternalRefCountData *)0x141d323b8;
                QString::QString((QString *)&local_398,&local_338);
                bVar16 = true;
                cVar20 = FUN_1412cef60(&local_398);
                if (cVar20 != '\0') goto LAB_14042aae2;
                bVar13 = true;
              }
              else {
LAB_14042aae2:
                bVar13 = false;
              }
              if (bVar16) {
                bVar16 = false;
                QString::~QString((QString *)&local_398);
              }
              if ((bVar13) && (cVar20 = FUN_140ddb890(*plVar38), cVar20 != '\0')) {
                pEVar33 = pEVar44;
                if (local_340 != 0) {
                  puVar34 = (undefined8 *)
                            (**(code **)(*(longlong *)
                                          ((longlong)*(int *)(*(longlong *)(local_340 + 0x18) + 4) +
                                          local_340 + 0x18) + 8))();
                  pEVar33 = (ExternalRefCountData *)*puVar34;
                  if (pEVar33 != (ExternalRefCountData *)0x0) {
                    FUN_14197ebf0(pEVar33);
                  }
                }
                local_2c0 = param_1;
                QString::QString((QString *)&local_2b8,(QString *)local_378);
                ppvStack_2a0 = local_3a8;
                local_298 = local_3a0;
                if (local_3a0 != (int *)0x0) {
                  LOCK();
                  *local_3a0 = *local_3a0 + 1;
                  UNLOCK();
                  LOCK();
                  local_3a0[1] = local_3a0[1] + 1;
                  UNLOCK();
                }
                local_290 = pEVar33;
                QString::QString((QString *)&local_338,(QString *)local_378);
                QString::QString(local_320,local_278);
                local_308 = FUN_140ddba30(*plVar38);
                local_307 = FUN_14047e380(*(undefined8 *)(param_1 + 0x398),local_378);
                if (cVar7 == '\0') {
                  local_118 = FUN_14036bb90;
                  local_110 = 0xfffffff0;
                  local_10c = 0;
                  FUN_140410880(local_e8,param_1,&local_118,local_3a8,&local_2c0,
                                (ulonglong)pEVar28 & 0xffffffff00000000);
                  QMetaObject::Connection::~Connection(local_e8);
                  FUN_14036bbd0(param_1,&local_338);
                }
                else {
                  local_128 = FUN_140321a40;
                  local_120 = 0xfffffff0;
                  local_11c = 0;
                  FUN_140410880(local_148,param_1,&local_128,local_3a8,&local_2c0,
                                (ulonglong)pEVar28 & 0xffffffff00000000);
                  QMetaObject::Connection::~Connection(local_148);
                  FUN_140321a80(param_1,&local_338);
                }
                QString::~QString(local_320);
                QString::~QString((QString *)&local_338);
                FUN_140416550(&local_2c0);
                piVar1 = local_3a0;
                if (local_3a0 != (int *)0x0) {
                  LOCK();
                  piVar4 = local_3a0 + 1;
                  iVar23 = *piVar4;
                  *piVar4 = *piVar4 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    if (*(code **)(local_3a0 + 2) == FUN_1402ae110) {
                      (**(code **)(*(longlong *)(local_3a0 + 4) + 0x18))(local_3a0 + 4,0);
                    }
                    else {
                      (**(code **)(local_3a0 + 2))(local_3a0);
                    }
                  }
                  LOCK();
                  iVar23 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    free(piVar1);
                  }
                }
                QString::~QString(local_278);
                QString::~QString((QString *)local_378);
                if (0xf < local_348) {
                  pvVar12 = (void *)CONCAT71(uStack_35f,local_360);
                  pvVar35 = pvVar12;
                  if ((0xfff < local_348 + 1) &&
                     (pvVar35 = *(void **)((longlong)pvVar12 + -8),
                     0x1f < (ulonglong)((longlong)pvVar12 + (-8 - (longlong)pvVar35)))) {
                    /* WARNING: Subroutine does not return */
                    _invalid_parameter_noinfo_noreturn();
                  }
                  free(pvVar35);
                }
                local_350 = 0;
                local_348 = 0xf;
                local_360 = 0;
              }
              else {
                ppvVar17 = local_3a8;
                if (cVar7 == '\0') {
                  local_1c8 = FUN_1404289e0;
                  uStack_1c0 = 0xfffffff0;
                  uStack_1bc = 0;
                  local_88 = FUN_140bdc890;
                  uStack_80 = 0;
                  local_338 = (ExternalRefCountData *)FUN_140bdc890;
                  pEStack_330 = (ExternalRefCountData *)((ulonglong)uStack_7c << 0x20);
                  pEVar28 = (ExternalRefCountData *)FUN_141981f80(0x20);
                  pEVar33 = pEVar44;
                  if (pEVar28 != (ExternalRefCountData *)0x0) {
                    *(undefined4 *)pEVar28 = 1;
                    *(code **)(pEVar28 + 8) = FUN_140380400;
                    *(code **)(pEVar28 + 0x10) = local_1c8;
                    *(longlong *)(pEVar28 + 0x18) = CONCAT44(uStack_1bc,uStack_1c0);
                    pEVar33 = pEVar28;
                  }
                  in_stack_fffffffffffffc18 =
                       (QMetaTypeInterface **)
                       ((ulonglong)in_stack_fffffffffffffc18 & 0xffffffff00000000);
                  QObject::connectImpl
                            (local_f8,ppvVar17,(QObject *)&local_338,(void **)param_1,
                             (QSlotObjectBase *)&local_1c8,(ConnectionType)pEVar33,
                             (int *)in_stack_fffffffffffffc18,(QMetaObject *)0x0);
                  QMetaObject::Connection::~Connection((Connection *)local_f8);
                  LOCK();
                  *(int *)(param_1 + 0x5c4) = *(int *)(param_1 + 0x5c4) + 1;
                  UNLOCK();
                }
                local_1b8 = (ExternalRefCountData *)(local_3a8 + 0x1c);
                if (local_3a8 == (void **)0x0) {
                  local_1b8 = pEVar44;
                }
                local_1b0 = local_3a0;
                if (local_3a0 != (int *)0x0) {
                  LOCK();
                  *local_3a0 = *local_3a0 + 1;
                  UNLOCK();
                  LOCK();
                  local_3a0[1] = local_3a0[1] + 1;
                  UNLOCK();
                }
                FUN_140bd7dc0(local_340,&local_108,&local_1b8);
                if (local_108 != (int *)0x0) {
                  LOCK();
                  iVar23 = *local_108;
                  *local_108 = *local_108 + -1;
                  UNLOCK();
                  if ((iVar23 == 1) && (local_108 != (int *)0x0)) {
                    free(local_108);
                  }
                }
                piVar1 = local_3a0;
                if (local_3a0 != (int *)0x0) {
                  LOCK();
                  piVar4 = local_3a0 + 1;
                  iVar23 = *piVar4;
                  *piVar4 = *piVar4 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    if (*(code **)(local_3a0 + 2) == FUN_1402ae110) {
                      (**(code **)(*(longlong *)(local_3a0 + 4) + 0x18))(local_3a0 + 4,0);
                    }
                    else {
                      (**(code **)(local_3a0 + 2))(local_3a0);
                    }
                  }
                  LOCK();
                  iVar23 = *piVar1;
                  *piVar1 = *piVar1 + -1;
                  UNLOCK();
                  if (iVar23 == 1) {
                    free(piVar1);
                  }
                }
                QString::~QString(local_278);
                QString::~QString((QString *)local_378);
                if (0xf < local_348) {
                  pvVar35 = (void *)CONCAT71(uStack_35f,local_360);
                  if (0xfff < local_348 + 1) {
                    lVar24 = (longlong)pvVar35 - (longlong)*(void **)((longlong)pvVar35 + -8);
                    pvVar35 = *(void **)((longlong)pvVar35 + -8);
                    goto joined_r0x00014042b05d;
                  }
                  goto LAB_140429b11;
                }
              }
              goto LAB_140429e0a;
            }
            lVar24 = FUN_14130f3e0();
            if ((((*(char *)(lVar24 + 0x2e8) != '\0') &&
                 (cVar20 = FUN_1413c4610(*(undefined8 *)(param_1 + 0x588),local_378), cVar20 == '\0'
                 )) && (cVar20 = FUN_1413c47e0(*(undefined8 *)(param_1 + 0x588),local_378),
                       cVar20 == '\0')) &&
               (cVar20 = FUN_1413c44a0(*(undefined8 *)(param_1 + 0x588),local_378), cVar20 != '\0'))
            {
              (*(code *)**(undefined8 **)param_1)(param_1);
              local_2f8 = param_1;
              QString::QString((QString *)&uStack_2f0,(QString *)local_378);
              local_338 = (ExternalRefCountData *)0x0;
              pEStack_330 = (ExternalRefCountData *)0x0;
              local_328 = &DAT_1428cd800;
              local_398 = (ExternalRefCountData *)0x0;
              pEStack_390 = (ExternalRefCountData *)0x0;
              local_388[0] = (QMetaTypeInterface *)&DAT_1428cd800;
              pQVar25 = (QSlotObjectBase *)FUN_141981f80(0x30);
              pQVar41 = (QSlotObjectBase *)pEVar44;
              if (pQVar25 != (QSlotObjectBase *)0x0) {
                *(undefined4 *)pQVar25 = 1;
                *(code **)(pQVar25 + 8) = FUN_1404231d0;
                *(QObject **)(pQVar25 + 0x10) = local_2f8;
                QString::QString((QString *)(pQVar25 + 0x18),(QString *)&uStack_2f0);
                pQVar41 = pQVar25;
              }
              in_stack_fffffffffffffc18 = local_388;
              QMetaObject::invokeMethodImpl
                        (param_1,pQVar41,2,1,&local_398,(char **)&pEStack_390,
                         in_stack_fffffffffffffc18);
              QString::~QString((QString *)&uStack_2f0);
            }
            QString::~QString(local_278);
            QString::~QString((QString *)local_378);
            if (local_348 < 0x10) goto LAB_140429e0a;
            pvVar35 = (void *)CONCAT71(uStack_35f,local_360);
            if (0xfff < local_348 + 1) {
              lVar24 = (longlong)pvVar35 - (longlong)*(void **)((longlong)pvVar35 + -8);
              pvVar35 = *(void **)((longlong)pvVar35 + -8);
joined_r0x00014042b05d:
              if (0x1f < lVar24 - 8U) {
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
            }
LAB_140429b11:
            free(pvVar35);
            plVar38 = plVar38 + 2;
          }
        }
        if (local_340 != 0) {
          FUN_14197ec40((longlong)*(int *)(*(longlong *)(local_340 + 0x18) + 4) + local_340 + 0x18);
        }
        if (local_3b0 != (void **)0x0) {
          FUN_14197ec40((longlong)local_3b0 + (longlong)*(int *)((longlong)local_3b0[3] + 4) + 0x18)
          ;
        }
        plVar38 = (longlong *)param_3[1];
        if (plVar38 == (longlong *)0x0) {
          return;
        }
        LOCK();
        piVar1 = (int *)((longlong)plVar38 + 0xc);
        iVar23 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        goto LAB_14042b0c6;
      }
      FUN_1403c1740(local_3b0);
      if (local_340 != 0) {
        FUN_14197ec40((longlong)*(int *)(*(longlong *)(local_340 + 0x18) + 4) + local_340 + 0x18);
      }
    }
    if (local_3b0 != (void **)0x0) {
      FUN_14197ec40((longlong)local_3b0 + (longlong)*(int *)((longlong)local_3b0[3] + 4) + 0x18);
    }
  }
  plVar38 = (longlong *)param_3[1];
  if (plVar38 == (longlong *)0x0) {
    return;
  }
  LOCK();
  piVar1 = (int *)((longlong)plVar38 + 0xc);
  iVar23 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
LAB_14042b0c6:
  if (iVar23 == 1) {
    (**(code **)(*plVar38 + 8))();
  }
  return;
}


