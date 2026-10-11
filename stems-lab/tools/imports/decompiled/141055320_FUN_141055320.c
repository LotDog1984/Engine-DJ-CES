// FUN_141055320 @ 141055320
// calls: [WriteFile]

void FUN_141055320(int param_1,longlong param_2)

{
  longlong lVar1;
  
  FUN_14108b440(2,"Fatal Internal Error in libarchive: ",0x24);
  lVar1 = -1;
  do {
    lVar1 = lVar1 + 1;
  } while (*(char *)(param_2 + lVar1) != '\0');
  FUN_14108b440(2,param_2);
  FUN_14108b440(2,&DAT_141cafc78,1);
                    /* WARNING: Subroutine does not return */
  exit(param_1);
}


