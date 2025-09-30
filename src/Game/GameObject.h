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

		bool getShouldRemove(void) { return _should_remove; }
		void setRemove(void) { _should_remove = true; }

	protected:

		inline float getRadius(void) const { return _radius; }
		inline void setRadius(float radius) { _radius = radius; }

		bool _should_remove = false;

	private:
		//collision radius
		float _radius = 0;

};
