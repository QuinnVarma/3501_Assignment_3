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
}

void Context::customDraw(void) {
	cam.begin();
	
	for (Asteroid * as : _asteroids)
		as->draw();

	for (Beacon* bc : _beacons){
		bc->draw();
	}

	cam.end();
	hud.customDraw();
}

void Context::Update(void) {
	player->Update(this);

	for (Beacon * bc : _beacons) {
		bc->Update(this);
	}
	cam.Update(this);
	hud.Update(this);
	hud.playerPos = player->getPosition();
	hud.playerOrient = player->getOrientationQuat();
	hud.camera = &cam;




	//handle removal
	for (int i = 0; i < _beacons.size();) {
		if (_beacons[i]->getShouldRemove()){
			_beacons.erase(_beacons.begin() + i);
		} else {
			i++;
		}
	}

}
