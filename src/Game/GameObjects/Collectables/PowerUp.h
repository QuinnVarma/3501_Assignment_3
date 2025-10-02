#pragma once

#include "ofMain.h"
#include "../GameObject.h"

class PowerUp : public GameObject {
public:
    PowerUp();

    void customDraw(void) override;
private:
    ofColor _color;
};

