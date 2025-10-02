#include "Beacon.h"
#include "../../Context.h"

Beacon::Beacon() {
	setRadius(5);
	_color = ofColor::white;
	_collisionRadius = 30.00f;
}

// Draws a yellow square if the beacon is the current goal and the other beacons are white spheres
void Beacon::customDraw(void) {

    ofSetColor(_color);

	if (isHighlighted()) {
		ofDrawBox(0, 0, 0, _collisionRadius * 2.0f);
	}
	else {
		ofDrawSphere(0, 0, 0, _collisionRadius);
	}
}

