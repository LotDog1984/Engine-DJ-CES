// FUN_1412f5710 @ 1412f5710
// calls: [ReadFile]

longlong FUN_1412f5710(longlong param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  DWORD DVar1;
  longlong lVar2;
  undefined1 local_118 [272];
  
  lVar2 = FUN_1412f6570(*(undefined8 *)(param_1 + 8));
  if (lVar2 < 0) {
    if (param_4 != '\0') {
      DVar1 = GetLastError();
      lVar2 = FUN_1412fa700(local_118,
                            "__int64 __cdecl crashpad::`anonymous-namespace\'::FileIOReadExactly::Read(void *,unsigned __int64,bool)"
                            ,
                            "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\util\\file\\file_io.cc"
                            ,0x28,2,DVar1);
      FUN_1402b8060(lVar2 + 8,"ReadFile");
      FUN_1412fa820(local_118);
    }
    lVar2 = -1;
  }
  return lVar2;
}


