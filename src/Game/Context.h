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
	int GetLives() const { return lives; }
	Beacon* getCurrentBeacon() const { return currentBeacon; }
	vector<PowerUp*> getPowerUps() const { return _powerups; }

	// Three posible game states
	enum class GameState {
		Playing,
		GameOver,
		Win
	};

private:
	int asteroids = 200;
	int lives = 3;
	int timeLastHit = 0;
	const int hitCooldown = 5000; 
	int beacons = 4;
	int extraPowerups = 10;
	Beacon* currentBeacon = nullptr;
	GameState state = GameState::Playing;
	float cubeArea = 100.0f;

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
