#include "ReactiveModule.h"
#include "LEDManager.h"

#define WIFI_DATABASE "wifiDatabase"
#define READ true
#define READ_WRITE false
#define DEFAULT_CONNECTION_CHECK_TIME 5000
#define MILLIS_TO_SECONDS 1000


void ReactiveModule::testMethod(){
  
  modulePrefs.begin(WIFI_DATABASE,READ_WRITE);

  const char* ssid = "Cisco33248-2G4";
  String password = String("Gr3b3nac1966");
  modulePrefs.clear();
  modulePrefs.putString(ssid,password);
  Serial.println(modulePrefs.getString(ssid));
  modulePrefs.end();
  
}



void ReactiveModule::printLocalTime(){

  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)){
    Serial.println("FAILURE");
  } else{
    Serial.println(&timeinfo,"%A, %B %d %Y %H:%M:%S");
  }  

}


void ReactiveModule::setup(){

  testMethod();
  LEDManager::setupLED();
  wifi.setup();
  randomSeed(analogRead(0)); // random debug code


  
  const char* ntpServer = "pool.ntp.org";
  const long gmOffset_sec = -8*3600;
  const int daylightOffset_sec = 3600;
  
  configTime(gmOffset_sec,daylightOffset_sec,ntpServer);
  

}

ReactiveModule::ReactiveModule(){
  //  testMethod();
  //  setup();
  
}

bool ReactiveModule::detectExternalEvent(){
  

  return (random(1,101) >= 90); 
}


bool ReactiveModule::checkTimer(unsigned long detectTimeMillis){
  
  if (!timerRunning){
    cycleStartTime = millis();
    timerRunning = true;
    
  }

  if (millis() >= (cycleStartTime + detectTimeMillis)){
    timerRunning = false;
    return true;
  }

  return false;
  
}

void ReactiveModule::mainloop(){
  

  if (checkTimer(intervalMillis) && WiFi.status() == WL_CONNECTED){
    
    if (detectExternalEvent()){
      
      LEDManager::setLED(0,0,255);
      printLocalTime();
      inactivityCounter = 0;
      
    } else {
      
      LEDManager::disableLED();
      inactivityCounter++;
      
    }
    
  }

}
