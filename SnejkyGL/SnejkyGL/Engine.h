#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"
#include "GameScreen.h"
#include "GameObject.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
	Renderer* renderer;
	GLFWwindow* window;

public:
	bool running;
	GameScreen* gameScreen;

	Engine();
	int initWindow(int width, int height);

	void update();
	void draw();

	void addGameObject(Object* object);
	void removeGameObject(Object* object);

	GLFWwindow* getWindow();
};

#endif

