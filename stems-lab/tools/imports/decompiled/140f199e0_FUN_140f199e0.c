// FUN_140f199e0 @ 140f199e0
// calls: [av_write_trailer]

void FUN_140f199e0(longlong param_1)

{
  undefined8 *puVar1;
  
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
  return;
}


