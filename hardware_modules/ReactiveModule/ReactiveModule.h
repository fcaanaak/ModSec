#ifndef REACTIVE_MODULE_H
#define REACTIVE_MODULE_H

#include <Preferences.h>
#include <functional>
#include "WiFiManager.h"



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
  WiFiManager wifi = WiFiManager(modulePrefs);  
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
