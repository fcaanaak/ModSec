#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include <Arduino.h>

class LEDManager{


  typedef unsigned short ushort;
  typedef unsigned int uint;

 private:
  static const ushort LEDPinRed = 13;
  static const ushort LEDPinGreen = 12;
  static const ushort LEDPinBlue = 14;

  

 public:
  static void setLED(ushort red, ushort green, ushort blue);
  static void setupLED();
  static void disableLED();
  static void flashLEDBlocking(ushort red, ushort green, ushort blue, ushort numFlashes, uint delay );
  
};


#endif
