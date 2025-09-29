/*
 *  ESP32 WiFi Scanner Example. Examples > WiFi > WiFiScan
 *  Full Tutorial @ https://deepbluembedded.com/esp32-wifi-library-examples-tutorial-
*/


#include "ReactiveModule.h"

#define ONBOARD_LED 2
#define PIN_RED 4
#define PIN_BLUE 5
#define PIN_GREEN 18
#include "driver/timer.h"
#define TIMER_DIVIDER 16
#define TIMER_SCALE (TIMER_BASE_CLK / TIMER_DIVIDER)


void setup()
{
  Serial.begin(9600);
  Serial.println("Starting");

  ReactiveModule mod = ReactiveModule();
}


void loop()
{
  

}
