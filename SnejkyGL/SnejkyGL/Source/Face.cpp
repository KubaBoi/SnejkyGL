#include "../Face.h"

Face::Face(Vertex* vert1, Vertex* vert2, Vertex* vert3) {
	vertex1 = vert1;
	vertex2 = vert2;
	vertex3 = vert3;

	color[0] = 255;
	color[1] = 0;
	color[2] = 255;
}

int* Face::getColor() {
	return color;
}

void Face::setColor(int r, int g, int b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void Face::setNormal() {
	vector3->newVector(v, vertex1->getPosition(), vertex2->getPosition());
	vector3->newVector(u, vertex1->getPosition(), vertex3->getPosition());

	normal[0] = u[1] * v[2] - v[1] * u[2];
	normal[1] = u[2] * v[0] - v[2] * u[0];
	normal[2] = u[0] * v[1] - v[0] * u[1];
}