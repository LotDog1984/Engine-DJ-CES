// FUN_140201280 @ 140201280
// strings: [semicolon-separated-list/Planck/Browser]

void FUN_140201280(void)

{
  int iVar1;
  int *local_28;
  wchar_t *local_20;
  undefined8 local_18;
  
  local_28 = (int *)0x0;
  local_20 = L"semicolon-separated-list/Planck/Browser";
  local_18 = 0x27;
  QString::QString((QString *)&DAT_142affaa0,(QArrayDataPointer<char16_t> *)&local_28);
  if (local_28 != (int *)0x0) {
    LOCK();
    iVar1 = *local_28;
    *local_28 = *local_28 + -1;
    UNLOCK();
    if (iVar1 == 1) {
      free(local_28);
    }
  }
  atexit((_func_5014 *)&LAB_141a6dd30);
  return;
}


