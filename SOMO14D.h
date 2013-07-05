/*
 Arduino Library for 4D Systems SOMO-14D Embedded Audio-Sound Module
 go to http://www.4dsystems.com.au/product/10/117/Development/SOMO_14D/ for more information
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created July 2013
 by Jonathan Ruiz de Garibay

 */ 

#ifndef SOMO14D_h
#define SOMO14D_h

#include "Arduino.h"

#define SOMO14D_MIN_VOLUME		0xFFF0
#define SOMO14D_MAX_VOLUME		0xFFF7

#define SOMO14D_STOP			0xFFFF
#define SOMO14D_PAUSE			0xFFFE
#define SOMO14D_RESUME			0xFFFE

class SOMO14D
{
	public:
		boolean begin(uint8_t clkPin, uint8_t dataPin, uint8_t busyPin);
		void play(unsigned int song);
		void stop();
		void pause();
		uint8_t getVolume();
		void setVolume(uint8_t volume);
		void increaseVolume();
		void decreaseVolume();

	private:
		uint8_t _clkPin;
		uint8_t _dataPin;
		uint8_t _busyPin;
		unsigned int _volume;
		void _sendCommand(unsigned int command);
};

#endif