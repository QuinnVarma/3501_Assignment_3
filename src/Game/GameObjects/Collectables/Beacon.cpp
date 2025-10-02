#include "Beacon.h"
#include "../../Context.h"

Beacon::Beacon() {
	setRadius(5);
	_color = ofColor::white;
	_collisionRadius = 30.00f;
}

void Beacon::Update(Context* ct) {
	//TODO, handle collisions here instead of in context
}

void Beacon::customDraw(void) {

    ofSetColor(_color);

	if (isHighlighted()) {
		ofDrawBox(0, 0, 0, _collisionRadius * 2.0f);
	}
	else {
		ofDrawSphere(0, 0, 0, _collisionRadius);
	}
}


/*
void Beacon::customDraw(void) {
	ofSetColor(_color);
	ofDrawSphere({ 0, 0, 0 }, getCollisionRadius());
	ofSetColor(ofColor::white); 
}
*/

