#pragma once

#include "ofMain.h"
#include "../Collectable.h"

class Beacon : public Collectable{

	public:
		Beacon();

		void Update(Context * ct) override;
		void customDraw(void) override;
		void setColor(const ofColor& c) { _color = c; }
		float getCollisionRadius(){ return _collisionRadius; }
		void setHighlighted(bool h) { highlighted = h; }
		bool isHighlighted() const { return highlighted; }

	private:
		ofColor _color;
		bool highlighted = false;
};
