// FUN_140649290 @ 140649290
// strings: [ Stems Support, Downloading Stems Support]

QString * FUN_140649290(longlong param_1,QString *param_2,undefined8 param_3,undefined8 param_4)

{
  bool bVar1;
  char *local_18;
  undefined8 uStack_10;
  
  bVar1 = QString::operator==((QString *)(param_1 + 0x38),"Cancel");
  if (bVar1) {
    QString::QString(param_2,"Downloading Stems Support");
    return param_2;
  }
  QString::QString(param_2,(QString *)(param_1 + 0x38));
  local_18 = " Stems Support";
  uStack_10 = 0xe;
  QString::append(param_2,&local_18,param_3,param_4,2);
  return param_2;
}


