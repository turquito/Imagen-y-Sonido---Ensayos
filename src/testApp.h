#pragma once
#include "ofMain.h"

class testApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	bool updateBall();     // move ball function
	
	ofSoundPlayer sound; // sample

};
