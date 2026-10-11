// FUN_1412efa30 @ 1412efa30
// calls: [CreateProcessW]

/* WARNING: Removing unreachable block (ram,0x0001412efcb3) */

undefined1
FUN_1412efa30(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
             undefined8 param_9,char param_10,undefined8 param_11,undefined8 param_12,
             undefined1 param_13)

{
  undefined1 uVar1;
  DWORD DVar2;
  LPVOID pvVar3;
  LPVOID lpParameter;
  HANDLE pvVar4;
  longlong lVar5;
  LPVOID pvVar6;
  undefined8 local_res8;
  _SECURITY_ATTRIBUTES local_160;
  longlong local_148;
  undefined1 local_140 [280];
  
  lpParameter = (LPVOID)0x0;
  local_res8 = (LPVOID)((ulonglong)local_res8 & 0xffffffff00000000);
  FUN_1412ef000();
  local_160.lpSecurityDescriptor = (LPVOID)0x0;
  local_160.nLength = 0x18;
  local_160._4_4_ = 0;
  local_160.bInheritHandle = 1;
  local_160._20_4_ = 0;
  DAT_1429402f0 = CreateEventW(&local_160,0,0,(LPCWSTR)0x0);
  DAT_142940304 = CreateEventW(&local_160,0,0,(LPCWSTR)0x0);
  DAT_14294030c = CreateEventW(&local_160,0,0,(LPCWSTR)0x0);
  FUN_1412f82a0(&DAT_142b29358);
  pvVar3 = (LPVOID)FUN_141981f80(0x28);
  pvVar6 = lpParameter;
  local_res8 = pvVar3;
  if (pvVar3 != (LPVOID)0x0) {
    FUN_1412fb650(pvVar3);
    pvVar6 = pvVar3;
  }
  DAT_142b29338 = pvVar6;
  FUN_1412ef860(param_1);
  local_148 = FUN_141981f80();
  if (local_148 != 0) {
    local_res8 = (LPVOID)0xffffffffffffffff;
    lpParameter = (LPVOID)FUN_1412ee8c0(local_148,param_2,param_3,param_4,param_5,param_6,param_7,
                                        param_8,param_11,param_12,param_13,param_1,&local_res8);
  }
  if (param_10 == '\0') {
    local_res8 = lpParameter;
    uVar1 = FUN_1412efcf0(&local_res8);
  }
  else {
    pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_1412eefd0,lpParameter,0,(LPDWORD)0x0);
    if (*(HANDLE *)(param_1 + 0x20) != (HANDLE)0x0) {
      if (*(HANDLE *)(param_1 + 0x20) == pvVar4) {
                    /* WARNING: Subroutine does not return */
        abort();
      }
      FUN_1412f5370();
    }
    *(HANDLE *)(param_1 + 0x20) = pvVar4;
    if (pvVar4 == (HANDLE)0x0) {
      DVar2 = GetLastError();
      lVar5 = FUN_1412fa700(local_140,
                            "bool __cdecl crashpad::CrashpadClient::StartHandler(const class base::FilePath &,const class base::FilePath &,const class base::FilePath &,const class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &,const class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > &,const class std::map<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > >,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > const ,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > > > > &,const class std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > > > &,bool,bool,const class std::vector<class base::FilePath,class std::allocator<class base::FilePath> > &,const class base::FilePath &,bool)"
                            ,
                            "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\crashpad_client_win.cc"
                            ,0x2cc,2,DVar2);
      local_res8._0_4_ = 2;
      FUN_1402b8060(lVar5 + 8,"CreateThread");
      local_res8 = (LPVOID)((ulonglong)local_res8._4_4_ << 0x20);
      FUN_1412fa820(local_140);
      DAT_142b29350 = 2;
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}


