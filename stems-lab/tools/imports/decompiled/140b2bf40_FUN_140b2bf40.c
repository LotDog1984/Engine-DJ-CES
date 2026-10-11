// FUN_140b2bf40 @ 140b2bf40
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140b2bf40(undefined8 *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  bool bVar4;
  char cVar5;
  uint *puVar6;
  int *piVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  byte *pbVar10;
  longlong lVar11;
  uint uVar12;
  ulonglong local_2b8;
  undefined1 local_2b0 [8];
  undefined1 local_2a8 [8];
  undefined8 local_2a0;
  longlong lStack_298;
  longlong local_290;
  byte *local_288;
  longlong local_280;
  longlong lStack_278;
  ulonglong uStack_270;
  undefined8 local_248;
  undefined8 uStack_240;
  ulonglong local_238;
  byte *local_230;
  longlong local_228;
  longlong local_220;
  longlong local_218;
  undefined8 local_1f8;
  int iStack_1ec;
  longlong local_1e8 [2];
  undefined1 local_1d8 [8];
  basic_istream<char,std::char_traits<char>_> local_1d0 [152];
  basic_ios<char,std::char_traits<char>_> local_138 [96];
  undefined1 local_d8 [176];
  
  local_248 = 0;
  uStack_240 = 0;
  local_238 = 0;
  puVar6 = (uint *)FUN_141974de0(&local_2b8,param_2,&local_248);
  if ((*puVar6 < 2) ||
     ((((local_238 & 1) != 0 && ((local_238 != 1 || ((int)local_248 != 0)))) ||
      (piVar7 = (int *)FUN_141974de0(&local_2b8,param_2,&local_248), *piVar7 == 3)))) {
LAB_140b2c408:
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return param_1;
  }
  puVar8 = (undefined8 *)FUN_1402b7590(param_2,&local_288);
  if (0xf < (ulonglong)puVar8[3]) {
    puVar8 = (undefined8 *)*puVar8;
  }
  uVar12 = 0;
  FUN_1407ef210(local_1e8,puVar8,1,0x40,1);
  *(undefined ***)((longlong)local_1e8 + (longlong)*(int *)(local_1e8[0] + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)((longlong)&iStack_1ec + (longlong)*(int *)(local_1e8[0] + 4)) =
       *(int *)(local_1e8[0] + 4) + -0xb0;
  if (0xf < uStack_270) {
    pbVar10 = local_288;
    if ((0xfff < uStack_270 + 1) &&
       (pbVar10 = *(byte **)(local_288 + -8), (byte *)0x1f < local_288 + (-8 - (longlong)pbVar10)))
    {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pbVar10);
  }
  lStack_278 = _DAT_141ac9b00;
  uStack_270 = _UNK_141ac9b08;
  local_288 = (byte *)((ulonglong)local_288 & 0xffffffffffffff00);
  bVar4 = std::ios_base::good((ios_base *)
                              ((longlong)*(int *)(local_1e8[0] + 4) + (longlong)local_1e8));
  if (!bVar4) {
    *(undefined ***)((longlong)local_1e8 + (longlong)*(int *)(local_1e8[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_1ec + (longlong)*(int *)(local_1e8[0] + 4)) =
         *(int *)(local_1e8[0] + 4) + -0xb0;
    FUN_1407f0da0(local_1d8);
    std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
              (local_1d0);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
              (local_138);
    goto LAB_140b2c408;
  }
  local_1f8 = 0;
  FUN_1407ecd60(local_2b0,local_1e8,&local_230,0,uVar12 & 0xffffff00);
  cVar5 = FUN_140b2d160(local_2b0);
  if (cVar5 != '\0') {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    FUN_140315ba0(local_2a8,local_2b0[0]);
    *(undefined ***)((longlong)local_1e8 + (longlong)*(int *)(local_1e8[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    goto LAB_140b2c0f8;
  }
  uVar9 = FUN_140b2d770(local_2b0);
  cVar5 = FUN_140b2d090(uVar9,param_3);
  if (cVar5 == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    FUN_140315ba0(local_2a8,local_2b0[0]);
    *(undefined ***)((longlong)local_1e8 + (longlong)*(int *)(local_1e8[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_1ec + (longlong)*(int *)(local_1e8[0] + 4)) =
         *(int *)(local_1e8[0] + 4) + -0xb0;
    FUN_1407f0da0(local_1d8);
    std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
              (local_1d0);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
              (local_138);
    return param_1;
  }
  pbVar10 = (byte *)FUN_1407a0e60(uVar9,param_3);
  local_2a0 = 0;
  lStack_298 = 0;
  local_290 = 0;
  local_2b8 = FUN_140523f70(pbVar10);
  lVar11 = 0;
  if (local_2b8 != 0) {
    if (0x186186186186186 < local_2b8) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a2a50();
    }
    FUN_140b2be90(&local_2a0,&local_2b8);
    lVar11 = local_290;
  }
  local_280 = 0;
  lStack_278 = 0;
  uStack_270 = -0x8000000000000000;
  switch(*pbVar10) {
  case 0:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    switch(*pbVar10) {
    case 0:
      uStack_270 = 1;
      break;
    case 1:
      goto switchD_140b2c245_caseD_1;
    case 2:
      goto switchD_140b2c245_caseD_2;
    default:
      goto switchD_140b2c245_default;
    }
    break;
  case 1:
switchD_140b2c245_caseD_1:
    local_280 = *(longlong *)**(undefined8 **)(pbVar10 + 8);
    break;
  case 2:
switchD_140b2c245_caseD_2:
    lStack_278 = **(longlong **)(pbVar10 + 8);
    break;
  default:
switchD_140b2c245_default:
    uStack_270 = 0;
  }
  uVar3 = uStack_270;
  local_288 = pbVar10;
  FUN_14051c430(pbVar10,&local_230);
  lVar2 = lStack_298;
  while( true ) {
    if (pbVar10 != local_230) {
      FUN_14029c480(&local_230,"cannot compare iterators of different containers");
      FUN_140513da0(&local_288,0xd4,&local_230,pbVar10);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_288,(ThrowInfo *)&DAT_14288dbb0);
    }
    switch(*pbVar10) {
    default:
      bVar4 = uVar3 == local_218;
      break;
    case 1:
      bVar4 = local_280 == local_228;
      break;
    case 2:
      bVar4 = lStack_278 == local_220;
    }
    if (bVar4) break;
    uVar9 = FUN_1407a0f20(&local_288);
    plVar1 = *(longlong **)(param_4 + 0x38);
    if (plVar1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xbad_function_call();
    }
    (**(code **)(*plVar1 + 0x10))(plVar1,local_d8,uVar9);
    if (lVar2 == lVar11) {
      FUN_140b2bc60(&local_2a0,lVar2,local_d8);
      lVar11 = local_290;
    }
    else {
      FUN_140b2caf0(lVar2,local_d8);
      lStack_298 = lVar2 + 0xa8;
    }
    lVar2 = lStack_298;
    FUN_140b2ccd0(local_d8);
    FUN_14051a520(&local_288);
    pbVar10 = local_288;
    uVar3 = uStack_270;
  }
  *param_1 = local_2a0;
  param_1[1] = lVar2;
  param_1[2] = lVar11;
  FUN_140315ba0(local_2a8,local_2b0[0]);
  *(undefined ***)((longlong)local_1e8 + (longlong)*(int *)(local_1e8[0] + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
LAB_140b2c0f8:
  *(int *)((longlong)&iStack_1ec + (longlong)*(int *)(local_1e8[0] + 4)) =
       *(int *)(local_1e8[0] + 4) + -0xb0;
  FUN_1407f0da0(local_1d8);
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            (local_1d0);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_138);
  return param_1;
}


