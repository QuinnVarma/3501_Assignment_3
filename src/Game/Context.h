#pragma once

#include "ofMain.h"
#include "MyCustomCamera.h"
#include "Hud.h"

#include "GameObjects/Player.h"

#include "GameObjects/Enemies/Asteroid.h"
#include "GameObjects/Enemies/Robot.h"

#include "GameObjects/Collectables/Beacon.h"
#include "GameObjects/Collectables/PowerUp.h"


class Context : public ofNode{


public:

	Context();
	~Context();

	void Setup(void);
	void customDraw(void) override;
	void Update(void);


	//getters and setters
	int GetScore(void) { return score; }
	void SetScore(int new_score) { score = new_score; }

	Player * GetPlayer(void) { return player; }

	vector<Beacon *> getBeacons(void) { return _beacons; }

private:
	int asteroids;
	int lives = 3;
	uint64_t lastHitTime = 0;
	const uint64_t hitCooldown = 5000; 
	int GetLives() const { return lives; }

	ofNode body[500];
	
	MyCustomCamera cam;
	Hud hud;
	int score = 0;

	// GameObjects

	Player * player;
	vector<Asteroid *> _asteroids;
	vector<Robot *> _robots;
	vector<Beacon *> _beacons;
	vector<PowerUp *> _powerups;
    
};
