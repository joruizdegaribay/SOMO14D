/*
 Arduino Library for 4D Systems SOMO-14D Embedded Audio-Sound Module
 go to http://www.4dsystems.com.au/product/10/117/Development/SOMO_14D/ for more information
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created July 2013
 by Jonathan Ruiz de Garibay

 */ 

#include "Arduino.h"
#include "SOMO14D.h"

//
// begin
//
// Init inputs and outputs.
boolean SOMO14D::begin(uint8_t clkPin, uint8_t dataPin, uint8_t busyPin){

	_clkPin = clkPin;
	pinMode(_clkPin, OUTPUT);

	_dataPin = dataPin;
	pinMode(_dataPin, OUTPUT);

	_busyPin = busyPin;
	pinMode(_busyPin, INPUT);

	_volume = SOMO14D_MAX_VOLUME;

	delay(200);
}

//
// play
//
// Play an specific song/audio
boolean SOMO14D::play(unsigned int song){

	_sendCommand(song);
	delay(1);
	return (digitalRead(_busyPin) == HIGH);
}

//
// stop
//
// Stop present song/audio
boolean SOMO14D::stop(){

	_sendCommand(SOMO14D_STOP);
	delay(1);
	return (digitalRead(_busyPin) == HIGH);
}

//
// pause
//
// Pause or resume present song/audio
boolean SOMO14D::pause(){

	_sendCommand(SOMO14D_PAUSE);
	delay(1);
	return (digitalRead(_busyPin) == HIGH);
}

//
// getState
//
// return if player is running (TRUE) or not (FALSE)
boolean SOMO14D::getState(){

	return (digitalRead(_busyPin) == HIGH);
}

//
// getVolume
//
// Get present volume for SOMO-14D
uint8_t SOMO14D::getVolume(){

	return _volume - SOMO14D_MIN_VOLUME;
}

//
// setVolume
//
// set a specific volume for SOMO-14D
void SOMO14D::setVolume(uint8_t volume){

	if (volume > 7)
		volume = 7;
	_volume = volume + SOMO14D_MIN_VOLUME;
	_sendCommand(_volume);
}

//
// sendCommand
//
// Send a command to SOMO-14D
void SOMO14D::_sendCommand(unsigned int command){

	uint8_t dataCounter = 0;

	digitalWrite(_clkPin, LOW);       //Hold for 2msec to signal data start
	delay(2);
   
    while(dataCounter < 16){

		digitalWrite(_clkPin, LOW); 
		if (command & 0x8000)
			digitalWrite(_dataPin, HIGH);
        else
			digitalWrite(_dataPin, LOW);
		command = command << 1;
		delayMicroseconds(120);      //Clock cycle period is 100 uSec - LOW
		digitalWrite(_clkPin, HIGH);
		dataCounter++;
		delayMicroseconds(120);      //Clock cycle period is 100 uSec - HIGH
	}

	digitalWrite(_dataPin, LOW);
	digitalWrite(_clkPin, HIGH);    // Place clock high to signal end of data
}