// FUN_1418b16e0 @ 1418b16e0
// calls: [av_write_trailer]

void FUN_1418b16e0(undefined8 *param_1)

{
  void *pvVar1;
  char cVar2;
  undefined4 uVar3;
  void *_Memory;
  int local_res8 [2];
  longlong local_res10;
  char *local_28;
  undefined8 uStack_20;
  
  *param_1 = ffmpegFileWriter::vftable;
  if (*(char *)(param_1 + 0x10) != '\0') {
    local_res10 = 0;
    do {
      local_res8[0] = 0;
      cVar2 = FUN_1418b1ab0(param_1,&local_res10,local_res8);
      if (cVar2 != '\0') break;
    } while (local_res8[0] != 0);
    local_28 = "av_write_trailer";
    uStack_20 = 0x10;
    uVar3 = av_write_trailer(param_1[10]);
    FUN_1418b2f50(uVar3,&local_28);
    if (param_1[8] != 0) {
      FUN_1418b2f10(param_1 + 8);
      param_1[8] = 0;
    }
    if (param_1[9] != 0) {
      avcodec_free_context(param_1 + 9);
      param_1[9] = 0;
    }
    if ((param_1[10] != 0) && (avio_closep(param_1[10] + 0x20), param_1[10] != 0)) {
      avformat_close_input(param_1 + 10);
      param_1[10] = 0;
    }
    if (local_res10 != 0) {
      av_frame_free(&local_res10);
    }
  }
  FUN_1402a29e0(param_1 + 0xc);
  if (param_1[10] != 0) {
    avformat_close_input(param_1 + 10);
    param_1[10] = 0;
  }
  if (param_1[9] != 0) {
    avcodec_free_context(param_1 + 9);
    param_1[9] = 0;
  }
  if (param_1[8] != 0) {
    FUN_1418b2f10(param_1 + 8);
    param_1[8] = 0;
  }
  pvVar1 = (void *)param_1[5];
  if (pvVar1 != (void *)0x0) {
    _Memory = pvVar1;
    if ((0xfff < (param_1[7] - (longlong)pvVar1 & 0xfffffffffffffffcU)) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
  }
  return;
}


