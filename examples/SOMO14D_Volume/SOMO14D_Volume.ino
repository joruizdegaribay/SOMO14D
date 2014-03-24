/*
  Volume
  Play the first song of the microSD memory and increase and decrease the volume
 
  This example code is in the public domain.
  
  Connections:
    SOMO-14D clk pin to arduino pin 8
    SOMO-14D data pin to arduino pin 9
    SOMO-14D busy pin to arduino pin 10
*/
 
#include "SOMO14D.h"

SOMO14D somo14d;

void setup() {
  
  somo14d.begin(8, 9, 10);
  somo14d.play(0);
}

void loop() {

  //decrease volume
  for (int i = 7; i >= 0; i--){
    somo14d.setVolume(i);
    delay(1000);
  }
  
  //increase volume
  for (int i = 0; i <= 7; i++){
    somo14d.setVolume(i);
    delay(1000);
  }
 delay(10);
}
