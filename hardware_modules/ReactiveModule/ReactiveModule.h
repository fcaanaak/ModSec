#ifndef REACTIVE_MODULE_H
#define REACTIVE_MODULE_H

#include <Preferences.h>
#include "WiFiManager.h"
#include "time.h"


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
  
  const unsigned short autoReconnectSeconds = 10;
  // Class methods
  // WiFi connection methods
  // Abstract (virtual methods for child classes)

  // Timing related fields
  const unsigned long intervalMillis = 1000;
  bool timerRunning = false;
  unsigned long cycleStartTime = 0;
  
  bool checkTimer(unsigned long detectTimeMillis);
  bool detectExternalEvent();

  void generateJSONReport();
  void sendReport();

  // Date time retrieval methods
  void printLocalTime();
  
  // A method purely to run code to test shit out
  void testMethod();
  
public:
  ReactiveModule();
  void setup();
  void mainloop();

};

#endif
