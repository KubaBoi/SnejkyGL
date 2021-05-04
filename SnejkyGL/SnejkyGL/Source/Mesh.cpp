#include "../Mesh.h"

Mesh::Mesh(float* pPosition) {
	position = pPosition;
}

void Mesh::update() {
	for (int i = 0; i < vertices.size(); i++) {
		realVertices[i]->getPosition()[0] = position[0] + (vertices[i]->getPosition()[0] * size);
		realVertices[i]->getPosition()[1] = position[1] + (vertices[i]->getPosition()[1] * size);
		realVertices[i]->getPosition()[2] = position[2] + (vertices[i]->getPosition()[2] * size);
	}
}

void Mesh::updateVertices(Camera* camera) {
	for (int i = 0; i < vertices.size(); i++) {
		realVertices[i]->update(camera); //vypocte obraz do 2d prostoru
	}
}

void Mesh::draw(Renderer* renderer, Camera* camera) {
	updateVertices(camera);

	float* light = new float[3];
	light[0] = 0;
	light[1] = 0;
	light[2] = 0;

	for (int i = 0; i < faces.size(); i++) {
		Face* face = faces[i];

		//ani jeden z vertexu neni pred kamerou
		if (!face->vertex1->getIsInFromOfCamera() &&
			!face->vertex2->getIsInFromOfCamera() &&
			!face->vertex3->getIsInFromOfCamera()) {
			continue;
		}

		face->setNormal();
		vector3->newVector(cP, face->vertex1->getPosition(), camera->position);
		//face je zady ke kamere
		if (vector3->angle(face->normal, cP) > M_PI_2) {
			continue;
		}

		calculateColor(face, light);

		GLfloat vertices[] = {
			face->vertex1->getProjection()[0], face->vertex1->getProjection()[1], 0,
			face->vertex2->getProjection()[0], face->vertex2->getProjection()[1], 0,
			face->vertex3->getProjection()[0], face->vertex3->getProjection()[1], 0,
		};

		GLfloat color[] = {
			face->getNewColor()[0] / 255, face->getNewColor()[1] / 255, face->getNewColor()[2] / 255,
			face->getNewColor()[0] / 255, face->getNewColor()[1] / 255, face->getNewColor()[2] / 255,
			face->getNewColor()[0] / 255, face->getNewColor()[1] / 255, face->getNewColor()[2] / 255
		};

		renderer->drawTriangle(vertices, color);
		drawEdges(renderer, face);
	}
}

void Mesh::drawEdges(Renderer* renderer, Face* face) {
	GLfloat lineVertice1[] = {
			face->vertex1->getProjection()[0], face->vertex1->getProjection()[1], 0,
			face->vertex2->getProjection()[0], face->vertex2->getProjection()[1], 0,
	};

	GLfloat lineVertice2[] = {
		face->vertex1->getProjection()[0], face->vertex1->getProjection()[1], 0,
		face->vertex3->getProjection()[0], face->vertex3->getProjection()[1], 0,
	};

	GLfloat lineVertice3[] = {
		face->vertex3->getProjection()[0], face->vertex3->getProjection()[1], 0,
		face->vertex2->getProjection()[0], face->vertex2->getProjection()[1], 0,
	};

	GLfloat blackColor[] = {
			0, 0, 0,
			0, 0, 0
	};

	renderer->drawLine(lineVertice1, blackColor, 1);
	renderer->drawLine(lineVertice2, blackColor, 1);
	renderer->drawLine(lineVertice3, blackColor, 1);
}

void Mesh::calculateColor(Face* face, float* light) {
	double brightness = 1;

	//vektor mezi vertexem a svetlem
	vector3->newVector(lv, face->vertex1->getPosition(), light);
	
	double angle = int((vector3->angle(lv, face->normal) * 180 / M_PI) * brightness);

	face->setNewColor(
		face->getColor()[0] - angle,
		face->getColor()[1] - angle,
		face->getColor()[2] - angle
	);
}

//"SnejkyGL/Meshes/cube.json"
void Mesh::loadMeshFromJson(string path, float pSize, float color[]) {
	Json::Value data = loadJson(path);
	size = pSize;

	for (int i = 0; i < data.get("vertices", "default").size(); i++) {
		vertices.push_back(new Vertex(
			data.get("vertices", "default")[i][0].asFloat(),
			data.get("vertices", "default")[i][1].asFloat(),
			data.get("vertices", "default")[i][2].asFloat()
		));
		realVertices.push_back(new Vertex(0, 0, 0));
	}

	for (int i = 0; i < data.get("triangles", "default").size(); i++) {
		faces.push_back(new Face(
			realVertices[data.get("triangles", "default")[i][0].asInt()],
			realVertices[data.get("triangles", "default")[i][1].asInt()],
			realVertices[data.get("triangles", "default")[i][2].asInt()]
		));
	}

	float r, g, b;
	if (color == NULL) {
		for (int i = 0; i < data.get("colors", "default").size(); i++) {
			r = data.get("colors", "default")[i][0].asFloat();
			g = data.get("colors", "default")[i][1].asFloat();
			b = data.get("colors", "default")[i][2].asFloat();
			faces[i]->setColor(r, g, b);
		}
	}
	else {
		r = color[0];
		g = color[1];
		b = color[2];
		for (int i = 0; i < data.get("triangles", "default").size(); i++) {
			faces[i]->setColor(r, g, b);
		}
	}
}

void Mesh::setSize(float pSize) {
	size = pSize;
}

Json::Value Mesh::loadJson(string path) {
	std::ifstream myFile(path);
	std::ostringstream tmp;
	tmp << myFile.rdbuf();
	std::string strJson = tmp.str();
	std::cout << strJson << std::endl;

	Json::CharReaderBuilder builder;
	Json::CharReader* reader = builder.newCharReader();

	Json::Value json;
	std::string errors;

	bool parsingSuccessful = reader->parse(
		strJson.c_str(),
		strJson.c_str() + strJson.size(),
		&json,
		&errors
	);
	delete reader;

	if (!parsingSuccessful) {
		std::cout << "Failed to parse the JSON, errors:" << std::endl;
		std::cout << errors << std::endl;
	}

	return json;
}