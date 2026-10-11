// FUN_140e52680 @ 140e52680
// strings: [.stems]

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140e52680(undefined8 param_1,int param_2,undefined8 *param_3)

{
  char *****pppppcVar1;
  int *piVar2;
  longlong *plVar3;
  code *pcVar4;
  void *pvVar5;
  size_t sVar6;
  ulonglong uVar7;
  int iVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  ulonglong uVar11;
  undefined8 ******ppppppuVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  char ******ppppppcVar16;
  char *_Buf1;
  undefined8 *******_Memory;
  void *pvVar17;
  char *******pppppppcVar18;
  char *pcVar19;
  char *******_Memory_00;
  ulonglong uVar20;
  longlong lVar21;
  longlong lVar22;
  undefined8 *******pppppppuVar23;
  bool bVar24;
  undefined8 *******local_188;
  longlong lStack_180;
  ulonglong local_178;
  ulonglong uStack_170;
  char *******local_168;
  char *****pppppcStack_160;
  void *local_158;
  longlong *plStack_150;
  undefined8 local_148;
  ulonglong uStack_140;
  char *******local_138;
  undefined8 uStack_130;
  size_t local_128;
  ulonglong local_120;
  char ******local_118;
  char *****pppppcStack_110;
  longlong local_f8;
  longlong *local_f0;
  void *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  ulonglong uStack_d0;
  undefined1 local_c8;
  undefined7 uStack_c7;
  undefined8 local_b8;
  ulonglong uStack_b0;
  longlong *local_a8;
  longlong *local_a0;
  longlong local_98 [7];
  longlong *local_60;
  undefined1 local_50 [40];
  
  plVar9 = (longlong *)FUN_140f727c0();
  if (plVar9 == (longlong *)0x0) {
    pcVar19 = "SQL function getStemsStatus has no context set";
LAB_140e530e2:
    FUN_140f72c20(param_1,pcVar19,0xffffffffffffffff);
    return;
  }
  if (1 < param_2 - 1U) {
    pcVar19 = "SQL function getStemsStatus called with invalid number of arguments";
    goto LAB_140e530e2;
  }
  iVar8 = FUN_140f724a0(*param_3);
  if (iVar8 != 3) {
    pcVar19 = "Invalid type of the first argument of getStemsStatus function call";
    goto LAB_140e530e2;
  }
  if ((param_2 == 2) && (iVar8 = FUN_140f724a0(param_3[1]), iVar8 != 3)) {
    pcVar19 = "Invalid type of the second argument of getStemsStatus function call";
    goto LAB_140e530e2;
  }
  pcVar19 = (char *)FUN_140f727a0(param_1,0xa8);
  if (pcVar19 == (char *)0x0) {
    pcVar19 = "Can\'t allocate memory for track id";
    goto LAB_140e530e2;
  }
  if (param_2 == 2) {
    puVar10 = (undefined1 *)FUN_140f72360(param_3[1]);
  }
  else {
    puVar10 = &DAT_141cafc56;
  }
  local_e8 = (void *)0x0;
  uStack_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  lVar21 = -1;
  do {
    lVar21 = lVar21 + 1;
  } while (puVar10[lVar21] != '\0');
  FUN_14029be90(&local_e8,puVar10);
  lVar21 = FUN_140f72360(*param_3);
  local_138 = (char *******)0x0;
  uStack_130 = 0;
  local_128 = 0;
  local_120 = 0;
  lVar22 = -1;
  do {
    lVar22 = lVar22 + 1;
  } while (*(char *)(lVar21 + lVar22) != '\0');
  FUN_14029be90(&local_138,lVar21);
  uVar7 = local_120;
  pppppppcVar18 = local_138;
  if (*pcVar19 == '\0') {
    bVar24 = plVar9[0x18] == 0;
    if (bVar24) {
      plVar9 = (longlong *)(**(code **)(*plVar9 + 0x68))(plVar9,&local_168);
    }
    else {
      plVar9 = (longlong *)FUN_140dfe590(plVar9[0x18],&local_158,&local_e8);
    }
    local_f8 = *plVar9;
    local_f0 = (longlong *)plVar9[1];
    *plVar9 = 0;
    plVar9[1] = 0;
    if ((bVar24) && (pppppcStack_160 != (char *****)0x0)) {
      LOCK();
      pppppcVar1 = pppppcStack_160 + 1;
      iVar8 = *(int *)pppppcVar1;
      *(int *)pppppcVar1 = *(int *)pppppcVar1 + -1;
      UNLOCK();
      if (iVar8 == 1) {
        (*(code *)**pppppcStack_160)(pppppcStack_160);
        LOCK();
        piVar2 = (int *)((longlong)pppppcStack_160 + 0xc);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          (*(code *)(*pppppcStack_160)[1])(pppppcStack_160);
        }
      }
    }
    if ((!bVar24) && (plStack_150 != (longlong *)0x0)) {
      LOCK();
      plVar9 = plStack_150 + 1;
      lVar21 = *plVar9;
      *(int *)plVar9 = (int)*plVar9 + -1;
      UNLOCK();
      if ((int)lVar21 == 1) {
        (**(code **)*plStack_150)(plStack_150);
        LOCK();
        piVar2 = (int *)((longlong)plStack_150 + 0xc);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          (**(code **)(*plStack_150 + 8))(plStack_150);
        }
      }
    }
    puVar14 = (undefined8 *)FUN_140dd3550(local_f8,&local_118);
    FUN_140dc2670(*puVar14,&local_a8);
    if (pppppcStack_110 != (char *****)0x0) {
      LOCK();
      pppppcVar1 = pppppcStack_110 + 1;
      iVar8 = *(int *)pppppcVar1;
      *(int *)pppppcVar1 = *(int *)pppppcVar1 + -1;
      UNLOCK();
      if (iVar8 == 1) {
        (*(code *)**pppppcStack_110)(pppppcStack_110);
        LOCK();
        piVar2 = (int *)((longlong)pppppcStack_110 + 0xc);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          (*(code *)(*pppppcStack_110)[1])(pppppcStack_110);
        }
      }
    }
    if (local_f8 == 0) {
      FUN_1406e9ad0(local_50,0x15,&local_e8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_50,(ThrowInfo *)&DAT_14288da78);
    }
    uVar15 = FUN_140dd39f0();
    plVar9 = (longlong *)FUN_14041f360(uVar15,&local_c8);
    local_188 = (undefined8 *******)*plVar9;
    lStack_180 = plVar9[1];
    local_178 = plVar9[2];
    uStack_170 = plVar9[3];
    plVar9[2] = 0;
    plVar9[3] = 0xf;
    *(undefined1 *)plVar9 = 0;
    if (0xf < uStack_b0) {
      pvVar5 = (void *)CONCAT71(uStack_c7,local_c8);
      pvVar17 = pvVar5;
      if ((0xfff < uStack_b0 + 1) &&
         (pvVar17 = *(void **)((longlong)pvVar5 + -8),
         0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    pcVar4 = *(code **)(*local_a8 + 0x20);
    plStack_150 = (longlong *)0x0;
    local_148 = _DAT_141cb0070;
    uStack_140 = _UNK_141cb0078;
    local_158 = (void *)0x0;
    if (local_178 != 0) {
      pppppppuVar23 = &local_188;
      if (0xf < uStack_170) {
        pppppppuVar23 = local_188;
      }
      lVar21 = (longlong)pppppppuVar23 + local_178;
      pppppppuVar23 = &local_188;
      if (0xf < uStack_170) {
        pppppppuVar23 = local_188;
      }
      uVar15 = FUN_14196e970();
      FUN_141971270(pppppppuVar23,lVar21,&local_158,uVar15);
    }
    ppppppcVar16 = (char ******)FUN_140e16e30(&local_c8,&local_158);
    local_168 = (char *******)ppppppcVar16;
    if ((char *****)0xf < ppppppcVar16[3]) {
      local_168 = (char *******)*ppppppcVar16;
    }
    pppppcStack_160 = ppppppcVar16[2];
    local_118 = (char ******)local_168;
    pppppcStack_110 = pppppcStack_160;
    (*pcVar4)(local_a8,local_98,&local_118);
    if (0xf < uStack_b0) {
      pvVar5 = (void *)CONCAT71(uStack_c7,local_c8);
      pvVar17 = pvVar5;
      if ((0xfff < uStack_b0 + 1) &&
         (pvVar17 = *(void **)((longlong)pvVar5 + -8),
         0x1f < (ulonglong)((longlong)pvVar5 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    local_b8 = _DAT_141ac9b00;
    uStack_b0 = _UNK_141ac9b08;
    local_c8 = 0;
    if (7 < uStack_140) {
      pvVar17 = local_158;
      if ((0xfff < uStack_140 * 2 + 2) &&
         (pvVar17 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar17)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar17);
    }
    *pcVar19 = '\x01';
    ppppppcVar16 = (char ******)(pcVar19 + 8);
    *ppppppcVar16 = (char *****)0x0;
    pcVar19[0x10] = '\0';
    pcVar19[0x11] = '\0';
    pcVar19[0x12] = '\0';
    pcVar19[0x13] = '\0';
    pcVar19[0x14] = '\0';
    pcVar19[0x15] = '\0';
    pcVar19[0x16] = '\0';
    pcVar19[0x17] = '\0';
    pcVar19[0x18] = '\0';
    pcVar19[0x19] = '\0';
    pcVar19[0x1a] = '\0';
    pcVar19[0x1b] = '\0';
    pcVar19[0x1c] = '\0';
    pcVar19[0x1d] = '\0';
    pcVar19[0x1e] = '\0';
    pcVar19[0x1f] = '\0';
    pcVar19[0x20] = '\a';
    pcVar19[0x21] = '\0';
    pcVar19[0x22] = '\0';
    pcVar19[0x23] = '\0';
    pcVar19[0x24] = '\0';
    pcVar19[0x25] = '\0';
    pcVar19[0x26] = '\0';
    pcVar19[0x27] = '\0';
    *(undefined2 *)ppppppcVar16 = 0;
    if (local_178 != 0) {
      pppppppuVar23 = &local_188;
      if (0xf < uStack_170) {
        pppppppuVar23 = local_188;
      }
      lVar21 = (longlong)pppppppuVar23 + local_178;
      pppppppuVar23 = &local_188;
      if (0xf < uStack_170) {
        pppppppuVar23 = local_188;
      }
      local_168 = (char *******)ppppppcVar16;
      uVar15 = FUN_14196e970();
      FUN_141971270(pppppppuVar23,lVar21,ppppppcVar16,uVar15);
    }
    local_168 = (char *******)(pcVar19 + 0x28);
    if (0x7fffffffffffffff - local_128 < 6) {
                    /* WARNING: Subroutine does not return */
      FUN_14029da10();
    }
    pppppppcVar18 = (char *******)&local_138;
    if (0xf < local_120) {
      pppppppcVar18 = local_138;
    }
    FUN_14029f6d0(local_168,(ulonglong)pcVar19 & 0xff,&local_138,pppppppcVar18,local_128,".stems",6)
    ;
    local_168 = (char *******)(pcVar19 + 0x48);
    if (local_60 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xbad_function_call();
    }
    (**(code **)(*local_60 + 0x10))();
    pcVar19[0xa0] = '\0';
    pcVar19[0xa1] = '\0';
    pcVar19[0xa2] = '\0';
    pcVar19[0xa3] = '\0';
    pcVar19[0xa4] = '\0';
    pcVar19[0xa5] = '\0';
    pcVar19[0xa6] = '\0';
    pcVar19[0xa7] = '\0';
    if (local_60 != (longlong *)0x0) {
      if (local_60 == local_98) {
        uVar15 = (**(code **)(*local_60 + 8))(local_60,pcVar19 + 0x68);
        *(undefined8 *)(pcVar19 + 0xa0) = uVar15;
        if (local_60 == (longlong *)0x0) goto LAB_140e52f62;
        (**(code **)(*local_60 + 0x20))
                  (local_60,CONCAT71((int7)((ulonglong)local_98 >> 8),local_60 != local_98));
      }
      else {
        *(longlong **)(pcVar19 + 0xa0) = local_60;
      }
      local_60 = (longlong *)0x0;
    }
LAB_140e52f62:
    if (local_60 != (longlong *)0x0) {
      (**(code **)(*local_60 + 0x20))
                (local_60,CONCAT71((int7)((ulonglong)local_98 >> 8),local_60 != local_98));
      local_60 = (longlong *)0x0;
    }
    if (0xf < uStack_170) {
      pppppppuVar23 = local_188;
      if ((0xfff < uStack_170 + 1) &&
         (pppppppuVar23 = (undefined8 *******)local_188[-1],
         0x1f < (ulonglong)((longlong)local_188 + (-8 - (longlong)pppppppuVar23)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pppppppuVar23);
    }
    local_178 = 0;
    uStack_170 = 0xf;
    local_188 = (undefined8 *******)((ulonglong)local_188 & 0xffffffffffffff00);
    if (local_a0 != (longlong *)0x0) {
      LOCK();
      plVar9 = local_a0 + 1;
      lVar21 = *plVar9;
      *(int *)plVar9 = (int)*plVar9 + -1;
      UNLOCK();
      if ((int)lVar21 == 1) {
        (**(code **)*local_a0)(local_a0);
        LOCK();
        piVar2 = (int *)((longlong)local_a0 + 0xc);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          (**(code **)(*local_a0 + 8))(local_a0);
        }
      }
    }
    plVar9 = local_f0;
    if (local_f0 != (longlong *)0x0) {
      LOCK();
      plVar3 = local_f0 + 1;
      lVar21 = *plVar3;
      *(int *)plVar3 = (int)*plVar3 + -1;
      UNLOCK();
      if ((int)lVar21 == 1) {
        (**(code **)*local_f0)(local_f0);
        LOCK();
        piVar2 = (int *)((longlong)plVar9 + 0xc);
        iVar8 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
        if (iVar8 == 1) {
          (**(code **)(*local_f0 + 8))();
        }
      }
    }
    if (0xf < local_120) {
      pppppppcVar18 = local_138;
      if ((0xfff < local_120 + 1) &&
         (pppppppcVar18 = (char *******)local_138[-1],
         (char *)0x1f < (char *)((longlong)local_138 + (-8 - (longlong)pppppppcVar18))))
      goto LAB_140e53085;
      free(pppppppcVar18);
    }
    if (uStack_d0 < 0x10) {
      return;
    }
    pvVar17 = local_e8;
    if (uStack_d0 + 1 < 0x1000) goto LAB_140e52a66;
    pvVar17 = *(void **)((longlong)local_e8 + -8);
    lVar21 = (longlong)local_e8 - (longlong)pvVar17;
  }
  else {
    if (0x7fffffffffffffff - local_128 < 6) {
                    /* WARNING: Subroutine does not return */
      FUN_14029da10();
    }
    local_168 = (char *******)&local_138;
    if (0xf < local_120) {
      local_168 = local_138;
    }
    local_188 = (undefined8 *******)0x0;
    lStack_180 = 0;
    uVar13 = local_128 + 6;
    uVar20 = 0xf;
    pppppppuVar23 = &local_188;
    if (0xf < uVar13) {
      uVar20 = uVar13 | 0xf;
      if (uVar20 < 0x8000000000000000) {
        if (uVar20 < 0x16) {
          uVar20 = 0x16;
        }
        if (uVar20 == 0xffffffffffffffff) {
          pppppppuVar23 = (undefined8 *******)0x0;
          local_188 = pppppppuVar23;
        }
        else {
          if (0xfff < uVar20 + 1) {
            uVar11 = uVar20 + 0x28;
            if (uVar11 <= uVar20 + 1) {
                    /* WARNING: Subroutine does not return */
              FUN_14029d880();
            }
            goto LAB_140e52855;
          }
          pppppppuVar23 = (undefined8 *******)FUN_141981f80();
          local_188 = pppppppuVar23;
        }
      }
      else {
        uVar20 = 0x7fffffffffffffff;
        uVar11 = 0x8000000000000027;
LAB_140e52855:
        ppppppuVar12 = (undefined8 ******)FUN_141981f80(uVar11);
        if (ppppppuVar12 == (undefined8 ******)0x0) goto LAB_140e52990;
        pppppppuVar23 = (undefined8 *******)((longlong)ppppppuVar12 + 0x27U & 0xffffffffffffffe0);
        pppppppuVar23[-1] = ppppppuVar12;
        local_188 = pppppppuVar23;
      }
    }
    local_178 = uVar13;
    uStack_170 = uVar20;
    memcpy(pppppppuVar23,local_168,local_128);
    sVar6 = local_128;
    *(undefined4 *)(local_128 + (longlong)pppppppuVar23) = s__stems_141d2eee0._0_4_;
    *(undefined2 *)(sVar6 + 4 + (longlong)pppppppuVar23) = s__stems_141d2eee0._4_2_;
    _Memory = local_188;
    *(undefined1 *)((longlong)pppppppuVar23 + sVar6 + 6) = 0;
    pppppppuVar23 = &local_188;
    if (0xf < uStack_170) {
      pppppppuVar23 = local_188;
    }
    uVar13 = *(ulonglong *)(pcVar19 + 0x38);
    _Buf1 = pcVar19 + 0x28;
    if (0xf < *(ulonglong *)(pcVar19 + 0x40)) {
      _Buf1 = *(char **)(pcVar19 + 0x28);
    }
    uVar20 = uVar13;
    if (local_178 < uVar13) {
      uVar20 = local_178;
    }
    iVar8 = memcmp(_Buf1,pppppppuVar23,uVar20);
    if (iVar8 == 0) {
      if (local_178 <= uVar13) goto LAB_140e5294a;
LAB_140e5299e:
      FUN_1402ac4f0(pcVar19 + 0x28,&local_188);
      if (0xf < uStack_170) {
        _Memory = local_188;
        if (0xfff < uStack_170 + 1) {
          _Memory = (undefined8 *******)local_188[-1];
          uVar13 = (longlong)local_188 + (-8 - (longlong)_Memory);
joined_r0x000140e5298e:
          if (0x1f < uVar13) {
LAB_140e52990:
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
LAB_140e529e6:
        free(_Memory);
      }
    }
    else {
      if (iVar8 < 0) goto LAB_140e5299e;
LAB_140e5294a:
      FUN_140f72c20(param_1,"getStemsStatus tracks identifiers are not properly sorted",0xffffffff);
      if (0xf < uStack_170) {
        if (0xfff < uStack_170 + 1) {
          uVar13 = (longlong)_Memory + (-8 - (longlong)_Memory[-1]);
          _Memory = (undefined8 *******)_Memory[-1];
          goto joined_r0x000140e5298e;
        }
        goto LAB_140e529e6;
      }
    }
    if (0xf < uVar7) {
      _Memory_00 = pppppppcVar18;
      if ((0xfff < uVar7 + 1) &&
         (_Memory_00 = (char *******)pppppppcVar18[-1],
         (char *)0x1f < (char *)((longlong)pppppppcVar18 + (-8 - (longlong)_Memory_00)))) {
LAB_140e53085:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(_Memory_00);
    }
    if (uStack_d0 < 0x10) {
      return;
    }
    pvVar17 = local_e8;
    if (uStack_d0 + 1 < 0x1000) goto LAB_140e52a66;
    pvVar17 = *(void **)((longlong)local_e8 + -8);
    lVar21 = (longlong)local_e8 - (longlong)pvVar17;
  }
  if (0x1f < lVar21 - 8U) {
                    /* WARNING: Subroutine does not return */
    _invalid_parameter_noinfo_noreturn();
  }
LAB_140e52a66:
  free(pvVar17);
  return;
}


