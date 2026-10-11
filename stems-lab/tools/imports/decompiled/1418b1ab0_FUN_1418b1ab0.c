// FUN_1418b1ab0 @ 1418b1ab0
// calls: [av_write_frame, avcodec_send_frame, avcodec_receive_packet]

undefined8 FUN_1418b1ab0(longlong param_1,longlong *param_2,undefined4 *param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  QLoggingCategory *this;
  QMessageLogger *this_00;
  QDebug *this_01;
  undefined8 uVar6;
  longlong local_res20;
  char *local_38;
  undefined8 uStack_30;
  QMessageLogger local_28 [32];
  
  local_res20 = av_packet_alloc();
  if (local_res20 == 0) {
    this = (QLoggingCategory *)FUN_1418b2b20();
    bVar1 = QLoggingCategory::isWarningEnabled(this);
    if (bVar1) {
      this_00 = (QMessageLogger *)
                QMessageLogger::QMessageLogger
                          (local_28,(char *)0x0,0,(char *)0x0,*(char **)(this + 8));
      this_01 = (QDebug *)QMessageLogger::warning(this_00);
      QDebug::operator<<(this_01,"ffmpegFileWriter: Could not allocate packet");
      QDebug::~QDebug((QDebug *)&local_38);
    }
    uVar6 = 0;
    goto LAB_1418b1c68;
  }
  if (*param_2 != 0) {
    *(undefined8 *)(*param_2 + 0x88) = *(undefined8 *)(param_1 + 0x58);
    *(longlong *)(param_1 + 0x58) =
         *(longlong *)(param_1 + 0x58) + (longlong)*(int *)(*param_2 + 0x70);
  }
  iVar3 = avcodec_send_frame(*(undefined8 *)(param_1 + 0x48),*param_2);
  if (iVar3 != -0x20464f45) {
    local_38 = "avcodec_send_frame";
    uStack_30 = 0x12;
    cVar2 = FUN_1418b2f50(iVar3,&local_38);
    if (cVar2 != '\0') {
      uVar6 = 0;
      goto LAB_1418b1c68;
    }
    iVar4 = avcodec_receive_packet(*(undefined8 *)(param_1 + 0x48),local_res20);
    if ((iVar4 != -0xb) && (iVar4 != -0x20464f45)) {
      local_38 = "avcodec_receive_packet";
      uStack_30 = 0x16;
      cVar2 = FUN_1418b2f50(iVar3,&local_38);
      if (cVar2 != '\0') {
        uVar6 = 0;
        goto LAB_1418b1c68;
      }
      *param_3 = 1;
      if (*(char *)(param_1 + 0x81) != '\0') {
        FUN_1418b3550(&local_res20);
      }
      local_38 = "av_write_frame";
      uStack_30 = 0xe;
      uVar5 = av_write_frame(*(undefined8 *)(param_1 + 0x50),local_res20);
      cVar2 = FUN_1418b2f50(uVar5,&local_38);
      if (cVar2 != '\0') {
        uVar6 = 0;
        goto LAB_1418b1c68;
      }
    }
  }
  uVar6 = 1;
LAB_1418b1c68:
  if (local_res20 != 0) {
    av_packet_free(&local_res20);
  }
  return uVar6;
}


