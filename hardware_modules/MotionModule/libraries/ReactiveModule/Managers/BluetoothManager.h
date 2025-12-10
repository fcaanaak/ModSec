#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include "BluetoothSerial.h"


class BluetoothManager{

 private:

  const char* defaultPassword = "1234";
  const char* defaultName = "New-Reactive-Module";

  String deviceName = String(defaultName);
  String devicePassword = String(defaultPassword);
  
  BluetoothSerial bluetoothHandler;
  
  
 public:

  void openConnection();
  void closeConnection();
  void setup();

};



#endif
