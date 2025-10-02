#include "Robot.h"
#include "Context.h"

Robot::Robot(glm::vec3 startPos) : Enemy(20.0f) { // robot radius = 20
    setPosition(startPos);
    _color = ofColor::green;
    detectionRadius = 300.0f;
    speed = 0.2f;
    _objectRadius = 10;
    _collisionRadius = 30.00f;
}

void Robot::Update(Context* ct) {
    glm::vec3 playerPos = ct->GetPlayer()->getPosition();
    glm::vec3 dir = playerPos - getPosition();
    float dist = glm::length(dir);

    if (dist < detectionRadius && dist > 1.0f) {
        dir = glm::normalize(dir);
        setPosition(getPosition() + dir * speed);
    }
}

void Robot::customDraw(void) {
    ofSetColor(_color);
    ofDrawSphere(0, 0, 0, _objectRadius);
}