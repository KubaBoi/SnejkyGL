#pragma once
#include "Renderer.h"
#include "Camera.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:

	Object();

	virtual void update();
	virtual void draw(Renderer* renderer, Camera* camera);
	virtual void input(UINT* uMsg);
};

#endif

