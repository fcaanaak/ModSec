#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Preferences.h>
#include <WiFi.h>
#include <LEDManager.h>
class WiFiManager{

 private:
  enum State{
    NETWORK_RECOVERY,
    MANUAL_SETUP
  };
  const unsigned short autoReconnectSeconds = 10;

  Preferences prefObject;

  void connectToWiFi(const char* ssid, const char* password);
  String scanStoredNetworks();
  bool autoReconnect();

  void registerWiFiEvents();
  void registerWiFiConnected();
  void resetToSTA();


  static void onWiFiReconnect(WiFiEvent_t event, WiFiEventInfo_t info);
  
 public:
  WiFiManager(Preferences passedPrefObject);
  void setup();
  
};

#endif
