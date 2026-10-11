// FUN_140647f20 @ 140647f20
// strings: [stems-processor]

QString * FUN_140647f20(undefined8 param_1,QString *param_2)

{
  int iVar1;
  QArrayData *_Memory;
  char cVar2;
  bool bVar3;
  QString *pQVar4;
  longlong lVar5;
  QLoggingCategory *this;
  QMessageLogger *this_00;
  QDebug *pQVar6;
  longlong lVar7;
  longlong lVar8;
  QString *pQVar9;
  QArrayData *local_res18;
  QArrayData *local_d8;
  QString *pQStack_d0;
  longlong local_c8;
  undefined4 local_b8;
  QArrayData *local_b0;
  QString *local_a8;
  longlong local_a0;
  QString local_98 [32];
  QString local_78 [24];
  QString local_60 [24];
  QString local_48 [32];
  
  lVar8 = 0;
  local_b8 = 0;
  pQVar4 = (QString *)QStandardPaths::writableLocation((StandardLocation)local_48);
  pQVar4 = QString::operator+=(pQVar4,"/bin");
  QString::QString(local_60,pQVar4);
  local_b8 = 2;
  local_a8 = QArrayData::allocate(&local_res18,0x18,8,1,1);
  local_b0 = local_res18;
  local_a0 = 0;
  FUN_1402af7a0(&local_b0,local_60,local_48);
  _eh_vector_destructor_iterator_(local_60,0x18,1,~QString_exref);
  QString::~QString(local_48);
  local_d8 = (QArrayData *)0x12;
  pQStack_d0 = (QString *)0x141d6f048;
  QString::QString(local_98,&local_d8);
  cVar2 = FUN_1412cef60(local_98);
  QString::~QString(local_98);
  if (cVar2 == '\0') goto LAB_140648339;
  local_d8 = (QArrayData *)0x12;
  pQStack_d0 = (QString *)0x141d6f048;
  QString::QString(local_78,&local_d8);
  FUN_1412cef90(local_98,local_78);
  QString::~QString(local_78);
  bVar3 = QString::isEmpty(local_98);
  if (!bVar3) {
    local_d8 = (QArrayData *)0x0;
    pQStack_d0 = (QString *)0x0;
    local_c8 = 0;
    QString::QString(local_78,local_98);
    bVar3 = local_c8 != 0;
    if ((local_d8 == (QArrayData *)0x0) || (1 < *(int *)local_d8)) {
LAB_1406481f2:
      FUN_1402b6850(&local_d8,bVar3,1);
      pQVar4 = pQStack_d0;
    }
    else {
      pQVar4 = pQStack_d0;
      if (((!bVar3) ||
          ((longlong)((longlong)pQStack_d0 - ((ulonglong)(local_d8 + 0x17) & 0xfffffffffffffff8)) <
           0x18)) &&
         ((bVar3 || (*(longlong *)(local_d8 + 8) -
                     (longlong)
                     ((longlong)pQStack_d0 - ((ulonglong)(local_d8 + 0x17) & 0xfffffffffffffff8)) /
                     0x18 < 1)))) {
        lVar5 = *(longlong *)(local_d8 + 8);
        lVar7 = (longlong)pQStack_d0 - ((ulonglong)(local_d8 + 0x17) & 0xfffffffffffffff8);
        lVar7 = lVar7 / 6 + (lVar7 >> 0x3f);
        lVar7 = (lVar7 >> 2) - (lVar7 >> 0x3f);
        if (bVar3) {
LAB_140648185:
          if (((!bVar3) || ((lVar5 - local_c8) - lVar7 < 1)) || (lVar5 <= local_c8 * 3))
          goto LAB_1406481f2;
          lVar5 = ((lVar5 - local_c8) + -1) / 2;
          if (0 < lVar5) {
            lVar8 = lVar5;
          }
          lVar8 = lVar8 + 1;
        }
        else {
          if (lVar7 < 1) goto LAB_1406481f2;
          if (lVar5 * 2 < 1) goto LAB_140648185;
        }
        pQVar4 = pQStack_d0 + (lVar8 - lVar7) * 0x18;
        if (((local_c8 != 0) && (pQStack_d0 != pQVar4)) &&
           ((pQStack_d0 != (QString *)0x0 && (pQVar4 != (QString *)0x0)))) {
          memmove(pQVar4,pQStack_d0,local_c8 * 0x18);
        }
      }
    }
    pQStack_d0 = pQVar4;
    pQVar4 = pQStack_d0;
    if (bVar3) {
      QString::QString(pQStack_d0 + -0x18,local_78);
      pQStack_d0 = pQStack_d0 + -0x18;
    }
    else {
      memmove(pQStack_d0 + 0x18,pQStack_d0,local_c8 * 0x18);
      QString::QString(pQVar4,local_78);
    }
    local_c8 = local_c8 + 1;
    QString::~QString(local_78);
    if ((local_d8 == (QArrayData *)0x0) || (1 < *(int *)local_d8)) {
      FUN_1402b6850(&local_d8,0,0);
    }
    lVar8 = local_a0;
    pQVar4 = local_a8;
    _Memory = local_b0;
    local_a0 = local_c8;
    local_a8 = pQStack_d0;
    local_b0 = local_d8;
    local_d8 = (QArrayData *)0x0;
    pQStack_d0 = (QString *)0x0;
    local_c8 = 0;
    if (_Memory != (QArrayData *)0x0) {
      LOCK();
      iVar1 = *(int *)_Memory;
      *(int *)_Memory = *(int *)_Memory + -1;
      UNLOCK();
      if (iVar1 == 1) {
        pQVar9 = pQVar4 + lVar8 * 0x18;
        for (; pQVar4 != pQVar9; pQVar4 = pQVar4 + 0x18) {
          QString::~QString(pQVar4);
        }
        free(_Memory);
      }
    }
    if (local_d8 != (QArrayData *)0x0) {
      LOCK();
      iVar1 = *(int *)local_d8;
      *(int *)local_d8 = *(int *)local_d8 + -1;
      UNLOCK();
      if (iVar1 == 1) {
        pQVar4 = pQStack_d0 + local_c8 * 0x18;
        for (pQVar9 = pQStack_d0; pQVar9 != pQVar4; pQVar9 = pQVar9 + 0x18) {
          QString::~QString(pQVar9);
        }
        free(local_d8);
      }
    }
  }
  QString::~QString(local_98);
LAB_140648339:
  QString::QString(local_98,"stems-processor");
  QStandardPaths::findExecutable(param_2,(QList<QString> *)local_98);
  local_b8 = 3;
  QString::~QString(local_98);
  this = (QLoggingCategory *)FUN_1412d07f0();
  bVar3 = QLoggingCategory::isDebugEnabled(this);
  if (bVar3) {
    this_00 = (QMessageLogger *)
              QMessageLogger::QMessageLogger
                        ((QMessageLogger *)local_98,(char *)0x0,0,(char *)0x0,*(char **)(this + 8));
    pQVar6 = (QDebug *)QMessageLogger::debug(this_00);
    pQVar6 = QDebug::operator<<(pQVar6,"Stems Processor Path:");
    QDebug::operator<<(pQVar6,param_2);
    QDebug::~QDebug((QDebug *)&local_res18);
  }
  FUN_14029fe30(&local_b0);
  return param_2;
}


