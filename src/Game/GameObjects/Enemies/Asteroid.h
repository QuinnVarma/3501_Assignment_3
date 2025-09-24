#pragma once

#include "ofMain.h"
#include "../Enemy.cpp"

class Asteroid : public Enemy{
public:
	Asteroid() { setRadius(10); }
	void customDraw(void) override { ofDrawBox({ 0, 0, 0 }, getRadius()); };
	void Update(Context * ct) override { };
    
};
