// FUN_140385130 @ 140385130
// strings: [.stems]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140385130(longlong param_1)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  undefined1 uVar4;
  longlong *plVar5;
  undefined8 uVar6;
  void **ppvVar7;
  void **ppvVar8;
  char cVar9;
  bool bVar10;
  longlong lVar11;
  code *pcVar12;
  QString *pQVar13;
  __uint64 _Var14;
  QLoggingCategory *this;
  QMessageLogger *this_00;
  QDebug *pQVar15;
  undefined8 *puVar16;
  QObject *pQVar17;
  code *pcVar18;
  code *pcVar19;
  QString *this_01;
  undefined8 uVar20;
  undefined8 *puVar21;
  char *_Memory;
  undefined **ppuVar22;
  void *_Memory_00;
  code *pcVar23;
  __uint64 _Var24;
  code *local_res8;
  code **local_res10;
  longlong local_res18;
  undefined8 local_res20;
  QSlotObjectBase *in_stack_fffffffffffffea8;
  ulonglong uVar25;
  code **in_stack_fffffffffffffeb0;
  undefined8 uVar26;
  ulonglong uVar27;
  undefined8 in_stack_fffffffffffffeb8;
  undefined4 uVar29;
  ulonglong uVar28;
  ulonglong in_stack_fffffffffffffec0;
  undefined **local_128;
  undefined8 uStack_120;
  longlong *local_118;
  ulonglong uStack_110;
  code *local_108;
  code *pcStack_100;
  code *local_e8;
  code *local_e0;
  undefined8 local_d8;
  char *local_c8;
  undefined8 uStack_c0;
  longlong *local_b8;
  ulonglong uStack_b0;
  int *local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined1 local_88 [8];
  undefined8 *local_80;
  void *local_70;
  undefined8 local_68;
  longlong lStack_60;
  
  uVar29 = (undefined4)((ulonglong)in_stack_fffffffffffffeb8 >> 0x20);
  pcVar18 = (code *)0x0;
  lVar11 = FUN_14130f3e0();
  uVar4 = *(undefined1 *)(lVar11 + 0x2e8);
  local_res10 = (code **)CONCAT71(local_res10._1_7_,uVar4);
  if (*(char *)(lVar11 + 0x619) == '\0') {
    pcVar12 = (code *)FUN_141981f80(0xc0);
    pcVar19 = pcVar18;
    local_res8 = pcVar12;
    if (pcVar12 != (code *)0x0) {
      *(undefined8 *)pcVar12 = 0;
      *(undefined8 *)(pcVar12 + 8) = 0;
      *(int *)(pcVar12 + 8) = 1;
      *(int *)(pcVar12 + 0xc) = 1;
      *(undefined ***)pcVar12 = std::_Ref_count_obj2<airFileFactory>::vftable;
      FUN_1418b41d0(pcVar12 + 0x10,uVar4);
      pcVar19 = pcVar12;
    }
    local_e8 = pcVar19 + 0x10;
    local_e0 = pcVar19;
    if ((local_e8 != (code *)0x0) &&
       ((*(longlong *)(pcVar19 + 0x20) == 0 || (*(int *)(*(longlong *)(pcVar19 + 0x20) + 8) == 0))))
    {
      pcVar12 = pcVar18;
      if (pcVar19 != (code *)0x0) {
        LOCK();
        *(int *)(pcVar19 + 8) = *(int *)(pcVar19 + 8) + 1;
        UNLOCK();
        LOCK();
        *(int *)(pcVar19 + 0xc) = *(int *)(pcVar19 + 0xc) + 1;
        UNLOCK();
        pcVar18 = local_e8;
        pcVar12 = pcVar19;
      }
      *(code **)(pcVar19 + 0x18) = pcVar18;
      plVar5 = *(longlong **)(pcVar19 + 0x20);
      *(code **)(pcVar19 + 0x20) = pcVar12;
      if (plVar5 != (longlong *)0x0) {
        LOCK();
        piVar1 = (int *)((longlong)plVar5 + 0xc);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(*plVar5 + 8))();
        }
      }
      if (pcVar19 != (code *)0x0) {
        FUN_1402a2270(pcVar19);
      }
    }
    FUN_14030b8c0(param_1 + 0x1d0,&local_e8);
    if (local_e0 != (code *)0x0) {
      FUN_1402a2270();
    }
  }
  else {
    pcVar12 = (code *)FUN_141981f80(200);
    pcVar19 = pcVar18;
    local_res8 = pcVar12;
    if (pcVar12 != (code *)0x0) {
      *(undefined8 *)pcVar12 = 0;
      *(undefined8 *)(pcVar12 + 8) = 0;
      *(int *)(pcVar12 + 8) = 1;
      *(int *)(pcVar12 + 0xc) = 1;
      *(undefined ***)pcVar12 = std::_Ref_count_obj2<airNfsFileFactory>::vftable;
      FUN_1413e5fd0(pcVar12 + 0x10,uVar4);
      pcVar19 = pcVar12;
    }
    pcVar12 = pcVar19 + 0x10;
    if ((pcVar12 != (code *)0x0) &&
       ((*(longlong *)(pcVar19 + 0x20) == 0 || (*(int *)(*(longlong *)(pcVar19 + 0x20) + 8) == 0))))
    {
      pcVar23 = pcVar18;
      if (pcVar19 != (code *)0x0) {
        LOCK();
        *(int *)(pcVar19 + 8) = *(int *)(pcVar19 + 8) + 1;
        UNLOCK();
        LOCK();
        *(int *)(pcVar19 + 0xc) = *(int *)(pcVar19 + 0xc) + 1;
        UNLOCK();
        pcVar18 = pcVar12;
        pcVar23 = pcVar19;
      }
      *(code **)(pcVar19 + 0x18) = pcVar18;
      plVar5 = *(longlong **)(pcVar19 + 0x20);
      *(code **)(pcVar19 + 0x20) = pcVar23;
      if (plVar5 != (longlong *)0x0) {
        LOCK();
        piVar1 = (int *)((longlong)plVar5 + 0xc);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(*plVar5 + 8))();
        }
      }
      if (pcVar19 != (code *)0x0) {
        FUN_1402a2270(pcVar19);
      }
    }
    puVar21 = (undefined8 *)(param_1 + 0x1d0);
    local_108 = pcVar12;
    pcStack_100 = pcVar19;
    FUN_14030b8c0(puVar21,&local_108);
    if (pcStack_100 != (code *)0x0) {
      FUN_1402a2270();
    }
    QString::QString((QString *)&local_128,"pageCacheSize");
    cVar9 = FUN_1412cef60(&local_128);
    QString::~QString((QString *)&local_128);
    _Var24 = 0x1f400000;
    if (cVar9 != '\0') {
      local_res8 = (code *)((ulonglong)local_res8 & 0xffffffffffffff00);
      QString::QString((QString *)&local_128,"pageCacheSize");
      pQVar13 = (QString *)FUN_1412cef90(&local_e8,&local_128);
      _Var14 = QString::toULongLong(pQVar13,(bool *)&local_res8,10);
      QString::~QString((QString *)&local_e8);
      QString::~QString((QString *)&local_128);
      if ((_Var14 != 0) && (_Var24 = _Var14, _Var14 != 0x1f400000)) {
        this = (QLoggingCategory *)FUN_1412cf050();
        bVar10 = QLoggingCategory::isInfoEnabled(this);
        if (bVar10) {
          this_00 = (QMessageLogger *)
                    QMessageLogger::QMessageLogger
                              ((QMessageLogger *)&local_c8,(char *)0x0,0,(char *)0x0,
                               *(char **)(this + 8));
          pQVar15 = (QDebug *)QMessageLogger::info(this_00);
          pQVar15 = QDebug::operator<<(pQVar15,"Page cache size set to");
          pQVar15 = QDebug::operator<<(pQVar15,_Var14);
          QDebug::operator<<(pQVar15,"bytes");
          QDebug::~QDebug((QDebug *)&local_res8);
        }
      }
    }
    if (*(longlong *)(param_1 + 0x1d8) != 0) {
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x1d8) + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    local_108 = (code *)*puVar21;
    pcStack_100 = *(code **)(param_1 + 0x1d8);
    local_res8 = *(code **)(param_1 + 0x280);
    if (local_res8 != (code *)0x0) {
      FUN_14197ec00(local_res8 + (longlong)*(int *)(*(longlong *)(local_res8 + 0x18) + 4) + 0x18);
    }
    puVar16 = (undefined8 *)FUN_1413dfbc0(&local_res18,&local_res8,&local_108,_Var24);
    uVar6 = *puVar16;
    *puVar16 = 0;
    lVar11 = *(longlong *)(param_1 + 0x1c8);
    *(undefined8 *)(param_1 + 0x1c8) = uVar6;
    if (lVar11 != 0) {
      FUN_14197ec40((longlong)*(int *)(*(longlong *)(lVar11 + 0x18) + 4) + lVar11 + 0x18);
    }
    if (local_res18 != 0) {
      FUN_14197ec40((longlong)*(int *)(*(longlong *)(local_res18 + 0x18) + 4) + local_res18 + 0x18);
    }
    local_e8 = (code *)*puVar21;
    if (*(longlong *)(param_1 + 0x1d8) != 0) {
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x1d8) + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    plVar5 = *(longlong **)(param_1 + 0x1d8);
    local_e0 = (code *)plVar5;
    FUN_1413e6ba0(local_e8,param_1 + 0x1c8);
    if (plVar5 != (longlong *)0x0) {
      LOCK();
      plVar2 = plVar5 + 1;
      lVar11 = *plVar2;
      *(int *)plVar2 = (int)*plVar2 + -1;
      UNLOCK();
      if ((int)lVar11 == 1) {
        (**(code **)*plVar5)(plVar5);
        LOCK();
        piVar1 = (int *)((longlong)plVar5 + 0xc);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar3 == 1) {
          (**(code **)(*plVar5 + 8))(plVar5);
        }
      }
    }
    lVar11 = *(longlong *)(param_1 + 0x48);
    pcVar18 = (code *)*puVar21;
    if (*(longlong *)(param_1 + 0x1d8) != 0) {
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x1d8) + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    pcVar19 = *(code **)(param_1 + 0x1d8);
    local_108 = pcVar18;
    pcStack_100 = pcVar19;
    FUN_14197e0c0(&local_128,0x150);
    local_128 = `public:_static_class_air::refptr<class_FileTransferController>___cdecl_air::refptr<FileTransferController>::make<air::refptr<airNfs>&___ptr64,std::shared_ptr<airNfsFileFactory>,PlanckClient*___ptr64,StateMap*___ptr64,air::weakptr<JobController>&___ptr64>(air::refptr<airNfs>&___ptr64,std::shared_ptr<airNfsFileFactory>&&___ptr64,PlanckClient*___ptr64&&___ptr64,StateMap*___ptr64&&___ptr64,air::weakptr<JobController>&___ptr64)'
                ::__l2::Storage::vftable;
    local_res20 = FUN_1409a74e0(&local_128);
    local_res8 = *(code **)(param_1 + 0x290);
    if (local_res8 != (code *)0x0) {
      FUN_14197ebf0();
    }
    local_res18 = lVar11;
    if (lVar11 != 0) {
      FUN_14197ec00((longlong)*(int *)(*(longlong *)(lVar11 + 8) + 4) + 8 + lVar11);
    }
    local_108 = (code *)0x0;
    pcStack_100 = (code *)0x0;
    lVar11 = param_1 + 0x20;
    if (param_1 == 0) {
      lVar11 = 0;
    }
    uVar25 = CONCAT44(uVar29,1);
    in_stack_fffffffffffffeb0 = &local_res8;
    in_stack_fffffffffffffea8 = (QSlotObjectBase *)&local_res18;
    local_e8 = pcVar18;
    local_e0 = pcVar19;
    pQVar17 = (QObject *)
              FUN_140578aa0(local_res20,param_1 + 0x1c8,&local_e8,lVar11,in_stack_fffffffffffffea8,
                            in_stack_fffffffffffffeb0,uVar25);
    if (local_res18 != 0) {
      FUN_14197ec40(local_res18 + 8 + (longlong)*(int *)(*(longlong *)(local_res18 + 8) + 4));
    }
    FUN_14143b190(&local_128);
    FUN_14197e280(&local_128);
    QJSEngine::setObjectOwnership(pQVar17,0);
    lVar11 = *(longlong *)(param_1 + 0x1f0);
    *(QObject **)(param_1 + 0x1f0) = pQVar17;
    if (lVar11 != 0) {
      FUN_14197ec40((longlong)*(int *)(*(longlong *)(lVar11 + 0x18) + 4) + lVar11 + 0x18);
    }
    if ((char)local_res10 != '\0') {
      FUN_14197e0c0(&local_128);
      local_128 = `public:_static_class_air::refptr<class_NetworkApplicationVersionObserver>___cdecl_air::refptr<NetworkApplicationVersionObserver>::make<>(void)'
                  ::__l2::Storage::vftable;
      pQVar17 = (QObject *)FUN_1409a74e0(&local_128);
      *(undefined8 *)pQVar17 = 0;
      *(undefined8 *)(pQVar17 + 8) = 0;
      *(undefined8 *)(pQVar17 + 0x10) = 0;
      *(undefined8 *)(pQVar17 + 0x20) = 0;
      *(undefined8 *)(pQVar17 + 0x28) = 0;
      *(undefined8 *)(pQVar17 + 0x30) = 0;
      *(undefined **)(pQVar17 + 0x18) = &DAT_141d26ac0;
      *(undefined ***)(pQVar17 + 0x38) = air::Irefcounted::vftable;
      QObject::QObject(pQVar17,(QObject *)0x0);
      FUN_14197e110(pQVar17 + 0x10);
      *(undefined ***)pQVar17 = NetworkApplicationVersionObserver::vftable;
      *(undefined ***)(pQVar17 + 0x10) = NetworkApplicationVersionObserver::vftable;
      *(undefined ***)(pQVar17 + (longlong)*(int *)(*(longlong *)(pQVar17 + 0x18) + 4) + 0x18) =
           NetworkApplicationVersionObserver::vftable;
      *(undefined4 *)(pQVar17 + (longlong)*(int *)(*(longlong *)(pQVar17 + 0x18) + 4) + 0x14) = 0;
      pQVar17[0x28] = (QObject)0x0;
      FUN_14143b190(&local_128);
      FUN_14197e280(&local_128);
      QJSEngine::setObjectOwnership(pQVar17,0);
      lVar11 = *(longlong *)(param_1 + 0x298);
      *(QObject **)(param_1 + 0x298) = pQVar17;
      if (lVar11 != 0) {
        FUN_14197ec40((longlong)*(int *)(*(longlong *)(lVar11 + 0x18) + 4) + lVar11 + 0x18);
      }
      local_108 = FUN_140582a10;
      pcStack_100 = (code *)0xfffffff0;
      ppvVar7 = *(void ***)(param_1 + 0x298);
      ppvVar8 = *(void ***)(param_1 + 0x280);
      local_e8 = FUN_14186b150;
      local_e0 = (code *)0xfffffff0;
      local_res10 = (code **)FUN_141981f80(0x20);
      if (local_res10 == (code **)0x0) {
        in_stack_fffffffffffffeb0 = (code **)0x0;
      }
      else {
        *(undefined4 *)local_res10 = 1;
        local_res10[1] = FUN_140380400;
        local_res10[2] = local_108;
        local_res10[3] = pcStack_100;
        in_stack_fffffffffffffeb0 = local_res10;
      }
      in_stack_fffffffffffffec0 = 0;
      in_stack_fffffffffffffea8 = (QSlotObjectBase *)&local_108;
      QObject::connectImpl
                ((QObject *)&local_res8,ppvVar8,(QObject *)&local_e8,ppvVar7,
                 in_stack_fffffffffffffea8,(ConnectionType)in_stack_fffffffffffffeb0,
                 (int *)(uVar25 & 0xffffffff00000000),(QMetaObject *)0x0);
      QMetaObject::Connection::~Connection((Connection *)&local_res8);
    }
  }
  pcVar18 = (code *)0x0;
  pcVar19 = (code *)FUN_141981f80(0x28);
  local_res8 = pcVar19;
  if (pcVar19 != (code *)0x0) {
    *(undefined8 *)pcVar19 = 0;
    *(undefined8 *)(pcVar19 + 8) = 0;
    *(undefined4 *)(pcVar19 + 8) = 1;
    *(undefined4 *)(pcVar19 + 0xc) = 1;
    *(undefined ***)pcVar19 = std::_Ref_count_obj2<airFileFormats>::vftable;
    if (*(longlong *)(param_1 + 0x1d8) != 0) {
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x1d8) + 8);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
    }
    local_108 = *(code **)(param_1 + 0x1d0);
    pcStack_100 = *(code **)(param_1 + 0x1d8);
    FUN_1418a76b0(pcVar19 + 0x10,&local_108);
    pcVar18 = pcVar19;
  }
  *(code **)(param_1 + 0x1e0) = pcVar18 + 0x10;
  plVar5 = *(longlong **)(param_1 + 0x1e8);
  *(code **)(param_1 + 0x1e8) = pcVar18;
  if (plVar5 != (longlong *)0x0) {
    LOCK();
    plVar2 = plVar5 + 1;
    lVar11 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      (**(code **)*plVar5)(plVar5);
      LOCK();
      piVar1 = (int *)((longlong)plVar5 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plVar5 + 8))(plVar5);
      }
    }
  }
  FUN_1418a9020(*(undefined8 *)(param_1 + 0x1e0),local_88);
  puVar16 = local_80;
  local_a8 = (int *)0x0;
  local_a0 = 0;
  uStack_98 = 0;
  for (puVar21 = (undefined8 *)*local_80; puVar21 != puVar16; puVar21 = (undefined8 *)*puVar21) {
    pQVar13 = (QString *)QString::fromUtf8((char *)&local_c8,puVar21[2]);
    local_e8 = (code *)0x0;
    local_e0 = (code *)&DAT_141cb059c;
    local_d8 = 1;
    this_01 = (QString *)
              QString::QString((QString *)&local_108,(QArrayDataPointer<char16_t> *)&local_e8);
    pQVar13 = QString::append(this_01,pQVar13);
    QString::QString((QString *)&local_128,pQVar13);
    FUN_1402a8b90(&local_a8,uStack_98,&local_128);
    if ((local_a8 == (int *)0x0) || (1 < *local_a8)) {
      FUN_1402b6850(&local_a8,0,0,0);
    }
    QString::~QString((QString *)&local_128);
    QString::~QString((QString *)&local_108);
    if (local_e8 != (code *)0x0) {
      LOCK();
      iVar3 = *(int *)local_e8;
      *(int *)local_e8 = *(int *)local_e8 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        free(local_e8);
      }
    }
    QString::~QString((QString *)&local_c8);
  }
  local_res8 = (code *)0x141d2eee0;
  FUN_140370ef0(&local_a8,&local_res8);
  pcVar18 = *(code **)(*(longlong *)(param_1 + 0x20) + 0x18);
  uVar28 = 0;
  uVar26 = CONCAT71((int7)((ulonglong)in_stack_fffffffffffffeb0 >> 8),1);
  uVar25 = (ulonglong)in_stack_fffffffffffffea8 & 0xffffffff00000000;
  uVar20 = FUN_141388190(&local_c8,0,0,&local_a8,uVar25,uVar26,0);
  local_128 = (undefined **)0x0;
  uStack_120 = 0;
  local_118 = (longlong *)0x0;
  uStack_110 = 0;
  local_128 = (undefined **)FUN_141981f80(0x20);
  uVar6 = s_SupportedFileTypes_141d2eee8._8_8_;
  local_118 = (longlong *)_DAT_141cb00b0;
  uStack_110 = _UNK_141cb00b8;
  *local_128 = (undefined *)s_SupportedFileTypes_141d2eee8._0_8_;
  local_128[1] = (undefined *)uVar6;
  *(undefined2 *)(local_128 + 2) = s_SupportedFileTypes_141d2eee8._16_2_;
  *(char *)((longlong)local_128 + 0x12) = '\0';
  uVar27 = CONCAT71((int7)((ulonglong)uVar26 >> 8),1);
  puVar21 = (undefined8 *)
            (*pcVar18)(param_1 + 0x20,&local_res8,&local_128,uVar20,uVar25 & 0xffffffffffffff00,
                       uVar27,uVar28 & 0xffffffffffffff00,
                       in_stack_fffffffffffffec0 & 0xffffffffffffff00);
  uVar6 = *puVar21;
  *puVar21 = 0;
  lVar11 = *(longlong *)(param_1 + 0x148);
  *(undefined8 *)(param_1 + 0x148) = uVar6;
  if (lVar11 != 0) {
    FUN_14197ec40((longlong)*(int *)(*(longlong *)(lVar11 + 8) + 4) + lVar11 + 8);
  }
  if (local_res8 != (code *)0x0) {
    FUN_14197ec40(local_res8 + (longlong)*(int *)(*(longlong *)(local_res8 + 8) + 4) + 8);
  }
  if (0xf < uStack_110) {
    ppuVar22 = local_128;
    if ((0xfff < uStack_110 + 1) &&
       (ppuVar22 = (undefined **)local_128[-1],
       (char *)0x1f < (char *)((longlong)local_128 + (-8 - (longlong)ppuVar22)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppuVar22);
  }
  local_118 = _DAT_141ac9b00;
  uStack_110 = _UNK_141ac9b08;
  local_128 = (undefined **)((ulonglong)local_128 & 0xffffffffffffff00);
  if (local_b8 != (longlong *)0x0) {
    LOCK();
    plVar5 = local_b8 + 1;
    lVar11 = *plVar5;
    *(int *)plVar5 = (int)*plVar5 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      (**(code **)*local_b8)(local_b8);
      LOCK();
      piVar1 = (int *)((longlong)local_b8 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*local_b8 + 8))(local_b8);
      }
    }
  }
  pcVar18 = *(code **)(*(longlong *)(param_1 + 0x20) + 0x10);
  uVar29 = 1;
  FUN_14137cd20(&local_128,0,0,&DAT_141d2ef00,&DAT_141d2eefc,uVar27 & 0xffffffffffffff00);
  local_c8 = (char *)0x0;
  uStack_c0 = 0;
  local_b8 = (longlong *)0x0;
  uStack_b0 = 0;
  local_c8 = (char *)FUN_141981f80(0x20);
  uVar6 = s_EnablePageCacheStatistics_141d2ef08._8_8_;
  local_b8 = (longlong *)_DAT_141d2ff40;
  uStack_b0 = _UNK_141d2ff48;
  *(undefined8 *)local_c8 = s_EnablePageCacheStatistics_141d2ef08._0_8_;
  *(undefined8 *)(local_c8 + 8) = uVar6;
  *(undefined8 *)(local_c8 + 0x10) = s_EnablePageCacheStatistics_141d2ef08._16_8_;
  local_c8[0x18] = s_EnablePageCacheStatistics_141d2ef08[0x18];
  local_c8[0x19] = '\0';
  uVar25 = CONCAT44(uVar29,4);
  puVar21 = (undefined8 *)(*pcVar18)(param_1 + 0x20,&local_res8,&local_c8,&local_128,uVar25);
  uVar6 = *puVar21;
  *puVar21 = 0;
  lVar11 = *(longlong *)(param_1 + 0x100);
  *(undefined8 *)(param_1 + 0x100) = uVar6;
  if (lVar11 != 0) {
    FUN_14197ec40((longlong)*(int *)(*(longlong *)(lVar11 + 8) + 4) + lVar11 + 8);
  }
  if (local_res8 != (code *)0x0) {
    FUN_14197ec40(local_res8 + (longlong)*(int *)(*(longlong *)(local_res8 + 8) + 4) + 8);
  }
  if (0xf < uStack_b0) {
    _Memory = local_c8;
    if ((0xfff < uStack_b0 + 1) &&
       (_Memory = *(char **)(local_c8 + -8), (char *)0x1f < local_c8 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  plVar5 = local_118;
  local_b8 = _DAT_141ac9b00;
  uStack_b0 = _UNK_141ac9b08;
  local_c8 = (char *)((ulonglong)local_c8 & 0xffffffffffffff00);
  if (local_118 != (longlong *)0x0) {
    LOCK();
    plVar2 = local_118 + 1;
    lVar11 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      (**(code **)*local_118)(local_118);
      LOCK();
      piVar1 = (int *)((longlong)plVar5 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plVar5 + 8))(plVar5);
      }
    }
  }
  pcVar18 = *(code **)(*(longlong *)(param_1 + 0x20) + 0x10);
  uVar20 = FUN_141380300(&local_c8);
  local_128 = (undefined **)0x0;
  uStack_120 = 0;
  local_118 = (longlong *)0x0;
  uStack_110 = 0;
  local_128 = (undefined **)FUN_141981f80(0x20);
  uVar6 = s_PageCacheStatistics_141d2ef28._8_8_;
  local_118 = (longlong *)_DAT_141cb4680;
  uStack_110 = _UNK_141cb4688;
  *local_128 = (undefined *)s_PageCacheStatistics_141d2ef28._0_8_;
  local_128[1] = (undefined *)uVar6;
  *(undefined2 *)(local_128 + 2) = s_PageCacheStatistics_141d2ef28._16_2_;
  *(char *)((longlong)local_128 + 0x12) = s_PageCacheStatistics_141d2ef28[0x12];
  *(char *)((longlong)local_128 + 0x13) = '\0';
  puVar21 = (undefined8 *)
            (*pcVar18)(param_1 + 0x20,&local_res8,&local_128,uVar20,uVar25 & 0xffffffff00000000);
  uVar6 = *puVar21;
  *puVar21 = 0;
  lVar11 = *(longlong *)(param_1 + 0x108);
  *(undefined8 *)(param_1 + 0x108) = uVar6;
  if (lVar11 != 0) {
    FUN_14197ec40((longlong)*(int *)(*(longlong *)(lVar11 + 8) + 4) + lVar11 + 8);
  }
  if (local_res8 != (code *)0x0) {
    FUN_14197ec40(local_res8 + (longlong)*(int *)(*(longlong *)(local_res8 + 8) + 4) + 8);
  }
  if (0xf < uStack_110) {
    ppuVar22 = local_128;
    if ((0xfff < uStack_110 + 1) &&
       (ppuVar22 = (undefined **)local_128[-1],
       (char *)0x1f < (char *)((longlong)local_128 + (-8 - (longlong)ppuVar22)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppuVar22);
  }
  plVar5 = local_b8;
  local_118 = _DAT_141ac9b00;
  uStack_110 = _UNK_141ac9b08;
  local_128 = (undefined **)((ulonglong)local_128 & 0xffffffffffffff00);
  if (local_b8 != (longlong *)0x0) {
    LOCK();
    plVar2 = local_b8 + 1;
    lVar11 = *plVar2;
    *(int *)plVar2 = (int)*plVar2 + -1;
    UNLOCK();
    if ((int)lVar11 == 1) {
      (**(code **)*local_b8)(local_b8);
      LOCK();
      piVar1 = (int *)((longlong)plVar5 + 0xc);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        (**(code **)(*plVar5 + 8))(plVar5);
      }
    }
  }
  FUN_14029fe30(&local_a8);
  if (local_70 != (void *)0x0) {
    _Memory_00 = local_70;
    if ((0xfff < (lStack_60 - (longlong)local_70 & 0xfffffffffffffff8U)) &&
       (_Memory_00 = *(void **)((longlong)local_70 + -8),
       0x1f < (ulonglong)((longlong)local_70 + (-8 - (longlong)_Memory_00)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory_00);
    local_70 = (void *)0x0;
    local_68 = 0;
    lStack_60 = 0;
  }
  *(undefined8 *)local_80[1] = 0;
  puVar21 = (undefined8 *)*local_80;
  while (puVar21 != (undefined8 *)0x0) {
    puVar16 = (undefined8 *)*puVar21;
    free(puVar21);
    puVar21 = puVar16;
  }
  free(local_80);
  return;
}


