// FUN_141972f10 @ 141972f10
// calls: [CreateFileW]

ulonglong FUN_141972f10(undefined4 param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  BOOL BVar3;
  DWORD DVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  longlong lVar8;
  int *piVar9;
  longlong in_RCX;
  LPCWSTR **lpPathName;
  undefined8 local_res8;
  int local_138;
  int iStack_134;
  undefined8 uStack_130;
  ulonglong local_128;
  undefined8 local_118;
  undefined8 uStack_110;
  ulonglong local_108;
  LPCWSTR *local_100 [3];
  ulonglong local_e8;
  undefined1 local_e0 [16];
  longlong local_d0;
  longlong local_c0;
  longlong local_b8;
  undefined1 local_b0 [16];
  longlong local_a0;
  undefined1 local_90 [32];
  longlong local_70;
  longlong local_68;
  undefined1 local_60 [56];
  
  if (*(longlong *)(in_RCX + 0x10) != 0) {
    if (param_2 != (int *)0x0) {
      local_108 = 0;
      param_2[0] = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_1 = 0;
      param_2[4] = 0;
      param_2[5] = 0;
    }
    FUN_14196f0e0(param_1,local_90);
    FUN_1402a5d70(local_e0,local_90);
    local_c0 = local_70;
    local_b8 = local_68;
    FUN_1402a5d70(local_100,in_RCX);
    uVar6 = FUN_14196efe0();
    uVar7 = FUN_14196eee0();
    local_118 = 0;
    uStack_110 = 0;
    local_108 = 0;
    FUN_14196f3f0(local_100,local_b0);
    lVar8 = FUN_14196f730(local_100,&local_138);
    for (lVar8 = *(longlong *)(lVar8 + 8); lVar8 != 0; lVar8 = *(longlong *)(lVar8 + 8)) {
      if (((local_a0 != 0) && (iVar2 = FUN_14196ead0(local_b0,uVar6), iVar2 != 0)) &&
         (iVar2 = FUN_14196ead0(local_b0,uVar7), iVar2 != 0)) {
        FUN_141974de0(&local_res8,local_100,&local_118);
        if ((int)local_res8 == 3) break;
        if ((int)local_res8 == 0) {
          if (param_2 == (int *)0x0) {
            local_138 = (int)local_118;
            iStack_134 = local_118._4_4_;
            uStack_130 = uStack_110;
            local_128 = local_108;
            FUN_1419783c0(local_60,"boost::filesystem::create_directories",in_RCX,local_100,
                          &local_138);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_60,(ThrowInfo *)&DAT_142890460);
          }
          *param_2 = (int)local_118;
          param_2[1] = local_118._4_4_;
          param_2[2] = (int)uStack_110;
          param_2[3] = uStack_110._4_4_;
          *(ulonglong *)(param_2 + 4) = local_108;
          FUN_1402a29e0(local_b0);
          goto LAB_141973249;
        }
      }
      FUN_14196eb90(local_e0);
      FUN_141970cf0(local_100);
      FUN_14196f3f0(local_100,local_60);
      FUN_1402ac5a0(local_b0,local_60);
      FUN_1402a29e0(local_60);
      lVar8 = FUN_14196f730(local_100,&local_138);
    }
    FUN_1402a29e0(local_b0);
    uVar5 = 0;
    do {
      if ((local_c0 == local_70) && (local_b8 == local_68)) {
        FUN_1402a29e0(local_100);
        FUN_1402a29e0(local_e0);
        FUN_1402a29e0(local_90);
        return uVar5;
      }
      FUN_14196e520(local_100,local_e0);
      if (((local_d0 != 0) && (iVar2 = FUN_14196ead0(local_e0,uVar6), iVar2 != 0)) &&
         (iVar2 = FUN_14196ead0(local_e0,uVar7), iVar2 != 0)) {
        local_128 = 0;
        local_118 = 0;
        uStack_110 = 0;
        local_108 = 0;
        lpPathName = local_100;
        if (7 < local_e8) {
          lpPathName = (LPCWSTR **)local_100[0];
        }
        BVar3 = CreateDirectoryW((LPCWSTR)lpPathName,(LPSECURITY_ATTRIBUTES)0x0);
        if (BVar3 == 0) {
          DVar4 = GetLastError();
          piVar9 = (int *)FUN_141974de0(&local_res8,local_100,local_b0);
          if (*piVar9 != 3) {
            FUN_141978c40(DVar4,local_100,&local_118,"boost::filesystem::create_directory");
          }
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
        if (((local_108 & 1) != 0) && ((local_108 != 1 || ((int)local_118 != 0))))
        goto LAB_141973231;
      }
      FUN_14196fbc0(local_e0);
    } while( true );
  }
  if (param_2 == (int *)0x0) {
    piVar9 = (int *)FUN_141973a10(local_b0,0x16);
    local_138 = *piVar9;
    iStack_134 = piVar9[1];
    uStack_130 = *(undefined8 *)(piVar9 + 2);
    local_128 = *(ulonglong *)(piVar9 + 4);
    FUN_1419785a0(local_60,"boost::filesystem::create_directories",in_RCX,&local_138);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_60,(ThrowInfo *)&DAT_142890460);
  }
  iStack_134 = 0;
  if (DAT_1428e4508 + 0x4d54ee85da812030U < 2) {
    bVar1 = 1;
  }
  else {
    bVar1 = (**(code **)(PTR_vftable_1428e4500 + 0x30))(&PTR_vftable_1428e4500,0x16);
  }
  uVar5 = (ulonglong)bVar1 + 2;
  *(ulonglong *)param_2 = CONCAT44(iStack_134,0x16);
  *(undefined ***)(param_2 + 2) = &PTR_vftable_1428e4500;
  *(ulonglong *)(param_2 + 4) = uVar5;
LAB_141973267:
  return uVar5 & 0xffffffffffffff00;
LAB_141973231:
  if (param_2 == (int *)0x0) {
    local_138 = (int)local_118;
    iStack_134 = local_118._4_4_;
    uStack_130 = uStack_110;
    local_128 = local_108;
    FUN_1419783c0(local_60,"boost::filesystem::create_directories",in_RCX,local_100,&local_138);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_60,(ThrowInfo *)&DAT_142890460);
  }
  *param_2 = (int)local_118;
  param_2[1] = local_118._4_4_;
  param_2[2] = (int)uStack_110;
  param_2[3] = uStack_110._4_4_;
  *(ulonglong *)(param_2 + 4) = local_108;
LAB_141973249:
  FUN_1402a29e0(local_100);
  FUN_1402a29e0(local_e0);
  uVar5 = FUN_1402a29e0(local_90);
  goto LAB_141973267;
}


