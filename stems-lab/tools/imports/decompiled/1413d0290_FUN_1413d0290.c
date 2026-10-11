// FUN_1413d0290 @ 1413d0290
// calls: [CreateFileW]

longlong * FUN_1413d0290(longlong *param_1,longlong *param_2,char param_3,char param_4)

{
  void *_Dst;
  undefined2 uVar1;
  code *pcVar2;
  longlong lVar3;
  void *_Src;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  bool bVar11;
  uint uVar12;
  UINT UVar13;
  undefined4 uVar14;
  QString *pQVar15;
  undefined2 *puVar16;
  LPCWSTR lpRootPathName;
  QStorageInfo *this;
  QByteArray *this_00;
  __int64 _Var17;
  char *pcVar18;
  longlong lVar19;
  longlong lVar20;
  longlong lVar21;
  longlong lVar22;
  longlong lVar23;
  uint uVar24;
  int iVar25;
  QChar local_e4 [2];
  QChar local_e2 [2];
  DWORD local_e0;
  QString local_d8 [24];
  QString local_c0 [24];
  QStorageInfo local_a8 [16];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  QString local_78 [24];
  QByteArray local_60 [32];
  
  iVar25 = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  bVar8 = false;
  bVar6 = false;
  bVar11 = false;
  uVar24 = 1;
  bVar9 = false;
  bVar7 = false;
  bVar5 = false;
  uVar12 = GetLogicalDrives();
  local_e0 = uVar12;
  do {
    if ((uVar12 & uVar24) != 0) {
      pQVar15 = (QString *)QString::QString(local_78,"%1:");
      puVar16 = (undefined2 *)QChar::QChar(local_e4,L' ');
      uVar1 = *puVar16;
      puVar16 = (undefined2 *)QChar::QChar(local_e2,iVar25 + 0x41);
      QString::arg(pQVar15,local_d8,*puVar16,0,uVar1);
      QString::~QString(local_78);
      cVar10 = FUN_1413d0bc0(param_1,local_d8,0);
      lpRootPathName = (LPCWSTR)QString::utf16(local_d8);
      UVar13 = GetDriveTypeW(lpRootPathName);
      if ((UVar13 == 4) || (cVar10 != param_3)) {
LAB_1413d0444:
        bVar4 = false;
      }
      else {
        if (param_4 != '\0') {
          pcVar2 = *(code **)(*param_1 + 0x60);
          this = (QStorageInfo *)QStorageInfo::QStorageInfo(local_a8,local_d8);
          this_00 = (QByteArray *)QStorageInfo::fileSystemType(this);
          _Var17 = QByteArray::size(this_00);
          bVar11 = QByteArray::isNull(this_00);
          if (bVar11) {
            pcVar18 = (char *)0x0;
          }
          else {
            pcVar18 = QByteArray::data(this_00);
          }
          local_88 = _Var17;
          pcVar18 = QByteArrayView::castHelper(pcVar18);
          uStack_80._0_4_ = SUB84(pcVar18,0);
          uStack_80._4_4_ = (undefined4)((ulonglong)pcVar18 >> 0x20);
          local_98 = (undefined4)local_88;
          uStack_94 = local_88._4_4_;
          uStack_90 = (undefined4)uStack_80;
          uStack_8c = uStack_80._4_4_;
          uStack_80 = pcVar18;
          QString::fromUtf8(local_c0,&local_98);
          bVar9 = true;
          bVar7 = true;
          bVar5 = true;
          uVar14 = (*pcVar2)(param_1,local_c0);
          cVar10 = FUN_1413ce850(param_1,uVar14);
          bVar11 = bVar5;
          bVar6 = bVar7;
          bVar8 = bVar9;
          if (cVar10 == '\0') goto LAB_1413d0444;
        }
        bVar4 = true;
      }
      if (bVar11) {
        bVar11 = false;
        QString::~QString(local_c0);
        bVar5 = bVar11;
        bVar7 = bVar6;
        bVar9 = bVar8;
      }
      if (bVar6) {
        bVar6 = false;
        QByteArray::~QByteArray(local_60);
        bVar5 = bVar11;
        bVar7 = bVar6;
        bVar9 = bVar8;
      }
      if (bVar8) {
        bVar8 = false;
        QStorageInfo::~QStorageInfo(local_a8);
        bVar5 = bVar11;
        bVar7 = bVar6;
        bVar9 = bVar8;
      }
      if (bVar4) {
        lVar3 = param_2[2];
        if (((int *)*param_2 == (int *)0x0) ||
           (bVar11 = bVar5, bVar6 = bVar7, bVar8 = bVar9, 1 < *(int *)*param_2)) {
LAB_1413d057e:
          QString::QString(local_c0,local_d8);
          if ((param_2[2] == 0) || (lVar3 != 0)) {
            cVar10 = '\0';
          }
          else {
            cVar10 = '\x01';
          }
          if (((int *)*param_2 == (int *)0x0) ||
             (bVar11 = bVar5, bVar6 = bVar7, bVar8 = bVar9, 1 < *(int *)*param_2)) {
LAB_1413d074b:
            FUN_1402b6850(param_2,cVar10,1);
          }
          else if (cVar10 == '\x01') {
            if (*param_2 == 0) goto LAB_1413d06a7;
            if ((longlong)(param_2[1] - (*param_2 + 0x17U & 0xfffffffffffffff8)) < 0x18)
            goto LAB_1413d05e3;
          }
          else {
LAB_1413d05e3:
            if (cVar10 == '\0') {
              lVar22 = *param_2;
              if (lVar22 == 0) goto LAB_1413d06a7;
              if (0 < (*(longlong *)(lVar22 + 8) -
                      (longlong)(param_2[1] - (lVar22 + 0x17U & 0xfffffffffffffff8)) / 0x18) -
                      param_2[2]) goto LAB_1413d075f;
            }
            lVar22 = *param_2;
            if (lVar22 == 0) {
LAB_1413d06a7:
              lVar19 = 0;
              lVar20 = 0;
              lVar22 = 0;
            }
            else {
              lVar19 = *(longlong *)(lVar22 + 8);
              lVar20 = param_2[1] - (lVar22 + 0x17U & 0xfffffffffffffff8);
              lVar20 = lVar20 / 6 + (lVar20 >> 0x3f);
              lVar20 = (lVar20 >> 2) - (lVar20 >> 0x3f);
              lVar22 = (lVar19 - (longlong)(param_2[1] - (lVar22 + 0x17U & 0xfffffffffffffff8)) /
                                 0x18) - param_2[2];
            }
            lVar21 = 0;
            if (cVar10 == '\0') {
              if (lVar20 < 1) goto LAB_1413d074b;
              lVar23 = param_2[2];
              if (lVar19 * 2 <= lVar23 * 3) goto LAB_1413d06d1;
            }
            else {
LAB_1413d06d1:
              if (((cVar10 != '\x01') || (lVar22 < 1)) ||
                 (lVar23 = param_2[2], lVar19 <= lVar23 * 3)) goto LAB_1413d074b;
              lVar22 = ((lVar19 - lVar23) + -1) / 2;
              lVar21 = 0;
              if (0 < lVar22) {
                lVar21 = lVar22;
              }
              lVar21 = lVar21 + 1;
            }
            _Src = (void *)param_2[1];
            _Dst = (void *)((longlong)_Src + (lVar21 - lVar20) * 0x18);
            if (((lVar23 != 0) && (_Src != _Dst)) &&
               ((_Src != (void *)0x0 && (_Dst != (void *)0x0)))) {
              memmove(_Dst,_Src,lVar23 * 0x18);
            }
            param_2[1] = (longlong)_Dst;
          }
LAB_1413d075f:
          if (cVar10 == '\0') {
            pQVar15 = (QString *)(param_2[1] + lVar3 * 0x18);
            memmove(pQVar15 + 0x18,pQVar15,(param_2[2] - lVar3) * 0x18);
            QString::QString(pQVar15,local_c0);
          }
          else {
            QString::QString((QString *)(param_2[1] + -0x18),local_c0);
            param_2[1] = param_2[1] + -0x18;
          }
          param_2[2] = param_2[2] + 1;
          QString::~QString(local_c0);
        }
        else {
          lVar22 = param_2[2];
          if ((lVar3 == lVar22) &&
             ((lVar19 = *param_2, lVar19 != 0 &&
              (*(longlong *)(lVar19 + 8) - lVar22 !=
               (longlong)(param_2[1] - (lVar19 + 0x17U & 0xfffffffffffffff8)) / 0x18)))) {
            QString::QString((QString *)(param_2[1] + lVar22 * 0x18),local_d8);
            param_2[2] = param_2[2] + 1;
          }
          else {
            if ((lVar3 != 0) ||
               ((*param_2 == 0 ||
                (lVar19 = param_2[1] - (*param_2 + 0x17U & 0xfffffffffffffff8),
                lVar22 = lVar19 >> 0x3f, lVar19 / 0x18 + lVar22 == lVar22)))) goto LAB_1413d057e;
            QString::QString((QString *)(param_2[1] + -0x18),local_d8);
            param_2[1] = param_2[1] + -0x18;
            param_2[2] = param_2[2] + 1;
          }
        }
        if (((int *)*param_2 == (int *)0x0) ||
           (bVar11 = bVar5, bVar6 = bVar7, bVar8 = bVar9, 1 < *(int *)*param_2)) {
          FUN_1402b6850(param_2,0,0);
        }
      }
      QString::~QString(local_d8);
      uVar12 = local_e0;
    }
    iVar25 = iVar25 + 1;
    uVar24 = uVar24 << 1 | (uint)((int)uVar24 < 0);
    if (0x19 < iVar25) {
      return param_2;
    }
  } while( true );
}


