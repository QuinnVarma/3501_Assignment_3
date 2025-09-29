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

	Player * GetPlayer(void) { return player; }

private:
	int asteroids;

	ofNode body[500];
	
	MyCustomCamera cam;
	Hud hud;

	// GameObjects

	Player * player;
	vector<Asteroid *> _asteroids;
	vector<Robot *> _robots;
	vector<Beacon *> _beacons;
	vector<PowerUp *> _powerups;
    
};
