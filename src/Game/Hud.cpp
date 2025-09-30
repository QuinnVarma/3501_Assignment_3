#include "Hud.h"
#include "Context.h"

Hud::Hud() {
}

Hud::~Hud() {
}

void Hud::Setup(void) {
}

void Hud::customDraw(void) {
	// Project lives and beacons remaining in top-left corner
	ofDrawBitmapStringHighlight("Lives: " + std::to_string(lives), 20, 20, ofColor::black, ofColor::white);
	ofDrawBitmapStringHighlight("Beacons: " + std::to_string(beacons), 20, 40, ofColor::black, ofColor::white);

	// get normalized vector from player to beacon
	glm::vec3 worldDir = glm::normalize(nearestBeacon - playerPos);

	// convert to camera space using quaternion rotation
	glm::vec3 camSpaceDir = glm::rotate(glm::inverse(playerOrient), worldDir);

	// get angle in radians from forward (-Z) to direction
	float angleRad = atan2(camSpaceDir.x, -camSpaceDir.z);

	// Calculate direction vector in screen space (Y up)
	glm::vec2 dirOnScreen(sin(angleRad), -cos(angleRad)); // "up" is forward

	float padding = 30.0f;
	float w = ofGetWidth() - 2 * padding;
	float h = ofGetHeight() - 2 * padding;
	glm::vec2 center(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);

	// --- Accurate visibility check using camera ---
	// Replace 'camera' with your actual camera pointer/reference
	glm::vec3 beaconScreen = camera->worldToScreen(nearestBeacon);

	bool beaconOnScreen =
		beaconScreen.x >= padding && beaconScreen.x <= ofGetWidth() - padding &&
		beaconScreen.y >= padding && beaconScreen.y <= ofGetHeight() - padding &&
		beaconScreen.z < 1.0f; // z < 1 means in front of camera (OpenGL NDC)

	if (!beaconOnScreen) {
		glm::vec2 center(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
		glm::vec2 beacon2D(beaconScreen.x, beaconScreen.y);
		glm::vec2 dir = beacon2D - center;

		glm::vec2 triPos = getEdgeIntersection(center, dir, ofGetWidth(), ofGetHeight(), padding);

		// Draw the triangle pointing toward the beacon
		float triSize = 28.0f;
		float angleRad = atan2(dir.x, -dir.y); // angle from up
		ofPushMatrix();
		ofTranslate(triPos);
		ofRotateDeg(ofRadToDeg(angleRad));
		ofSetColor(255, 50, 50);
		ofDrawTriangle(
			ofPoint(0, -triSize), // tip
			ofPoint(-triSize * 0.6f, triSize * 0.6f), // left
			ofPoint(triSize * 0.6f, triSize * 0.6f)   // right
		);
		ofPopMatrix();
		ofSetColor(ofColor::white);
	}
}

void Hud::Update(Context* ct) {
	// Update lives and beacons from context
	beacons = ct->getBeacons().size();


	//getting closest beacon
	GameObject * player = ct->GetPlayer();

	if (ct->getBeacons().size() > 0) {
		GameObject * closest_beacon = ct->getBeacons().back();
		for (GameObject * beacon : ct->getBeacons()){
			float min_dist = glm::length(player->getPosition() - closest_beacon->getPosition());
			float new_dist = glm::length(player->getPosition() - beacon->getPosition());
			if (new_dist < min_dist)
				closest_beacon = beacon;

		}
		nearestBeacon = closest_beacon->getPosition();
	}
}

glm::vec2 Hud::getEdgeIntersection(const glm::vec2& center, const glm::vec2& dir, float w, float h, float padding) {
	// Screen bounds
	float left   = padding;
	float right  = w - padding;
	float top    = padding;
	float bottom = h - padding;

	// Direction vector (normalized)
	if (glm::length(dir) < 1e-6f) {
		// Degenerate case: direction is zero, return center
		return center;
	}
	glm::vec2 d = glm::normalize(dir);

	// Calculate t for each edge
	std::vector<float> tCandidates;
	if (d.x != 0) {
		float tLeft   = (left - center.x)   / d.x;
		float tRight  = (right - center.x)  / d.x;
		if (tLeft > 0)  tCandidates.push_back(tLeft);
		if (tRight > 0) tCandidates.push_back(tRight);
	}
	if (d.y != 0) {
		float tTop    = (top - center.y)    / d.y;
		float tBottom = (bottom - center.y) / d.y;
		if (tTop > 0)    tCandidates.push_back(tTop);
		if (tBottom > 0) tCandidates.push_back(tBottom);
	}

	if (tCandidates.empty()) {
		// No valid intersection, return center
		return center;
	}

	// Find the smallest positive t
	float tEdge = *std::min_element(tCandidates.begin(), tCandidates.end());

	// Intersection point
	return center + d * tEdge;
}
