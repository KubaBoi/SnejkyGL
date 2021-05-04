#include "../Pyramid.h"

Pyramid::Pyramid(float x, float y, float z, float size, float color[]) : GameObject(x, y, z) {
	Mesh* mesh = getMesh();
	mesh->loadMeshFromJson("SnejkyGL/Meshes/cube.json", size, color);
}