// FUN_140b2c500 @ 140b2c500
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140b2c500(undefined8 *param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  longlong *plVar1;
  void *pvVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  bool bVar5;
  char cVar6;
  uint *puVar7;
  int *piVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  byte *pbVar11;
  void *pvVar12;
  uint uVar13;
  ulonglong local_228;
  undefined1 local_220 [8];
  undefined1 local_218 [8];
  byte *local_210;
  longlong local_208;
  longlong lStack_200;
  undefined8 *local_1f8;
  undefined8 local_1f0;
  undefined8 *puStack_1e8;
  undefined8 *local_1e0;
  undefined1 local_1d8;
  undefined7 uStack_1d7;
  undefined8 uStack_1d0;
  undefined8 local_1c8;
  ulonglong uStack_1c0;
  undefined8 local_198;
  undefined8 uStack_190;
  ulonglong local_188;
  byte *local_180;
  longlong local_178;
  longlong local_170;
  undefined8 *local_168;
  undefined8 local_148;
  int iStack_13c;
  longlong local_138 [2];
  undefined1 local_128 [8];
  basic_istream<char,std::char_traits<char>_> local_120 [152];
  basic_ios<char,std::char_traits<char>_> local_88 [96];
  
  local_198 = 0;
  uStack_190 = 0;
  local_188 = 0;
  puVar7 = (uint *)FUN_141974de0(&local_228,param_2,&local_198);
  if ((*puVar7 < 2) ||
     ((((local_188 & 1) != 0 && ((local_188 != 1 || ((int)local_198 != 0)))) ||
      (piVar8 = (int *)FUN_141974de0(&local_228,param_2,&local_198), *piVar8 == 3)))) {
LAB_140b2ca05:
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    return param_1;
  }
  puVar9 = (undefined8 *)FUN_1402b7590(param_2,&local_1d8);
  if (0xf < (ulonglong)puVar9[3]) {
    puVar9 = (undefined8 *)*puVar9;
  }
  uVar13 = 0;
  FUN_1407ef210(local_138,puVar9,1,0x40,1);
  *(undefined ***)((longlong)local_138 + (longlong)*(int *)(local_138[0] + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(local_138[0] + 4)) =
       *(int *)(local_138[0] + 4) + -0xb0;
  if (0xf < uStack_1c0) {
    pvVar2 = (void *)CONCAT71(uStack_1d7,local_1d8);
    pvVar12 = pvVar2;
    if ((0xfff < uStack_1c0 + 1) &&
       (pvVar12 = *(void **)((longlong)pvVar2 + -8),
       0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pvVar12);
  }
  local_1c8 = _DAT_141ac9b00;
  uStack_1c0 = _UNK_141ac9b08;
  local_1d8 = 0;
  bVar5 = std::ios_base::good((ios_base *)
                              ((longlong)local_138 + (longlong)*(int *)(local_138[0] + 4)));
  if (!bVar5) {
    *(undefined ***)((longlong)local_138 + (longlong)*(int *)(local_138[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_13c + (longlong)*(int *)(local_138[0] + 4)) =
         *(int *)(local_138[0] + 4) + -0xb0;
    FUN_1407f0da0(local_128);
    std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
              (local_120);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_88)
    ;
    goto LAB_140b2ca05;
  }
  local_148 = 0;
  FUN_1407ecd60(local_220,local_138,&local_180,0,uVar13 & 0xffffff00);
  cVar6 = FUN_140b2d160(local_220);
  if (cVar6 != '\0') {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    FUN_140315ba0(local_218,local_220[0]);
    *(undefined ***)((longlong)local_138 + (longlong)*(int *)(local_138[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    goto LAB_140b2c6b1;
  }
  uVar10 = FUN_140b2d770(local_220);
  cVar6 = FUN_140b2d090(uVar10,param_3);
  if (cVar6 == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    FUN_140315ba0(local_218,local_220[0]);
    *(undefined ***)((longlong)local_138 + (longlong)*(int *)(local_138[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_13c + (longlong)*(int *)(local_138[0] + 4)) =
         *(int *)(local_138[0] + 4) + -0xb0;
    FUN_1407f0da0(local_128);
    std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
              (local_120);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_88)
    ;
    return param_1;
  }
  pbVar11 = (byte *)FUN_1407a0e60(uVar10,param_3);
  local_1f0 = 0;
  puStack_1e8 = (undefined8 *)0x0;
  local_1e0 = (undefined8 *)0x0;
  local_228 = FUN_140523f70(pbVar11);
  puVar9 = (undefined8 *)0x0;
  if (local_228 != 0) {
    if (0x7ffffffffffffff < local_228) {
                    /* WARNING: Subroutine does not return */
      FUN_1402a2a50();
    }
    FUN_1404aa920(&local_1f0,&local_228);
    puVar9 = local_1e0;
  }
  local_208 = 0;
  lStack_200 = 0;
  local_1f8 = (undefined8 *)0x8000000000000000;
  switch(*pbVar11) {
  case 0:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
    switch(*pbVar11) {
    case 0:
      local_1f8 = (undefined8 *)0x1;
      break;
    case 1:
      goto switchD_140b2c7fe_caseD_1;
    case 2:
      goto switchD_140b2c7fe_caseD_2;
    default:
      goto switchD_140b2c7fe_default;
    }
    break;
  case 1:
switchD_140b2c7fe_caseD_1:
    local_208 = *(longlong *)**(undefined8 **)(pbVar11 + 8);
    break;
  case 2:
switchD_140b2c7fe_caseD_2:
    lStack_200 = **(longlong **)(pbVar11 + 8);
    break;
  default:
switchD_140b2c7fe_default:
    local_1f8 = (undefined8 *)0x0;
  }
  puVar3 = local_1f8;
  local_210 = pbVar11;
  FUN_14051c430(pbVar11,&local_180);
  puVar4 = puStack_1e8;
  while( true ) {
    if (pbVar11 != local_180) {
      FUN_14029c480(&local_180,"cannot compare iterators of different containers");
      FUN_140513da0(&local_1d8,0xd4,&local_180,pbVar11);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_1d8,(ThrowInfo *)&DAT_14288dbb0);
    }
    switch(*pbVar11) {
    default:
      bVar5 = puVar3 == local_168;
      break;
    case 1:
      bVar5 = local_208 == local_178;
      break;
    case 2:
      bVar5 = lStack_200 == local_170;
    }
    if (bVar5) break;
    uVar10 = FUN_1407a0f20(&local_210);
    plVar1 = *(longlong **)(param_4 + 0x38);
    if (plVar1 == (longlong *)0x0) {
                    /* WARNING: Subroutine does not return */
      std::_Xbad_function_call();
    }
    (**(code **)(*plVar1 + 0x10))(plVar1,&local_1d8,uVar10);
    if (puVar4 == puVar9) {
      FUN_14036e320(&local_1f0,puVar4,&local_1d8);
      puVar9 = local_1e0;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      *puVar4 = CONCAT71(uStack_1d7,local_1d8);
      puVar4[1] = uStack_1d0;
      puVar4[2] = local_1c8;
      puVar4[3] = uStack_1c0;
      local_1c8 = 0;
      uStack_1c0 = 0xf;
      local_1d8 = 0;
      puStack_1e8 = puVar4 + 4;
    }
    puVar4 = puStack_1e8;
    if (0xf < uStack_1c0) {
      pvVar2 = (void *)CONCAT71(uStack_1d7,local_1d8);
      pvVar12 = pvVar2;
      if ((0xfff < uStack_1c0 + 1) &&
         (pvVar12 = *(void **)((longlong)pvVar2 + -8),
         0x1f < (ulonglong)((longlong)pvVar2 + (-8 - (longlong)pvVar12)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar12);
    }
    FUN_14051a520(&local_210);
    pbVar11 = local_210;
    puVar3 = local_1f8;
  }
  *param_1 = local_1f0;
  param_1[1] = puVar4;
  param_1[2] = puVar9;
  FUN_140315ba0(local_218,local_220[0]);
  *(undefined ***)((longlong)local_138 + (longlong)*(int *)(local_138[0] + 4)) =
       std::basic_ifstream<char,std::char_traits<char>_>::vftable;
LAB_140b2c6b1:
  *(int *)((longlong)&iStack_13c + (longlong)*(int *)(local_138[0] + 4)) =
       *(int *)(local_138[0] + 4) + -0xb0;
  FUN_1407f0da0(local_128);
  std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
            (local_120);
  std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_88);
  return param_1;
}


