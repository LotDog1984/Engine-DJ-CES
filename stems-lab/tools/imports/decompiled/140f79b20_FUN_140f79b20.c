// FUN_140f79b20 @ 140f79b20
// calls: [CreateFileW]

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FUN_140f79b20(longlong param_1,longlong param_2,undefined8 *param_3,uint param_4,int *param_5)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined8 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined *puVar10;
  char *pcVar11;
  longlong lVar12;
  char *pcVar13;
  char *pcVar14;
  int iVar15;
  char *pcVar16;
  undefined4 uVar17;
  undefined1 *puVar18;
  char *pcVar19;
  uint uVar20;
  bool bVar21;
  undefined1 auStack_108 [32];
  int local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  uint local_c8;
  int local_c4;
  uint local_c0;
  uint local_bc;
  ulonglong local_b8;
  longlong local_b0;
  longlong local_a8;
  uint local_a0;
  longlong local_98;
  longlong local_90;
  undefined8 *local_88;
  int *local_80;
  ulonglong local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  ulonglong local_50;
  
  local_50 = DAT_142955700 ^ (ulonglong)auStack_108;
  local_80 = param_5;
  local_a8 = param_2;
  local_90 = param_1;
  local_88 = param_3;
  do {
    *local_88 = 0;
    local_88[1] = 0;
    local_88[2] = 0;
    local_88[3] = 0;
    local_c0 = param_4 & 0x10;
    local_c4 = 0;
    local_88[4] = 0;
    local_88[5] = 0;
    local_88[6] = 0;
    local_88[7] = 0;
    local_a0 = param_4 & 1;
    local_b0 = 0;
    local_88[8] = 0;
    local_88[9] = 0;
    uVar20 = param_4 & 2;
    local_88[10] = 0;
    local_88[0xb] = 0;
    local_88[2] = 0xffffffffffffffff;
    local_c8 = uVar20;
    local_bc = param_4;
    local_98 = local_a8;
    if (local_a8 == 0) {
      uVar7 = FUN_141039a20(local_90,&local_b0);
      if ((int)uVar7 != 0) {
        return uVar7;
      }
      local_98 = local_b0;
    }
    lVar9 = local_b0;
    uVar8 = FUN_14103adb0();
    local_b8 = uVar8;
    if (uVar8 == 0) {
      if (lVar9 != 0) {
        if (DAT_142934540 == 0) {
          (*DAT_142934568)(lVar9);
        }
        else {
          if (DAT_142b24e50 != 0) {
            (*DAT_1429345c0)();
          }
          iVar15 = (*DAT_142934578)(lVar9);
          DAT_142b24dd8 = DAT_142b24dd8 + -1;
          DAT_142b24d90 = DAT_142b24d90 - iVar15;
          (*DAT_142934568)(lVar9);
          if (DAT_142b24e50 != 0) {
            (*DAT_1429345d0)();
          }
        }
      }
      return 0xc0a;
    }
    local_58 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    uStack_60 = 0;
    iVar15 = 0;
    while (iVar5 = (*(code *)PTR_GetFileAttributesExW_142935048)(uVar8,0,&local_78), iVar5 == 0) {
      iVar5 = (*(code *)PTR_GetLastError_1429350a8)();
      if ((DAT_1429348e8 <= iVar15) ||
         ((((0x3b < iVar5 - 5U ||
            ((0x804000018000001U >> ((ulonglong)(iVar5 - 5U) & 0x3f) & 1) == 0)) && (iVar5 != 0x79))
          && (iVar5 != 0x4cf)))) goto LAB_140f79cb6;
      iVar15 = iVar15 + 1;
      (*(code *)PTR_Sleep_142935360)(iVar15 * DAT_1429348ec);
    }
    if (((int)local_78 != -1) && ((local_78 & 0x10) != 0)) {
      if (DAT_142934540 == 0) {
        (*DAT_142934568)(uVar8);
      }
      else {
        if (DAT_142b24e50 != 0) {
          (*DAT_1429345c0)();
        }
        iVar15 = (*DAT_142934578)(uVar8);
        DAT_142b24dd8 = DAT_142b24dd8 + -1;
        DAT_142b24d90 = DAT_142b24d90 - iVar15;
        (*DAT_142934568)(uVar8);
        if (DAT_142b24e50 != 0) {
          (*DAT_1429345d0)();
        }
      }
      if (lVar9 != 0) {
        if (DAT_142934540 == 0) {
          (*DAT_142934568)(lVar9);
        }
        else {
          if (DAT_142b24e50 != 0) {
            (*DAT_1429345c0)();
          }
          iVar15 = (*DAT_142934578)(lVar9);
          DAT_142b24dd8 = DAT_142b24dd8 + -1;
          DAT_142b24d90 = DAT_142b24d90 - iVar15;
          (*DAT_142934568)(lVar9);
          if (DAT_142b24e50 != 0) {
            (*DAT_1429345d0)();
            return 0x20e;
          }
        }
      }
      return 0x20e;
    }
LAB_140f79cb6:
    uVar7 = 0xc0000000;
    if (uVar20 == 0) {
      uVar7 = 0x80000000;
    }
    if (local_c0 == 0) {
      iVar15 = ((param_4 & 4) != 0) + 3;
    }
    else {
      iVar15 = 1;
    }
    lVar9 = local_a8;
    if (local_a8 == 0) {
LAB_140f79dbc:
      bVar21 = false;
    }
    else {
      for (; ((*(char *)(lVar9 + -1) != '\0' || (*(char *)(lVar9 + -2) != '\0')) ||
             ((*(char *)(lVar9 + -3) != '\0' || (*(char *)(lVar9 + -4) != '\0'))));
          lVar9 = lVar9 + -1) {
      }
      lVar12 = -1;
      do {
        lVar12 = lVar12 + 1;
      } while (*(char *)(lVar9 + lVar12) != '\0');
      for (pcVar16 = (char *)((ulonglong)((uint)lVar12 & 0x3fffffff) + 1 + lVar9);
          pcVar16 != (char *)0x0; pcVar16 = pcVar16 + (ulonglong)((uint)lVar9 & 0x3fffffff) + 1) {
        while( true ) {
          if (*pcVar16 == '\0') goto LAB_140f79d97;
          iVar5 = strcmp(pcVar16,"exclusive");
          lVar9 = -1;
          do {
            lVar9 = lVar9 + 1;
          } while (pcVar16[lVar9] != '\0');
          pcVar16 = pcVar16 + (ulonglong)((uint)lVar9 & 0x3fffffff) + 1;
          if (iVar5 == 0) goto LAB_140f79d9b;
          if (pcVar16 != (char *)0x0) break;
          pcVar16 = (char *)0x1;
        }
        lVar9 = -1;
        do {
          lVar9 = lVar9 + 1;
        } while (pcVar16[lVar9] != '\0');
      }
LAB_140f79d97:
      pcVar16 = (char *)0x0;
LAB_140f79d9b:
      if (pcVar16 == (char *)0x0) goto LAB_140f79dbc;
      cVar4 = FUN_140faea50(pcVar16,1,0);
      bVar21 = cVar4 != '\0';
    }
    uVar8 = local_b8;
    puVar18 = &DAT_00000007;
    if (bVar21) {
      puVar18 = (undefined1 *)0x0;
    }
    uVar17 = 0x4000102;
    iVar5 = 0;
    if ((param_4 & 8) == 0) {
      uVar17 = 0x80;
      iVar5 = 0;
    }
    while( true ) {
      local_d8 = 0;
      local_e8 = iVar15;
      local_e0 = uVar17;
      lVar9 = (*(code *)PTR_CreateFileW_142934eb0)(uVar8,uVar7,puVar18,0);
      iVar6 = local_c4;
      if (lVar9 != -1) break;
      if (local_c8 != 0) {
        local_b8 = local_b8 & 0xffffffff00000000;
        if (DAT_142b24e38 != (code *)0x0) {
          (*DAT_142b24e38)();
        }
        iVar6 = FUN_140f7c5a0(local_90,local_98);
        if (DAT_142b24e40 != (code *)0x0) {
          (*DAT_142b24e40)();
        }
        if ((iVar6 == 0) && (iVar6 = local_c4, (int)local_b8 != 0)) break;
      }
      iVar6 = (*(code *)PTR_GetLastError_1429350a8)();
      if ((DAT_1429348e8 <= iVar5) ||
         ((((0x3b < iVar6 - 5U ||
            ((0x804000018000001U >> ((ulonglong)(iVar6 - 5U) & 0x3f) & 1) == 0)) && (iVar6 != 0x79))
          && (iVar6 != 0x4cf)))) break;
      iVar5 = iVar5 + 1;
      (*(code *)PTR_Sleep_142935360)(DAT_1429348ec * iVar5);
    }
    if (iVar5 != 0) {
      FUN_140f7a5e0(0x1b,"delayed %dms for lock/sharing conflict at line %d",
                    ((iVar5 + 1) * DAT_1429348ec * iVar5) / 2,0xc96c);
    }
    lVar12 = local_90;
    if (lVar9 != -1) {
      pcVar16 = (char *)0x0;
      if (local_80 != (int *)0x0) {
        *local_80 = (local_c8 != 0) + 1;
      }
      puVar1 = *(undefined8 **)(local_90 + 0x20);
      FUN_140f8c910(uVar8);
      lVar2 = local_b0;
      if (local_b0 != 0) {
        if (DAT_142934540 == 0) {
          (*DAT_142934568)(local_b0);
        }
        else {
          if (DAT_142b24e50 != 0) {
            (*DAT_1429345c0)();
          }
          iVar15 = (*DAT_142934578)(lVar2);
          DAT_142b24dd8 = DAT_142b24dd8 + -1;
          DAT_142b24d90 = DAT_142b24d90 - iVar15;
          (*DAT_142934568)(lVar2);
          if (DAT_142b24e50 != 0) {
            (*DAT_1429345d0)();
          }
        }
      }
      puVar3 = local_88;
      lVar2 = local_a8;
      if (puVar1 == (undefined8 *)0x0) {
        puVar10 = &DAT_14209da70;
      }
      else {
        puVar10 = (undefined *)*puVar1;
      }
      *local_88 = puVar10;
      local_88[1] = lVar12;
      local_88[2] = lVar9;
      if (local_a0 != 0) {
        *(byte *)((longlong)local_88 + 0x1c) = *(byte *)((longlong)local_88 + 0x1c) | 2;
      }
      if ((local_bc & 0x100) == 0) goto LAB_140f7a257;
      lVar9 = local_a8;
      if (local_a8 != 0) goto LAB_140f7a180;
      goto LAB_140f7a253;
    }
    FUN_140f8c910(uVar8);
    lVar9 = local_b0;
    if (local_b0 != 0) {
      if (DAT_142934540 == 0) {
        (*DAT_142934568)(local_b0);
      }
      else {
        if (DAT_142b24e50 != 0) {
          (*DAT_1429345c0)();
        }
        iVar15 = (*DAT_142934578)(lVar9);
        DAT_142b24dd8 = DAT_142b24dd8 + -1;
        DAT_142b24d90 = DAT_142b24d90 - iVar15;
        (*DAT_142934568)(lVar9);
        if (DAT_142b24e50 != 0) {
          (*DAT_1429345d0)();
        }
      }
    }
    if ((local_c8 == 0) || (local_c0 != 0)) {
      local_e8 = 0xc97b;
      *(int *)(local_88 + 4) = iVar6;
      FUN_14103a1b0(0xe,iVar6,"winOpen",local_98);
      uVar7 = FUN_140fd6f30(0xc97c);
      return uVar7;
    }
    param_4 = local_bc & 0xfffffff9 | 1;
  } while( true );
LAB_140f7a21c:
  lVar9 = -1;
  do {
    lVar9 = lVar9 + 1;
  } while (pcVar13[lVar9] != '\0');
  pcVar14 = pcVar13 + (ulonglong)((uint)lVar9 & 0x3fffffff) + 1;
  goto joined_r0x000140f7a1ba;
LAB_140f7a180:
  for (; ((*(char *)(lVar9 + -1) != '\0' || (*(char *)(lVar9 + -2) != '\0')) ||
         ((*(char *)(lVar9 + -3) != '\0' || (*(char *)(lVar9 + -4) != '\0')))); lVar9 = lVar9 + -1)
  {
  }
  lVar12 = -1;
  do {
    lVar12 = lVar12 + 1;
  } while (*(char *)(lVar9 + lVar12) != '\0');
  pcVar14 = (char *)((ulonglong)((uint)lVar12 & 0x3fffffff) + 1 + lVar9);
joined_r0x000140f7a1ba:
  pcVar13 = pcVar16;
  if (pcVar14 != (char *)0x0) {
    do {
      pcVar13 = pcVar16;
      if (*pcVar14 == '\0') break;
      do {
        pcVar11 = pcVar13 + 1;
        if (pcVar14[(longlong)pcVar13] != pcVar13[0x1420a3920]) {
          pcVar19 = (char *)(ulonglong)
                            (-(uint)((byte)pcVar14[(longlong)pcVar13] < (byte)pcVar13[0x1420a3920])
                            | 1);
          break;
        }
        pcVar13 = pcVar11;
        pcVar19 = pcVar16;
      } while (pcVar11 != &DAT_00000005);
      lVar9 = -1;
      do {
        lVar9 = lVar9 + 1;
      } while (pcVar14[lVar9] != '\0');
      pcVar13 = pcVar14 + (ulonglong)((uint)lVar9 & 0x3fffffff) + 1;
      if ((int)pcVar19 == 0) break;
      if (pcVar13 != (char *)0x0) goto LAB_140f7a21c;
      pcVar14 = (char *)0x1;
    } while( true );
  }
  if ((pcVar13 == (char *)0x0) || (cVar4 = FUN_140faea50(pcVar13,1,1), cVar4 != '\0')) {
LAB_140f7a253:
    *(byte *)((longlong)puVar3 + 0x1c) = *(byte *)((longlong)puVar3 + 0x1c) | 0x10;
  }
LAB_140f7a257:
  *(undefined4 *)(puVar3 + 4) = 0;
  puVar3[6] = lVar2;
  puVar3[8] = 0;
  puVar3[9] = 0;
  puVar3[10] = 0;
  puVar3[0xb] = DAT_142934668;
  return 0;
}


