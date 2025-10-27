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

  // setup methods
  void setupSensor();
  
 public:
  void setup() override;
};


#endif
