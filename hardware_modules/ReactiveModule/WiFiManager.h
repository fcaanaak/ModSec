#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include <Preferences.h>
#include "LEDManager.h"
class WiFiManager{

 private:

  static const unsigned short autoReconnectSeconds = 10;

  Preferences prefObject;

  static bool connectToWiFi(const char* ssid, const char* password, unsigned int waitSecs);
  static bool reconnectToWiFi(unsigned int waitSecs);
  static bool waitForConnection(unsigned int waitSecs);
  String scanStoredNetworks();
  bool autoReconnect();
  
  void registerWiFiEvents();
  void registerWiFiConnected();
  void registerWiFiDisconnected();
  void resetToSTA();


  static void onWiFiReconnect(WiFiEvent_t event, WiFiEventInfo_t info);
  static void onWiFiDisconnect(WiFiEvent_t event, WiFiEventInfo_t info);


public:

   enum State{
    NETWORK_RECOVERY,
    MANUAL_SETUP
  };
  WiFiManager(Preferences prefObject);
  void setup();
  
};

#endif
