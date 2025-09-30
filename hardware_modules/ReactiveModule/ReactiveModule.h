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
  Preferences modulePrefs;
  
  /**Wi-Fi related fields **/
  WiFiManager wifi = WiFiManager(modulePrefs);  




  
  enum State{
    NETWORK_RECOVERY,
    MANUAL_SETUP,
    BORED,
    DETECTING,
    UNDECIDED
  };

  
  unsigned short inactivityCounter = 0;
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
