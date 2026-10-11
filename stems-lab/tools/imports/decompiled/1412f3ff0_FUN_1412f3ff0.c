// FUN_1412f3ff0 @ 1412f3ff0
// calls: [CreateFileW]

undefined1 FUN_1412f3ff0(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 local_168;
  undefined8 local_164;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  longlong local_140;
  undefined8 local_138;
  undefined1 local_130 [264];
  
  lVar5 = -1;
  if (param_2 == -1) {
    lVar5 = FUN_1412f5e30(param_1,1,0);
    local_138 = 0xffffffffffffffff;
    local_140 = lVar5;
    if (lVar5 != -1) {
      iVar3 = FUN_1412f5bc0(lVar5,1,0);
      if (iVar3 != 0) {
        thunk_FUN_1412f5560(lVar5);
        lVar5 = -1;
      }
    }
    cVar1 = FUN_1412f3ec0(param_1,lVar5,param_3,1);
    if (cVar1 != '\0') {
      uVar2 = 1;
      goto LAB_1412f40f1;
    }
    param_2 = lVar5;
    if (lVar5 != -1) goto LAB_1412f4123;
    lVar4 = FUN_1412fa530(local_130,
                          "bool __cdecl crashpad::Settings::RecoverSettings(void *,struct crashpad::Settings::Data *)"
                          ,
                          "C:\\local-cache\\akl-win-build-2_0\\planck\\external\\sentry-native\\external\\crashpad\\client\\settings.cc"
                          ,0x1b9,2);
    FUN_1402b8060(lVar4 + 8,"Invalid file handle");
    FUN_1412fa7a0(local_130);
  }
  else {
LAB_1412f4123:
    local_168 = 0x43506473;
    local_164 = 1;
    local_15c = 0;
    local_158 = 0;
    local_150 = 0;
    uStack_148 = 0;
    cVar1 = FUN_1412f6d50(&local_150);
    if (cVar1 != '\0') {
      lVar4 = FUN_1412f61b0(param_2,0,0);
      if (lVar4 == 0) {
        cVar1 = FUN_1412f6270(param_2);
        if (cVar1 != '\0') {
          cVar1 = FUN_1412f5620(param_2,&local_168,0x28);
          if (cVar1 != '\0') {
            uVar2 = FUN_1412f3ec0(param_1,param_2,param_3,1);
            goto LAB_1412f40f1;
          }
        }
      }
    }
  }
  uVar2 = 0;
LAB_1412f40f1:
  if (lVar5 != -1) {
    FUN_1412f6380(lVar5);
    FUN_1412f5560(lVar5);
  }
  return uVar2;
}


