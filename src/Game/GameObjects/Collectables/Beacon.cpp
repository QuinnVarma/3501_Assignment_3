#include "Beacon.h"
#include "../../Context.h"

Beacon::Beacon() {
	setRadius(5);
	_color = ofColor::white;
}

void Beacon::Update(Context* ct) {
	//TODO, handle collisions here instead of in context
}

void Beacon::customDraw(void) {
	ofSetColor(_color);
	ofDrawSphere({ 0, 0, 0 }, getCollisionRadius());
	ofSetColor(ofColor::white); 
}


