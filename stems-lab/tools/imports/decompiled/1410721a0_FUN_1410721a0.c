// FUN_1410721a0 @ 1410721a0
// calls: [CreateFileW]

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_1410721a0(undefined8 param_1,undefined8 param_2,longlong param_3,longlong param_4,
                 undefined4 *param_5)

{
  bool bVar1;
  undefined8 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  longlong lVar8;
  int *piVar9;
  undefined8 uVar10;
  int iVar11;
  longlong *plVar12;
  uint uVar13;
  undefined1 auStack_d8 [32];
  uint *local_b8;
  undefined8 local_a8;
  uint local_a0 [2];
  undefined8 local_98;
  undefined4 *local_90;
  undefined1 local_88 [8];
  undefined4 local_80;
  undefined2 local_7c;
  ushort local_7a;
  short local_78;
  short local_76;
  short local_74;
  undefined4 local_70;
  int local_6c;
  undefined8 local_60;
  ulonglong local_50;
  
  local_50 = DAT_142955700 ^ (ulonglong)auStack_d8;
  local_90 = param_5;
  *(undefined1 *)(param_4 + 0x39) = 1;
  local_a8 = param_2;
  local_98 = param_1;
  FUN_1410569a0(param_2,0x8000);
  FUN_141056c50(local_a8,0);
  uVar10 = local_a8;
  *(undefined8 *)(param_3 + 0x80) = 0;
  iVar7 = 0;
  plVar12 = *(longlong **)(param_4 + 0x28);
  local_a0[0] = 0;
  iVar4 = 0;
  if (plVar12 == (longlong *)0x0) {
LAB_141072252:
    uVar13 = local_a0[0];
    if ((local_a0[0] >> 8 & 1) == 0) {
      FUN_1410557b0(param_1,0x2a,"Missing type keyword in mtree specification");
      iVar4 = -0x14;
    }
  }
  else {
    do {
      local_b8 = local_a0;
      iVar4 = FUN_141072790(param_1,param_3,uVar10,plVar12);
      plVar12 = (longlong *)*plVar12;
      if (iVar4 < iVar7) {
        iVar7 = iVar4;
      }
    } while (plVar12 != (longlong *)0x0);
    uVar13 = local_a0[0];
    iVar4 = iVar7;
    if (iVar7 == 0) goto LAB_141072252;
  }
  if (*(char *)(param_4 + 0x38) == '\0') {
    lVar8 = *(longlong *)(param_3 + 0x68);
    if (lVar8 != 0) {
      FUN_141058140(param_3 + 0x60,0x141d310a8);
    }
    FUN_141058140(param_3 + 0x60,*(undefined8 *)(param_4 + 0x30));
    FUN_141056170(local_a8,*(undefined8 *)(param_3 + 0x60));
    sVar3 = FUN_1410562e0(local_a8);
    if (sVar3 != 0x4000) {
      *(longlong *)(param_3 + 0x68) = lVar8;
    }
  }
  else {
    FUN_141056170(local_a8,*(undefined8 *)(param_4 + 0x30));
    lVar8 = FUN_14108f7a0(param_3 + 0x98,*(undefined8 *)(param_4 + 0x30));
    uVar10 = local_a8;
    uVar2 = local_98;
    iVar7 = iVar4;
    for (; local_a8 = uVar10, local_98 = uVar2, lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 0x18)) {
      if ((*(char *)(lVar8 + 0x38) != '\0') && (*(char *)(lVar8 + 0x39) == '\0')) {
        plVar12 = *(longlong **)(lVar8 + 0x28);
        iVar11 = 0;
        *(undefined1 *)(lVar8 + 0x39) = 1;
        if (plVar12 == (longlong *)0x0) {
LAB_14107230e:
          param_1 = local_98;
          if ((uVar13 >> 8 & 1) == 0) {
            FUN_1410557b0(local_98,0x2a,"Missing type keyword in mtree specification");
            iVar11 = -0x14;
          }
        }
        else {
          do {
            local_b8 = local_a0;
            iVar5 = FUN_141072790(uVar2,param_3,uVar10,plVar12);
            plVar12 = (longlong *)*plVar12;
            if (iVar5 < iVar11) {
              iVar11 = iVar5;
            }
          } while (plVar12 != (longlong *)0x0);
          param_1 = local_98;
          uVar13 = local_a0[0];
          if (iVar11 == 0) goto LAB_14107230e;
        }
        bVar1 = iVar11 < iVar4;
        iVar4 = iVar7;
        if (bVar1) {
          iVar4 = iVar11;
          iVar7 = iVar11;
        }
      }
      uVar10 = local_a8;
      uVar2 = local_98;
    }
  }
  if (*(char *)(param_3 + 0xb0) == '\0') goto LAB_14107271e;
  *(undefined4 *)(param_3 + 0x30) = 0xffffffff;
  if (*(longlong *)(param_3 + 0x80) == 0) {
    uVar10 = FUN_1410565b0(local_a8);
  }
  else {
    uVar10 = *(undefined8 *)(param_3 + 0x78);
  }
  sVar3 = FUN_1410562e0(local_a8);
  if ((sVar3 == -0x8000) || (sVar3 = FUN_1410562e0(local_a8), sVar3 == 0x4000)) {
    uVar6 = FUN_14108ab80(uVar10,0x8000);
    *(undefined4 *)(param_3 + 0x30) = uVar6;
    FUN_140ed6720(uVar6);
    if ((*(int *)(param_3 + 0x30) == -1) &&
       (((piVar9 = _errno(), *piVar9 != 2 && (piVar9 = _errno(), *piVar9 != 0x16)) ||
        (*(longlong *)(param_3 + 0x80) != 0)))) {
      piVar9 = _errno();
      FUN_1410557b0(param_1,*piVar9,"Can\'t open %s",uVar10);
      iVar4 = -0x14;
    }
  }
  if (*(int *)(param_3 + 0x30) < 0) {
    iVar7 = FUN_14108af00(uVar10,&local_80);
    if (iVar7 == -1) goto LAB_1410724aa;
  }
  else {
    iVar7 = FUN_14108aaa0();
    if (iVar7 == -1) {
      piVar9 = _errno();
      FUN_1410557b0(param_1,*piVar9,"Could not fstat %s",uVar10);
      iVar4 = -0x14;
      _close(*(int *)(param_3 + 0x30));
      *(undefined4 *)(param_3 + 0x30) = 0xffffffff;
LAB_1410724aa:
      if ((uVar13 >> 0xb & 1) != 0) {
        *local_90 = 1;
        return 0;
      }
      goto LAB_14107271e;
    }
  }
  if (((((((local_7a & 0xf000) != 0x8000) || (sVar3 = FUN_1410562e0(local_a8), sVar3 != -0x8000)) &&
        (((local_7a & 0xf000) != 0xa000 || (sVar3 = FUN_1410562e0(local_a8), sVar3 != -0x6000)))) &&
       (((local_7a & 0xc000) != 0xc000 || (sVar3 = FUN_1410562e0(local_a8), sVar3 != -0x4000)))) &&
      (((local_7a & 0xf000) != 0x2000 || (sVar3 = FUN_1410562e0(local_a8), sVar3 != 0x2000)))) &&
     (((((local_7a & 0xf000) != 0x6000 || (sVar3 = FUN_1410562e0(local_a8), sVar3 != 0x6000)) &&
       (((local_7a & 0xf000) != 0x4000 || (sVar3 = FUN_1410562e0(local_a8), sVar3 != 0x4000)))) &&
      (((local_7a & 0xf000) != 0x1000 || (sVar3 = FUN_1410562e0(local_a8), sVar3 != 0x1000)))))) {
    if (-1 < *(int *)(param_3 + 0x30)) {
      _close(*(int *)(param_3 + 0x30));
    }
    *(undefined4 *)(param_3 + 0x30) = 0xffffffff;
    if ((uVar13 >> 0xb & 1) != 0) {
      *local_90 = 1;
      return iVar4;
    }
    if (iVar4 != 0) {
      return iVar4;
    }
    uVar10 = FUN_1410565b0(local_a8);
    FUN_1410557b0(param_1,0xffffffff,"mtree specification has different type for %s",uVar10);
    return -0x14;
  }
  if (((uVar13 & 0x1001) != 1) &&
     ((sVar3 = FUN_1410562e0(local_a8), sVar3 == 0x2000 ||
      (sVar3 = FUN_1410562e0(local_a8), sVar3 == 0x6000)))) {
    FUN_141056bc0(local_a8,local_70);
  }
  if (((uVar13 & 0xc) == 0) || ((uVar13 & 0x1000) != 0)) {
    FUN_1410569d0(local_a8,(longlong)local_74);
  }
  if (((uVar13 & 0x600) == 0) || ((uVar13 & 0x1000) != 0)) {
    FUN_141056c80(local_a8,(longlong)local_76);
  }
  if ((uVar13 & 0x1010) != 0x10) {
    FUN_141056b10(local_a8,local_60,0);
  }
  if ((uVar13 & 0x1020) != 0x20) {
    FUN_141056b70(local_a8,(int)local_78);
  }
  if ((uVar13 & 0x1040) != 0x40) {
    FUN_141056b80(local_a8,local_7a);
  }
  if ((uVar13 & 0x1080) != 0x80) {
    FUN_141056c50(local_a8,(longlong)local_6c);
  }
  FUN_141056a30(local_a8,local_7c);
  FUN_141056830(local_a8,local_80);
  FUN_14108f0d0(*(undefined8 *)(param_3 + 0x90),&local_a8,local_88);
LAB_14107271e:
  uVar10 = FUN_141056ca0(local_a8);
  *(undefined8 *)(param_3 + 0xa8) = uVar10;
  *(undefined8 *)(param_3 + 0x28) = 0;
  return iVar4;
}


