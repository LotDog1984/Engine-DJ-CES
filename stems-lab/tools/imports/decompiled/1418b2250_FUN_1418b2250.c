// FUN_1418b2250 @ 1418b2250
// calls: [avcodec_find_encoder]

ulonglong FUN_1418b2250(undefined8 param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar2 = avcodec_find_encoder();
  uVar3 = 0;
  if (lVar2 != 0) {
    uVar1 = **(uint **)(lVar2 + 0x30);
    uVar3 = (ulonglong)uVar1;
    if (uVar1 != 0) {
      lVar4 = 0;
      do {
        if ((int)uVar3 == param_2) {
          return CONCAT71((int7)(uVar3 >> 8),1);
        }
        uVar1 = (*(uint **)(lVar2 + 0x30))[lVar4 + 1];
        uVar3 = (ulonglong)uVar1;
        lVar4 = lVar4 + 1;
      } while (uVar1 != 0);
    }
  }
  return uVar3 & 0xffffffffffffff00;
}


