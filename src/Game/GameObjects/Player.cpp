#include "Player.h"
#include "../Context.cpp"


Player::Player() {
	movementSpeed = 100.0f; // units per second
	rotationSpeed = 0.35f; // rads per second
	position = glm::vec3(0, 0, 0);
	velocity = glm::vec3(0, 0, 0);
	orientation = glm::quat(1, 0, 0, 0); // nothing

	BASE_SIDE = glm::vec3(1, 0, 0);
	BASE_UP = glm::vec3(0, 1, 0);
	BASE_FORWARD = glm::vec3(0, 0, 1); // don't need to store all three, note
	_collisionRadius = 30.00f; //collision radius of the player

	setRadius(10);
}



void Player::Update(Context* ct) {
	velocity = glm::vec3(0, 0, 0);

	HandleControls();

	// need to set ofCamera parameters using internal position, orientation
	setPosition(position);
	setOrientation(orientation);
}

void Player::HandleControls(void) {
	// WASD movement
	if (ofGetKeyPressed('w')) velocity += getqForward();
	if (ofGetKeyPressed('s')) velocity -= getqForward();
	if (ofGetKeyPressed('a')) velocity -= getqSide();
	if (ofGetKeyPressed('d')) velocity += getqSide();
	if (ofGetKeyPressed('q')) velocity += getqUp();
	if (ofGetKeyPressed('e')) velocity -= getqUp();

	if (glm::length(velocity) > 0.0f) // did it move at all?
	{
		velocity = glm::normalize(velocity) * movementSpeed * ofGetLastFrameTime();
		position = position + velocity;
	}

	float rotationamt = rotationSpeed * ofGetLastFrameTime();

	// IJKL rotation
	if (ofGetKeyPressed('i')) pitch(rotationamt);
	if (ofGetKeyPressed('k')) pitch(-rotationamt);
	if (ofGetKeyPressed('j')) yaw(rotationamt);
	if (ofGetKeyPressed('l')) yaw(-rotationamt);
	if (ofGetKeyPressed('o')) roll(rotationamt);
	if (ofGetKeyPressed('u')) roll(-rotationamt);
	orientation = orientation / length(orientation); // normalize
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
