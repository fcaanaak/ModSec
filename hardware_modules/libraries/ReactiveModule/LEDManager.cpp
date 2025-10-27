#include "LEDManager.h"


void LEDManager::setupLED(){

  pinMode(LEDPinRed,OUTPUT);
  pinMode(LEDPinGreen,OUTPUT);
  pinMode(LEDPinBlue,OUTPUT);

}

void LEDManager::setLED(ushort red, ushort green, ushort blue){
  analogWrite(LEDPinRed,red);
  analogWrite(LEDPinGreen,green);
  analogWrite(LEDPinBlue,blue);
}

void LEDManager::disableLED(){
  LEDManager::setLED(0,0,0);

}

void LEDManager::flashLEDBlocking(ushort red, ushort green,ushort blue, ushort numFlashes, uint delay_time){

  for (ushort currentFlash = 0; currentFlash < numFlashes; currentFlash++){
    LEDManager::setLED(red,green,blue);
    delay(delay_time);
    LEDManager::disableLED();
    delay(delay_time);
  } 
  
}
