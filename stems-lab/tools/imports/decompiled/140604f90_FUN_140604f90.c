// FUN_140604f90 @ 140604f90
// calls: [CreateFileW]

ulonglong FUN_140604f90(wchar_t *param_1,undefined8 *param_2)

{
  undefined1 uVar1;
  uint uVar2;
  ulonglong uVar3;
  wchar_t *pwVar4;
  ulonglong uVar5;
  short *psVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  wchar_t *pwVar11;
  undefined1 local_res10;
  undefined7 uStackX_11;
  ulonglong in_stack_ffffffffffffffc8;
  
  if (param_2[2] != 0) {
    lVar8 = 0;
    if (7 < (ulonglong)param_2[3]) {
      param_2 = (undefined8 *)*param_2;
    }
    uVar2 = __std_fs_open_handle(&local_res10,param_2,0x80,0x2000000);
    uVar10 = (ulonglong)uVar2;
    if (uVar2 != 0) {
LAB_1406051f2:
      FUN_141980918(CONCAT71(uStackX_11,local_res10));
      return uVar10;
    }
    uVar10 = *(ulonglong *)(param_1 + 8);
    lVar9 = lVar8;
    uVar1 = local_res10;
    if (uVar10 < 0x104) {
      uVar3 = 0x104 - uVar10;
      if (*(ulonglong *)(param_1 + 0xc) - uVar10 < uVar3) {
        in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffffffff0000;
        FUN_14029f040(param_1,uVar3,local_res10,uVar3,in_stack_ffffffffffffffc8);
        uVar1 = local_res10;
      }
      else {
        param_1[8] = L'Ą';
        param_1[9] = L'\0';
        param_1[10] = L'\0';
        param_1[0xb] = L'\0';
        pwVar4 = param_1;
        if (7 < *(ulonglong *)(param_1 + 0xc)) {
          pwVar4 = *(wchar_t **)param_1;
        }
        pwVar11 = pwVar4 + uVar10;
        if (uVar3 != 0) {
          for (; uVar3 != 0; uVar3 = uVar3 - 1) {
            *pwVar11 = L'\0';
            pwVar11 = pwVar11 + 1;
          }
        }
        pwVar4[0x104] = L'\0';
      }
    }
    else {
      param_1[8] = L'Ą';
      param_1[9] = L'\0';
      param_1[10] = L'\0';
      param_1[0xb] = L'\0';
      pwVar4 = param_1;
      if (7 < *(ulonglong *)(param_1 + 0xc)) {
        pwVar4 = *(wchar_t **)param_1;
      }
      pwVar4[0x104] = L'\0';
    }
    do {
      while( true ) {
        uVar2 = *(uint *)(param_1 + 8);
        pwVar4 = param_1;
        if (7 < *(ulonglong *)(param_1 + 0xc)) {
          pwVar4 = *(wchar_t **)param_1;
        }
        uVar3 = __std_fs_get_final_path_name_by_handle
                          (CONCAT71(uStackX_11,local_res10),pwVar4,uVar2,lVar9);
        uVar10 = uVar3 >> 0x20;
        if ((uint)uVar3 != 0) break;
        if (((int)(uVar3 >> 0x20) != 3) || ((int)lVar9 != 0)) {
          param_1[8] = L'\0';
          param_1[9] = L'\0';
          param_1[10] = L'\0';
          param_1[0xb] = L'\0';
          if (7 < *(ulonglong *)(param_1 + 0xc)) {
            param_1 = *(wchar_t **)param_1;
          }
          *param_1 = L'\0';
          goto LAB_1406051f2;
        }
        lVar9 = 2;
      }
      uVar7 = uVar3 & 0xffffffff;
      uVar10 = *(ulonglong *)(param_1 + 8);
      if (uVar10 < uVar7) {
        uVar5 = uVar7 - uVar10;
        if (*(ulonglong *)(param_1 + 0xc) - uVar10 < uVar5) {
          in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffffffff0000;
          FUN_14029f040(param_1,uVar5,uVar1,uVar5,in_stack_ffffffffffffffc8);
        }
        else {
          *(ulonglong *)(param_1 + 8) = uVar7;
          pwVar4 = param_1;
          if (7 < *(ulonglong *)(param_1 + 0xc)) {
            pwVar4 = *(wchar_t **)param_1;
          }
          pwVar11 = pwVar4 + uVar10;
          if (uVar5 != 0) {
            for (; uVar5 != 0; uVar5 = uVar5 - 1) {
              *pwVar11 = L'\0';
              pwVar11 = pwVar11 + 1;
            }
          }
          pwVar4[uVar7] = L'\0';
        }
      }
      else {
        *(ulonglong *)(param_1 + 8) = uVar7;
        pwVar4 = param_1;
        if (7 < *(ulonglong *)(param_1 + 0xc)) {
          pwVar4 = *(wchar_t **)param_1;
        }
        pwVar4[uVar7] = L'\0';
      }
    } while (uVar2 <= (uint)uVar3);
    FUN_141980918(CONCAT71(uStackX_11,local_res10));
    if ((int)lVar9 == 0) {
      pwVar4 = param_1;
      if (7 < *(ulonglong *)(param_1 + 0xc)) {
        pwVar4 = *(wchar_t **)param_1;
      }
      if (5 < *(ulonglong *)(param_1 + 8)) {
        psVar6 = &DAT_141d683b0;
        lVar8 = 4;
        do {
          if (*(short *)((longlong)psVar6 + (longlong)(pwVar4 + -0xa0eb41d8)) != *psVar6)
          goto LAB_140605203;
          psVar6 = psVar6 + 1;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
        if ((*(uint *)(pwVar4 + 4) & 0xffffffdf) - 0x3a0041 < 0x1a) {
          uVar10 = *(ulonglong *)(param_1 + 8);
          uVar3 = 4;
          if (uVar10 < 4) {
            uVar3 = uVar10;
          }
          pwVar4 = param_1;
          if (7 < *(ulonglong *)(param_1 + 0xc)) {
            pwVar4 = *(wchar_t **)param_1;
          }
          memmove(pwVar4,pwVar4 + uVar3,(uVar10 - uVar3) * 2 + 2);
          *(ulonglong *)(param_1 + 8) = uVar10 - uVar3;
          return 0;
        }
      }
LAB_140605203:
      pwVar4 = param_1;
      if (7 < *(ulonglong *)(param_1 + 0xc)) {
        pwVar4 = *(wchar_t **)param_1;
      }
      if (7 < *(ulonglong *)(param_1 + 8)) {
        psVar6 = &DAT_141d68428;
        lVar8 = 8;
        do {
          if (*(short *)((longlong)psVar6 + (longlong)(pwVar4 + -0xa0eb4214)) != *psVar6) {
            return 0;
          }
          psVar6 = psVar6 + 1;
          lVar8 = lVar8 + -1;
        } while (lVar8 != 0);
        uVar10 = *(longlong *)(param_1 + 8) - 2;
        uVar3 = 6;
        if (uVar10 < 6) {
          uVar3 = uVar10;
        }
        pwVar4 = param_1;
        if (7 < *(ulonglong *)(param_1 + 0xc)) {
          pwVar4 = *(wchar_t **)param_1;
        }
        lVar8 = *(longlong *)(param_1 + 8) - uVar3;
        memmove(pwVar4 + 2,pwVar4 + 2 + uVar3,lVar8 * 2 - 2);
        *(longlong *)(param_1 + 8) = lVar8;
      }
    }
    else {
      lVar9 = *(longlong *)(param_1 + 8);
      if (*(ulonglong *)(param_1 + 0xc) - lVar9 < 0xe) {
        FUN_140601680(param_1,0xe,local_res10,0,L"\\\\?\\GLOBALROOT",0xe);
      }
      else {
        *(longlong *)(param_1 + 8) = lVar9 + 0xe;
        if (7 < *(ulonglong *)(param_1 + 0xc)) {
          param_1 = *(wchar_t **)param_1;
        }
        if (((wchar_t *)((longlong)L"\\\\?\\GLOBALROOT" + 0x1b) < param_1) ||
           (param_1 + lVar9 < L"\\\\?\\GLOBALROOT")) {
          lVar8 = 0xe;
        }
        else if (L"\\\\?\\GLOBALROOT" < param_1) {
          lVar8 = (longlong)(param_1 + -0xa0eb4220) >> 1;
        }
        memmove(param_1 + 0xe,param_1,lVar9 * 2 + 2);
        memcpy(param_1,L"\\\\?\\GLOBALROOT",lVar8 * 2);
        memcpy(param_1 + lVar8,L"\\\\?\\GLOBALROOT" + lVar8 + 0xe,(0xe - lVar8) * 2);
      }
    }
  }
  return 0;
}


