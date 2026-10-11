// FUN_1418b1ca0 @ 1418b1ca0
// calls: [av_write_trailer]

void FUN_1418b1ca0(longlong param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  QLoggingCategory *this;
  QMessageLogger *this_00;
  QDebug *this_01;
  int local_res8 [2];
  longlong local_res10;
  char *local_38;
  undefined8 uStack_30;
  
  if (*(char *)(param_1 + 0x80) == '\0') {
    this = (QLoggingCategory *)FUN_1418b2b20();
    bVar1 = QLoggingCategory::isWarningEnabled(this);
    if (bVar1) {
      this_00 = (QMessageLogger *)
                QMessageLogger::QMessageLogger
                          ((QMessageLogger *)&local_38,(char *)0x0,0,(char *)0x0,
                           *(char **)(this + 8));
      this_01 = (QDebug *)QMessageLogger::warning(this_00);
      QDebug::operator<<(this_01,"ffmpegFileWriter: Cannot flush file, not initialized");
      QDebug::~QDebug((QDebug *)local_res8);
      return;
    }
  }
  else {
    local_res10 = 0;
    do {
      local_res8[0] = 0;
      cVar2 = FUN_1418b1ab0(param_1,&local_res10,local_res8);
      if (cVar2 != '\0') break;
    } while (local_res8[0] != 0);
    local_38 = "av_write_trailer";
    uStack_30 = 0x10;
    uVar3 = av_write_trailer(*(undefined8 *)(param_1 + 0x50));
    FUN_1418b2f50(uVar3,&local_38);
    if (*(longlong *)(param_1 + 0x40) != 0) {
      FUN_1418b2f10(param_1 + 0x40);
      *(undefined8 *)(param_1 + 0x40) = 0;
    }
    if (*(longlong *)(param_1 + 0x48) != 0) {
      avcodec_free_context(param_1 + 0x48);
      *(undefined8 *)(param_1 + 0x48) = 0;
    }
    if (*(longlong *)(param_1 + 0x50) != 0) {
      avio_closep(*(longlong *)(param_1 + 0x50) + 0x20);
      if (*(longlong *)(param_1 + 0x50) != 0) {
        avformat_close_input(param_1 + 0x50);
        *(undefined8 *)(param_1 + 0x50) = 0;
      }
    }
    if (local_res10 != 0) {
      av_frame_free(&local_res10);
    }
  }
  return;
}


