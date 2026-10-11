// FUN_141073730 @ 141073730
// calls: [ReadFile]

undefined8 FUN_141073730(longlong param_1,longlong *param_2,longlong *param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  void *pvVar3;
  longlong lVar4;
  longlong lVar5;
  int *piVar6;
  
  lVar1 = **(longlong **)(param_1 + 0x818);
  if (*(int *)(lVar1 + 0x30) < 0) {
    *param_2 = 0;
    *param_4 = 0;
    *param_3 = 0;
    uVar2 = 1;
  }
  else {
    pvVar3 = *(void **)(lVar1 + 0x20);
    if (pvVar3 == (void *)0x0) {
      *(undefined8 *)(lVar1 + 0x18) = 0x10000;
      pvVar3 = malloc(0x10000);
      *(void **)(lVar1 + 0x20) = pvVar3;
      if (pvVar3 == (void *)0x0) {
        FUN_1410557b0(param_1,0xc,"Can\'t allocate memory");
        return 0xffffffe2;
      }
    }
    *param_2 = (longlong)pvVar3;
    *param_4 = *(undefined8 *)(lVar1 + 0x28);
    lVar4 = *(longlong *)(lVar1 + 0xa8) - *(longlong *)(lVar1 + 0x28);
    lVar5 = *(longlong *)(lVar1 + 0x18);
    if (lVar4 < *(longlong *)(lVar1 + 0x18)) {
      lVar5 = lVar4;
    }
    lVar5 = FUN_14108ae00(*(undefined4 *)(lVar1 + 0x30),*(undefined8 *)(lVar1 + 0x20),lVar5);
    if (lVar5 < 0) {
      piVar6 = _errno();
      FUN_1410557b0(param_1,*piVar6,"Can\'t read");
      uVar2 = 0xffffffec;
    }
    else if (lVar5 == 0) {
      *param_3 = 0;
      uVar2 = 1;
    }
    else {
      *(longlong *)(lVar1 + 0x28) = *(longlong *)(lVar1 + 0x28) + lVar5;
      *param_3 = lVar5;
      uVar2 = 0;
    }
  }
  return uVar2;
}


