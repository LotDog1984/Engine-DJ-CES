// FUN_140649c40 @ 140649c40
// strings: [stems-processor]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_140649c40(longlong param_1,
             basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_2)

{
  undefined2 uVar1;
  longlong *plVar2;
  void *pvVar3;
  bool bVar4;
  undefined8 uVar5;
  QLoggingCategory *pQVar6;
  QMessageLogger *pQVar7;
  QDebug *pQVar8;
  QString *pQVar9;
  QChar *pQVar10;
  undefined2 *puVar11;
  QString *pQVar12;
  undefined8 ****ppppuVar13;
  undefined1 *_Memory;
  void *pvVar14;
  QString *pQVar15;
  uint uVar16;
  QDebug local_res8 [8];
  QFileInfo local_res18 [16];
  void *local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  ulonglong uStack_140;
  undefined8 ***local_138 [3];
  ulonglong local_120;
  uint local_118;
  QChar local_110 [8];
  QString *local_108;
  longlong local_100;
  undefined1 *local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  ulonglong uStack_e0;
  void *local_d8 [3];
  ulonglong local_c0;
  QString local_b8 [24];
  undefined1 local_a0;
  undefined7 uStack_9f;
  undefined8 local_90;
  ulonglong uStack_88;
  QString local_78 [24];
  QString local_60 [24];
  undefined1 local_48 [24];
  undefined1 local_30 [8];
  
  uVar16 = 0;
  local_118 = 0;
  plVar2 = *(longlong **)(param_1 + 0x98);
  if (plVar2 == (longlong *)0x0) {
    QString::QString(local_78,"/content");
    QString::QString(local_60,"/data/content");
    QStandardPaths::writableLocation((StandardLocation)local_48);
    local_108 = QArrayData::allocate((QArrayData **)local_res8,0x18,8,3,1);
    local_100 = 0;
    FUN_1402af7a0(local_110,local_78,local_30);
    _eh_vector_destructor_iterator_(local_78,0x18,3,~QString_exref);
    pQVar6 = (QLoggingCategory *)FUN_1412d07f0();
    bVar4 = QLoggingCategory::isDebugEnabled(pQVar6);
    if (bVar4) {
      pQVar7 = (QMessageLogger *)
               QMessageLogger::QMessageLogger
                         ((QMessageLogger *)local_d8,(char *)0x0,0,(char *)0x0,
                          *(char **)(pQVar6 + 8));
      pQVar8 = (QDebug *)QMessageLogger::debug(pQVar7);
      pQVar8 = QDebug::operator<<(pQVar8,"Searching for Stems Processor in:");
      QString::QString((QString *)local_138,",");
      QString::size((QString *)local_138);
      pQVar10 = QString::constData((QString *)local_138);
      QtPrivate::QStringList_join((QList<QString> *)&local_158,local_110,(__int64)pQVar10);
      uVar16 = 8;
      QDebug::operator<<(pQVar8,(QString *)&local_158);
      QString::~QString((QString *)&local_158);
      QString::~QString((QString *)local_138);
      QDebug::~QDebug(local_res8);
    }
    QString::QString(local_b8);
    pQVar9 = local_108 + local_100 * 0x18;
    for (pQVar15 = local_108; pQVar15 != pQVar9; pQVar15 = pQVar15 + 0x18) {
      puVar11 = (undefined2 *)QDir::separator();
      uVar1 = *puVar11;
      QString::QString((QString *)local_138,pQVar15);
      local_118 = uVar16 | 4;
      QString::append((QString *)local_138,uVar1);
      pQVar12 = QString::operator+=((QString *)local_138,"stems-child-process.sqsh.signed");
      QString::QString((QString *)&local_158,pQVar12);
      uVar16 = uVar16 | 2;
      QString::~QString((QString *)local_138);
      QFileInfo::QFileInfo(local_res18,(QString *)&local_158);
      bVar4 = QFileInfo::exists(local_res18);
      if ((bVar4) && (bVar4 = QFileInfo::isFile(local_res18), bVar4)) {
        pQVar9 = (QString *)QFileInfo::absoluteFilePath(local_res18);
        QString::operator=(local_b8,pQVar9);
        QString::~QString((QString *)local_138);
        QFileInfo::~QFileInfo(local_res18);
        QString::~QString((QString *)&local_158);
        break;
      }
      QFileInfo::~QFileInfo(local_res18);
      QString::~QString((QString *)&local_158);
    }
    pQVar6 = (QLoggingCategory *)FUN_1412d07f0();
    bVar4 = QLoggingCategory::isDebugEnabled(pQVar6);
    if (bVar4) {
      pQVar7 = (QMessageLogger *)
               QMessageLogger::QMessageLogger
                         ((QMessageLogger *)local_d8,(char *)0x0,0,(char *)0x0,
                          *(char **)(pQVar6 + 8));
      pQVar8 = (QDebug *)QMessageLogger::debug(pQVar7);
      pQVar8 = QDebug::operator<<(pQVar8,"Stems Processor Path:");
      QDebug::operator<<(pQVar8,local_b8);
      QDebug::~QDebug(local_res8);
    }
    QString::QString((QString *)param_2,local_b8);
    QString::~QString(local_b8);
    FUN_14029fe30(local_110);
  }
  else {
    uVar5 = (**(code **)(*plVar2 + 8))(plVar2,&local_a0);
    local_148 = _DAT_141cb69a0;
    uStack_140 = _UNK_141cb69a8;
    local_158 = (void *)s_stems_processor_141d6f060._0_8_;
    uStack_150 = (ulonglong)
                 CONCAT16(s_stems_processor_141d6f060[0xe],
                          CONCAT24(s_stems_processor_141d6f060._12_2_,
                                   s_stems_processor_141d6f060._8_4_));
    uStack_f0 = 0;
    local_e8 = _DAT_141d6f690;
    uStack_e0 = _UNK_141d6f698;
    local_f8 = &DAT_0000002f;
    FUN_14029f4d0(local_138,local_res8[0],&local_f8);
    ppppuVar13 = local_138;
    if (0xf < local_120) {
      ppppuVar13 = (undefined8 ****)local_138[0];
    }
    uVar5 = FUN_1402a2ae0(uVar5,ppppuVar13);
    FUN_1402aa5d0(local_d8,uVar5);
    if (0xf < local_120) {
      ppppuVar13 = (undefined8 ****)local_138[0];
      if ((0xfff < local_120 + 1) &&
         (ppppuVar13 = (undefined8 ****)local_138[0][-1],
         0x1f < (ulonglong)((longlong)local_138[0] + (-8 - (longlong)ppppuVar13)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppuVar13);
    }
    if (0xf < uStack_e0) {
      _Memory = local_f8;
      if ((0xfff < uStack_e0 + 1) &&
         (_Memory = *(undefined1 **)(local_f8 + -8),
         (undefined1 *)0x1f < local_f8 + (-8 - (longlong)_Memory))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(_Memory);
    }
    if (0xf < uStack_140) {
      pvVar14 = local_158;
      if ((0xfff < uStack_140 + 1) &&
         (pvVar14 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
    if (0xf < uStack_88) {
      pvVar3 = (void *)CONCAT71(uStack_9f,local_a0);
      pvVar14 = pvVar3;
      if ((0xfff < uStack_88 + 1) &&
         (pvVar14 = *(void **)((longlong)pvVar3 + -8),
         0x1f < (ulonglong)((longlong)pvVar3 + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
    local_90 = _DAT_141ac9b00;
    uStack_88 = _UNK_141ac9b08;
    local_a0 = 0;
    pQVar6 = (QLoggingCategory *)FUN_1412d07f0();
    bVar4 = QLoggingCategory::isDebugEnabled(pQVar6);
    if (bVar4) {
      pQVar7 = (QMessageLogger *)
               QMessageLogger::QMessageLogger
                         ((QMessageLogger *)&local_f8,(char *)0x0,0,(char *)0x0,
                          *(char **)(pQVar6 + 8));
      pQVar8 = (QDebug *)QMessageLogger::debug(pQVar7);
      pQVar8 = QDebug::operator<<(pQVar8,"Stems Processor mounted at:");
      pQVar9 = (QString *)
               QString::fromStdString
                         ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          &local_158);
      QDebug::operator<<(pQVar8,pQVar9);
      QString::~QString((QString *)&local_158);
      QDebug::~QDebug(local_res8);
    }
    QString::fromStdString(param_2);
    if (0xf < local_c0) {
      pvVar14 = local_d8[0];
      if ((0xfff < local_c0 + 1) &&
         (pvVar14 = *(void **)((longlong)local_d8[0] + -8),
         0x1f < (ulonglong)((longlong)local_d8[0] + (-8 - (longlong)pvVar14)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar14);
    }
  }
  return param_2;
}


