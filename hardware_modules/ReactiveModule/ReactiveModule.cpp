#include "ReactiveModule.h"
#include "LEDManager.h"

#define WIFI_DATABASE "wifiDatabase"
#define READ true
#define READ_WRITE false
#define DEFAULT_CONNECTION_CHECK_TIME 5000
#define MILLIS_TO_SECONDS 1000


void ReactiveModule::testMethod(){
  
  modulePrefs.begin(WIFI_DATABASE,READ_WRITE);
  
  //  DataManager::putStr();

  const char* ssid = "test_network";
  String password = String("12345678");
  modulePrefs.clear();
  modulePrefs.putString(ssid,password);
  Serial.println(modulePrefs.getString(ssid));
  modulePrefs.end();
  
}


/**
void ReactiveModule::setupWiFi(){
  registerWiFiEvents();

  
  if (!autoReconnect()){

    //LEDIndicateNoNetworks();
    currentState = NETWORK_RECOVERY;

  }


  while (currentState == NETWORK_RECOVERY){
    
    delay(autoReconnectSeconds*MILLIS_TO_SECONDS);

    if (autoReconnect()){
     
      currentState = DETECTING;
      
    }
  
  }
  

}
**/
void ReactiveModule::setup(){
  LEDManager::setupLED();
  // wifi.resetToSTA();
  testMethod();
  wifi.setup();
  //resetToSTA();
  //  setupWiFi();
}

ReactiveModule::ReactiveModule(){
  //Serial.begin(9600);


  // scanStoredNetworks();
  //  testMethod();
  setup();
  
}
