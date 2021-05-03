#include "../Camera.h"

Camera::Camera(float x, float y, float z) {
	position[0] = x;
	position[1] = y;
	position[2] = z;

	speed = 0.1f;
	viewAngle = M_PI;
	maxView = 1000;
	minView = 1;

	rotX = M_PI;
	rotY = 0;

	forward[0] = 0;
	forward[1] = 0;
	forward[2] = minView;

	up[0] = 0;
	up[1] = minView;
	up[2] = 0;

	right[0] = -minView;
	right[1] = 0;
	right[2] = 0;

	S[0] = 0;
	S[1] = 0;
	S[2] = minView;
}

void Camera::update() {

}

void Camera::input(UINT* uMsg) {

}