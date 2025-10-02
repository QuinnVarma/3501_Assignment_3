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
		float getScale() const { return _scale; }
		void setScale(float scale) { _scale = scale; }


	protected:

		inline float getCollisionRadius(void) const { return _collisionRadius; }
		inline float getObjectRadius(void) const { return _objectRadius; }
		inline void setRadius(float radius) { _collisionRadius = radius; }

		bool _should_remove = false;
		float _collisionRadius;
		float _objectRadius;
		float _scale;

};
