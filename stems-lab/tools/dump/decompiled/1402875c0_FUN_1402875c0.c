// FUN_1402875c0 @ 1402875c0
// strings: [air.planck.stems.controller]

void FUN_1402875c0(void)

{
  bool bVar1;
  QMessageLogger *this;
  QDebug *pQVar2;
  QDebug local_res8 [32];
  QMessageLogger local_28 [40];
  
  if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +
              0x160) < DAT_142b28e20) {
    FUN_141982544(&DAT_142b28e20);
    if (DAT_142b28e20 == -1) {
      QLoggingCategory::QLoggingCategory
                ((QLoggingCategory *)&DAT_142b28e08,"air.planck.stems.controller",1);
      atexit((_func_5014 *)&LAB_141ab35a0);
      _Init_thread_footer(&DAT_142b28e20);
    }
  }
  bVar1 = QLoggingCategory::isDebugEnabled((QLoggingCategory *)&DAT_142b28e08);
  if (bVar1) {
    this = (QMessageLogger *)
           QMessageLogger::QMessageLogger(local_28,(char *)0x0,0,(char *)0x0,DAT_142b28e10);
    pQVar2 = (QDebug *)QMessageLogger::debug(this);
    pQVar2 = QDebug::operator<<(pQVar2,"init");
    QDebug::operator<<(pQVar2,"air.planck.stems.controller");
    QDebug::~QDebug(local_res8);
  }
  return;
}


