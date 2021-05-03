#include "../Vector3.h"

Vector3::Vector3() {}

float Vector3::selfLength(float vector[]) {
	return sqrt(vector[0] * vector[0] +
		vector[1] * vector[1] +
		vector[2] * vector[2]);
}

float Vector3::distance(float point1[], float point2[]) {
	return sqrt(
		pow(point1[0] - point2[0], 2) +
		pow(point1[1] - point2[1], 2) +
		pow(point1[2] - point2[2], 2)
	);
}

void Vector3::newVector(float newVector[], float point1[], float point2[]) {
	newVector[0] = point2[0] - point1[0];
	newVector[1] = point2[1] - point1[1];
	newVector[2] = point2[2] - point1[2];
}

void Vector3::moveVector(float point1[], float point2[]) {
	point1[0] += point2[0];
	point1[1] += point2[1];
	point1[2] += point2[2];
}

float Vector3::scalar(float point1[], float point2[]) {
	return (point1[0] * point2[0]) +
		(point1[1] * point2[1]) + 
		(point1[2] * point2[2]);
}

float Vector3::angle(float point1[], float point2[]) {
	float length = selfLength(point1) * selfLength(point2);
	if (length == 0) {
		return 0;
	}

	float ang = scalar(point1, point2) / length;
	if (-1 >= ang <= 1) {
		return acos(ang);
	}
	return 0;
}

bool Vector3::parallelVector(float point1[], float point2[]) {
	normalized(norm1, point1);
	normalized(norm2, point2);

	bool parallel = (fabs(norm1[0]) == fabs(norm2[0]) &&
		fabs(norm1[1]) == fabs(norm2[1]) &&
		fabs(norm1[2]) == fabs(norm2[2]));

	return parallel;
}

bool Vector3::equals(float point1[], float point2[]) {
	float d = 10000;
	return (int(point1[0] * d) == int(point2[0] * d) &&
		int(point1[1] * d) == int(point2[1] * d) &&
		int(point1[2] * d) == int(point2[2] * d));
}

void Vector3::reverseVector(float newVector[], float vector[]) {
	newVector[0] = vector[0] * -1;
	newVector[1] = vector[1] * -1;
	newVector[2] = vector[2] * -1;
}

void Vector3::setVectorLength(float newVector[], float vector[], float distance) {
	normalized(norm1, vector);

	newVector[0] = norm1[0] * distance;
	newVector[1] = norm1[1] * distance;
	newVector[2] = norm1[2] * distance;
}

void Vector3::multipleVector(float newVector[], float vector[], float m) {
	newVector[0] = vector[0] * m;
	newVector[1] = vector[1] * m;
	newVector[2] = vector[2] * m;
}

void Vector3::normalized(float newVector[], float vector[]) {
	float leng = selfLength(vector);
	if (leng != 0) {
		newVector[0] = vector[0] / leng;
		newVector[1] = vector[1] / leng;
		newVector[2] = vector[2] / leng;
	}
	else {
		newVector[0] = 0;
		newVector[1] = 0;
		newVector[2] = 0;
	}
}

void Vector3::copy(float newVector[], float vector[]) {
	newVector[0] = vector[0];
	newVector[1] = vector[1];
	newVector[2] = vector[2];
}