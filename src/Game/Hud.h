#pragma once
#include "ofMain.h"
#include "GameObject.h"

class Hud : public GameObject
{
	public:
		Hud();
		~Hud();

		void Setup(void);
		void customDraw(void) override;
		void Update(Context* ct) override;

		int lives = 3;
		int beacons = 5;

		glm::vec3 playerPos = { 0,0,0 };
		glm::quat playerOrient = { 1,0,0,0 };
		glm::vec3 nearestBeacon = { 0,0,0 };

		ofCamera* camera = nullptr;

		glm::vec2 getEdgeIntersection(const glm::vec2& center, const glm::vec2& dir, float w, float h, float padding);
};

