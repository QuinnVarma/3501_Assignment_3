#include "Player.h"
#include "../Context.cpp"


Player::Player() {
	currentSpeed = 100.0f; // units per second
	rotationSpeed = 0.35f; // rads per second
	velocity = glm::vec3(0, 0, 0);
	orientation = glm::quat(1, 0, 0, 0); // nothing

	BASE_SIDE = glm::vec3(1, 0, 0);
	BASE_UP = glm::vec3(0, 1, 0);
	BASE_FORWARD = glm::vec3(0, 0, 1); // don't need to store all three, note
	_collisionRadius = 30.00f; //collision radius of the player
	maxSpeed = currentSpeed * 2;  // cap
	accelRate = 100.0f;  // change per second
	minSpeed = 50.0f;
	minScale = 0.2f;   // can shrink to 1/5 size
	maxScale = 3.0f;   // can grow to 3x size
	scaleRate = 0.5f;   // change per second
	setScale(1.0f);     // default scale
	baseSpeed = 0.5f;
	MIN_SCALE = 0.5f;
	MAX_SCALE = 2.5f;
	SCALE_STEP = 0.01f;

	setRadius(10);
}



void Player::Update(Context* ct) {
	HandleControls();
	setOrientation(orientation);
}


void Player::HandleControls(void) {
	float dt = ofGetLastFrameTime();

	// --- Speed control ---
	if (ofGetKeyPressed('w')) {
		currentSpeed += accelRate * dt;
		if (currentSpeed > maxSpeed) currentSpeed = maxSpeed;
	}
	if (ofGetKeyPressed('s')) {
		currentSpeed -= accelRate * dt;
		if (currentSpeed < minSpeed) currentSpeed = minSpeed; 
	}

	// grow with "="
	if (ofGetKeyPressed('=')) {
		float newScale = std::min(MAX_SCALE, getScale() + SCALE_STEP);
		setScale(newScale);
	}

	// shrink with "-"
	if (ofGetKeyPressed('-')) {
		float newScale = std::max(MIN_SCALE, getScale() - SCALE_STEP);
		setScale(newScale);
	}

	// --- Always move forward at currentSpeed ---
	glm::vec3 forward = getLookAtDir();
	setPosition(getPosition() + forward * (currentSpeed * ofGetLastFrameTime()));

	// --- Rotations (yaw, pitch, roll) ---
	float rotationamt = rotationSpeed * dt;
	if (ofGetKeyPressed('i')) pitch(rotationamt);
	if (ofGetKeyPressed('k')) pitch(-rotationamt);
	if (ofGetKeyPressed('j')) yaw(rotationamt);
	if (ofGetKeyPressed('l')) yaw(-rotationamt);
	if (ofGetKeyPressed('o')) roll(rotationamt);
	if (ofGetKeyPressed('u')) roll(-rotationamt);

	orientation = glm::normalize(orientation);
}

void Player::pitch(float amt) {
	glm::quat change = glm::angleAxis(amt, getqSide());
	orientation = glm::normalize(change * orientation);
}

void Player::yaw(float amt) {
	glm::quat change = glm::angleAxis(amt, getqUp());
	orientation = glm::normalize(change * orientation);
}

void Player::roll(float amt) {
	glm::quat change = glm::angleAxis(amt, getqForward());
	orientation = glm::normalize(change * orientation);
}

glm::vec3 Player::getqForward() {

	return glm::rotate(orientation, -BASE_FORWARD);
}

glm::vec3 Player::getqSide() {

	return glm::rotate(orientation, BASE_SIDE);
}

glm::vec3 Player::getqUp() {

	return glm::rotate(orientation, BASE_UP);
}
