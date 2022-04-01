#ifndef __SHCUSTOMPROTOCOL_H__
#define __SHCUSTOMPROTOCOL_H__

#include <Arduino.h>

class SHCustomProtocol {
private:

public:
     Servo myservox;
     float posx = 0.00; 
     Servo myservoz;
     float posz = 0.00; 

	void setup() {
     	myservox.attach(9);
		myservoz.attach(10);
	}

	void read() {

		float accelx = FlowSerialReadStringUntil(';').toFloat();
		float accely = FlowSerialReadStringUntil(';').toFloat();
		float accelz = FlowSerialReadStringUntil('\n').toFloat();
		//For debugging. Prints output to the SIMHUB System Log
		//FlowSerialDebugPrintLn("accelx: " + String(accelx));
		//FlowSerialDebugPrintLn("accely: " + String(accely));
		//FlowSerialDebugPrintLn("accelz: " + String(accelz));
				
		// Y-Axis is not used for this project, but I left it here for expansion.
		//posy = map(accelx, -20, 60, 0, 180);
		
		// The map function works like this:
		// map(value, fromLow, fromHigh, toLow, toHigh)
		// X-Axis is left (negative) and right (positive) **If I remember correct. This might be reversed
		// Z-Axis is forward (negative) and backward (positive) 
		// You can adjust the toLow and toHigh based on how you wire the 3D hanger movement arms
		
		posx = map(accelx, -20, 20, 0, 180);
		myservox.write(posx);    
		
		posz = map(accelz, -20, 20, 70, 110);
		myservoz.write(posz);    
		
	}

	void loop() {
	}

	void idle() {
	}
};

#endif
