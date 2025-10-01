#include "Beacon.h"
#include "../../Context.h"

Beacon::Beacon() {
	setRadius(5);
}

void Beacon::Update(Context * ct) {
	if (DoesCollide(ct->GetPlayer())){
		setRemove();
		ct->SetScore(ct->GetScore());
	}

}

void Beacon::customDraw(void) {
	ofSetColor(ofColor::blue);
	ofDrawSphere({ 0, 0, 0 }, getCollisionRadius());
	ofSetColor(ofColor::white);
}


