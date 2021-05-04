#include "../Plain.h"

Plain::Plain(float pX, float pY, float pZ, float pWidth, float pHeight) : GameObject(pX, pY, pZ) {
	width = pWidth;
	height = pHeight;
	cluster = 1;

	createMesh();
}

void Plain::createMesh() {
	Mesh* mesh = getMesh();
	for (int x = 0; x < width; x++) {
		for (int z = 0; z < height; z++) {
			mesh->vertices.push_back(new Vertex(x, 0, z));
			mesh->realVertices.push_back(new Vertex(0, 0, 0));
		}
	}

	int i = 0;
	for (int x = 0; x < width; x++) {
		for (int z = 0; z < height; z++) {
			if (i + width + 1 < width * height) {
				mesh->faces.push_back(new Face(
					mesh->realVertices[i],
					mesh->realVertices[i + width],
					mesh->realVertices[i + width + 1]
				));

				mesh->faces.push_back(new Face(
					mesh->realVertices[i],
					mesh->realVertices[i + width + 1],
					mesh->realVertices[i + 1]
				));
			}

			i++;
		}
	}
}
