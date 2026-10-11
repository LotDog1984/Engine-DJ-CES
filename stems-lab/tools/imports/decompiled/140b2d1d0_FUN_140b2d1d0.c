// FUN_140b2d1d0 @ 140b2d1d0
// calls: [CreateFileW]

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_140b2d1d0(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  void *pvVar2;
  char cVar3;
  int *piVar4;
  undefined8 uVar5;
  void *pvVar6;
  longlong *plVar7;
  undefined8 *******pppppppuVar8;
  void *pvVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined8 *******pppppppuVar12;
  void *local_158;
  undefined8 uStack_150;
  longlong local_148;
  ulonglong local_140;
  longlong *local_138;
  longlong *plStack_130;
  longlong local_128;
  ulonglong uStack_120;
  undefined8 *******local_118 [2];
  longlong local_108;
  ulonglong local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  ulonglong local_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined1 local_c0 [32];
  undefined1 local_a0 [8];
  undefined **local_98 [7];
  undefined ***local_60;
  undefined **local_58 [7];
  undefined ***local_20;
  
  local_f8 = 0;
  uStack_f0 = 0;
  local_e8 = 0;
  piVar4 = (int *)FUN_141974de0(local_a0,param_4,&local_f8);
  if ((*piVar4 == 3) && (((local_e8 & 1) == 0 || ((local_e8 == 1 && ((int)local_f8 == 0)))))) {
    plStack_130 = (longlong *)0x0;
    local_128 = _DAT_141cb0070;
    uStack_120 = _UNK_141cb0078;
    local_138 = (longlong *)0x0;
    local_148 = 0xc;
    local_140 = 0xf;
    local_158 = (void *)s_autorun_json_141f7cf20._0_8_;
    uStack_150 = (void *)(ulonglong)(uint)s_autorun_json_141f7cf20._8_4_;
    uVar5 = FUN_14196e970();
    FUN_141971270(&local_158,(longlong)&uStack_150 + 4,&local_138,uVar5);
    if (0xf < local_140) {
      pvVar6 = local_158;
      if ((0xfff < local_140 + 1) &&
         (pvVar6 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    FUN_1402a5d70(local_118,param_4);
    FUN_14196e520(local_118,&local_138);
    if (7 < uStack_120) {
      plVar7 = local_138;
      if ((0xfff < uStack_120 * 2 + 2) &&
         (plVar7 = (longlong *)local_138[-1],
         0x1f < (ulonglong)((longlong)local_138 + (-8 - (longlong)plVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(plVar7);
    }
    plStack_130 = (longlong *)0x0;
    local_128 = _DAT_141cb0070;
    uStack_120 = _UNK_141cb0078;
    local_138 = (longlong *)0x0;
    local_148 = 0xd;
    local_140 = 0xf;
    local_158 = (void *)s_autorun_check_141f7cf30._0_8_;
    uStack_150 = (void *)(ulonglong)
                         CONCAT14(s_autorun_check_141f7cf30[0xc],s_autorun_check_141f7cf30._8_4_);
    uVar5 = FUN_14196e970();
    FUN_141971270(&local_158,(longlong)&uStack_150 + 5,&local_138,uVar5);
    if (0xf < local_140) {
      pvVar6 = local_158;
      if ((0xfff < local_140 + 1) &&
         (pvVar6 = *(void **)((longlong)local_158 + -8),
         0x1f < (ulonglong)((longlong)local_158 + (-8 - (longlong)pvVar6)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    FUN_1402a5d70(local_c0,param_4);
    FUN_14196e520(local_c0,&local_138);
    if (7 < uStack_120) {
      plVar7 = local_138;
      if ((0xfff < uStack_120 * 2 + 2) &&
         (plVar7 = (longlong *)local_138[-1],
         (undefined1 *)0x1f < (undefined1 *)((longlong)local_138 + (-8 - (longlong)plVar7)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(plVar7);
    }
    local_98[0] = std::
                  _Func_impl_no_alloc<`class_std::vector<scriptRunner::ScriptInformation,std::allocator<scriptRunner::ScriptInformation>_>___cdecl__anon_7B6ECC00::getScriptsInformation(boost::filesystem::path_const&___ptr64)'::`2'::<lambda_1>,scriptRunner::ScriptInformation,nlohmann::json_abi_v3_11_3::basic_json<std::map,std::vector,std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,bool,__int64,unsigned___int64,double,std::allocator,nlohmann::json_abi_v3_11_3::adl_serializer,std::vector<unsigned_char,std::allocator<unsigned_char>_>,void>_const&___ptr64>
                  ::vftable;
    local_60 = local_98;
    FUN_140b2bf40(&local_158,local_118,s_scripts_1428edbd8,local_98);
    if (local_60 != (undefined ***)0x0) {
      (*(code *)(*local_60)[4])
                (local_60,CONCAT71((int7)((ulonglong)local_98 >> 8),local_60 != local_98));
    }
    local_58[0] = std::
                  _Func_impl_no_alloc<`class_std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char>_>_>_>___cdecl__anon_7B6ECC00::getFilesInformation(boost::filesystem::path_const&___ptr64)'::`2'::<lambda_1>,std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,nlohmann::json_abi_v3_11_3::basic_json<std::map,std::vector,std::basic_string<char,std::char_traits<char>,std::allocator<char>_>,bool,__int64,unsigned___int64,double,std::allocator,nlohmann::json_abi_v3_11_3::adl_serializer,std::vector<unsigned_char,std::allocator<unsigned_char>_>,void>_const&___ptr64>
                  ::vftable;
    local_20 = local_58;
    FUN_140b2c500(&local_138,local_118,s_files_1428edbf8,local_58);
    if (local_20 != (undefined ***)0x0) {
      (*(code *)(*local_20)[4])
                (local_20,CONCAT71((int7)((ulonglong)local_58 >> 8),local_20 != local_58));
    }
    uStack_d8 = 0;
    local_d0 = _DAT_141ac9b00;
    uStack_c8 = _UNK_141ac9b08;
    local_e0 = 0;
    if (local_108 != 0) {
      pppppppuVar8 = local_118;
      if (7 < local_100) {
        pppppppuVar8 = local_118[0];
      }
      pppppppuVar12 = local_118;
      if (7 < local_100) {
        pppppppuVar12 = local_118[0];
      }
      uVar5 = FUN_14196e970();
      FUN_141971350(pppppppuVar12,(longlong)pppppppuVar8 + local_108 * 2,&local_e0,uVar5);
    }
    cVar3 = FUN_140b2e6f0(param_3,&local_e0,&local_158,&local_138,local_c0);
    plVar11 = plStack_130;
    plVar7 = local_138;
    if (cVar3 != '\0') {
      *param_2 = local_158;
      param_2[1] = uStack_150;
      param_2[2] = local_148;
      if (local_138 != (longlong *)0x0) {
        FUN_14029c160(local_138,plStack_130,&local_138);
        plVar11 = plVar7;
        if ((0xfff < (local_128 - (longlong)plVar7 & 0xffffffffffffffe0U)) &&
           (plVar11 = (longlong *)plVar7[-1],
           (undefined1 *)0x1f < (undefined1 *)((longlong)plVar7 + (-8 - (longlong)plVar11))))
        goto LAB_140b2d722;
        free(plVar11);
      }
      FUN_1402a29e0(local_c0);
      FUN_1402a29e0(local_118);
      return param_2;
    }
    plVar1 = local_138;
    if (local_138 != (longlong *)0x0) {
      for (; plVar1 != plVar11; plVar1 = plVar1 + 4) {
        if (0xf < (ulonglong)plVar1[3]) {
          pvVar6 = (void *)*plVar1;
          pvVar9 = pvVar6;
          if ((0xfff < plVar1[3] + 1U) &&
             (pvVar9 = *(void **)((longlong)pvVar6 + -8),
             0x1f < (ulonglong)((longlong)pvVar6 + (-8 - (longlong)pvVar9)))) goto LAB_140b2d722;
          free(pvVar9);
        }
        plVar1[2] = 0;
        plVar1[3] = 0xf;
        *(undefined1 *)plVar1 = 0;
      }
      plVar11 = plVar7;
      if ((0xfff < (local_128 - (longlong)plVar7 & 0xffffffffffffffe0U)) &&
         (plVar11 = (longlong *)plVar7[-1],
         (undefined1 *)0x1f < (undefined1 *)((longlong)plVar7 + (-8 - (longlong)plVar11))))
      goto LAB_140b2d722;
      free(plVar11);
    }
    pvVar2 = uStack_150;
    pvVar9 = local_158;
    pvVar6 = local_158;
    if (local_158 != (void *)0x0) {
      for (; pvVar6 != pvVar2; pvVar6 = (void *)((longlong)pvVar6 + 0xa8)) {
        FUN_140b2ccd0(pvVar6);
      }
      lVar10 = SUB168(SEXT816(-0x3cf3cf3cf3cf3cf3) * SEXT816(local_148 - (longlong)pvVar9),8) +
               (local_148 - (longlong)pvVar9);
      pvVar6 = pvVar9;
      if ((0xfff < (ulonglong)(((lVar10 >> 7) - (lVar10 >> 0x3f)) * 0xa8)) &&
         (pvVar6 = *(void **)((longlong)pvVar9 + -8),
         0x1f < (ulonglong)((longlong)pvVar9 + (-8 - (longlong)pvVar6)))) {
LAB_140b2d722:
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(pvVar6);
    }
    FUN_1402a29e0(local_c0);
    FUN_1402a29e0(local_118);
  }
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  return param_2;
}


