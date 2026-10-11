// FUN_1412c42b0 @ 1412c42b0
// strings: [stems-processor]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_1412c42b0(int *param_1,int param_2,int param_3,int param_4,undefined1 param_5,byte param_6
                   ,longlong *param_7,longlong *param_8,int param_9,
                   basic_ostream<char,std::char_traits<char>_> *param_10,int param_11)

{
  basic_ostream<char,std::char_traits<char>_> *this;
  basic_istream<char,std::char_traits<char>_> *this_00;
  int *piVar1;
  longlong *plVar2;
  byte bVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  void *_Memory;
  longlong lVar7;
  bool bVar8;
  void *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  
  plVar4 = param_7;
  bVar3 = param_6;
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  *(undefined1 *)(param_1 + 3) = param_5;
  *(byte *)((longlong)param_1 + 0xd) = param_6;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  plVar2 = (longlong *)param_7[7];
  if (plVar2 != (longlong *)0x0) {
    if (plVar2 == param_7) {
      uVar6 = (**(code **)(*plVar2 + 8))(plVar2,param_1 + 4);
      *(undefined8 *)(param_1 + 0x12) = uVar6;
      plVar2 = (longlong *)plVar4[7];
      if (plVar2 == (longlong *)0x0) goto LAB_1412c4341;
      (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != plVar4);
    }
    else {
      *(longlong **)(param_1 + 0x12) = plVar2;
    }
    plVar4[7] = 0;
  }
LAB_1412c4341:
  plVar5 = param_8;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  plVar2 = (longlong *)param_8[7];
  if (plVar2 != (longlong *)0x0) {
    if (plVar2 == param_8) {
      uVar6 = (**(code **)(*plVar2 + 8))(plVar2,param_1 + 0x14);
      *(undefined8 *)(param_1 + 0x22) = uVar6;
      plVar2 = (longlong *)plVar5[7];
      if (plVar2 == (longlong *)0x0) goto LAB_1412c4395;
      (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != plVar5);
    }
    else {
      *(longlong **)(param_1 + 0x22) = plVar2;
    }
    plVar5[7] = 0;
  }
LAB_1412c4395:
  param_1[0x24] = param_9;
  bVar8 = *(longlong *)((longlong)param_10 + 0x10) == 0;
  if (bVar8) {
    local_48 = _DAT_141cb69a0;
    uStack_40 = _UNK_141cb69a8;
    local_58 = (void *)s_stems_processor_141d6f060._0_8_;
    uStack_50 = (ulonglong)
                CONCAT16(s_stems_processor_141d6f060[0xe],
                         CONCAT24(s_stems_processor_141d6f060._12_2_,
                                  s_stems_processor_141d6f060._8_4_));
  }
  FUN_1402aa5d0(param_1 + 0x26);
  if (bVar8) {
    if (0xf < uStack_40) {
      _Memory = local_58;
      if ((0xfff < uStack_40 + 1) &&
         (_Memory = *(void **)((longlong)local_58 + -8),
         0x1f < (ulonglong)((longlong)local_58 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
        _invalid_parameter_noinfo_noreturn();
      }
      free(_Memory);
    }
  }
  param_1[0x2e] = (bVar3 + 4) * param_2;
  param_1[0x2f] = param_11;
  this = (basic_ostream<char,std::char_traits<char>_> *)(param_1 + 0x30);
  *(undefined **)this = &DAT_1423b35f8;
  param_10 = this;
  std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)(param_1 + 0x5e));
  std::basic_ostream<char,std::char_traits<char>_>::basic_ostream<char,std::char_traits<char>_>
            (this,(basic_streambuf<char,std::char_traits<char>_> *)0x0,false);
  *(undefined ***)(this + *(int *)(*(longlong *)this + 4)) =
       boost::process::basic_opstream<char,std::char_traits<char>_>::vftable;
  *(int *)(this + (longlong)*(int *)(*(longlong *)this + 4) + -4) =
       *(int *)(*(longlong *)this + 4) + -0xb8;
  FUN_1412c40e0(param_1 + 0x32);
  std::basic_ios<char,std::char_traits<char>_>::rdbuf
            ((basic_ios<char,std::char_traits<char>_> *)(this + *(int *)(*(longlong *)this + 4)),
             (basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + 0x32));
  this_00 = (basic_istream<char,std::char_traits<char>_> *)(param_1 + 0x76);
  *(undefined **)this_00 = &DAT_1423b3610;
  param_10 = (basic_ostream<char,std::char_traits<char>_> *)this_00;
  std::basic_ios<char,std::char_traits<char>_>::basic_ios<char,std::char_traits<char>_>
            ((basic_ios<char,std::char_traits<char>_> *)(param_1 + 0xa6));
  std::basic_istream<char,std::char_traits<char>_>::basic_istream<char,std::char_traits<char>_>
            (this_00,(basic_streambuf<char,std::char_traits<char>_> *)0x0,false);
  *(undefined ***)(this_00 + *(int *)(*(longlong *)this_00 + 4)) =
       boost::process::basic_ipstream<char,std::char_traits<char>_>::vftable;
  *(int *)(this_00 + (longlong)*(int *)(*(longlong *)this_00 + 4) + -4) =
       *(int *)(*(longlong *)this_00 + 4) + -0xc0;
  FUN_1412c40e0(param_1 + 0x7a);
  std::basic_ios<char,std::char_traits<char>_>::rdbuf
            ((basic_ios<char,std::char_traits<char>_> *)
             (this_00 + *(int *)(*(longlong *)this_00 + 4)),
             (basic_streambuf<char,struct_std::char_traits<char>_> *)(param_1 + 0x7a));
  FUN_1412c4660(param_1 + 0xbe);
  *(undefined1 *)(param_1 + 0xca) = 0;
  piVar1 = param_1 + 0xcc;
  piVar1[0] = 0;
  piVar1[1] = 0;
  param_1[0xce] = 0;
  param_1[0xcf] = 0;
  param_1[0xd0] = 0;
  param_1[0xd1] = 0;
  lVar7 = (longlong)(param_4 * param_1[0x2e]) << 2;
  if (lVar7 != 0) {
    FUN_14059ab80(piVar1,lVar7,&param_5);
  }
  if ((*(longlong *)(param_1 + 0x12) != 0) && (*(longlong *)(param_1 + 0x22) != 0)) {
    plVar2 = (longlong *)plVar4[7];
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != plVar4);
      plVar4[7] = 0;
    }
    plVar2 = (longlong *)plVar5[7];
    if (plVar2 != (longlong *)0x0) {
      (**(code **)(*plVar2 + 0x20))(plVar2,plVar2 != plVar5);
      plVar5[7] = 0;
    }
    return param_1;
  }
  FUN_1402ab200(&local_58,"audioCallback and errorCallback must be set");
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(&local_58,(ThrowInfo *)&DAT_14288d888);
}


