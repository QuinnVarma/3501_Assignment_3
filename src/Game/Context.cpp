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
}

void Context::customDraw(void) {
	cam.begin();
	ofSetColor(ofColor::white);
	for (Asteroid * as : _asteroids)
		as->draw();
	// Draw point at origin for testing
	ofSetColor(ofColor::blue);
	ofDrawSphere({ 0,0,0 }, 5);
	cam.end();
	hud.customDraw();
}

void Context::Update(void) {
	player->Update(this);
	cam.Update(this);
	hud.Update();
	hud.playerPos = player->getPosition();
	hud.playerOrient = player->getOrientationQuat();
	hud.camera = &cam;
}
