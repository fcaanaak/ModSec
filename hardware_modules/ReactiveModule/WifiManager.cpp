#include "WiFiManager.h"
#define WIFI_DATABASE "wifiDatabase"
#define READ true
#define READ_WRITE false


void WiFiManager::resetToSTA(){
  /**
     @brief Set the esp32 to STA mode in case it wasn't already
   */
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void WiFiManager::connectToWiFi(const char* ssid, const char* password){
   /**
     @brief Connect to a WiFi network
     @param ssid: The ssid or name of the WiFi network
     @param password: The password of the WiFi network 
   */
  Serial.print("Connecting to Wifi network with credentials: ");
  Serial.print(ssid);
  Serial.print(" ");
  Serial.println(password);
  
  // Add logic if we fail to connect
  WiFi.begin(ssid,password);
  
  // Connecting to WiFi takes time, this will wait
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
}

String WiFiManager::scanStoredNetworks(){

  prefObject.begin(WIFI_DATABASE,READ);

  int availableNetworks = WiFi.scanNetworks();

  if (availableNetworks > 0) {

    for (int currentNetwork = 0;(currentNetwork < availableNetworks);currentNetwork++){
      
      String ssid = WiFi.SSID(currentNetwork);
      //Serial.println(ssid);// Remove this later
      
      if (prefObject.getString(ssid.c_str(),"fail") != "fail"){	

	Serial.print("Found SSID: ");
	Serial.println(ssid);

	WiFi.scanDelete();
	prefObject.end();
        return ssid;
      }
     
    }
  }
  
  prefObject.end();
  return String();

}

bool WiFiManager::autoReconnect(){
  /**
     @brief Automatically reconnect to a previously saved WiFi network
     if said network is found during scanning

     @return true if a WiFi network was able to be connected
     to and false otherwise
   */
  String storedSSID = scanStoredNetworks();
 
  if (storedSSID != ""){

    prefObject.begin(WIFI_DATABASE,READ);
    
    String password = prefObject.getString(storedSSID.c_str());
    const char* password_cstring = password.c_str();

    prefObject.end();
    connectToWiFi(storedSSID.c_str(),password_cstring);

    return true;
  }
  
  return false;

}

void WiFiManager::registerWiFiEvents(){
  registerWiFiConnected();
}

void WiFiManager::registerWiFiConnected(){
  WiFi.onEvent(
	       onWiFiReconnect,
	       WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED
	       );
}

void WiFiManager::onWiFiReconnect(WiFiEvent_t event, WiFiEventInfo_t info){
  
  LEDManager::flashLEDBlocking(0,255,0,3,100);
}

void WiFiManager::setup(){
  //  resetToSTA();

  registerWiFiEvents();

  if (!autoReconnect()){
    LEDManager::setLED(255,0,0);
    
  }
  
  while (!autoReconnect()){
    delay(10*1000);
  }
  
}

WiFiManager::WiFiManager(Preferences passedPrefObject){
  prefObject = passedPrefObject;
  
}
