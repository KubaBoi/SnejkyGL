#include "../TestObject.h"

TestObject::TestObject(float x, float y, float z) : GameObject(x, y, z) {
}

void TestObject::loadMeshFromJson(string path, float size, float color[]) {
	Mesh* mesh = getMesh();
	mesh->loadMeshFromJson(path, size, color);
}