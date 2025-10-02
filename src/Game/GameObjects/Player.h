#pragma once

#include "../GameObject.h"
#include "ofMain.h"

class Player : public GameObject {
public:
	Player();

	void Update(Context* ct) override;
	void increaseMaxSpeed() { currentSpeed += 100.0f; }  // permanent boost

	void HandleControls(void);

	glm::vec3 getqForward();
	glm::vec3 getqSide();
	glm::vec3 getqUp();

	void pitch(float a);
	void roll(float a);
	void yaw(float a);

private:
	float maxSpeed;       // maximum speed
	float accelRate;      // how much speed changes per second
	float currentSpeed;
	float rotationSpeed;
	float minSpeed;
	float minScale;       // smallest size
	float maxScale;       // largest size
	float scaleRate;      // how fast scaling changes
	float baseSpeed;
	float MIN_SCALE;
	float MAX_SCALE;
	float SCALE_STEP;
	float baseCollisionRadius;

	glm::vec3 velocity;
	glm::quat orientation;

	glm::vec3 BASE_UP;
	glm::vec3 BASE_SIDE;
	glm::vec3 BASE_FORWARD;
};
