#include "ReactiveModule.h"
//#include "BluetoothSerial.h"

#define ONBOARD_LED 2
#define PIN_RED 4
#define PIN_BLUE 5
#define PIN_GREEN 18
#define TIMER_DIVIDER 16
#define TIMER_SCALE (TIMER_BASE_CLK / TIMER_DIVIDER)

ReactiveModule mod = ReactiveModule();
//BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);// For debug, remove later of course
  //  Serial.println("Starting");
  //  SerialBT.begin("ESP32-TEST");
  
  //delay(5000);
 
  mod.setup();
  
}


void loop()
{
  mod.mainloop();

  /*
    if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
  */
}
