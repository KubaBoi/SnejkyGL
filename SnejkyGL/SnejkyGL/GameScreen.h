#pragma once

#include <vector>
#include <algorithm>
#include "Object.h"
#include "Renderer.h"
#include "Camera.h"

using namespace std;

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

class GameScreen
{
private:
	vector<Object*> objects;

public:

	Camera* camera;

	GameScreen();
	void update();
	void input(UINT* uMsg);
	void draw(Renderer* renderer);

	void addGameObject(Object* object);
	void removeGameObject(Object* object);

	void setCamera(int width, int height);
};

#endif

