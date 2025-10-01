#pragma once

#include "ofMain.h"
#include "Game/MyCustomCamera.h"
#include "Game/Context.h"
#include "Game/GameObjects/Player.h"
#include "Game/GameObjects/Enemies/Robot.h"

class ofApp : public ofBaseApp{

	public:
	~ofApp();

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		int asteroids;
		
		ofNode body[500];

		MyCustomCamera cam;
		Context * ct;
};
