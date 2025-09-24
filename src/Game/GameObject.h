#pragma once

#include "ofMain.h"

class Context;

class GameObject : public ofNode {

	public:

		GameObject() {};

		virtual void customDraw(void) override { };
		virtual void Update(Context * ct) { };

		// only for circle collision
		bool DoesCollide(GameObject * other);

	protected:

		inline float getRadius(void) const { return _radius; }
		inline void setRadius(float radius) { _radius = radius; }

	private:
		//collision radius
		float _radius = 0;

};
