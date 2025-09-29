#include "Hud.h"

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

	float padding = 30.0f;
	float w = ofGetWidth();
	float h = ofGetHeight();
	glm::vec2 center(w / 2.0f, h / 2.0f);

	// Transform beacon position to camera space
	glm::vec3 camSpaceDir = glm::rotate(glm::inverse(camera->getOrientationQuat()), nearestBeacon - camera->getPosition());

	// Project to screen direction (ignore Z)
	glm::vec2 dirOnScreen(camSpaceDir.x, -camSpaceDir.y);

	// Check if beacon is on screen
	glm::vec3 beaconScreen = camera->worldToScreen(nearestBeacon);
	bool beaconOnScreen =
		beaconScreen.x >= padding && beaconScreen.x <= w - padding &&
		beaconScreen.y >= padding && beaconScreen.y <= h - padding &&
		beaconScreen.z < 1.0f;

	if (!beaconOnScreen && glm::length(dirOnScreen) > 1e-6f) {
		glm::vec2 triPos = getEdgeIntersection(center, dirOnScreen, w, h, padding);

		float triSize = 28.0f;
		float angleRad = atan2(dirOnScreen.x, -dirOnScreen.y);
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
	}
}

void Hud::Update(void) {
	// Update lives and beacons from context
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
