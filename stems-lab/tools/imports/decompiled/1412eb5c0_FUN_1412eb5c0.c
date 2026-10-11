// FUN_1412eb5c0 @ 1412eb5c0
// calls: [CreateFileW]

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_1412eb5c0(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  DWORD DVar5;
  __time64_t _Var6;
  undefined8 uVar7;
  undefined8 *puVar8;
  uint uVar9;
  void *_Memory;
  LPCWSTR lpFileName;
  longlong lVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  int iVar14;
  longlong local_res20;
  void *local_368;
  undefined8 uStack_360;
  undefined8 local_358;
  ulonglong uStack_350;
  undefined8 *local_348;
  undefined8 local_340;
  void *local_338;
  undefined8 uStack_330;
  undefined1 local_328 [32];
  undefined1 local_308 [32];
  longlong local_2e8 [2];
  undefined1 local_2d8 [32];
  undefined1 local_2b8 [32];
  undefined1 local_298 [608];
  
  iVar4 = 0;
  iVar14 = 0;
  local_368 = (void *)0x0;
  uStack_360 = 0;
  local_358 = 0;
  uStack_350 = 0;
  lVar13 = -1;
  do {
    lVar13 = lVar13 + 1;
  } while (L"reports"[lVar13] != L'\0');
  FUN_1402a7200(&local_368);
  FUN_1412f9330(param_1 + 8,local_2d8,&local_368);
  if (7 < uStack_350) {
    _Memory = local_368;
    if ((0xfff < uStack_350 * 2 + 2) &&
       (_Memory = *(void **)((longlong)local_368 + -8),
       0x1f < (ulonglong)((longlong)local_368 + (-8 - (longlong)_Memory)))) {
                    /* WARNING: Subroutine does not return */
      _invalid_parameter_noinfo_noreturn();
    }
    free(_Memory);
  }
  local_358 = _DAT_141cb0070;
  uStack_350 = _UNK_141cb0078;
  local_368 = (void *)((ulonglong)local_368 & 0xffffffffffff0000);
  FUN_1412f6fb0(local_298);
  cVar3 = FUN_1412f7200(local_298,local_2d8);
  if (cVar3 != '\0') {
    FUN_1412f91f0();
    _Var6 = _time64((__time64_t *)0x0);
    FUN_1412eb3d0(param_1,&local_res20);
    if (local_res20 == 0) {
      iVar4 = 3;
    }
    else {
      iVar4 = FUN_1412f7050(local_298,local_308);
      lVar13 = local_res20;
      while (iVar4 == 0) {
        local_res20 = lVar13;
        FUN_1412f9310(local_2d8,local_328,local_308);
        cVar3 = FUN_1412f7400(local_328,local_2e8);
        if ((cVar3 != '\0') && (local_2e8[0] <= _Var6 - param_2)) {
          uVar7 = FUN_1412fa0c0(local_328,local_2b8);
          puVar8 = (undefined8 *)FUN_1412f96f0(uVar7,&local_368);
          local_348 = puVar8;
          if (7 < (ulonglong)puVar8[3]) {
            local_348 = (undefined8 *)*puVar8;
          }
          local_340 = puVar8[2];
          cVar3 = FUN_1412f6c30(&local_338,&local_348);
          thunk_FUN_1402a29e0(&local_368);
          thunk_FUN_1402a29e0(local_2b8);
          lVar13 = local_res20;
          if (cVar3 != '\0') {
            lVar1 = *(longlong *)(local_res20 + 0x58);
            lVar10 = *(longlong *)(local_res20 + 0x50);
            local_368 = local_338;
            uStack_360 = uStack_330;
            while ((lVar10 != lVar1 && (cVar3 = FUN_1412f6c10(lVar10,&local_368), cVar3 == '\0'))) {
              lVar10 = lVar10 + 0x80;
            }
            if (lVar10 != *(longlong *)(lVar13 + 0x58)) {
              lpFileName = (LPCWSTR)(lVar10 + 0x10);
              if (7 < *(ulonglong *)(lVar10 + 0x28)) {
                lpFileName = *(LPCWSTR *)lpFileName;
              }
              DVar5 = GetFileAttributesW(lpFileName);
              uVar9 = DVar5 >> 3 & 2;
              if (DVar5 == 0xffffffff) {
                uVar9 = 1;
              }
              if (uVar9 != 1) goto LAB_1412eb83a;
            }
            cVar3 = FUN_1412f7d40(local_328);
            if (cVar3 != '\0') {
              iVar14 = iVar14 + 1;
              FUN_1412f5270(param_1,&local_338);
            }
          }
        }
LAB_1412eb83a:
        thunk_FUN_1402a29e0(local_328);
        iVar4 = FUN_1412f7050(local_298,local_308);
        lVar13 = local_res20;
      }
      iVar4 = 0;
      puVar8 = *(undefined8 **)(lVar13 + 0x50);
      if (puVar8 != *(undefined8 **)(lVar13 + 0x58)) {
        do {
          puVar11 = puVar8 + 0x10;
          cVar3 = FUN_1412f7a70(puVar8 + 2);
          if (cVar3 == '\0') {
            puVar2 = *(undefined8 **)(lVar13 + 0x58);
            if (puVar11 != puVar2) {
              puVar12 = puVar8 + 6;
              do {
                uVar7 = puVar11[1];
                puVar12[-6] = *puVar11;
                puVar12[-5] = uVar7;
                FUN_1412f9210(puVar12 + -4,puVar12 + 0xc);
                FUN_1402ac4f0(puVar12,puVar12 + 0x10);
                puVar12[4] = puVar12[0x14];
                *(undefined1 *)(puVar12 + 5) = *(undefined1 *)(puVar12 + 0x15);
                puVar12[6] = puVar12[0x16];
                *(undefined4 *)(puVar12 + 7) = *(undefined4 *)(puVar12 + 0x17);
                *(undefined1 *)((longlong)puVar12 + 0x3c) =
                     *(undefined1 *)((longlong)puVar12 + 0xbc);
                puVar12[8] = puVar12[0x18];
                *(undefined4 *)(puVar12 + 9) = *(undefined4 *)(puVar12 + 0x19);
                puVar11 = puVar11 + 0x10;
                puVar12 = puVar12 + 0x10;
              } while (puVar11 != puVar2);
            }
            FUN_1412e4190(*(longlong *)(lVar13 + 0x58) + -0x80);
            *(longlong *)(lVar13 + 0x58) = *(longlong *)(lVar13 + 0x58) + -0x80;
            iVar4 = iVar4 + 1;
            *(undefined1 *)(lVar13 + 0x48) = 1;
            puVar11 = puVar8;
          }
          puVar8 = puVar11;
        } while (puVar11 != *(undefined8 **)(lVar13 + 0x58));
      }
      iVar4 = iVar4 + iVar14;
      FUN_1412eb9b0(param_1);
    }
    FUN_1412eb070(&local_res20);
    thunk_FUN_1402a29e0(local_308);
  }
  FUN_1412f7020(local_298);
  thunk_FUN_1402a29e0(local_2d8);
  return iVar4;
}


