// FUN_140f19d50 @ 140f19d50
// calls: [av_interleaved_write_frame]

void FUN_140f19d50(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_28 [32];
  
  *(undefined8 *)(**(longlong **)(param_1 + 0x48) + 0x18) = *param_2;
  *(undefined4 *)(**(longlong **)(param_1 + 0x48) + 0x20) = param_3;
  *(undefined4 *)(**(longlong **)(param_1 + 0x48) + 0x24) =
       *(undefined4 *)**(undefined8 **)(param_1 + 0x38);
  *(ulonglong *)(**(longlong **)(param_1 + 0x48) + 8) = (ulonglong)*(uint *)(param_1 + 0x58);
  *(ulonglong *)(**(longlong **)(param_1 + 0x48) + 0x10) = (ulonglong)*(uint *)(param_1 + 0x58);
  *(int *)(param_1 + 0x58) =
       *(int *)(param_1 + 0x58) +
       (uint)(*(int *)(param_1 + 0x54) * *(int *)(param_1 + 0x50)) / *(uint *)(param_1 + 0x5c);
  iVar1 = av_interleaved_write_frame
                    (**(undefined8 **)(param_1 + 0x28),**(undefined8 **)(param_1 + 0x48));
  if (-1 < iVar1) {
    av_packet_unref(**(undefined8 **)(param_1 + 0x48));
    return;
  }
  FUN_1402ab200(local_28,"Error while writing audio frame");
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_28,(ThrowInfo *)&DAT_14288d888);
}


