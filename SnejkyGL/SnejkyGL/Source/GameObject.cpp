#include "../GameObject.h"

GameObject::GameObject(float x, float y, float z) {
	position[0] = x;
	position[1] = y;
	position[2] = z;

	oldPosition[0] = position[0];
	oldPosition[1] = position[1];
	oldPosition[2] = position[2];

	mesh = new Mesh(position);
}

void GameObject::update() {
	mesh->update(oldPosition);

	oldPosition[0] = position[0];
	oldPosition[1] = position[1];
	oldPosition[2] = position[2];
}

void GameObject::draw(Renderer* renderer, Camera* camera) {
	mesh->draw(renderer, camera);
}

void GameObject::input(UINT* uMsg) {

}

void GameObject::setMesh(Mesh* pMesh) {
	mesh = pMesh;
}

Mesh* GameObject::getMesh() {
	return mesh;
}