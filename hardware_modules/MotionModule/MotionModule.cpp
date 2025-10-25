#include "MotionModule.h"

#define SPEED_OF_SOUND 0.034 // Units cm/(micro seconds)


float MotionModule::getMeasuredDistance(){
  /**
     @brief Return distance measured from the sensor in cm
   */
  digitalWrite(sensorTriggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(sensorTriggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTriggerPin,LOW);

  detectionDuration = pulseIn(sensorEchoPin,HIGH);

  distanceCM = detectionDuration * SPEED_OF_SOUND / 2;

  return distanceCM;

}


void MotionModule::setupSensor(){

  pinMode(sensorTriggerPin, OUTPUT);
  pinMode(sensorEchoPin, INPUT);
  
}

void MotionModule::setup(){

  ReactiveModule::setup();
  setupSensor();

}





