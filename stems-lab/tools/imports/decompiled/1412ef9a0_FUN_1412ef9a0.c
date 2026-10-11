// FUN_1412ef9a0 @ 1412ef9a0
// calls: [CreateFileW]

void FUN_1412ef9a0(undefined8 param_1,undefined8 *param_2)

{
  undefined8 local_228;
  undefined4 local_220;
  undefined4 local_218;
  wchar_t local_214 [262];
  
  memset(local_214,0,0x208);
  local_218 = 3;
  if (7 < (ulonglong)param_2[3]) {
    param_2 = (undefined8 *)*param_2;
  }
  FID_conflict_sprintf_s(local_214,0x104,L"%ls",param_2);
  local_228 = 0;
  local_220 = 0;
  FUN_1412f8910(param_1,&local_218,&local_228);
  return;
}


