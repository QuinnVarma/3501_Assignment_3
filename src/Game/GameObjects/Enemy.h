#pragma once
#include "ofMain.h"
#include "../GameObject.h"

class Enemy : public GameObject {
public:
    Enemy(float radius = 10.0f);
    virtual ~Enemy() = default;

    // All enemies must override customDraw
    virtual void customDraw(void) override = 0;

protected:
    ofColor _color;
};
