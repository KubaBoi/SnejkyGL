#pragma once

#include "Vertex.h"

#ifndef FACE_H
#define FACE_H

class Face
{
private:
	Vector3* vector3 = new Vector3();

	int* color = new int[3];

	float* v = new float[3];
	float* u = new float[3];

public:
	Vertex* vertex1;
	Vertex* vertex2;
	Vertex* vertex3;

	float* normal = new float[3];

	Face(Vertex* vert1, Vertex* vert2, Vertex* vert3);

	int* getColor();

	void setColor(int r, int g, int b);
	void setNormal();
};

#endif