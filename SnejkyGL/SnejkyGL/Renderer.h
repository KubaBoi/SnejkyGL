#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Vector2.h"

#include <iostream>
#include <sstream>
#include <memory>

#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
private:
	Vector2* vector2 = new Vector2();
	float* background = new float[4];

	bool more = false;

public:
	Renderer();

	void clearScreen();
	void drawTriangle(GLfloat vertices[], GLfloat color[]);
	void setBackground(float r, float g, float b, float a);
};

#endif


