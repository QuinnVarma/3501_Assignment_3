#pragma once
#include "ofCamera.h"

class Context;

class MyCustomCamera : public ofCamera {
public:
    MyCustomCamera();

    void Update(Context * ct);
};
