#pragma once

#include "../GameObject.h"
#include "ofMain.h"

class Player : public GameObject {
public:
	Player();

	void Update(Context* ct) override;


	void HandleControls(void);

	glm::vec3 getqForward();
	glm::vec3 getqSide();
	glm::vec3 getqUp();

	void pitch(float a);
	void roll(float a);
	void yaw(float a);

private:
	float movementSpeed;
	float rotationSpeed;
	glm::vec3 velocity;
	glm::vec3 position;
	glm::quat orientation;

	glm::vec3 BASE_UP;
	glm::vec3 BASE_SIDE;
	glm::vec3 BASE_FORWARD;
};
