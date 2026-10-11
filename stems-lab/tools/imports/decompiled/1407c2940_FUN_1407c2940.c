// FUN_1407c2940 @ 1407c2940
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_1407c2940(undefined8 *param_1,QString *param_2)

{
  undefined2 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 ******ppppppuVar4;
  size_t sVar5;
  ulonglong uVar6;
  size_t sVar7;
  ulonglong uVar8;
  bool bVar9;
  int iVar10;
  QFileInfo *this;
  QLoggingCategory *pQVar11;
  QByteArray *this_00;
  char *pcVar12;
  int *piVar13;
  undefined8 *puVar14;
  longlong lVar15;
  QMessageLogger *this_01;
  QDebug *this_02;
  QString *pQVar16;
  undefined2 *puVar17;
  __int64 _Var18;
  undefined8 *_Buf1;
  char *******pppppppcVar19;
  undefined8 *******_Buf2;
  longlong lVar20;
  char *******pppppppcVar21;
  undefined8 *******pppppppuVar22;
  QFileInfo local_res18 [8];
  QChar local_res20 [8];
  undefined4 uVar24;
  undefined8 uVar23;
  char ******local_120;
  undefined8 uStack_118;
  longlong local_110;
  ulonglong uStack_108;
  longlong local_100;
  undefined8 ******local_f8;
  undefined8 uStack_f0;
  size_t local_e8;
  ulonglong local_e0;
  longlong local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  ulonglong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  QElapsedTimer local_a8 [16];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 local_78 [32];
  QMessageLogger local_58 [32];
  
  lVar20 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  this = (QFileInfo *)QFileInfo::QFileInfo(local_res18,param_2);
  bVar9 = QFileInfo::exists(this);
  QFileInfo::~QFileInfo(local_res18);
  if (!bVar9) {
    return param_1;
  }
  QElapsedTimer::QElapsedTimer(local_a8);
  pQVar11 = (QLoggingCategory *)FUN_1412cf8c0();
  bVar9 = QLoggingCategory::isInfoEnabled(pQVar11);
  if (bVar9) {
    QElapsedTimer::start(local_a8);
  }
  this_00 = (QByteArray *)QString::toUtf8(param_2);
  pcVar12 = QByteArray::constData(this_00);
  uStack_118 = 0;
  local_110 = _DAT_141cb0070;
  uStack_108 = _UNK_141cb0078;
  local_120 = (char ******)0x0;
  FUN_14196e970();
  FUN_141971270(pcVar12,0);
  local_100 = 0;
  FUN_141976e70(&local_100);
  FUN_1402a29e0(&local_120);
  QByteArray::~QByteArray((QByteArray *)&local_d0);
  local_d8 = 0;
  do {
    if ((local_100 == lVar20) ||
       (((local_100 == 0 || (*(longlong *)(local_100 + 8) == *(longlong *)(local_100 + 0x10))) &&
        ((lVar20 == 0 || (*(longlong *)(lVar20 + 8) == *(longlong *)(lVar20 + 0x10)))))))
    goto LAB_1407c2e6b;
    FUN_1402a5d70(local_78,*(longlong *)(*(longlong *)(local_100 + 0x10) + -8) + 8);
    local_d0 = 0;
    uStack_c8 = 0;
    local_c0 = 0;
    piVar13 = (int *)FUN_141974de0(local_res18,local_78);
    if (((local_c0 & 1) == 0) || ((local_c0 == 1 && ((int)local_d0 == 0)))) {
      if (*piVar13 == 3) {
        FUN_14196f3f0(local_78,&local_120);
        uStack_f0 = 0;
        local_e8 = 0;
        local_e0 = 0xf;
        local_f8 = (undefined8 *******)0x0;
        puVar14 = DAT_142b0e040;
        puVar2 = DAT_142b0e048;
        pppppppuVar22 = (undefined8 *******)local_f8;
        sVar7 = local_e8;
        uVar8 = local_e0;
        if (local_110 != 0) {
          pppppppcVar19 = &local_120;
          if (7 < uStack_108) {
            pppppppcVar19 = (char *******)local_120;
          }
          lVar15 = local_110 * 2;
          pppppppcVar21 = &local_120;
          if (7 < uStack_108) {
            pppppppcVar21 = (char *******)local_120;
          }
          FUN_14196e970();
          FUN_141971350(pppppppcVar21,(longlong)pppppppcVar19 + lVar15);
          puVar14 = DAT_142b0e040;
          puVar2 = DAT_142b0e048;
          pppppppuVar22 = (undefined8 *******)local_f8;
          sVar7 = local_e8;
          uVar8 = local_e0;
        }
        for (; uVar6 = local_e0, sVar5 = local_e8, ppppppuVar4 = local_f8, puVar3 = DAT_142b0e048,
            bVar9 = puVar14 != DAT_142b0e048, DAT_142b0e048 = puVar2, bVar9; puVar14 = puVar14 + 4)
        {
          _Buf2 = &local_f8;
          if (0xf < local_e0) {
            _Buf2 = (undefined8 *******)local_f8;
          }
          _Buf1 = puVar14;
          if (0xf < (ulonglong)puVar14[3]) {
            _Buf1 = (undefined8 *)*puVar14;
          }
          bVar9 = puVar14[2] == local_e8;
          local_f8 = pppppppuVar22;
          local_e8 = sVar7;
          local_e0 = uVar8;
          if ((bVar9) &&
             (iVar10 = memcmp(_Buf1,_Buf2,puVar14[2]), pppppppuVar22 = (undefined8 *******)local_f8,
             sVar7 = local_e8, uVar8 = local_e0, iVar10 == 0)) break;
          puVar2 = DAT_142b0e048;
          pppppppuVar22 = (undefined8 *******)local_f8;
          sVar7 = local_e8;
          uVar8 = local_e0;
          local_e0 = uVar6;
          local_e8 = sVar5;
          local_f8 = ppppppuVar4;
          DAT_142b0e048 = puVar3;
        }
        local_e0 = uVar8;
        local_e8 = sVar7;
        local_f8 = pppppppuVar22;
        if (0xf < uVar6) {
          pppppppuVar22 = (undefined8 *******)ppppppuVar4;
          if ((0xfff < uVar6 + 1) &&
             (pppppppuVar22 = (undefined8 *******)ppppppuVar4[-1],
             0x1f < (ulonglong)((longlong)ppppppuVar4 + (-8 - (longlong)pppppppuVar22)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pppppppuVar22);
        }
        local_e8 = 0;
        local_e0 = 0xf;
        local_f8 = (undefined8 ******)((ulonglong)local_f8 & 0xffffffffffffff00);
        FUN_1402a29e0(&local_120);
        if (puVar14 != puVar3) {
          *(uint *)(local_100 + 0x20) = *(uint *)(local_100 + 0x20) | 0x10;
        }
      }
      else {
        FUN_14196ffa0(local_78,local_58);
        puVar14 = (undefined8 *)FUN_14196fa80(local_58,&local_98);
        uStack_118 = 0;
        local_110 = 0;
        uStack_108 = 0xf;
        local_120 = (char ******)0x0;
        lVar15 = puVar14[2];
        if (lVar15 != 0) {
          if (7 < (ulonglong)puVar14[3]) {
            puVar14 = (undefined8 *)*puVar14;
          }
          FUN_14196e970();
          FUN_141971350(puVar14,(longlong)puVar14 + lVar15 * 2,&local_120);
        }
        lVar15 = 0;
        FUN_1402a29e0(&local_98);
        pppppppcVar19 = &local_120;
        if ((uStack_108 < 0x10) ||
           (pppppppcVar19 = (char *******)local_120, (char *******)local_120 != (char *******)0x0))
        {
          lVar15 = -1;
          do {
            lVar15 = lVar15 + 1;
          } while (*(char *)((longlong)pppppppcVar19 + lVar15) != '\0');
        }
        local_b8 = lVar15;
        pcVar12 = QByteArrayView::castHelper((char *)pppppppcVar19);
        uStack_b0._0_4_ = SUB84(pcVar12,0);
        uStack_b0._4_4_ = (undefined4)((ulonglong)pcVar12 >> 0x20);
        local_98 = (undefined4)local_b8;
        uStack_94 = local_b8._4_4_;
        uStack_90 = (undefined4)uStack_b0;
        uStack_8c = uStack_b0._4_4_;
        uStack_b0 = pcVar12;
        QString::fromUtf8(&local_f8,&local_98);
        FUN_1402a8b90(param_1,param_1[2]);
        if (((int *)*param_1 == (int *)0x0) || (lVar20 = local_d8, 1 < *(int *)*param_1)) {
          FUN_1402b6850(param_1,0);
        }
        QString::~QString((QString *)&local_f8);
        if (0xf < uStack_108) {
          pppppppcVar19 = (char *******)local_120;
          if ((0xfff < uStack_108 + 1) &&
             (pppppppcVar19 = (char *******)local_120[-1],
             (char *)0x1f < (char *)((longlong)local_120 + (-8 - (longlong)pppppppcVar19)))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pppppppcVar19);
        }
        local_110 = 0;
        uStack_108 = 0xf;
        local_120 = (char ******)((ulonglong)local_120 & 0xffffffffffffff00);
        FUN_1402a29e0(local_58);
      }
    }
    FUN_141977260(&local_100);
    if (((local_c0 & 1) != 0) && ((local_c0 != 1 || ((int)local_d0 != 0)))) {
      FUN_1402a29e0(local_78);
LAB_1407c2e6b:
      pQVar11 = (QLoggingCategory *)FUN_1412cf8c0();
      bVar9 = QLoggingCategory::isInfoEnabled(pQVar11);
      while (bVar9 != false) {
        pcVar12 = *(char **)(pQVar11 + 8);
        this_01 = (QMessageLogger *)
                  QMessageLogger::QMessageLogger(local_58,(char *)0x0,0,(char *)0x0,pcVar12);
        uVar24 = (undefined4)((ulonglong)pcVar12 >> 0x20);
        this_02 = (QDebug *)QMessageLogger::info(this_01);
        pQVar16 = (QString *)QString::QString((QString *)&local_98,"Took %1 ms to gather %2 files");
        puVar17 = (undefined2 *)QChar::QChar((QChar *)local_res18,L' ');
        uVar1 = *puVar17;
        _Var18 = QElapsedTimer::elapsed(local_a8);
        uVar23 = CONCAT44(uVar24,10);
        pQVar16 = (QString *)QString::arg(pQVar16,&local_d0,_Var18,0,uVar23,uVar1);
        uVar24 = (undefined4)((ulonglong)uVar23 >> 0x20);
        puVar17 = (undefined2 *)QChar::QChar(local_res20,L' ');
        pQVar16 = (QString *)
                  QString::arg(pQVar16,&local_f8,param_1[2],0,CONCAT44(uVar24,10),*puVar17);
        QDebug::operator<<(this_02,pQVar16);
        QString::~QString((QString *)&local_f8);
        QString::~QString((QString *)&local_d0);
        QString::~QString((QString *)&local_98);
        QDebug::~QDebug((QDebug *)&local_b8);
        bVar9 = false;
      }
      FUN_1407c2730(&local_d8);
      FUN_1407c2730(&local_100);
      return param_1;
    }
    FUN_1402a29e0(local_78);
  } while( true );
}


