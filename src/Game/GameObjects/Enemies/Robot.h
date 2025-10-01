#pragma once
#include "Enemy.h"
#include "../Player.h"

class Robot : public Enemy {
public:
    Robot(glm::vec3 startPos);

    void Update(Context* ct) override;
    void customDraw(void) override;

private:
    float detectionRadius;
    float speed;
};

