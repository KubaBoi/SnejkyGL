#include "../Mesh.h"

Mesh::Mesh(float* pPosition) {
	position = pPosition;
}

//pPosition je stara pozice objektu
void Mesh::update(float* pPosition) {
	vector3->newVector(transformVector, pPosition, position);

	for (int i = 0; i < vertices.size(); i++) {
		vector3->moveVector(vertices[i]->getPosition(), transformVector); //posune vertex
	}
}

void Mesh::updateVertices(Camera* camera) {
	for (int i = 0; i < vertices.size(); i++) {
		vertices[i]->update(camera); //vypocte obraz do 2d prostoru
	}
}

void Mesh::draw(Renderer* renderer, Camera* camera) {
	updateVertices(camera);

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


		GLfloat vertices[] =
		{
			face->vertex1->getProjection()[0], face->vertex1->getProjection()[1], 0,
			face->vertex2->getProjection()[0], face->vertex2->getProjection()[1], 0,
			face->vertex3->getProjection()[0], face->vertex3->getProjection()[1], 0,
		};

		GLfloat color[] =
		{
			face->getColor()[0], face->getColor()[1], face->getColor()[2],
			face->getColor()[0], face->getColor()[1], face->getColor()[2],
			face->getColor()[0], face->getColor()[1], face->getColor()[2]
		};

		renderer->drawTriangle(vertices, color);
	}
}

int Mesh::calculateColor(float* normal, Vertex* vertex, int color, float* light) {
	double brightness = 1;

	//vektor mezi vertexem a svetlem
	vector3->newVector(lv, vertex->getPosition(), light);
	
	double angle = int((vector3->angle(lv, normal) * 180 / M_PI) * brightness);

	//int r = 
	return color;
}

//"SnejkyGL/Meshes/cube.json"
void Mesh::loadMeshFromJson(string path) {
	Json::Value data = loadJson(path);

	for (int i = 0; i < data.get("vertices", "default").size(); i++) {
		vertices.push_back(new Vertex(
			position[0] + data.get("vertices", "default")[i][0].asFloat(),
			position[1] + data.get("vertices", "default")[i][1].asFloat(),
			position[2] + data.get("vertices", "default")[i][2].asFloat()
		));
	}

	for (int i = 0; i < data.get("triangles", "default").size(); i++) {
		faces.push_back(new Face(
			vertices[data.get("triangles", "default")[i][0].asInt()],
			vertices[data.get("triangles", "default")[i][1].asInt()],
			vertices[data.get("triangles", "default")[i][2].asInt()]
		));
	}
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