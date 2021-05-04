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

//smer vertexu je PROTISMERU hodinovych rucicek

class Mesh
{
private:
	void updateVertices(Camera* camera);
	void drawEdges(Renderer* renderer, Face* face);
	void calculateColor(Face* face, float* light);
	Json::Value loadJson(string path);

	Vector2* vector2 = new Vector2();
	Vector3* vector3 = new Vector3();

	float* cP = new float[3];
	float* lv = new float[3];

public:
	vector<Vertex*> vertices; //poloha vzhledem k Mesh
	vector<Vertex*> realVertices; //poloha v prostoru
	vector<Face*> faces;

	float* position;
	float size = 1;

	Mesh(float* pPosition);

	void update();
	void draw(Renderer* renderer, Camera* camera);

	void loadMeshFromJson(string path, float pSize, float color[]);
	void setSize(float size);
};

#endif
