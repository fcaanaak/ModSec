#include "MotionModule.h"
MotionModule mod = MotionModule();

void setup(){
  Serial.begin(9600);

  mod.setup();
  
}

void loop(){
  
  mod.mainloop();
}
