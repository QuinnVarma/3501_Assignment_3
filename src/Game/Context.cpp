#include "Context.h"

Context::Context() {
}

Context::~Context() {

	delete player;

	for (Asteroid * as : _asteroids)
		delete as;
}

void Context::Setup(void) {
	player = new Player();

	asteroids = 200;
	for (int i = 0; i < asteroids; i++) {
		Asteroid * as = new Asteroid();
		as->setPosition({ ofRandom(-800, 800), ofRandom(-800, 800), ofRandom(-800, 800) });
		_asteroids.push_back(as);
	}


	int beacons = 20;
	for (int i = 0; i < beacons; i++) {
		Beacon* bc = new Beacon();
		bc->setPosition({ ofRandom(-800, 800), ofRandom(-800, 800), ofRandom(-800, 800) });
		_beacons.push_back(bc);
	}

	int robots = 10;
	for (int i = 0; i < robots; i++) {
		Robot* rb = new Robot(glm::vec3(ofRandom(-800, 800), ofRandom(-800, 800), ofRandom(-800, 800)));
		_robots.push_back(rb);
	}
}

void Context::customDraw(void) {
	cam.begin();

	for (Asteroid* as : _asteroids)
		as->draw();

	for (Beacon* bc : _beacons) {
		bc->draw();
	}

	for (Robot* rb : _robots) {
		rb->draw();
	}

	cam.end();
	hud.customDraw();
}

void Context::Update(void) {
	player->Update(this);

	for (Beacon * bc : _beacons) {
		bc->Update(this);
	}

	for (Robot* rb : _robots) {
		rb->Update(this);
	}

	// --- Collision detection with cooldown ---
	uint64_t now = ofGetElapsedTimeMillis();

	if (now - lastHitTime > hitCooldown) {
		bool wasHit = false;

		// check robots
		for (Robot* rb : _robots) {
			if (player->DoesCollide(rb)) {
				wasHit = true;
				break;
			}
		}

		// check asteroids if not already hit
		if (!wasHit) {
			for (Asteroid* as : _asteroids) {
				if (player->DoesCollide(as)) {
					wasHit = true;
					break;
				}
			}
		}

		// apply damage
		if (wasHit) {
			lives--;
			lastHitTime = now;
			hud.lives = lives;   // update HUD
			ofLogNotice() << "Player hit! Lives left: " << lives;
		}
	}
	ofLogNotice() << "Lives (Context): " << lives << " HUD: " << hud.lives;

	cam.Update(this);
	hud.Update(this);
	hud.playerPos = player->getPosition();
	hud.playerOrient = player->getOrientationQuat();
	hud.camera = &cam;
	hud.lives = lives;

	//handle removal
	for (int i = 0; i < _beacons.size();) {
		if (_beacons[i]->getShouldRemove()){
			_beacons.erase(_beacons.begin() + i);
		} else {
			i++;
		}
	}

}
