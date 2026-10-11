// FUN_141971d50 @ 141971d50
// calls: [CreateFileW]

undefined8 * FUN_141971d50(undefined8 *param_1,undefined8 param_2,undefined8 param_3,DWORD *param_4)

{
  undefined **ppuVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  DWORD DVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  short ****ppppsVar10;
  LPCWSTR pWVar11;
  undefined8 *puVar12;
  undefined8 ****ppppuVar13;
  undefined8 ****ppppuVar14;
  ulonglong uVar15;
  int iVar16;
  DWORD DVar17;
  DWORD DVar18;
  DWORD DVar19;
  ulonglong local_res10;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  ulonglong local_148;
  ulonglong uStack_140;
  undefined8 *local_138;
  undefined **ppuStack_130;
  ulonglong local_128;
  ulonglong uStack_120;
  undefined8 ***local_118 [3];
  ulonglong local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  short ***local_e0 [2];
  longlong local_d0;
  ulonglong local_c8;
  longlong local_c0;
  longlong local_b8;
  undefined8 ***local_b0 [2];
  undefined8 local_a0;
  ulonglong local_98;
  undefined1 local_70 [32];
  longlong local_50;
  longlong local_48;
  undefined1 local_38 [16];
  
  if (param_4 != (DWORD *)0x0) {
    local_148 = 0;
    param_4[0] = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    param_4[3] = 0;
    param_4[4] = 0;
    param_4[5] = 0;
  }
  FUN_1402a5d70(local_118);
  lVar7 = FUN_14196fa10(param_2);
  if ((lVar7 == 0) || (lVar7 = FUN_14196f7d0(param_2,local_38), *(longlong *)(lVar7 + 8) == 0)) {
    uVar8 = FUN_1419715c0(local_b0,param_2,param_3,param_4);
    FUN_1402ac5a0(local_118,uVar8);
    FUN_1402a29e0(local_b0);
    if (((param_4 != (DWORD *)0x0) && ((*(ulonglong *)(param_4 + 4) & 1) != 0)) &&
       ((*(ulonglong *)(param_4 + 4) != 1 || (*param_4 != 0)))) goto LAB_1419727ad;
  }
  local_f8 = 0;
  uStack_f0 = (undefined **)0x0;
  local_e8 = 0;
  FUN_141974de0(&local_res10,local_118,&local_f8);
  if ((int)local_res10 == 1) {
    local_f8 = local_f8 & 0xffffffff;
    if (DAT_1428e4508 + 0x4d54ee85da812030U < 2) {
      bVar2 = 1;
    }
    else {
      bVar2 = (**(code **)(PTR_vftable_1428e4500 + 0x30))(&PTR_vftable_1428e4500,2);
    }
    local_e8 = (ulonglong)bVar2 + 2;
    local_f8 = CONCAT44(local_f8._4_4_,2);
    uVar9 = local_f8;
    uStack_f0 = &PTR_vftable_1428e4500;
    ppuVar1 = uStack_f0;
    local_f8._0_4_ = 2;
    uStack_f0._0_4_ = 0x428e4500;
    uStack_f0._4_4_ = 1;
    DVar5 = (DWORD)local_f8;
    DVar17 = local_f8._4_4_;
    DVar18 = (DWORD)uStack_f0;
    DVar19 = uStack_f0._4_4_;
    local_f8 = uVar9;
    uStack_f0 = ppuVar1;
    uVar9 = local_e8;
  }
  else {
    if (((local_e8 & 1) == 0) || ((local_e8 == 1 && ((DWORD)local_f8 == 0)))) {
      ppppuVar13 = local_118;
      if (7 < local_100) {
        ppppuVar13 = (undefined8 ****)local_118[0];
      }
      lVar7 = FUN_14196fa40(local_118);
      ppppuVar13 = (undefined8 ****)((longlong)ppppuVar13 + lVar7 * 2);
      ppppuVar14 = local_118;
      if (7 < local_100) {
        ppppuVar14 = (undefined8 ****)local_118[0];
      }
      local_138 = (undefined8 *)0x0;
      ppuStack_130 = (undefined **)0x0;
      local_128 = 0;
      uStack_120 = 0;
      if (ppppuVar14 == ppppuVar13) {
        local_128 = 0;
        uStack_120 = 7;
        local_138 = (undefined8 *)0x0;
      }
      else {
        FUN_1402a7200(&local_138,ppppuVar14,(longlong)ppppuVar13 - (longlong)ppppuVar14 >> 1);
      }
      uVar8 = FUN_14196efe0();
      uVar9 = FUN_14196eee0();
      iVar16 = 0x28;
      uStack_170 = 0;
      local_168 = 0;
      uStack_160 = 7;
      local_178 = (LPCWSTR)0x0;
      local_res10 = uVar9;
LAB_141971f70:
      uVar15 = local_res10;
      FUN_14196e770(local_118,local_e0);
      FUN_14196f0e0(local_118,local_70);
LAB_141971f90:
      if ((local_c0 == local_50) && (local_b8 == local_48)) {
        FUN_1402a29e0(local_70);
        FUN_1402a29e0(local_e0);
        *(undefined4 *)param_1 = (undefined4)local_178;
        *(undefined4 *)((longlong)param_1 + 4) = local_178._4_4_;
        *(undefined4 *)(param_1 + 1) = (undefined4)uStack_170;
        *(undefined4 *)((longlong)param_1 + 0xc) = uStack_170._4_4_;
        *(undefined4 *)(param_1 + 2) = (undefined4)local_168;
        *(undefined4 *)((longlong)param_1 + 0x14) = local_168._4_4_;
        *(undefined4 *)(param_1 + 3) = (undefined4)uStack_160;
        *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_160._4_4_;
        local_168 = 0;
        uStack_160 = 7;
        local_178 = (LPCWSTR)((ulonglong)local_178 & 0xffffffffffff0000);
        FUN_1402a29e0(&local_178);
        FUN_1402a29e0(&local_138);
        goto LAB_1419727c6;
      }
      iVar4 = FUN_14196ead0(local_e0,uVar8);
      if (iVar4 != 0) {
        iVar4 = FUN_14196ead0(local_e0,uVar15);
        if (iVar4 == 0) {
          iVar4 = FUN_14196ead0(&local_178,&local_138);
          if (iVar4 == 0) goto LAB_1419722ba;
          FUN_141970cf0(&local_178);
          FUN_14196fbc0(local_e0);
          goto LAB_141971f90;
        }
        if (local_d0 == 1) {
          ppppsVar10 = local_e0;
          if (7 < local_c8) {
            ppppsVar10 = (short ****)local_e0[0];
          }
          if ((*(short *)ppppsVar10 == 0x2f) || (*(short *)ppppsVar10 == 0x5c)) {
            if (local_168 < uStack_160) {
              pWVar11 = (LPCWSTR)&local_178;
              if (7 < uStack_160) {
                pWVar11 = local_178;
              }
              pWVar11 = pWVar11 + local_168;
              local_168 = local_168 + 1;
              pWVar11[0] = L'\\';
              pWVar11[1] = L'\0';
              FUN_14196fbc0(local_e0);
            }
            else {
              FUN_1402a5a70(&local_178,1,uVar9 & 0xff,0x5c);
              FUN_14196fbc0(local_e0);
            }
            goto LAB_141971f90;
          }
        }
        FUN_14196e520(&local_178,local_e0);
        lVar7 = FUN_14196fa10(&local_178);
        if ((lVar7 != 0) &&
           (lVar7 = FUN_14196f7d0(&local_178,local_38), *(longlong *)(lVar7 + 8) != 0)) {
          if (param_4 != (DWORD *)0x0) {
            local_148 = 0;
            param_4[0] = 0;
            param_4[1] = 0;
            param_4[2] = 0;
            param_4[3] = 0;
            param_4[4] = 0;
            param_4[5] = 0;
          }
          pWVar11 = (LPCWSTR)&local_178;
          if (7 < uStack_160) {
            pWVar11 = local_178;
          }
          DVar5 = GetFileAttributesW(pWVar11);
          if (DVar5 == 0xffffffff) {
            DVar5 = GetLastError();
            if (param_4 != (DWORD *)0x0) {
              local_158 = (undefined8 *)((ulonglong)local_158 & 0xffffffff);
              if (DAT_1428e1960 + 0x4d54ee85da812030U < 2) {
                bVar2 = DVar5 != 0;
              }
              else {
                bVar2 = (**(code **)(PTR_vftable_1428e1958 + 0x30))(&PTR_vftable_1428e1958,DVar5);
              }
              local_148 = (ulonglong)bVar2 + 2;
              local_158 = (undefined8 *)CONCAT44(local_158._4_4_,DVar5);
              uStack_150 = &PTR_vftable_1428e1958;
              *param_4 = DVar5;
              param_4[1] = local_158._4_4_;
              param_4[2] = 0x428e1958;
              param_4[3] = 1;
              *(ulonglong *)(param_4 + 4) = local_148;
            }
            if ((((DVar5 < 0x36) && ((0x2000000020800cU >> ((longlong)(int)DVar5 & 0x3fU) & 1) != 0)
                 ) || ((DVar5 - 0x43 < 0x39 &&
                       ((0x100000000100001U >> ((ulonglong)(DVar5 - 0x43) & 0x3f) & 1) != 0)))) ||
               (DVar5 == 0xa1)) {
              uVar6 = 1;
            }
            else if (DVar5 == 0x20) {
              uVar6 = 10;
            }
            else {
              if (param_4 == (DWORD *)0x0) {
                uVar8 = FUN_1405ad2d0();
                puVar12 = (undefined8 *)FUN_14080e890(&local_f8,DVar5,uVar8);
                local_158 = (undefined8 *)*puVar12;
                uStack_150 = (undefined **)puVar12[1];
                local_148 = puVar12[2];
                FUN_1419785a0(local_b0,"boost::filesystem::status",&local_178,&local_158);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_b0,(ThrowInfo *)&DAT_142890460);
              }
              uVar6 = 0;
            }
          }
          else {
            FUN_141973a90(&local_178,DVar5);
            if ((DVar5 >> 10 & 1) == 0) {
              uVar6 = (DVar5 & 0x10 | 0x20) >> 4;
            }
            else {
              cVar3 = FUN_1419735e0(&local_178);
              uVar6 = 4;
              if (cVar3 == '\0') {
                uVar6 = 9;
              }
            }
          }
          if (((param_4 != (DWORD *)0x0) && ((*(ulonglong *)(param_4 + 4) & 1) != 0)) &&
             ((*(ulonglong *)(param_4 + 4) != 1 || (*param_4 != 0)))) {
            FUN_1402a29e0(local_70);
            FUN_1402a29e0(local_e0);
            if (7 < uStack_160) {
              pWVar11 = local_178;
              if ((0xfff < uStack_160 * 2 + 2) &&
                 (pWVar11 = *(LPCWSTR *)(local_178 + -4),
                 0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)pWVar11)))) {
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              free(pWVar11);
            }
            local_168 = 0;
            uStack_160 = 7;
            local_178 = (LPCWSTR)((ulonglong)local_178 & 0xffffffffffff0000);
            if (7 < uStack_120) {
              puVar12 = local_138;
              if ((0xfff < uStack_120 * 2 + 2) &&
                 (puVar12 = (undefined8 *)local_138[-1],
                 0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)puVar12)))) {
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
LAB_14197265a:
              uStack_160 = 7;
              local_168 = 0;
              free(puVar12);
            }
LAB_14197265f:
            local_128 = 0;
            uStack_120 = 7;
            local_138 = (undefined8 *)((ulonglong)local_138 & 0xffffffffffff0000);
            goto LAB_1419727ad;
          }
          uVar15 = local_res10;
          if (uVar6 != 4) goto LAB_1419722ba;
          if (iVar16 == 0) {
            local_158 = (undefined8 *)((ulonglong)local_158 & 0xffffffff);
            if (DAT_1428e4508 + 0x4d54ee85da812030U < 2) {
              bVar2 = 1;
            }
            else {
              bVar2 = (**(code **)(PTR_vftable_1428e4500 + 0x30))(&PTR_vftable_1428e4500,0x72);
            }
            local_148 = (ulonglong)bVar2 + 2;
            local_158 = (undefined8 *)CONCAT44(local_158._4_4_,0x72);
            uStack_150 = &PTR_vftable_1428e4500;
            FUN_1402a29e0(local_70);
            FUN_1402a29e0(local_e0);
            if (7 < uStack_160) {
              pWVar11 = local_178;
              if ((0xfff < uStack_160 * 2 + 2) &&
                 (pWVar11 = *(LPCWSTR *)(local_178 + -4),
                 0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)pWVar11)))) {
LAB_141972717:
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              free(pWVar11);
            }
            local_168 = 0;
            uStack_160 = 7;
            local_178 = (LPCWSTR)((ulonglong)local_178 & 0xffffffffffff0000);
            if (7 < uStack_120) {
              puVar12 = local_138;
              if ((0xfff < uStack_120 * 2 + 2) &&
                 (puVar12 = (undefined8 *)local_138[-1],
                 0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)puVar12)))) {
LAB_141972773:
                uStack_160 = 7;
                local_168 = 0;
                    /* WARNING: Subroutine does not return */
                _invalid_parameter_noinfo_noreturn();
              }
              free(puVar12);
            }
            local_128 = 0;
            uStack_120 = 7;
            local_138 = (undefined8 *)((ulonglong)local_138 & 0xffffffffffff0000);
            DVar5 = (DWORD)local_158;
            DVar17 = local_158._4_4_;
            DVar18 = (DWORD)uStack_150;
            DVar19 = uStack_150._4_4_;
            uVar9 = local_148;
            goto LAB_14197279e;
          }
          iVar16 = iVar16 + -1;
          FUN_141973ed0(local_b0,&local_178,param_4);
          if (((param_4 != (DWORD *)0x0) && ((*(ulonglong *)(param_4 + 4) & 1) != 0)) &&
             ((*(ulonglong *)(param_4 + 4) != 1 || (*param_4 != 0)))) {
            FUN_1402a29e0(local_b0);
            FUN_1402a29e0(local_70);
            FUN_1402a29e0(local_e0);
            if (7 < uStack_160) {
              pWVar11 = local_178;
              if ((0xfff < uStack_160 * 2 + 2) &&
                 (pWVar11 = *(LPCWSTR *)(local_178 + -4),
                 0x1f < (ulonglong)((longlong)local_178 + (-8 - (longlong)pWVar11))))
              goto LAB_141972717;
              free(pWVar11);
            }
            local_168 = 0;
            uStack_160 = 7;
            local_178 = (LPCWSTR)((ulonglong)local_178 & 0xffffffffffff0000);
            if (7 < uStack_120) {
              puVar12 = local_138;
              if ((0xfff < uStack_120 * 2 + 2) &&
                 (puVar12 = (undefined8 *)local_138[-1],
                 0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)local_138[-1]))))
              goto LAB_141972773;
              goto LAB_14197265a;
            }
            goto LAB_14197265f;
          }
          FUN_141970cf0(&local_178);
          lVar7 = FUN_14196fa10(local_b0);
          if ((lVar7 != 0) &&
             (lVar7 = FUN_14196f7d0(local_b0,&local_f8), *(longlong *)(lVar7 + 8) != 0))
          goto LAB_1419722c8;
          FUN_141970da0(local_b0);
          iVar4 = FUN_14196ead0(local_b0,uVar8);
          if (iVar4 != 0) {
            FUN_1402a5d70(&local_158,&local_178);
            ppppsVar10 = (short ****)local_b0;
            do {
              FUN_14196e520(&local_158,ppppsVar10);
              do {
                FUN_14196fbc0(local_e0);
                if ((local_c0 == local_50) && (local_b8 == local_48)) {
                  puVar12 = &local_158;
                  if (7 < uStack_140) {
                    puVar12 = local_158;
                  }
                  FUN_1402a6570(local_118,puVar12,local_148);
                  FUN_1402a29e0(&local_158);
                  goto LAB_141972456;
                }
                iVar4 = FUN_14196ead0(local_e0,uVar8);
              } while (iVar4 == 0);
              ppppsVar10 = local_e0;
            } while( true );
          }
          FUN_1402a29e0(local_b0);
          uVar15 = local_res10;
        }
      }
LAB_1419722ba:
      FUN_14196fbc0(local_e0);
      goto LAB_141971f90;
    }
    DVar5 = (DWORD)local_f8;
    DVar17 = local_f8._4_4_;
    DVar18 = (DWORD)uStack_f0;
    DVar19 = uStack_f0._4_4_;
    uVar9 = local_e8;
  }
LAB_14197279e:
  if (param_4 == (DWORD *)0x0) {
    local_158 = (undefined8 *)CONCAT44(DVar17,DVar5);
    uStack_150 = (undefined **)CONCAT44(DVar19,DVar18);
    local_148 = uVar9;
    FUN_1419785a0(local_70,"boost::filesystem::canonical",local_118,&local_158);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_70,(ThrowInfo *)&DAT_142890460);
  }
  *param_4 = DVar5;
  param_4[1] = DVar17;
  param_4[2] = DVar18;
  param_4[3] = DVar19;
  *(ulonglong *)(param_4 + 4) = uVar9;
LAB_1419727ad:
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 7;
  *(undefined2 *)param_1 = 0;
LAB_1419727c6:
  FUN_1402a29e0(local_118);
  return param_1;
LAB_1419722c8:
  while ((FUN_14196fbc0(local_e0), local_c0 != local_50 || (local_b8 != local_48))) {
    iVar4 = FUN_14196ead0(local_e0,uVar8);
    if (iVar4 != 0) {
      FUN_14196e520(local_b0,local_e0);
    }
  }
  ppppuVar13 = local_b0;
  if (7 < local_98) {
    ppppuVar13 = (undefined8 ****)local_b0[0];
  }
  FUN_1402a6570(local_118,ppppuVar13,local_a0);
  ppppuVar13 = local_118;
  if (7 < local_100) {
    ppppuVar13 = (undefined8 ****)local_118[0];
  }
  lVar7 = FUN_14196fa40(local_118);
  ppppuVar13 = (undefined8 ****)((longlong)ppppuVar13 + lVar7 * 2);
  ppppuVar14 = local_118;
  if (7 < local_100) {
    ppppuVar14 = (undefined8 ****)local_118[0];
  }
  local_158 = (undefined8 *)0x0;
  uStack_150 = (undefined **)0x0;
  local_148 = 0;
  uStack_140 = 0;
  if (ppppuVar14 == ppppuVar13) {
    uStack_140 = 7;
    local_158 = (undefined8 *)0x0;
  }
  else {
    FUN_1402a7200(&local_158,ppppuVar14,(longlong)ppppuVar13 - (longlong)ppppuVar14 >> 1);
  }
  if (7 < uStack_120) {
    puVar12 = local_138;
    if ((0xfff < uStack_120 * 2 + 2) &&
       (puVar12 = (undefined8 *)local_138[-1],
       0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)puVar12)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(puVar12);
  }
  local_138 = local_158;
  ppuStack_130 = uStack_150;
  local_128 = local_148;
  uStack_120 = uStack_140;
LAB_141972456:
  FUN_1402a29e0(local_b0);
  FUN_1402a29e0(local_70);
  FUN_1402a29e0(local_e0);
  local_168 = 0;
  pWVar11 = (LPCWSTR)&local_178;
  if (7 < uStack_160) {
    pWVar11 = local_178;
  }
  *pWVar11 = L'\0';
  goto LAB_141971f70;
}


