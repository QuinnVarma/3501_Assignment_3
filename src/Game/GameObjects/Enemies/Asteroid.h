#pragma once

#include "ofMain.h"
#include "../Enemy.h"

class Asteroid : public Enemy {
public:
    Asteroid();

    void customDraw(void) override;
};
