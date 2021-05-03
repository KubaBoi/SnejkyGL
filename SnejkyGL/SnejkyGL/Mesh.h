#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include <stdio.h>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>
#include <fstream>
#include <iostream>

#include "Face.h"
#include "Renderer.h"

using namespace std;

#ifndef MESH_H
#define MESH_H

class Mesh
{
private:
	void updateVertices(Camera* camera);
	int calculateColor(float* normal, Vertex* vertex, int color, float* light);
	Json::Value loadJson(string path);

	Vector2* vector2 = new Vector2();
	Vector3* vector3 = new Vector3();

	float* transformVector = new float[3];
	float* cP = new float[3];
	float* lv = new float[3];

public:
	vector<Vertex*> vertices;
	vector<Face*> faces;

	float* position;

	Mesh(float* pPosition);

	void update(float* pPosition);
	void draw(Renderer* renderer, Camera* camera);

	void loadMeshFromJson(string path);
};

#endif
