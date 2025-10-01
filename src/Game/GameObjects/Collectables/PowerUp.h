#pragma once

#include "ofMain.h"
#include "../GameObject.h"

class PowerUp : public GameObject {
public:
    PowerUp();

    void Update(Context* ct) override;   // checks collision with player
    void customDraw(void) override;     // draw pink sphere
private:
    ofColor _color;
};

