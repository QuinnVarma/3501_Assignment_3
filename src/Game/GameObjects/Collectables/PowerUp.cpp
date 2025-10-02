#include "PowerUp.h"
#include "../Context.h"

PowerUp::PowerUp() {
    setRadius(10.0f);       // small sphere
    _color = ofColor::pink; // make it pink
}

void PowerUp::Update(Context* ct) {
    // Power-ups don’t move, but they might be removed if collected
    // Actual collection handled in Context
}

void PowerUp::customDraw(void) {
    ofSetColor(_color);
    ofDrawSphere({ 0, 0, 0 }, getCollisionRadius());
}
