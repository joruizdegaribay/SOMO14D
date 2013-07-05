/*
  Volume
  Play the first song of the microSD memory and increase and decrease the volume
 
  This example code is in the public domain.
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
    somo14d.decreaseVolume();
    delay(1000);
  }
  
  //increase volume
  for (int i = 0; i <= 7; i++){
    somo14d.increaseVolume();
    delay(1000);
  }
 delay(10);
}
