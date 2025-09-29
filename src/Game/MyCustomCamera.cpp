#include "MyCustomCamera.h"
#include "ofMain.h"
#include "Context.h"
#include <glm/gtc/quaternion.hpp>


MyCustomCamera::MyCustomCamera() {
}

void MyCustomCamera::Update(Context * ct) {
   
    // need to set ofCamera parameters using internal position, orientation
    setPosition(ct->GetPlayer()->getPosition());
	setOrientation(ct->GetPlayer()->getOrientationEuler());

}

