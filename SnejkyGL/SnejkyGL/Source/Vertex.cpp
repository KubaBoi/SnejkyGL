#include "../Vertex.h"

Vertex::Vertex(float x, float y, float z) {
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

void Vertex::update(Camera* camera) {
	setIsInFrontOfCamera(camera);
	findProjection(camera);
}

float* Vertex::getPosition() {
	return position;
}

float* Vertex::getProjection() {
	return projection;
}

bool Vertex::getIsInFromOfCamera() {
	return isInFrontOfCamera;
}

void Vertex::findProjection(Camera* camera) {
	findG(camera); //prunik primky pohledu a roviny pohledu

	vector3->newVector(g, camera->S, G); //vektor mezi G a S

	float x = camera->centerOfScreen[0];
	float y = camera->centerOfScreen[1];

	float gLength = vector3->selfLength(g);

	if (gLength != 0) {
		float alpha = vector3->angle(g, camera->up); //uhel mezi g a up

		float beta = M_PI - (M_PI_2 + alpha); //uhel mezi g a kolmici na up

		x = abs(gLength * sin(alpha)) * camera->maxView;
		y = abs(gLength * sin(beta)) * camera->maxView;

		float angle1 = vector3->angle(g, camera->up);
		float angle2 = vector3->angle(g, camera->right);

		if (0 <= angle1 && angle1 <= M_PI_2 && 0 <= angle2 && angle2 <= M_PI_2) { //I.kvadrant
			x = camera->centerOfScreen[0] + x;
			y = camera->centerOfScreen[1] + y;
		}
		else if (0 <= angle1 && angle1 <= M_PI_2 && angle2 >= M_PI_2) { //II.kvadrant
			x = camera->centerOfScreen[0] - x;
			y = camera->centerOfScreen[1] + y;
		}
		else if (angle1 >= M_PI_2 && angle2 >= M_PI_2) { //III.kvadrant
			x = camera->centerOfScreen[0] - x;
			y = camera->centerOfScreen[1] - y;
		}
		else if (angle1 >= M_PI_2 && 0 <= angle2 && angle2 <= M_PI_2) { //IV.kvadrant
			x = camera->centerOfScreen[0] + x;
			y = camera->centerOfScreen[1] - y;
		}
	}

	projection[0] = int(x);
	projection[1] = int(y);
}

void Vertex::findG(Camera* camera) {
	double g1 = position[0];
	double g2 = 0;
	double g3 = position[2];
		
	if (isInFrontOfCamera) {
		g1 = camera->position[0] - position[0];
		g2 = camera->position[1] - position[1];
		g3 = camera->position[2] - position[2];
	}

	double t = 0; //parametr

	double b = (g1 * camera->right[1] * camera->up[2] -
		g1 * camera->right[2] * camera->up[1] -
		g2 * camera->right[0] * camera->up[2] +
		g2 * camera->right[2] * camera->up[0] +
		g3 * camera->right[0] * camera->up[1] -
		g3 * camera->right[1] * camera->up[0]);

	if (b != 0) {
		t = -(position[0] * camera->right[1] * camera->up[2] - position[0] * camera->right[2] * camera->up[1] -
			position[1] * camera->right[0] * camera->up[2] + position[1] * camera->right[2] * camera->up[0] +
			position[2] * camera->right[0] * camera->up[1] - position[2] * camera->right[1] * camera->up[0] +

			camera->right[0] * camera->S[1] * camera->up[2] - camera->right[0] * camera->S[2] * camera->up[1] -
			camera->right[1] * camera->S[0] * camera->up[2] +

			camera->right[1] * camera->S[2] * camera->up[0] - camera->right[2] * camera->S[0] * camera->up[1] -
			camera->right[2] * camera->S[1] * camera->up[0])
			/ b;
	}

	G[0] = position[0] + t * g1;
	G[1] = position[1] + t * g2;
	G[2] = position[2] + t * g3;

}

void Vertex::setIsInFrontOfCamera(Camera* camera) {
	float a = vector3->distance(position, camera->S);
	float ac = vector3->distance(position, camera->position);

	isInFrontOfCamera = (a <= ac);
}

float* Vertex::fromBack(float side, float bigger, float lower) {
	//zatim nevim co presne dela a jestli je to nutny
	//burger
	//porad sem si nevzpomnel co to dela :D
	//uz to vim, je to zbytecny, ale necham to tu, jen tak
	return NULL;
}
