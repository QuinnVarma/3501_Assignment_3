#pragma once
#include "ofMain.h"
#include "../GameObject.h"

class Enemy : public GameObject {
public:
    Enemy(float radius = 10.0f);
    virtual ~Enemy() = default;

    // All enemies must override Update and customDraw
    virtual void Update(Context* ct) override = 0;
    virtual void customDraw(void) override = 0;

protected:
    ofColor _color;
};
