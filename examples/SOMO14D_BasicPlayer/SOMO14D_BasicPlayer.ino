/*
  BasicPlayer
  Play the first song of the microSD memory
 
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

  delay(10);
}
