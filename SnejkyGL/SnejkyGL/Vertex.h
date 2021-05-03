#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include "Vector3.h"
#include "Vector2.h"
#include "Camera.h"

#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
private:
	float* position = new float[3];
	float* projection = new float[2];
	bool isInFrontOfCamera = true;

	void findG(Camera* camera); //vrati bod, ve kterem se protina primka pohledu s rovinou promitani

	float* G = new float[3];
	float* g = new float[3];

	Vector2* vector2 = new Vector2();
	Vector3* vector3 = new Vector3();

public:
	Vertex(float x, float y, float z);

	//return
	float* getPosition();
	float* getProjection();
	bool getIsInFromOfCamera();

	void findProjection(Camera* camera); //nalezne obraz vertexu do 2d souradnic
	void setIsInFrontOfCamera(Camera* camera); //vypocete jestli je vertex za kamerou
	float* fromBack(float side, float bigger, float lower); //vrati upravene souradnice vertexu ktery je za kamerou

	void update(Camera* camera);
};

#endif

