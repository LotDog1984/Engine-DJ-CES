// FUN_1405548e0 @ 1405548e0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1405548e0(QObject *param_1,ulonglong param_2,int param_3)

{
  int *piVar1;
  QObject QVar2;
  undefined8 *puVar3;
  code *pcVar4;
  void **ppvVar5;
  void *pvVar6;
  bool bVar7;
  undefined1 uVar8;
  char cVar9;
  byte bVar10;
  int iVar11;
  undefined8 *puVar12;
  longlong *plVar13;
  QLoggingCategory *pQVar14;
  QMessageLogger *pQVar15;
  QDebug *pQVar16;
  uint *puVar17;
  QString *pQVar18;
  longlong lVar19;
  undefined8 uVar20;
  QObject **ppQVar21;
  longlong *plVar22;
  ulonglong uVar23;
  QObject *pQVar24;
  QObject *pQVar25;
  undefined4 *puVar26;
  undefined4 *puVar27;
  undefined8 *puVar28;
  undefined8 *puVar29;
  QObject *pQVar30;
  void *pvVar31;
  QObject *pQVar32;
  uint uVar33;
  uint uVar34;
  undefined1 *puVar35;
  longlong lVar36;
  undefined4 *puVar37;
  QObject *pQVar38;
  undefined1 *puVar39;
  ulonglong uVar40;
  ulonglong local_res8;
  ulonglong local_res10;
  int local_res18;
  undefined8 local_res20;
  ulonglong in_stack_fffffffffffffe80;
  undefined4 in_stack_fffffffffffffe8c;
  QObject *local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  ulonglong uStack_140;
  QObject *local_138;
  longlong *plStack_130;
  undefined8 local_128;
  ulonglong local_120;
  longlong local_118;
  longlong *local_110;
  QObject *local_108;
  char local_100;
  QObject *local_f8;
  undefined8 uStack_f0;
  QObject *local_e8;
  undefined1 local_e0;
  undefined7 uStack_df;
  ulonglong local_d0;
  ulonglong local_c8;
  longlong local_c0;
  longlong *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  QString local_a0 [24];
  ulonglong local_88;
  longlong local_80;
  undefined8 local_78;
  longlong *local_70;
  void *local_68 [3];
  ulonglong local_50;
  
  local_res20 = (undefined4 *)((ulonglong)local_res20 & 0xffffffff00000000);
  pQVar38 = param_1 + 0x50;
  local_100 = 0;
  local_res10 = param_2;
  local_res18 = param_3;
  local_108 = pQVar38;
  iVar11 = _Mtx_lock(pQVar38);
  if (iVar11 != 0) {
                    /* WARNING: Subroutine does not return */
    std::_Throw_Cpp_error(5);
  }
  if (*(int *)(param_1 + 0x9c) == 0x7fffffff) {
    *(undefined4 *)(param_1 + 0x9c) = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
    std::_Throw_Cpp_error(6);
  }
  local_100 = '\x01';
  puVar3 = *(undefined8 **)(param_1 + 0xc0);
  cVar9 = *(char *)((longlong)puVar3[1] + 0x19);
  puVar29 = puVar3;
  puVar28 = (undefined8 *)puVar3[1];
  while (cVar9 == '\0') {
    if ((ulonglong)puVar28[4] < param_2) {
      puVar12 = (undefined8 *)puVar28[2];
      puVar28 = puVar29;
    }
    else {
      puVar12 = (undefined8 *)*puVar28;
    }
    puVar29 = puVar28;
    puVar28 = puVar12;
    cVar9 = *(char *)((longlong)puVar12 + 0x19);
  }
  if ((*(char *)((longlong)puVar29 + 0x19) != '\0') || (param_2 < (ulonglong)puVar29[4])) {
    puVar29 = puVar3;
  }
  if ((param_1[0xa0] != (QObject)0x0) ||
     ((puVar29 != puVar3 && ((puVar29[5] != 0 || (param_3 == 0)))))) {
    bVar7 = false;
    goto LAB_140555b86;
  }
  local_88 = param_2;
  plVar13 = (longlong *)FUN_1405535e0(param_1 + 0xc0,&local_88);
  local_b8 = plVar13;
  if (pQVar38 == (QObject *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1402a28d0(1);
  }
  _Mtx_unlock(pQVar38);
  local_100 = '\0';
  FUN_140dc4fc0(*(undefined8 *)(param_1 + 0x40));
  if (local_118 == 0) {
    pQVar14 = (QLoggingCategory *)FUN_1412cf0e0();
    bVar7 = QLoggingCategory::isWarningEnabled(pQVar14);
    if (bVar7) {
      pQVar15 = (QMessageLogger *)
                QMessageLogger::QMessageLogger
                          ((QMessageLogger *)local_68,(char *)0x0,0,(char *)0x0,
                           *(char **)(pQVar14 + 8));
      pQVar16 = (QDebug *)QMessageLogger::warning(pQVar15);
      pQVar16 = QDebug::operator<<(pQVar16,"Failed to get track from librarian by universal id");
      QDebug::operator<<(pQVar16,param_2);
      QDebug::~QDebug((QDebug *)&local_res8);
    }
LAB_140555b47:
    bVar7 = false;
  }
  else {
    iVar11 = _Mtx_lock(pQVar38);
    if (iVar11 != 0) {
                    /* WARNING: Subroutine does not return */
      std::_Throw_Cpp_error(5);
    }
    if (*(int *)(param_1 + 0x9c) == 0x7fffffff) {
      *(undefined4 *)(param_1 + 0x9c) = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
      std::_Throw_Cpp_error(6);
    }
    if ((param_1[0xa0] != (QObject)0x0) || (*plVar13 == -1)) {
      _Mtx_unlock(pQVar38);
      goto LAB_140555b47;
    }
    _Mtx_unlock(pQVar38);
    FUN_140d8e200(local_118,&local_e0);
    local_f8 = (QObject *)0x0;
    uStack_f0 = (undefined8 *)0x0;
    local_e8 = (QObject *)0x0;
    uStack_150 = 0;
    local_148 = _DAT_141cb0070;
    uStack_140 = _UNK_141cb0078;
    local_158 = (QObject *)0x0;
    if (local_d0 != 0) {
      puVar35 = &local_e0;
      if (0xf < local_c8) {
        puVar35 = (undefined1 *)CONCAT71(uStack_df,local_e0);
      }
      puVar35 = puVar35 + local_d0;
      puVar39 = &local_e0;
      if (0xf < local_c8) {
        puVar39 = (undefined1 *)CONCAT71(uStack_df,local_e0);
      }
      FUN_14196e970();
      FUN_141971270(puVar39,puVar35,&local_158);
    }
    puVar17 = (uint *)FUN_141974de0(&local_res8,&local_158);
    uVar33 = *puVar17;
    if (7 < uStack_140) {
      pQVar32 = local_158;
      if ((0xfff < uStack_140 * 2 + 2) &&
         (pQVar32 = *(QObject **)(local_158 + -8),
         (QObject *)0x1f < local_158 + (-8 - (longlong)pQVar32))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pQVar32);
    }
    if (uVar33 < 2) {
      pQVar14 = (QLoggingCategory *)FUN_1412cf0e0();
      bVar7 = QLoggingCategory::isWarningEnabled(pQVar14);
      if (bVar7) {
        pQVar15 = (QMessageLogger *)
                  QMessageLogger::QMessageLogger
                            ((QMessageLogger *)local_68,(char *)0x0,0,(char *)0x0,
                             *(char **)(pQVar14 + 8));
        pQVar16 = (QDebug *)QMessageLogger::warning(pQVar15);
        pQVar16 = QDebug::operator<<(pQVar16,"Track is missing ");
        FUN_141956310(&local_158,&local_e0);
        pQVar18 = (QString *)
                  QString::fromStdString
                            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                             &local_138);
        QDebug::operator<<(pQVar16,pQVar18);
        QString::~QString((QString *)&local_138);
        if (0xf < uStack_140) {
          pQVar32 = local_158;
          if ((0xfff < uStack_140 + 1) &&
             (pQVar32 = *(QObject **)(local_158 + -8),
             (QObject *)0x1f < local_158 + (-8 - (longlong)pQVar32))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pQVar32);
        }
        local_148 = 0;
        uStack_140 = 0xf;
        local_158 = (QObject *)((ulonglong)local_158 & 0xffffffffffffff00);
        QDebug::~QDebug((QDebug *)&local_res8);
        bVar7 = false;
      }
      else {
LAB_140554f31:
        bVar7 = false;
      }
    }
    else {
      if (pQVar38 == (QObject *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_1402a28d0(1);
      }
      iVar11 = _Mtx_lock(pQVar38);
      if (iVar11 != 0) {
                    /* WARNING: Subroutine does not return */
        std::_Throw_Cpp_error(5);
      }
      if (*(int *)(param_1 + 0x9c) == 0x7fffffff) {
        *(undefined4 *)(param_1 + 0x9c) = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
        std::_Throw_Cpp_error(6);
      }
      local_100 = '\x01';
      pQVar32 = *(QObject **)(param_1 + 0xe0);
      local_f8 = *(QObject **)(pQVar32 + 8);
      uStack_f0 = (undefined8 *)((ulonglong)uStack_f0 & 0xffffffff00000000);
      QVar2 = local_f8[0x19];
      pQVar25 = pQVar32;
      pQVar24 = local_f8;
      while (QVar2 == (QObject)0x0) {
        pQVar30 = pQVar24 + 0x20;
        puVar35 = &local_e0;
        if (0xf < local_c8) {
          puVar35 = (undefined1 *)CONCAT71(uStack_df,local_e0);
        }
        uVar23 = *(ulonglong *)(pQVar24 + 0x30);
        if (0xf < *(ulonglong *)(pQVar24 + 0x38)) {
          pQVar30 = *(QObject **)pQVar30;
        }
        uVar40 = uVar23;
        if (local_d0 < uVar23) {
          uVar40 = local_d0;
        }
        local_f8 = pQVar24;
        iVar11 = memcmp(pQVar30,puVar35,uVar40);
        if (iVar11 == 0) {
          if (uVar23 < local_d0) goto LAB_140554e76;
LAB_140554d11:
          uStack_f0 = (undefined8 *)CONCAT44(uStack_f0._4_4_,1);
          pQVar30 = *(QObject **)pQVar24;
          pQVar25 = pQVar24;
        }
        else {
          if (-1 < iVar11) goto LAB_140554d11;
LAB_140554e76:
          uStack_f0 = (undefined8 *)((ulonglong)uStack_f0._4_4_ << 0x20);
          pQVar30 = *(QObject **)(pQVar24 + 0x10);
        }
        pQVar24 = pQVar30;
        QVar2 = pQVar30[0x19];
      }
      if (pQVar25[0x19] == (QObject)0x0) {
        pQVar24 = pQVar25 + 0x20;
        uVar23 = *(ulonglong *)(pQVar25 + 0x30);
        if (0xf < *(ulonglong *)(pQVar25 + 0x38)) {
          pQVar24 = *(QObject **)pQVar24;
        }
        puVar35 = &local_e0;
        if (0xf < local_c8) {
          puVar35 = (undefined1 *)CONCAT71(uStack_df,local_e0);
        }
        uVar40 = local_d0;
        if (uVar23 < local_d0) {
          uVar40 = uVar23;
        }
        iVar11 = memcmp(puVar35,pQVar24,uVar40);
        plVar13 = local_b8;
        if (iVar11 == 0) {
          if (uVar23 <= local_d0) goto LAB_140554e8f;
        }
        else if (-1 < iVar11) {
LAB_140554e8f:
          if (((param_1[0xa0] == (QObject)0x0) && (*local_b8 != -1)) &&
             (*(longlong *)(pQVar25 + 0x48) != 0)) {
            local_res8 = FUN_140d96330();
            plVar22 = (longlong *)FUN_1405535e0(param_1 + 0xc0,&local_res8);
            if (*plVar22 != -1) {
              if (*(char *)(*(longlong *)(pQVar25 + 0x48) + 0x518) != '\0') {
                _Mtx_unlock(pQVar38);
                local_100 = '\0';
                FUN_140552530(&local_res8,pQVar25 + 0x40,&local_118);
                bVar7 = false;
                goto LAB_14055558f;
              }
              FUN_140552f00(pQVar25 + 0x58,&local_118);
              *plVar13 = (longlong)(pQVar25 + 0x40);
            }
          }
          goto LAB_140554f31;
        }
      }
      if (*(longlong *)(param_1 + 0xe8) == 0x222222222222222) {
                    /* WARNING: Subroutine does not return */
        FUN_1402a2950();
      }
      plStack_130 = (longlong *)0x0;
      local_138 = param_1 + 0xe0;
      plVar13 = (longlong *)FUN_141981f80(0x78);
      plStack_130 = plVar13;
      FUN_1402aa5d0(plVar13 + 4,&local_e0);
      plVar13[0xe] = 0;
      plVar13[8] = 0;
      plVar13[9] = 0;
      plVar13[10] = 0;
      plVar13[0xb] = 0;
      plVar13[0xc] = 0;
      plVar13[0xd] = 0;
      *plVar13 = (longlong)pQVar32;
      plVar13[1] = (longlong)pQVar32;
      plVar13[2] = (longlong)pQVar32;
      *(undefined2 *)(plVar13 + 3) = 0;
      local_138 = local_f8;
      plStack_130 = uStack_f0;
      lVar19 = FUN_1402a2590(param_1 + 0xe0,&local_138,plVar13);
      plVar13 = (longlong *)(lVar19 + 0x40);
      local_c0 = lVar19;
      _Mtx_unlock(pQVar38);
      local_100 = '\0';
      FUN_140d8ffc0(local_118,&local_78);
      plVar22 = *(longlong **)(param_1 + 0x38);
      pcVar4 = *(code **)(*plVar22 + 8);
      uVar8 = FUN_140dd5510(local_78);
      local_res8 = CONCAT71(local_res8._1_7_,uVar8);
      if (*(longlong *)(local_118 + 0x618) == 0) {
        uStack_150 = 0;
        local_148 = _DAT_141ac9b00;
        uStack_140 = _UNK_141ac9b08;
        local_158 = (QObject *)0x0;
        ppQVar21 = &local_158;
        uVar33 = 2;
      }
      else {
        uVar20 = FUN_1409272a0(local_78);
        uVar20 = FUN_14029c470(uVar20);
        ppQVar21 = (QObject **)FUN_1402aa5d0(local_68,uVar20);
        uVar33 = 1;
      }
      local_res20 = (undefined4 *)CONCAT44(local_res20._4_4_,uVar33);
      uVar20 = QString::fromStdString
                         ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                          &local_f8);
      (*pcVar4)(plVar22,&local_80,uVar20,ppQVar21,local_res8 & 0xff,
                in_stack_fffffffffffffe80 & 0xffffffffffffff00);
      FUN_1402ac680(plVar13);
      if (local_80 != 0) {
        FUN_14197ec40((longlong)*(int *)(*(longlong *)(local_80 + 0x18) + 4) + local_80 + 0x18);
      }
      uVar34 = uVar33;
      if ((uVar33 & 2) != 0) {
        uVar34 = uVar33 & 0xfffffffd;
        local_res20 = (undefined4 *)(CONCAT44(local_res20._4_4_,uVar33) & 0xfffffffffffffffd);
        if (0xf < uStack_140) {
          pQVar32 = local_158;
          if ((0xfff < uStack_140 + 1) &&
             (pQVar32 = *(QObject **)(local_158 + -8),
             (QObject *)0x1f < local_158 + (-8 - (longlong)pQVar32))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
          free(pQVar32);
        }
        local_148 = _DAT_141ac9b00;
        uStack_140 = _UNK_141ac9b08;
        local_158 = (QObject *)((ulonglong)local_158 & 0xffffffffffffff00);
      }
      if (((uVar34 & 1) != 0) && (0xf < local_50)) {
        pvVar31 = local_68[0];
        if ((0xfff < local_50 + 1) &&
           (pvVar31 = *(void **)((longlong)local_68[0] + -8),
           0x1f < (ulonglong)((longlong)local_68[0] + (-8 - (longlong)pvVar31)))) {
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pvVar31);
      }
      if ((longlong *)*plVar13 == (longlong *)0x0) {
        pQVar14 = (QLoggingCategory *)FUN_1412cf0e0();
        bVar7 = QLoggingCategory::isWarningEnabled(pQVar14);
        if (bVar7) {
          pQVar15 = (QMessageLogger *)
                    QMessageLogger::QMessageLogger
                              ((QMessageLogger *)local_68,(char *)0x0,0,(char *)0x0,
                               *(char **)(pQVar14 + 8));
          pQVar16 = (QDebug *)QMessageLogger::warning(pQVar15);
          pQVar16 = QDebug::operator<<(pQVar16,"TrackData is missing ");
          FUN_141956310(&local_158,&local_e0);
          pQVar18 = (QString *)
                    QString::fromStdString
                              ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                               &local_f8);
          QDebug::operator<<(pQVar16,pQVar18);
          QString::~QString((QString *)&local_f8);
          if (0xf < uStack_140) {
            pQVar32 = local_158;
            if ((0xfff < uStack_140 + 1) &&
               (pQVar32 = *(QObject **)(local_158 + -8),
               (QObject *)0x1f < local_158 + (-8 - (longlong)pQVar32))) {
                    /* WARNING: Subroutine does not return */
              _invalid_parameter_noinfo_noreturn();
            }
            free(pQVar32);
          }
          local_148 = 0;
          uStack_140 = 0xf;
          local_158 = (QObject *)((ulonglong)local_158 & 0xffffffffffffff00);
          QDebug::~QDebug((QDebug *)&local_res8);
        }
LAB_14055554e:
        bVar7 = false;
      }
      else {
        cVar9 = (**(code **)(*(longlong *)*plVar13 + 0x1a0))();
        if (cVar9 != '\0') goto LAB_14055554e;
        if (local_res18 == 1) {
          if (*(char *)(local_118 + 0x520) != '\0') {
            *(undefined1 *)(local_118 + 0x520) = 0;
            *(undefined1 *)(local_118 + 0x510) = 1;
          }
          if (*(char *)(local_118 + 0x518) != '\0') {
            *(undefined1 *)(local_118 + 0x518) = 0;
            *(undefined1 *)(local_118 + 0x510) = 1;
          }
          if (*(double *)(local_118 + 0x158) != 0.0) {
            *(undefined8 *)(local_118 + 0x158) = 0;
            *(undefined1 *)(local_118 + 0x150) = 1;
          }
          *(undefined1 *)(local_118 + 0x160) = 1;
          if (*(char *)(local_118 + 0x430) != '\0') {
            *(undefined1 *)(local_118 + 0x430) = 0;
            *(undefined1 *)(local_118 + 0x420) = 1;
          }
          if (*(int *)(local_118 + 0x428) != -1) {
            *(undefined4 *)(local_118 + 0x428) = 0xffffffff;
            *(undefined1 *)(local_118 + 0x420) = 1;
          }
          iVar11 = thunk_FUN_140da0400(local_118);
          if (iVar11 != 0) {
            pQVar14 = (QLoggingCategory *)FUN_1412cf710();
            bVar7 = QLoggingCategory::isWarningEnabled(pQVar14);
            if (bVar7) {
              pQVar15 = (QMessageLogger *)
                        QMessageLogger::QMessageLogger
                                  ((QMessageLogger *)local_68,(char *)0x0,0,(char *)0x0,
                                   *(char **)(pQVar14 + 8));
              pQVar16 = (QDebug *)QMessageLogger::warning(pQVar15);
              pQVar16 = QDebug::operator<<(pQVar16,"Failed to reset analysis data for:");
              uVar20 = FUN_140d8e200(local_118,&local_138);
              FUN_141956310(&local_158,uVar20);
              pQVar18 = (QString *)
                        QString::fromStdString
                                  ((basic_string<char,std::char_traits<char>,std::allocator<char>_>
                                    *)&local_f8);
              pQVar16 = QDebug::operator<<(pQVar16,pQVar18);
              QString::~QString((QString *)&local_f8);
              pQVar16 = QDebug::operator<<(pQVar16,", error code:");
              QDebug::operator<<(pQVar16,iVar11);
              if (0xf < uStack_140) {
                pQVar32 = local_158;
                if ((0xfff < uStack_140 + 1) &&
                   (pQVar32 = *(QObject **)(local_158 + -8),
                   (QObject *)0x1f < local_158 + (-8 - (longlong)pQVar32))) {
                    /* WARNING: Subroutine does not return */
                  _invalid_parameter_noinfo_noreturn();
                }
                free(pQVar32);
              }
              local_148 = 0;
              uStack_140 = 0xf;
              local_158 = (QObject *)((ulonglong)local_158 & 0xffffffffffffff00);
              if (0xf < local_120) {
                pQVar32 = local_138;
                if ((0xfff < local_120 + 1) &&
                   (pQVar32 = *(QObject **)(local_138 + -8),
                   (QObject *)0x1f < local_138 + (-8 - (longlong)pQVar32))) {
                    /* WARNING: Subroutine does not return */
                  _invalid_parameter_noinfo_noreturn();
                }
                free(pQVar32);
              }
              local_128 = 0;
              local_120 = 0xf;
              local_138 = (QObject *)((ulonglong)local_138 & 0xffffffffffffff00);
              QDebug::~QDebug((QDebug *)&local_res8);
            }
            goto LAB_14055554e;
          }
          (**(code **)(*(longlong *)*plVar13 + 0x1d0))();
        }
        uVar23 = (**(code **)(*(longlong *)*plVar13 + 0x58))();
        if (uVar23 == local_res10) {
          if (local_110 != (longlong *)0x0) {
            LOCK();
            *(int *)(local_110 + 1) = (int)local_110[1] + 1;
            UNLOCK();
            pQVar38 = local_108;
          }
          *(longlong *)(lVar19 + 0x48) = local_118;
          lVar36 = *(longlong *)(lVar19 + 0x50);
          *(longlong **)(lVar19 + 0x50) = local_110;
          if (lVar36 != 0) {
            FUN_1402a2270(lVar36);
          }
        }
        else {
          FUN_140dc4fc0(*(undefined8 *)(param_1 + 0x40),&local_138);
          FUN_14030b8c0(lVar19 + 0x48);
          FUN_1402a0280(&local_138);
          if (*(longlong *)(lVar19 + 0x48) == 0) {
            pQVar14 = (QLoggingCategory *)FUN_1412cf0e0();
            bVar7 = QLoggingCategory::isWarningEnabled(pQVar14);
            if (bVar7) {
              pQVar15 = (QMessageLogger *)
                        QMessageLogger::QMessageLogger
                                  ((QMessageLogger *)local_68,(char *)0x0,0,(char *)0x0,
                                   *(char **)(pQVar14 + 8));
              pQVar16 = (QDebug *)QMessageLogger::warning(pQVar15);
              pQVar16 = QDebug::operator<<(pQVar16,
                                           "Failed to get track from librarian by universal id");
              QDebug::operator<<(pQVar16,uVar23);
              QDebug::~QDebug((QDebug *)&local_res8);
            }
            goto LAB_14055554e;
          }
        }
        iVar11 = _Mtx_lock(pQVar38);
        if (iVar11 != 0) {
                    /* WARNING: Subroutine does not return */
          std::_Throw_Cpp_error(5);
        }
        if (*(int *)(pQVar38 + 0x4c) == 0x7fffffff) {
          *(undefined4 *)(pQVar38 + 0x4c) = 0x7ffffffe;
                    /* WARNING: Subroutine does not return */
          std::_Throw_Cpp_error(6);
        }
        local_100 = '\x01';
        pQVar32 = param_1 + 0xc0;
        lVar36 = local_c0 + 0x40;
        uVar20 = *(undefined8 *)pQVar32;
        plStack_130 = (longlong *)0x0;
        local_138 = pQVar32;
        plStack_130 = (longlong *)FUN_141981f80(0x30);
        plStack_130[4] = uVar23;
        plStack_130[5] = lVar36;
        *plStack_130 = uVar20;
        plStack_130[1] = uVar20;
        plStack_130[2] = uVar20;
        *(undefined2 *)(plStack_130 + 3) = 0;
        pQVar25 = *(QObject **)pQVar32;
        pQVar24 = *(QObject **)(pQVar25 + 8);
        uStack_f0 = (undefined8 *)((ulonglong)uStack_f0 & 0xffffffff00000000);
        QVar2 = pQVar24[0x19];
        local_e8 = pQVar25;
        local_f8 = pQVar24;
        while (pQVar30 = pQVar24, QVar2 == (QObject)0x0) {
          uStack_f0._4_4_ = (uint)((ulonglong)uStack_f0 >> 0x20);
          if (*(ulonglong *)(pQVar30 + 0x20) < uVar23) {
            uStack_f0 = (undefined8 *)((ulonglong)uStack_f0._4_4_ << 0x20);
            pQVar24 = *(QObject **)(pQVar30 + 0x10);
          }
          else {
            uStack_f0 = (undefined8 *)CONCAT44(uStack_f0._4_4_,1);
            pQVar24 = *(QObject **)pQVar30;
            pQVar25 = pQVar30;
            local_e8 = pQVar30;
          }
          QVar2 = pQVar24[0x19];
          local_f8 = pQVar30;
        }
        if ((pQVar25[0x19] == (QObject)0x0) && (*(ulonglong *)(pQVar25 + 0x20) <= uVar23)) {
          bVar7 = false;
          free(plStack_130);
        }
        else {
          if (*(longlong *)(param_1 + 200) == 0x555555555555555) {
                    /* WARNING: Subroutine does not return */
            FUN_1402a2950();
          }
          local_138 = local_f8;
          plStack_130 = uStack_f0;
          pQVar25 = (QObject *)FUN_1402a2590(pQVar32,&local_138);
          bVar7 = true;
        }
        plVar22 = local_b8;
        if (((param_1[0xa0] != (QObject)0x0) || (*local_b8 == -1)) ||
           (*(longlong *)(pQVar25 + 0x28) == -1)) goto LAB_14055554e;
        if (uVar23 != local_res10) {
          if (((!bVar7) || (local_res18 != 1)) &&
             (*(char *)(*(longlong *)(lVar19 + 0x48) + 0x518) != '\0')) {
            _Mtx_unlock(pQVar38);
            local_100 = '\0';
            FUN_140552530(&local_res8,plVar13,&local_118);
            goto LAB_14055554e;
          }
          FUN_140552f00(lVar19 + 0x58,&local_118);
        }
        *plVar22 = local_c0 + 0x40;
        _Mtx_unlock(pQVar38);
        local_100 = '\0';
        (**(code **)(*(longlong *)*plVar13 + 0x60))((longlong *)*plVar13,local_a0);
        local_158 = param_1;
        QString::QString((QString *)&uStack_150,local_a0);
        ppvVar5 = (void **)*plVar13;
        local_138 = (QObject *)&LAB_141898020;
        puVar37 = (undefined4 *)0x0;
        plStack_130 = (longlong *)0xfffffff0;
        puVar26 = (undefined4 *)FUN_141981f80(0x30);
        puVar27 = puVar37;
        local_res20 = puVar26;
        if (puVar26 != (undefined4 *)0x0) {
          *puVar26 = 1;
          *(code **)(puVar26 + 2) = FUN_140556c90;
          *(QObject **)(puVar26 + 4) = local_158;
          QString::QString((QString *)(puVar26 + 6),(QString *)&uStack_150);
          puVar27 = puVar26;
        }
        QObject::connectImpl
                  ((QObject *)&local_res8,ppvVar5,(QObject *)&local_138,(void **)param_1,
                   (QSlotObjectBase *)0x0,(ConnectionType)puVar27,
                   (int *)CONCAT44(in_stack_fffffffffffffe8c,1),(QMetaObject *)0x0);
        QMetaObject::Connection::~Connection((Connection *)&local_res8);
        QString::~QString((QString *)&uStack_150);
        local_158 = param_1;
        QString::QString((QString *)&uStack_150,local_a0);
        ppvVar5 = (void **)*plVar13;
        local_138 = (QObject *)FUN_141897f80;
        plStack_130 = (longlong *)0xfffffff0;
        puVar26 = (undefined4 *)FUN_141981f80(0x30);
        puVar27 = puVar37;
        local_res20 = puVar26;
        if (puVar26 != (undefined4 *)0x0) {
          *puVar26 = 1;
          *(code **)(puVar26 + 2) = FUN_140556ce0;
          *(QObject **)(puVar26 + 4) = local_158;
          QString::QString((QString *)(puVar26 + 6),(QString *)&uStack_150);
          puVar27 = puVar26;
        }
        QObject::connectImpl
                  ((QObject *)&local_res8,ppvVar5,(QObject *)&local_138,(void **)param_1,
                   (QSlotObjectBase *)0x0,(ConnectionType)puVar27,
                   (int *)CONCAT44(in_stack_fffffffffffffe8c,1),(QMetaObject *)0x0);
        QMetaObject::Connection::~Connection((Connection *)&local_res8);
        QString::~QString((QString *)&uStack_150);
        local_158 = param_1;
        QString::QString((QString *)&uStack_150,local_a0);
        ppvVar5 = (void **)*plVar13;
        local_138 = (QObject *)&LAB_141898060;
        plStack_130 = (longlong *)0xfffffff0;
        puVar26 = (undefined4 *)FUN_141981f80(0x30);
        puVar27 = puVar37;
        local_res20 = puVar26;
        if (puVar26 != (undefined4 *)0x0) {
          *puVar26 = 1;
          *(code **)(puVar26 + 2) = FUN_140556d40;
          *(QObject **)(puVar26 + 4) = local_158;
          QString::QString((QString *)(puVar26 + 6),(QString *)&uStack_150);
          puVar27 = puVar26;
        }
        QObject::connectImpl
                  ((QObject *)&local_res8,ppvVar5,(QObject *)&local_138,(void **)param_1,
                   (QSlotObjectBase *)0x0,(ConnectionType)puVar27,
                   (int *)CONCAT44(in_stack_fffffffffffffe8c,1),(QMetaObject *)0x0);
        QMetaObject::Connection::~Connection((Connection *)&local_res8);
        QString::~QString((QString *)&uStack_150);
        local_158 = param_1;
        QString::QString((QString *)&uStack_150,local_a0);
        ppvVar5 = (void **)*plVar13;
        local_138 = (QObject *)&LAB_141897e60;
        plStack_130 = (longlong *)0xfffffff0;
        puVar26 = (undefined4 *)FUN_141981f80(0x30);
        puVar27 = puVar37;
        local_res20 = puVar26;
        if (puVar26 != (undefined4 *)0x0) {
          *puVar26 = 1;
          *(code **)(puVar26 + 2) = FUN_140556d40;
          *(QObject **)(puVar26 + 4) = local_158;
          QString::QString((QString *)(puVar26 + 6),(QString *)&uStack_150);
          puVar27 = puVar26;
        }
        QObject::connectImpl
                  ((QObject *)&local_res8,ppvVar5,(QObject *)&local_138,(void **)param_1,
                   (QSlotObjectBase *)0x0,(ConnectionType)puVar27,
                   (int *)CONCAT44(in_stack_fffffffffffffe8c,1),(QMetaObject *)0x0);
        QMetaObject::Connection::~Connection((Connection *)&local_res8);
        QString::~QString((QString *)&uStack_150);
        local_158 = param_1;
        QString::QString((QString *)&uStack_150,local_a0);
        ppvVar5 = (void **)*plVar13;
        local_138 = (QObject *)FUN_141897ec0;
        plStack_130 = (undefined8 *)0xfffffff0;
        puVar27 = (undefined4 *)FUN_141981f80(0x30);
        local_res20 = puVar27;
        if (puVar27 != (undefined4 *)0x0) {
          *puVar27 = 1;
          *(code **)(puVar27 + 2) = FUN_140556d90;
          *(QObject **)(puVar27 + 4) = local_158;
          QString::QString((QString *)(puVar27 + 6),(QString *)&uStack_150);
          puVar37 = puVar27;
        }
        QObject::connectImpl
                  ((QObject *)&local_res8,ppvVar5,(QObject *)&local_138,(void **)param_1,
                   (QSlotObjectBase *)0x0,(ConnectionType)puVar37,
                   (int *)CONCAT44(in_stack_fffffffffffffe8c,1),(QMetaObject *)0x0);
        QMetaObject::Connection::~Connection((Connection *)&local_res8);
        QString::~QString((QString *)&uStack_150);
        local_b0 = *(undefined8 *)(param_1 + 0x28);
        uStack_a8 = *(undefined8 *)(param_1 + 0x30);
        iVar11 = (**(code **)(*(longlong *)*plVar13 + 0xd0))();
        if ((iVar11 == -1) || (uStack_a8._1_1_ == '\0')) {
          bVar10 = 1;
        }
        else {
          bVar10 = 0;
        }
        uStack_a8 = CONCAT71(uStack_a8._1_7_,(byte)uStack_a8 & bVar10);
        cVar9 = (**(code **)(*(longlong *)*plVar13 + 0x180))((longlong *)*plVar13,&local_b0);
        bVar7 = cVar9 != '\0';
        if (!bVar7) {
          QObject::disconnect((QObject *)*plVar13,param_1,(char *)0x0);
        }
        QString::~QString(local_a0);
      }
      if (local_70 != (longlong *)0x0) {
        LOCK();
        plVar13 = local_70 + 1;
        lVar19 = *plVar13;
        *(int *)plVar13 = (int)*plVar13 + -1;
        UNLOCK();
        pQVar38 = local_108;
        if ((int)lVar19 == 1) {
          (**(code **)*local_70)(local_70);
          LOCK();
          piVar1 = (int *)((longlong)local_70 + 0xc);
          iVar11 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          pQVar38 = local_108;
          if (iVar11 == 1) {
            (**(code **)(*local_70 + 8))(local_70);
            pQVar38 = local_108;
          }
        }
      }
    }
LAB_14055558f:
    if (0xf < local_c8) {
      pvVar6 = (void *)CONCAT71(uStack_df,local_e0);
      pvVar31 = pvVar6;
      if ((0xfff < local_c8 + 1) &&
         (pvVar31 = *(void **)((longlong)pvVar6 + -8),
         0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar31)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar31);
    }
    local_d0 = 0;
    local_c8 = 0xf;
    local_e0 = 0;
  }
  if (local_110 != (longlong *)0x0) {
    LOCK();
    plVar13 = local_110 + 1;
    lVar19 = *plVar13;
    *(int *)plVar13 = (int)*plVar13 + -1;
    UNLOCK();
    pQVar38 = local_108;
    if ((int)lVar19 == 1) {
      (**(code **)*local_110)(local_110);
      LOCK();
      piVar1 = (int *)((longlong)local_110 + 0xc);
      iVar11 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      pQVar38 = local_108;
      if (iVar11 == 1) {
        (**(code **)(*local_110 + 8))(local_110);
        pQVar38 = local_108;
      }
    }
  }
LAB_140555b86:
  if (local_100 != '\0') {
    _Mtx_unlock(pQVar38);
  }
  return bVar7;
}


