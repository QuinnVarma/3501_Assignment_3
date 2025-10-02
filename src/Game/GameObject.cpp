#include "GameObject.h"

bool GameObject::DoesCollide(GameObject* other) {
	glm::vec3 p1 = this->getPosition();
	glm::vec3 p2 = other->getPosition();

	float r1 = this->_collisionRadius;
	float r2 = other->_collisionRadius;


	// if the distance is less than the combined radii, then there is a collision
	return glm::length(p1 - p2) < (r1 + r2);

}
