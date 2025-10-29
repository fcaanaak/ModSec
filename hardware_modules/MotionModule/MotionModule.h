#ifndef MOTION_MODULE_H
#define MOTION_MODULE_H
#include <ReactiveModule.h>
/*

  TODO: 
  Replace the project structure like so,

  hardware_modules:
  |
  |__ Managers

  And move ReactiveModule and MotionModule to the hardware_modules
  folder.

  Then, move all the other Manager files like WiFi and LED into the Managers
  folder
 */

class MotionModule : public ReactiveModule {

 private:

  static const unsigned short sensorTriggerPin = 25;
  static const unsigned short sensorEchoPin = 26;
  
  bool detectExternalEvent() override;
  float getMeasuredDistance();
  unsigned long detectionDuration;
  float distanceCM;

  unsigned short calibrationTimeMillis = 3000;
  unsigned short calibrationDelayMillis = 20;
  unsigned short numMeasurements = calibrationTimeMillis/calibrationDelayMillis;

  unsigned short toleranceCm = 2;

  // setup methods
  void setupSensor();
  void setupThreshold();
  
 public:
  void setup() override;
};


#endif
