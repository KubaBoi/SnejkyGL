#include "../TestObject.h"

TestObject::TestObject(float x, float y, float z) : GameObject(x, y, z) {
	Mesh* mesh = getMesh();
	mesh->loadMeshFromJson("SnejkyGL/Meshes/pyramid.json");
}
