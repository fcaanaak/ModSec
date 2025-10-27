#include "MotionModule.h"

MotionModule mod = MotionModule();

void setup(){
  Serial.begin(9600);

  mod.setup();
  mod.setIntervalMillis(100);
  mod.setThreshold(10.0);
  
}

void loop(){
  
  mod.mainloop();
}
