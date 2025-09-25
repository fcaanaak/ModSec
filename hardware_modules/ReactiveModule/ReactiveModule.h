#ifndef REACTIVE_MODULE_H
#define REACTIVE_MODULE_H

#include <Preferences.h>
#include <WiFi.h>
#include <functional>

typedef struct RGBColorStruct {
  unsigned int red;
  unsigned int green;
  unsigned int blue;
} RGBColor;



class ReactiveModule{

protected:

  /* Class fields */

  /**Wi-Fi related fields **/
  bool connectionRecoveryMode = false;
  
  Preferences modulePrefs;
  unsigned long connectionCheckStartTime;
  unsigned short inactivityCounter = 0;
  hw_timer_t* Timer0_Cfg = NULL;// hardware timer

  
  enum State{
    NETWORK_RECOVERY,
    MANUAL_SETUP,
    BORED,
    DETECTING,
    UNDECIDED
  };

  volatile State currentState = UNDECIDED;
  
  // LED pin



  // Wifi related fields
  const unsigned short autoReconnectSeconds = 10;
  // Class methods
  // WiFi connection methods
  void connectToWiFi(const char* ssid, const char* password);
  String scanStoredNetworks();
  bool autoReconnect();
  
  /**  WiFi event methods **/

  // Wifi setup
  void registerWiFiEvents();
  void registerWiFiConnected();
  void resetToSTA();
  void LEDIndicateNoNetworks();
  void setupWiFi();


  static void onWiFiReconnect(WiFiEvent_t event, WiFiEventInfo_t info);
  // LED methods
  static void setupLED();
  static void setLEDColor(RGBColor colors);
  static void disableLED();

  void flashLED(RGBColor colors, unsigned int intervalMillis);
  bool checkConnection();
  
  // Abstract (virtual methods for child classes)
  //  virtual bool detectExternalEvent() = 0;

  void generateJSONReport();
  void sendReport();

  // A method purely to run code to test shit out
  void testMethod();
public:
  ReactiveModule();
  void setup();
  void mainloop();

};

#endif
