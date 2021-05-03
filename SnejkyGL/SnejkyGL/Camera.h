#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <windows.h>
#include "Vector3.h"
#include "Vector2.h"

#ifndef CAMERA_H 
#define CAMERA_H

class Camera
{
public:
	float* centerOfScreen = new float[2];
	float* position = new float[3];
	float speed;
	float viewAngle;
	float maxView;
	float minView; //vzdalenost plochy zobrazeni

	float* forward = new float[3]; //vektor dopredu
	float* up = new float[3]; //vektor nahoru
	float* right = new float[3]; //vektor doprava
	float* S = new float[3]; //stred plochy zobrazeni (od position->forward)

	float rotX;
	float rotY;

	Camera(float x, float y, float z);

	void update();
	void input(UINT* uMsg);
};

#endif
