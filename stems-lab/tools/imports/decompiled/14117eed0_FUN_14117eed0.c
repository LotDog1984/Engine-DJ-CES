// FUN_14117eed0 @ 14117eed0
// calls: [WriteFile]

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_14117eed0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_14117f080("%s:%d: OpenSSL internal error: %s\n",param_2,param_3,param_1,0x14117eeda);
  raise(0x16);
                    /* WARNING: Subroutine does not return */
  _exit(3);
}


