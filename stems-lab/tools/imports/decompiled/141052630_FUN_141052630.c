// FUN_141052630 @ 141052630
// calls: [WriteFile]

undefined8 FUN_141052630(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_14105d1b0(param_1,0xc001b0c5,4,"archive_write_data");
  if (iVar1 == -0x1e) {
    return 0xffffffffffffffe2;
  }
  uVar2 = FUN_141054ee0(param_1,param_2,param_3);
  return uVar2;
}


