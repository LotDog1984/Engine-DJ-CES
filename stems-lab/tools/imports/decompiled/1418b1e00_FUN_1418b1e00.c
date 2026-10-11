// FUN_1418b1e00 @ 1418b1e00
// calls: [avformat_write_header]

undefined8 FUN_1418b1e00(longlong param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  QLoggingCategory *pQVar4;
  QMessageLogger *pQVar5;
  QDebug *pQVar6;
  longlong local_res8;
  char *local_28;
  undefined8 uStack_20;
  
  if (*(char *)(param_1 + 0x80) == '\0') {
    if (*(int *)(param_1 + 0xc) < 1) {
      pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
      bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
      if (bVar1) {
        pQVar5 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger
                           ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                            *(char **)(pQVar4 + 8));
        pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
        QDebug::operator<<(pQVar6,"ffmpegFileWriter: Invalid sample rate");
        QDebug::~QDebug((QDebug *)&local_res8);
        return 0;
      }
    }
    else if (*(int *)(param_1 + 0x10) < 1) {
      pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
      bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
      if (bVar1) {
        pQVar5 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger
                           ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                            *(char **)(pQVar4 + 8));
        pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
        QDebug::operator<<(pQVar6,"ffmpegFileWriter: Invalid number of channels");
        QDebug::~QDebug((QDebug *)&local_res8);
        return 0;
      }
    }
    else if (*(int *)(param_1 + 0x18) < 1) {
      pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
      bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
      if (bVar1) {
        pQVar5 = (QMessageLogger *)
                 QMessageLogger::QMessageLogger
                           ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                            *(char **)(pQVar4 + 8));
        pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
        QDebug::operator<<(pQVar6,"ffmpegFileWriter: Invalid bitrate");
        QDebug::~QDebug((QDebug *)&local_res8);
        return 0;
      }
    }
    else {
      *(bool *)(param_1 + 0x81) = *(int *)(param_1 + 0x20) != 0;
      cVar2 = FUN_1418b22a0();
      if (cVar2 == '\0') {
        pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
        bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
        if (bVar1) {
          pQVar5 = (QMessageLogger *)
                   QMessageLogger::QMessageLogger
                             ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                              *(char **)(pQVar4 + 8));
          pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
          QDebug::operator<<(pQVar6,"ffmpegFileWriter: Could not open encoder");
          QDebug::~QDebug((QDebug *)&local_res8);
          return 0;
        }
      }
      else {
        local_res8 = av_audio_fifo_alloc(*(undefined4 *)(*(longlong *)(param_1 + 0x48) + 0x198));
        if (*(longlong *)(param_1 + 0x40) != 0) {
          FUN_1418b2f10();
        }
        *(longlong *)(param_1 + 0x40) = local_res8;
        if (local_res8 == 0) {
          local_res8 = 0;
          pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
          bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
          if (bVar1) {
            pQVar5 = (QMessageLogger *)
                     QMessageLogger::QMessageLogger
                               ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                                *(char **)(pQVar4 + 8));
            pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
            QDebug::operator<<(pQVar6,"ffmpegFileWriter: Could not allocate FIFO");
            QDebug::~QDebug((QDebug *)&local_res8);
          }
          pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
          bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
          if (bVar1) {
            pQVar5 = (QMessageLogger *)
                     QMessageLogger::QMessageLogger
                               ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                                *(char **)(pQVar4 + 8));
            pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
            QDebug::operator<<(pQVar6,"ffmpegFileWriter: Could not init fifo");
            QDebug::~QDebug((QDebug *)&local_res8);
            return 0;
          }
        }
        else {
          local_28 = "avformat_write_header";
          uStack_20 = 0x15;
          local_res8 = 0;
          uVar3 = avformat_write_header(*(undefined8 *)(param_1 + 0x50),0);
          cVar2 = FUN_1418b2f50(uVar3);
          if (cVar2 == '\0') {
            *(undefined1 *)(param_1 + 0x80) = 1;
            return 1;
          }
          pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
          bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
          if (bVar1) {
            pQVar5 = (QMessageLogger *)
                     QMessageLogger::QMessageLogger
                               ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                                *(char **)(pQVar4 + 8));
            pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
            QDebug::operator<<(pQVar6,"ffmpegFileWriter: Could not write output file header");
            QDebug::~QDebug((QDebug *)&local_res8);
          }
        }
      }
    }
  }
  else {
    pQVar4 = (QLoggingCategory *)FUN_1418b2b20();
    bVar1 = QLoggingCategory::isWarningEnabled(pQVar4);
    if (bVar1) {
      pQVar5 = (QMessageLogger *)
               QMessageLogger::QMessageLogger
                         ((QMessageLogger *)&local_28,(char *)0x0,0,(char *)0x0,
                          *(char **)(pQVar4 + 8));
      pQVar6 = (QDebug *)QMessageLogger::warning(pQVar5);
      QDebug::operator<<(pQVar6,"ffmpegFileWriter: Already initialized");
      QDebug::~QDebug((QDebug *)&local_res8);
      return 0;
    }
  }
  return 0;
}


