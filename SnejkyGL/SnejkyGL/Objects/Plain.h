#pragma once
#include "../GameObject.h"

class Plain: public GameObject
{
public:
	float width, height, cluster;

	Plain(float pX, float pY, float pZ, float pWidth, float pHeight);

	void createMesh();
};

