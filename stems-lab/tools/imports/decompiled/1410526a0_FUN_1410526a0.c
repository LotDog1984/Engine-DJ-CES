// FUN_1410526a0 @ 1410526a0
// calls: [WriteFile]

ulonglong FUN_1410526a0(longlong param_1,undefined8 param_2,ulonglong param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  
  iVar1 = FUN_14105d1b0(param_1,0xc001b0c5,4,"archive_write_data_block");
  if (iVar1 == -0x1e) {
    uVar2 = 0xffffffffffffffe2;
  }
  else {
    *(undefined8 *)(param_1 + 0x1b8) = param_4;
    uVar2 = FUN_141054ee0(param_1,param_2,param_3);
    if (-1 < (longlong)uVar2) {
      if (uVar2 < param_3) {
        FUN_1410557b0(param_1,0,"Write request too large");
        uVar2 = 0xffffffffffffffec;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}


