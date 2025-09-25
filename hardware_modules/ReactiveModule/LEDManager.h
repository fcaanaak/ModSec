#infdef LED_MANAGER_H
#define LED_MANAGER_H

typedef unsigned short ushort
typedef unsigned int uint
class LEDManager{


 private:
  static const ushort LEDPinRed = 4;
  static const ushort LEDPinGreen = 18;
  static const ushort LEDPinBlue = 5;

  static void setupLED();

 public:
  static void setLED(ushort red, ushort green, ushort blue);
  static void disableLED();
  static void flashLEDBlocking(ushort red, ushort green, ushort blue, ushort numFlashes, uint delay );
  
};


#endif
