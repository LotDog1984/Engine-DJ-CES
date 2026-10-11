// FUN_1412f8fb0 @ 1412f8fb0
// calls: [ReadFile]

longlong FUN_1412f8fb0(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  code *pcVar1;
  DWORD DVar2;
  longlong lVar3;
  undefined1 local_118 [272];
  
  if (0x7fffffffffffffff < param_3) {
    pcVar1 = (code *)swi(3);
    lVar3 = (*pcVar1)();
    return lVar3;
  }
  lVar3 = FUN_1412f6570(*(undefined8 *)(param_1 + 0x10));
  if (lVar3 < 0) {
    DVar2 = GetLastError();
    lVar3 = FUN_1412fa700(local_118,
                          "__int64 __cdecl crashpad::WeakFileHandleFileReader::Read(void *,unsigned __int64)"
                          ,
                          "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\util\\file\\file_reader.cc"
                          ,0x42,2,DVar2);
    FUN_1402b8060(lVar3 + 8,"ReadFile");
    FUN_1412fa820(local_118);
    lVar3 = -1;
  }
  return lVar3;
}


