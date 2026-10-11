// FUN_140f19830 @ 140f19830
// calls: [av_write_trailer]

void FUN_140f19830(longlong param_1)

{
  undefined8 *puVar1;
  void *pvVar2;
  void *_Memory;
  
  if (*(undefined8 **)(param_1 + 0x28) != (undefined8 *)0x0) {
    av_write_trailer(**(undefined8 **)(param_1 + 0x28));
    if ((*(byte *)(*(longlong *)(**(longlong **)(param_1 + 0x28) + 0x10) + 0x2c) & 1) == 0) {
      avio_closep(**(longlong **)(param_1 + 0x28) + 0x20);
    }
    puVar1 = *(undefined8 **)(param_1 + 0x28);
    *(undefined8 *)(param_1 + 0x28) = 0;
    if (puVar1 != (undefined8 *)0x0) {
      avformat_free_context(*puVar1);
      *puVar1 = 0;
      free(puVar1);
    }
    puVar1 = *(undefined8 **)(param_1 + 0x40);
    *(undefined8 *)(param_1 + 0x40) = 0;
    if (puVar1 != (undefined8 *)0x0) {
      av_frame_free(puVar1);
      *puVar1 = 0;
      free(puVar1);
    }
    puVar1 = *(undefined8 **)(param_1 + 0x48);
    *(undefined8 *)(param_1 + 0x48) = 0;
    if (puVar1 != (undefined8 *)0x0) {
      av_packet_free(puVar1);
      *puVar1 = 0;
      free(puVar1);
    }
  }
  puVar1 = *(undefined8 **)(param_1 + 0x48);
  if (puVar1 != (undefined8 *)0x0) {
    av_packet_free(puVar1);
    *puVar1 = 0;
    free(puVar1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  if (puVar1 != (undefined8 *)0x0) {
    av_frame_free(puVar1);
    *puVar1 = 0;
    free(puVar1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x38);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0;
    free(puVar1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x30);
  if (puVar1 != (undefined8 *)0x0) {
    avcodec_free_context(puVar1);
    *puVar1 = 0;
    free(puVar1);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x28);
  if (puVar1 != (undefined8 *)0x0) {
    avformat_free_context(*puVar1);
    *puVar1 = 0;
    free(puVar1);
  }
  if (0xf < *(ulonglong *)(param_1 + 0x20)) {
    pvVar2 = *(void **)(param_1 + 8);
    _Memory = pvVar2;
    if ((0xfff < *(ulonglong *)(param_1 + 0x20) + 1) &&
       (_Memory = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  *(undefined8 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined8 *)(param_1 + 0x20) = 0xf;
  return;
}


