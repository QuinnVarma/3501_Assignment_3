#pragma once

#include "ofMain.h"
#include "../Collectable.h"

class Beacon : public Collectable{

	public:
		Beacon();

		void Update(Context * ct) override;
		void customDraw(void) override;
    
};
