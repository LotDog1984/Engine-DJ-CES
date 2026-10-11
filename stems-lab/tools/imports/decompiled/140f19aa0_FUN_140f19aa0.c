// FUN_140f19aa0 @ 140f19aa0
// calls: [avio_open, avformat_write_header, avformat_new_stream]

void FUN_140f19aa0(longlong *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                  ushort param_5)

{
  undefined8 *_Memory;
  longlong lVar1;
  void *_Dst;
  void *_Src;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 local_res8;
  undefined1 local_48 [32];
  
  *(undefined4 *)((longlong)param_1 + 0x5c) = param_2;
  uVar5 = *(undefined8 *)param_1[5];
  plVar3 = (longlong *)FUN_141981f80(8);
  if (plVar3 == (longlong *)0x0) {
    plVar3 = (longlong *)0x0;
  }
  else {
    *plVar3 = 0;
    lVar4 = avformat_new_stream(uVar5,0);
    *plVar3 = lVar4;
    if (lVar4 == 0) {
      FUN_1402ab200(local_48,"Failed to create new stream");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_48,(ThrowInfo *)&DAT_14288d888);
    }
  }
  _Memory = (undefined8 *)param_1[7];
  param_1[7] = (longlong)plVar3;
  if (_Memory != (undefined8 *)0x0) {
    *_Memory = 0;
    free(_Memory);
  }
  *(undefined4 *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 4) = 0x15002;
  **(undefined4 **)(*(longlong *)param_1[7] + 0xd0) = 1;
  *(undefined4 *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x1c) = 8;
  *(ulonglong *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x20) = (ulonglong)param_4;
  *(undefined4 *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x74) = param_2;
  uVar5 = av_get_default_channel_layout(param_5);
  *(undefined8 *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x68) = uVar5;
  *(uint *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x70) = (uint)param_5;
  *(undefined4 *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x7c) = param_3;
  *(undefined4 *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x30) = 1;
  lVar4 = *(longlong *)*param_1;
  lVar1 = ((longlong *)*param_1)[1];
  if (lVar4 != lVar1) {
    uVar5 = av_mallocz((lVar1 - lVar4) + 0x40);
    *(undefined8 *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x10) = uVar5;
    _Dst = *(void **)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x10);
    if (_Dst == (void *)0x0) {
      FUN_1402ab200(local_48,"Failed to allocate memory for extradata");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_48,(ThrowInfo *)&DAT_14288d888);
    }
    _Src = *(void **)*param_1;
    memcpy(_Dst,_Src,((undefined8 *)*param_1)[1] - (longlong)_Src);
    *(int *)(*(longlong *)(*(longlong *)param_1[7] + 0xd0) + 0x18) =
         ((int *)*param_1)[2] - *(int *)*param_1;
  }
  local_res8 = CONCAT44(*(undefined4 *)((longlong)param_1 + 0x54),1);
  *(undefined8 *)(*(longlong *)param_1[7] + 0x18) = local_res8;
  if ((*(byte *)(*(longlong *)(*(longlong *)param_1[5] + 0x10) + 0x2c) & 1) == 0) {
    plVar3 = param_1 + 1;
    if (0xf < (ulonglong)param_1[4]) {
      plVar3 = (longlong *)*plVar3;
    }
    iVar2 = avio_open(*(longlong *)param_1[5] + 0x20,plVar3,2);
    if (iVar2 < 0) {
      FUN_1402ab200(local_48,"Failed to open output file");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_48,(ThrowInfo *)&DAT_14288d888);
    }
  }
  iVar2 = avformat_write_header(*(undefined8 *)param_1[5],0);
  if (iVar2 < 0) {
    FUN_1402ab200(local_48,"Failed to write header");
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_48,(ThrowInfo *)&DAT_14288d888);
  }
  return;
}


