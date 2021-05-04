#pragma once
#include "GameObject.h"

class TestObject: public GameObject
{


public:
	TestObject(float x, float y, float z);
	void loadMeshFromJson(string path, float size, float color[]);

};

