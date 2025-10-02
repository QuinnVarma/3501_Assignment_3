#include "Asteroid.h"
#include "../Context.h"

Asteroid::Asteroid() : Enemy(10.0f) {
    _color = ofColor::red; 
    _objectRadius = 10.00f;
    _collisionRadius = 30.00f;
}

void Asteroid::Update(Context* ct) {
    // Asteroids don’t move for now
}

void Asteroid::customDraw(void) {
    ofSetColor(_color);
    ofDrawBox(0, 0, 0, _collisionRadius);  // base cube scaled
}

