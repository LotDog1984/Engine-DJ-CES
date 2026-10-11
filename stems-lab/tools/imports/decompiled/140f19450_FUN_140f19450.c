// FUN_140f19450 @ 140f19450
// calls: [avformat_alloc_output_context2]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140f19450(undefined8 *param_1,longlong *param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined2 param_6,undefined4 param_7,undefined8 param_8)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined8 ****ppppuVar7;
  void *_Memory;
  bool bVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  undefined1 local_78 [24];
  undefined8 ***local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong uStack_48;
  
  bVar8 = false;
  *param_1 = param_8;
  puVar10 = param_1 + 1;
  *puVar10 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar2 = *(undefined4 *)((longlong)param_2 + 4);
  lVar6 = param_2[1];
  uVar3 = *(undefined4 *)((longlong)param_2 + 0xc);
  *(int *)puVar10 = (int)*param_2;
  *(undefined4 *)((longlong)param_1 + 0xc) = uVar2;
  *(int *)(param_1 + 2) = (int)lVar6;
  *(undefined4 *)((longlong)param_1 + 0x14) = uVar3;
  lVar6 = param_2[3];
  param_1[3] = param_2[2];
  param_1[4] = lVar6;
  param_2[2] = 0;
  param_2[3] = 0xf;
  *(undefined1 *)param_2 = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined4 *)(param_1 + 10) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x54) = param_7;
  param_1[0xb] = 0;
  plVar5 = (longlong *)FUN_141981f80(8);
  uVar4 = _UNK_141daf568;
  plVar9 = (longlong *)0x0;
  if (plVar5 != (longlong *)0x0) {
    uStack_58 = 0;
    local_50 = _DAT_141daf560;
    uStack_48 = _UNK_141daf568;
    local_60 = (undefined8 ***)(ulonglong)(uint3)DAT_141fc0f6c;
    bVar8 = true;
    *plVar5 = 0;
    if (0xf < (ulonglong)param_1[4]) {
      puVar10 = (undefined8 *)*puVar10;
    }
    ppppuVar7 = &local_60;
    if (0xf < uVar4) {
      ppppuVar7 = (undefined8 ****)local_60;
    }
    avformat_alloc_output_context2(plVar5,0,ppppuVar7,puVar10);
    plVar9 = plVar5;
    if (*plVar5 == 0) {
      FUN_1402ab200(local_78,"Failed to create output format context");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_78,(ThrowInfo *)&DAT_14288d888);
    }
  }
  if ((bVar8) && (0xf < uStack_48)) {
    ppppuVar7 = (undefined8 ****)local_60;
    if ((0xfff < uStack_48 + 1) &&
       (ppppuVar7 = (undefined8 ****)local_60[-1],
       0x1f < (ulonglong)((longlong)local_60 + (-8 - (longlong)ppppuVar7)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar7);
  }
  puVar10 = (undefined8 *)param_1[5];
  param_1[5] = plVar9;
  if (puVar10 != (undefined8 *)0x0) {
    avformat_free_context(*puVar10);
    *puVar10 = 0;
    free(puVar10);
  }
  FUN_140f19aa0(param_1,param_3,*(undefined4 *)(param_1 + 10),param_5,param_6);
  plVar5 = (longlong *)FUN_141981f80(8);
  plVar9 = (longlong *)0x0;
  if (plVar5 != (longlong *)0x0) {
    *plVar5 = 0;
    lVar6 = av_packet_alloc();
    *plVar5 = lVar6;
    plVar9 = plVar5;
    if (lVar6 == 0) {
      FUN_1402ab200(local_78,"Failed to allocate AVPacket");
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_78,(ThrowInfo *)&DAT_14288d888);
    }
  }
  puVar10 = (undefined8 *)param_1[9];
  param_1[9] = plVar9;
  if (puVar10 != (undefined8 *)0x0) {
    av_packet_free(puVar10);
    *puVar10 = 0;
    free(puVar10);
  }
  if (0xf < (ulonglong)param_2[3]) {
    pvVar1 = (void *)*param_2;
    _Memory = pvVar1;
    if ((0xfff < param_2[3] + 1U) &&
       (_Memory = *(void **)((longlong)pvVar1 + -8),
       0x1f < (ulonglong)((longlong)pvVar1 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  param_2[2] = 0;
  param_2[3] = 0xf;
  *(undefined1 *)param_2 = 0;
  return param_1;
}


