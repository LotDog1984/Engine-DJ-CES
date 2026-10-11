// FUN_140e8db50 @ 140e8db50
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_140e8db50(undefined8 *param_1,undefined8 *param_2)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  uint *puVar5;
  longlong lVar6;
  longlong *plVar7;
  basic_istream<char,struct_std::char_traits<char>_> *pbVar8;
  undefined8 ****ppppuVar9;
  char *pcVar10;
  char *pcVar11;
  undefined8 ****ppppuVar12;
  undefined8 *puVar13;
  ulonglong uVar14;
  undefined1 local_res10 [8];
  undefined8 ***local_1b0;
  undefined8 uStack_1a8;
  longlong local_1a0;
  ulonglong uStack_198;
  char *local_190;
  char *pcStack_188;
  char *local_180;
  ulonglong uStack_178;
  undefined8 ***local_170 [2];
  longlong local_160;
  ulonglong local_158;
  int iStack_14c;
  undefined *local_148 [2];
  undefined **local_138;
  basic_istream<char,std::char_traits<char>_> local_130 [96];
  undefined8 local_d0;
  undefined1 local_c7;
  undefined8 local_c4;
  undefined1 local_bc;
  undefined8 local_b8;
  basic_ios<char,std::char_traits<char>_> local_98 [112];
  
  if (param_2[2] == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0xf;
    *(undefined1 *)param_1 = 0;
    return param_1;
  }
  if ((DAT_142b22e40 == '\0') && (cVar2 = FUN_140e8e170(), cVar2 == '\0')) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0xf;
    *(undefined1 *)param_1 = 0;
    return param_1;
  }
  if (0x7fffffffffffffff - param_2[2] < 6) {
                    /* WARNING: Subroutine does not return */
    FUN_14029da10();
  }
  puVar13 = param_2;
  if (0xf < (ulonglong)param_2[3]) {
    puVar13 = (undefined8 *)*param_2;
  }
  FUN_14029f6d0(&local_1b0,local_res10[0],param_2,puVar13,param_2[2],".cache",6);
  pcStack_188 = (char *)0x0;
  local_180 = _DAT_141cb0070;
  uStack_178 = _UNK_141cb0078;
  local_190 = (char *)0x0;
  if (local_1a0 != 0) {
    ppppuVar9 = &local_1b0;
    if (0xf < uStack_198) {
      ppppuVar9 = (undefined8 ****)local_1b0;
    }
    ppppuVar12 = &local_1b0;
    if (0xf < uStack_198) {
      ppppuVar12 = (undefined8 ****)local_1b0;
    }
    uVar4 = FUN_14196e970();
    FUN_141971270(ppppuVar12,(longlong)ppppuVar9 + local_1a0,&local_190,uVar4);
  }
  FUN_1403a32e0(local_170,&DAT_142930978,&local_190);
  if (7 < uStack_178) {
    pcVar10 = local_190;
    if ((0xfff < uStack_178 * 2 + 2) &&
       (pcVar10 = *(char **)(local_190 + -8), (char *)0x1f < local_190 + (-8 - (longlong)pcVar10)))
    {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(pcVar10);
  }
  local_180 = _DAT_141cb0070;
  uStack_178 = _UNK_141cb0078;
  local_190 = (char *)((ulonglong)local_190 & 0xffffffffffff0000);
  if (0xf < uStack_198) {
    ppppuVar9 = (undefined8 ****)local_1b0;
    if ((0xfff < uStack_198 + 1) &&
       (ppppuVar9 = (undefined8 ****)local_1b0[-1],
       0x1f < (ulonglong)((longlong)local_1b0 + (-8 - (longlong)ppppuVar9)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(ppppuVar9);
  }
  uVar14 = _UNK_141ac9b08;
  uVar4 = _DAT_141ac9b00;
  local_1a0 = _DAT_141ac9b00;
  uStack_198 = _UNK_141ac9b08;
  local_1b0 = (undefined8 ***)((ulonglong)local_1b0 & 0xffffffffffffff00);
  puVar5 = (uint *)FUN_141974de0(local_res10,local_170,0);
  if (1 < *puVar5) {
    uStack_1a8 = 0;
    local_1a0 = uVar4;
    uStack_198 = uVar14;
    local_1b0 = (undefined8 ****)0x0;
    if (local_160 != 0) {
      ppppuVar9 = local_170;
      if (7 < local_158) {
        ppppuVar9 = (undefined8 ****)local_170[0];
      }
      ppppuVar12 = local_170;
      if (7 < local_158) {
        ppppuVar12 = (undefined8 ****)local_170[0];
      }
      uVar4 = FUN_14196e970();
      FUN_141971350(ppppuVar12,(longlong)ppppuVar9 + local_160 * 2,&local_1b0,uVar4);
    }
    ppppuVar9 = &local_1b0;
    if (0xf < uStack_198) {
      ppppuVar9 = (undefined8 ****)local_1b0;
    }
    local_148[0] = &DAT_141da2fa8;
    std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>(local_98);
    std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
              ((basic_istream<char,std::char_traits<char>_> *)local_148,
               (basic_streambuf<char,std::char_traits<char>_> *)&local_138,false);
    *(undefined ***)((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_14c + (longlong)*(int *)(local_148[0] + 4)) =
         *(int *)(local_148[0] + 4) + -0xb0;
    std::basic_streambuf<char,std::char_traits<char>_>::
    basic_streambuf<char,std::char_traits<char>_>
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_138);
    local_138 = std::basic_filebuf<char,std::char_traits<char>_>::vftable;
    local_bc = 0;
    local_c7 = 0;
    std::basic_streambuf<char,std::char_traits<char>_>::_Init
              ((basic_streambuf<char,std::char_traits<char>_> *)&local_138);
    local_b8 = 0;
    local_c4 = DAT_142b0ef28;
    local_d0 = 0;
    lVar6 = FUN_1407fc690(&local_138,ppppuVar9,0x25,0x40);
    if (lVar6 == 0) {
      std::basic_ios<char,std::char_traits<char>_>::setstate
                ((basic_ios<char,std::char_traits<char>_> *)
                 ((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)),2,false);
    }
    *(undefined ***)((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_14c + (longlong)*(int *)(local_148[0] + 4)) =
         *(int *)(local_148[0] + 4) + -0xb0;
    if (0xf < uStack_198) {
      ppppuVar9 = (undefined8 ****)local_1b0;
      if ((0xfff < uStack_198 + 1) &&
         (ppppuVar9 = (undefined8 ****)local_1b0[-1],
         0x1f < (ulonglong)((longlong)local_1b0 + (-8 - (longlong)ppppuVar9)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(ppppuVar9);
    }
    local_1a0 = _DAT_141ac9b00;
    uStack_198 = _UNK_141ac9b08;
    local_1b0 = (undefined8 ***)((ulonglong)local_1b0 & 0xffffffffffffff00);
    plVar7 = (longlong *)
             std::basic_istream<char,std::char_traits<char>_>::tellg
                       ((basic_istream<char,std::char_traits<char>_> *)local_148);
    uVar14 = plVar7[1] + *plVar7;
    std::basic_istream<char,std::char_traits<char>_>::seekg
              ((basic_istream<char,std::char_traits<char>_> *)local_148,0,0);
    local_190 = (char *)0x0;
    pcStack_188 = (char *)0x0;
    local_180 = (char *)0x0;
    if (uVar14 == 0) {
      pcVar10 = (char *)0x0;
    }
    else {
      if (0x7fffffffffffffff < uVar14) {
                    /* WARNING: Subroutine does not return */
        FUN_1402a2a50();
      }
      if (uVar14 < 0x1000) {
        pcVar10 = (char *)FUN_141981f80(uVar14);
      }
      else {
        if (uVar14 + 0x27 <= uVar14) {
                    /* WARNING: Subroutine does not return */
          FUN_14029d880();
        }
        lVar6 = FUN_141981f80();
        if (lVar6 == 0) goto LAB_140e8e0c4;
        pcVar10 = (char *)(lVar6 + 0x27U & 0xffffffffffffffe0);
        *(longlong *)(pcVar10 + -8) = lVar6;
      }
      local_190 = pcVar10;
      local_180 = pcVar10 + uVar14;
      memset(pcVar10,0,uVar14);
      pcStack_188 = pcVar10 + uVar14;
    }
    pcVar1 = pcStack_188;
    pbVar8 = std::basic_istream<char,std::char_traits<char>_>::read
                       ((basic_istream<char,std::char_traits<char>_> *)local_148,pcVar10,uVar14);
    bVar3 = std::ios_base::operator_bool((ios_base *)(pbVar8 + *(int *)(*(longlong *)pbVar8 + 4)));
    if (bVar3) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      if (pcVar10 == pcVar1) {
        param_1[2] = 0;
        param_1[3] = 0xf;
        *(undefined1 *)param_1 = 0;
      }
      else {
        FUN_14029be90(param_1,pcVar10,(longlong)pcVar1 - (longlong)pcVar10);
      }
      if (pcVar10 != (char *)0x0) {
        pcVar11 = pcVar10;
        if ((0xfff < (ulonglong)((longlong)pcVar1 - (longlong)pcVar10)) &&
           (pcVar11 = *(char **)(pcVar10 + -8), (char *)0x1f < pcVar10 + (-8 - (longlong)pcVar11)))
        {
LAB_140e8e0c4:
                    /* WARNING: Subroutine does not return */
          _invalid_parameter_noinfo_noreturn();
        }
        free(pcVar11);
      }
      *(undefined ***)((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)) =
           std::basic_ifstream<char,std::char_traits<char>_>::vftable;
      *(int *)((longlong)&iStack_14c + (longlong)*(int *)(local_148[0] + 4)) =
           *(int *)(local_148[0] + 4) + -0xb0;
      FUN_1407f0da0(&local_138);
      std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
                (local_130);
      std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>
                (local_98);
      goto LAB_140e8e128;
    }
    if (pcVar10 != (char *)0x0) {
      pcVar11 = pcVar10;
      if ((0xfff < (ulonglong)((longlong)pcVar1 - (longlong)pcVar10)) &&
         (pcVar11 = *(char **)(pcVar10 + -8), (char *)0x1f < pcVar10 + (-8 - (longlong)pcVar11)))
      goto LAB_140e8e0c4;
      free(pcVar11);
    }
    *(undefined ***)((longlong)local_148 + (longlong)*(int *)(local_148[0] + 4)) =
         std::basic_ifstream<char,std::char_traits<char>_>::vftable;
    *(int *)((longlong)&iStack_14c + (longlong)*(int *)(local_148[0] + 4)) =
         *(int *)(local_148[0] + 4) + -0xb0;
    FUN_1407f0da0(&local_138);
    std::basic_istream<char,std::char_traits<char>_>::~basic_istream<char,std::char_traits<char>_>
              (local_130);
    std::basic_ios<char,std::char_traits<char>_>::~basic_ios<char,std::char_traits<char>_>(local_98)
    ;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0xf;
  *(undefined1 *)param_1 = 0;
LAB_140e8e128:
  FUN_1402a29e0(local_170);
  return param_1;
}


