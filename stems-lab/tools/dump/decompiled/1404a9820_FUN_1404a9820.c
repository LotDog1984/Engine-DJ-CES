// FUN_1404a9820 @ 1404a9820
// strings: [*.stems]

undefined1 FUN_1404a9820(longlong param_1)

{
  undefined1 uVar1;
  undefined4 local_res8;
  undefined4 uStackX_c;
  char *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  void *local_50;
  undefined8 local_48;
  QString local_40 [24];
  QString local_28 [24];
  undefined1 local_10 [8];
  
  local_res8 = 0;
  QString::QString(local_28,"*.stems");
  local_50 = QArrayData::allocate((QArrayData **)&local_res8,0x18,8,1,1);
  local_58 = CONCAT44(uStackX_c,local_res8);
  local_48 = 0;
  FUN_1402af7a0(&local_58,local_28,local_10);
  QString::QString(local_40,(QString *)(param_1 + 0x68));
  local_res8 = 2;
  local_68 = "/Stems";
  uStack_60 = 6;
  QString::append(local_40,&local_68);
  uVar1 = FUN_1404a89b0(param_1 + 0x20,local_40,&local_58);
  QString::~QString(local_40);
  FUN_14029fe30(&local_58);
  _eh_vector_destructor_iterator_(local_28,0x18,1,~QString_exref);
  return uVar1;
}


