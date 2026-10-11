// FUN_1406465a0 @ 1406465a0
// strings: [stems-processor.tar.zst]

longlong * FUN_1406465a0(undefined8 param_1,longlong *param_2,QUrl *param_3)

{
  QObject *pQVar1;
  QString *pQVar2;
  undefined8 uVar3;
  QObject *pQVar4;
  QObject *pQVar5;
  QObject *local_res20;
  QDir local_60 [8];
  QUrl local_58 [8];
  QObject *local_50;
  QString local_48 [24];
  QString local_30 [24];
  
  pQVar5 = (QObject *)0x0;
  pQVar1 = (QObject *)FUN_141981f80(0x148);
  pQVar4 = pQVar5;
  local_res20 = pQVar1;
  if (pQVar1 != (QObject *)0x0) {
    memset(pQVar1,0,0x148);
    QObject::QObject(pQVar1,(QObject *)0x0);
    *(undefined8 *)(pQVar1 + 0x18) = 0;
    *(undefined8 *)(pQVar1 + 0x20) = 0;
    *(undefined ***)pQVar1 = FileDownloader::vftable;
    *(undefined ***)(pQVar1 + 0x10) = FileDownloader::vftable;
    *(undefined8 *)(pQVar1 + 0x28) = 0;
    *(undefined8 *)(pQVar1 + 0x30) = 0;
    *(undefined8 *)(pQVar1 + 0x38) = 0;
    *(undefined4 *)(pQVar1 + 0x40) = 0;
    *(undefined8 *)(pQVar1 + 0x80) = 0;
    *(undefined8 *)(pQVar1 + 0xc0) = 0;
    *(undefined8 *)(pQVar1 + 0x100) = 0;
    *(undefined8 *)(pQVar1 + 0x140) = 0;
    pQVar4 = pQVar1;
  }
  local_50 = pQVar4;
  local_res20 = (QObject *)FUN_141981f80();
  if (local_res20 != (QObject *)0x0) {
    *(undefined8 *)local_res20 = 0;
    *(code **)(local_res20 + 8) = _guard_check_icall;
    *(undefined4 *)(local_res20 + 4) = 1;
    *(undefined4 *)local_res20 = 1;
  }
  pQVar1 = local_res20 + 0x10;
  param_2[1] = (longlong)local_res20;
  QString::QString(local_48,"stems-processor.tar.zst");
  pQVar2 = (QString *)QStandardPaths::writableLocation((StandardLocation)local_30);
  QDir::QDir(local_60,pQVar2);
  uVar3 = QUrl::QUrl(local_58,param_3);
  local_50 = (QObject *)0x0;
  local_res20 = pQVar4 + 0x10;
  if (pQVar4 == (QObject *)0x0) {
    local_res20 = pQVar5;
  }
  FUN_1405a90f0(pQVar1,&local_res20,uVar3,local_60,local_48);
  QDir::~QDir(local_60);
  QString::~QString(local_30);
  QString::~QString(local_48);
  *param_2 = (longlong)pQVar1;
  *(code **)(param_2[1] + 8) = FUN_1402ae110;
  QtSharedPointer::ExternalRefCountData::setQObjectShared
            ((ExternalRefCountData *)param_2[1],(QObject *)*param_2,true);
  pQVar4 = (QObject *)(*param_2 + 0xf0);
  if (*param_2 == 0) {
    pQVar4 = pQVar5;
  }
  FUN_1402a8dc0(param_2,pQVar4);
  return param_2;
}


