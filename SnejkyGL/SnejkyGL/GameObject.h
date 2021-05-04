#pragma once

#include "Vector3.h"
#include "Renderer.h"
#include "Object.h"
#include "Mesh.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject: public Object 
{
private:
	Mesh* mesh;

public:
	float* position = new float[3];

	GameObject(float x, float y, float z);

	virtual void update() override;
	virtual void draw(Renderer* renderer, Camera* camera) override;
	virtual void input(UINT* uMsg) override;

	virtual void setMesh(Mesh* pMesh);

	virtual Mesh* getMesh();
};

#endif
