// FUN_1418b22a0 @ 1418b22a0
// calls: [avio_open, avformat_new_stream, avcodec_find_encoder, avcodec_parameters_from_context]

undefined8 FUN_1418b22a0(longlong param_1)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  undefined8 ****ppppuVar6;
  ulonglong uVar7;
  QLoggingCategory *pQVar8;
  QMessageLogger *pQVar9;
  QDebug *pQVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  ulonglong uVar14;
  void *_Dst;
  ulonglong _Size;
  ulonglong local_res8;
  undefined8 local_res10;
  ulonglong in_stack_ffffffffffffff78;
  char *local_78;
  undefined8 uStack_70;
  undefined8 ***local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_res8 = local_res8 & 0xffffffff00000000;
  local_res10 = 0;
  lVar12 = param_1 + 0x60;
  if (7 < *(ulonglong *)(param_1 + 0x78)) {
    lVar12 = *(longlong *)(param_1 + 0x60);
  }
  uVar7 = *(ulonglong *)(param_1 + 0x70);
  uVar4 = FUN_141980938();
  uStack_50 = 0;
  local_48 = 0;
  local_40 = 0xf;
  local_58 = (undefined8 ****)0x0;
  local_res8 = CONCAT44(local_res8._4_4_,8);
  if (uVar7 != 0) {
    if (0x7fffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a28d0(0x16);
    }
    in_stack_ffffffffffffff78 = in_stack_ffffffffffffff78 & 0xffffffff00000000;
    uVar5 = __std_fs_convert_wide_to_narrow
                      (uVar4,lVar12,uVar7 & 0xffffffff,0,in_stack_ffffffffffffff78);
    if ((int)(uVar5 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a2910(uVar5 >> 0x20);
    }
    uVar14 = (ulonglong)(int)uVar5;
    if (local_48 < uVar14) {
      _Size = uVar14 - local_48;
      if (local_40 - local_48 < _Size) {
        FUN_1402a5720(&local_58,_Size,local_res8 & 0xff,_Size,
                      in_stack_ffffffffffffff78 & 0xffffffffffffff00);
      }
      else {
        ppppuVar6 = &local_58;
        if (0xf < local_40) {
          ppppuVar6 = (undefined8 ****)local_58;
        }
        _Dst = (void *)((longlong)ppppuVar6 + local_48);
        local_48 = uVar14;
        memset(_Dst,0,_Size);
        *(undefined1 *)(_Size + (longlong)_Dst) = 0;
      }
    }
    else {
      ppppuVar6 = &local_58;
      if (0xf < local_40) {
        ppppuVar6 = (undefined8 ****)local_58;
      }
      local_48 = uVar14;
      *(undefined1 *)((longlong)ppppuVar6 + uVar14) = 0;
    }
    ppppuVar6 = &local_58;
    if (0xf < local_40) {
      ppppuVar6 = (undefined8 ****)local_58;
    }
    uVar7 = __std_fs_convert_wide_to_narrow
                      (uVar4,lVar12,uVar7 & 0xffffffff,ppppuVar6,uVar5 & 0xffffffff);
    if ((int)(uVar7 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a2910(uVar7 >> 0x20);
    }
  }
  local_78 = "avio_open";
  uStack_70 = 9;
  ppppuVar6 = &local_58;
  if (0xf < local_40) {
    ppppuVar6 = (undefined8 ****)local_58;
  }
  uVar4 = avio_open(&local_res10,ppppuVar6);
  cVar2 = FUN_1418b2f50(uVar4);
  if (cVar2 == '\0') {
    uVar7 = avformat_alloc_context();
    if (*(longlong *)(param_1 + 0x50) != 0) {
      local_res8 = uVar7;
      avformat_close_input(param_1 + 0x50);
      uVar7 = local_res8;
    }
    local_res8 = 0;
    *(ulonglong *)(param_1 + 0x50) = uVar7;
    if (uVar7 == 0) {
      pQVar8 = (QLoggingCategory *)FUN_1418b2b20();
      bVar3 = QLoggingCategory::isWarningEnabled(pQVar8);
      if (bVar3) {
        pQVar9 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger
                           ((QMessageLogger *)&local_78,(char *)0x0,0,(char *)0x0,
                            *(char **)(pQVar8 + 8));
        pQVar10 = (QDebug *)QMessageLogger::warning(pQVar9);
        QDebug::operator<<(pQVar10,"ffmpegFileWriter: Could not allocate output format context");
LAB_1418b24b8:
        QDebug::~QDebug((QDebug *)&local_res8);
      }
    }
    else {
      *(undefined8 *)(uVar7 + 0x20) = local_res10;
      uVar11 = av_guess_format(0);
      *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 0x10) = uVar11;
      if (*(longlong *)(*(longlong *)(param_1 + 0x50) + 0x10) == 0) {
        pQVar8 = (QLoggingCategory *)FUN_1418b2b20();
        bVar3 = QLoggingCategory::isWarningEnabled(pQVar8);
        if (bVar3) {
          pQVar9 = (QMessageLogger *)
                   QMessageLogger::QMessageLogger
                             ((QMessageLogger *)&local_78,(char *)0x0,0,(char *)0x0,
                              *(char **)(pQVar8 + 8));
          pQVar10 = (QDebug *)QMessageLogger::warning(pQVar9);
          QDebug::operator<<(pQVar10,"ffmpegFileWriter: Could not find output file format");
          goto LAB_1418b24b8;
        }
      }
      else {
        ppppuVar6 = &local_58;
        if (0xf < local_40) {
          ppppuVar6 = (undefined8 ****)local_58;
        }
        uVar11 = av_strdup(ppppuVar6);
        *(undefined8 *)(*(longlong *)(param_1 + 0x50) + 0x438) = uVar11;
        if (*(longlong *)(*(longlong *)(param_1 + 0x50) + 0x438) == 0) {
          pQVar8 = (QLoggingCategory *)FUN_1418b2b20();
          bVar3 = QLoggingCategory::isWarningEnabled(pQVar8);
          if (bVar3) {
            pQVar9 = (QMessageLogger *)
                     QMessageLogger::QMessageLogger
                               ((QMessageLogger *)&local_78,(char *)0x0,0,(char *)0x0,
                                *(char **)(pQVar8 + 8));
            pQVar10 = (QDebug *)QMessageLogger::warning(pQVar9);
            QDebug::operator<<(pQVar10,"ffmpegFileWriter: Could not allocate url.");
            goto LAB_1418b24b8;
          }
        }
        else {
          lVar12 = avcodec_find_encoder(0x15002);
          if (lVar12 == 0) {
            pQVar8 = (QLoggingCategory *)FUN_1418b2b20();
            bVar3 = QLoggingCategory::isWarningEnabled(pQVar8);
            if (bVar3) {
              pQVar9 = (QMessageLogger *)
                       QMessageLogger::QMessageLogger
                                 ((QMessageLogger *)&local_78,(char *)0x0,0,(char *)0x0,
                                  *(char **)(pQVar8 + 8));
              pQVar10 = (QDebug *)QMessageLogger::warning(pQVar9);
              QDebug::operator<<(pQVar10,"ffmpegFileWriter: Could not find an AAC encoder.");
              goto LAB_1418b24b8;
            }
          }
          else {
            lVar13 = avformat_new_stream(*(undefined8 *)(param_1 + 0x50));
            if (lVar13 == 0) {
              pQVar8 = (QLoggingCategory *)FUN_1418b2b20();
              bVar3 = QLoggingCategory::isWarningEnabled(pQVar8);
              if (bVar3) {
                pQVar9 = (QMessageLogger *)
                         QMessageLogger::QMessageLogger
                                   ((QMessageLogger *)&local_78,(char *)0x0,0,(char *)0x0,
                                    *(char **)(pQVar8 + 8));
                pQVar10 = (QDebug *)QMessageLogger::warning(pQVar9);
                QDebug::operator<<(pQVar10,"ffmpegFileWriter: Could not create new stream");
                goto LAB_1418b24b8;
              }
            }
            else {
              uVar7 = avcodec_alloc_context3(lVar12);
              if (*(longlong *)(param_1 + 0x48) != 0) {
                local_res8 = uVar7;
                avcodec_free_context(param_1 + 0x48);
                uVar7 = local_res8;
              }
              local_res8 = 0;
              *(ulonglong *)(param_1 + 0x48) = uVar7;
              if (uVar7 == 0) {
                pQVar8 = (QLoggingCategory *)FUN_1418b2b20();
                bVar3 = QLoggingCategory::isWarningEnabled(pQVar8);
                if (bVar3) {
                  pQVar9 = (QMessageLogger *)
                           QMessageLogger::QMessageLogger
                                     ((QMessageLogger *)&local_78,(char *)0x0,0,(char *)0x0,
                                      *(char **)(pQVar8 + 8));
                  pQVar10 = (QDebug *)QMessageLogger::warning(pQVar9);
                  QDebug::operator<<(pQVar10,
                                     "ffmpegFileWriter: Could not allocate an encoding context");
                  goto LAB_1418b24b8;
                }
              }
              else {
                *(undefined4 *)(uVar7 + 0x194) = *(undefined4 *)(param_1 + 0x10);
                uVar11 = FUN_1418b3470(*(undefined4 *)(param_1 + 0x10));
                *(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x1b0) = uVar11;
                *(undefined4 *)(*(longlong *)(param_1 + 0x48) + 400) =
                     *(undefined4 *)(param_1 + 0xc);
                *(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x198) =
                     **(undefined4 **)(lVar12 + 0x38);
                *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x38) =
                     (longlong)*(int *)(param_1 + 0x18);
                *(undefined4 *)(lVar13 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
                *(undefined4 *)(lVar13 + 0x18) = 1;
                if ((*(byte *)(*(longlong *)(*(longlong *)(param_1 + 0x50) + 0x10) + 0x2c) & 0x40)
                    != 0) {
                  puVar1 = (uint *)(*(longlong *)(param_1 + 0x48) + 0x4c);
                  *puVar1 = *puVar1 | 0x400000;
                }
                local_78 = "avcodec_open2 (ffmpegFileWriter)";
                uStack_70 = 0x20;
                uVar4 = avcodec_open2(*(undefined8 *)(param_1 + 0x48),lVar12);
                cVar2 = FUN_1418b2f50(uVar4,&local_78);
                if (cVar2 == '\0') {
                  local_78 = "avcodec_parameters_from_context";
                  uStack_70 = 0x1f;
                  uVar4 = avcodec_parameters_from_context
                                    (*(undefined8 *)(lVar13 + 0xd0),*(undefined8 *)(param_1 + 0x48))
                  ;
                  cVar2 = FUN_1418b2f50(uVar4);
                  if (cVar2 == '\0') {
                    uVar11 = 1;
                    goto LAB_1418b24c4;
                  }
                  pQVar8 = (QLoggingCategory *)FUN_1418b2b20();
                  bVar3 = QLoggingCategory::isWarningEnabled(pQVar8);
                  if (bVar3) {
                    pQVar9 = (QMessageLogger *)
                             QMessageLogger::QMessageLogger
                                       ((QMessageLogger *)&local_78,(char *)0x0,0,(char *)0x0,
                                        *(char **)(pQVar8 + 8));
                    pQVar10 = (QDebug *)QMessageLogger::warning(pQVar9);
                    QDebug::operator<<(pQVar10,
                                       "ffmpegFileWriter: Could not initialize stream parameters");
                    goto LAB_1418b24b8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  uVar11 = 0;
LAB_1418b24c4:
  if (0xf < local_40) {
    ppppuVar6 = (undefined8 ****)local_58;
    if ((0xfff < local_40 + 1) &&
       (ppppuVar6 = (undefined8 ****)local_58[-1],
       0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)ppppuVar6)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar6);
  }
  return uVar11;
}


