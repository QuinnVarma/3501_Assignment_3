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
	for (Asteroid * as : _asteroids)
		as->draw();
	cam.end();
}

void Context::Update(void) {
	player->Update(this);
	cam.Update(this);
}
