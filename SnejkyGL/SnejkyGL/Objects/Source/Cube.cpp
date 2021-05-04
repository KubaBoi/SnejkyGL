#include "../Cube.h"

Cube::Cube(float x, float y, float z, float size, float color[]) : GameObject(x, y, z) {
	Mesh* mesh = getMesh();
	mesh->loadMeshFromJson("SnejkyGL/Meshes/cube.json", size, color);
}
