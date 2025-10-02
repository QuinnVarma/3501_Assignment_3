#include "PowerUp.h"
#include "../Context.h"

PowerUp::PowerUp() {
    setRadius(10.0f);
    _color = ofColor::pink;
}

void PowerUp::customDraw(void) {
    ofSetColor(_color);
    ofDrawSphere({ 0, 0, 0 }, _collisionRadius);
}
