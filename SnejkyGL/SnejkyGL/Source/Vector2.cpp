#include "../Vector2.h"

Vector2::Vector2() {}

float Vector2::selfLength(float vector[]) {
	return sqrt(vector[0] * vector[0] + vector[1] * vector[1]);
}

float Vector2::distance(float point1[], float point2[]) {
	return sqrt(
		pow(point1[0] - point2[0], 2) +
		pow(point1[1] - point2[1], 2)
	);
}

void Vector2::newVector(float newVector[], float point1[], float point2[]) {
	newVector[0] = point2[0] - point1[0];
	newVector[1] = point2[1] - point1[1];
}

void Vector2::moveVector(float point1[], float point2[]) {
	point1[0] += point2[0];
	point1[1] += point2[1];
}

float Vector2::scalar(float point1[], float point2[]) {
	return (point1[0] * point2[0]) + (point1[1] * point2[1]);
}

float Vector2::angle(float point1[], float point2[]) {
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

bool Vector2::parallelVector(float point1[], float point2[]) {
	normalized(norm1, point1);
	normalized(norm2, point2);

	bool parallel = (fabs(norm1[0]) == fabs(norm2[0]) &&
		fabs(norm1[1]) == fabs(norm2[1]));

	return parallel;
}

bool Vector2::equals(float point1[], float point2[]) {
	float d = 10000;
	return (int(point1[0] * d) == int(point2[0] * d) &&
		int(point1[1] * d) == int(point2[1] * d));
}

void Vector2::reverseVector(float newVector[], float vector[]) {
	newVector[0] = vector[0] * -1;
	newVector[1] = vector[1] * -1;
}

void Vector2::setVectorLength(float newVector[], float vector[], float distance) {
	normalized(norm1, vector);

	newVector[0] = norm1[0] * distance;
	newVector[1] = norm1[1] * distance;
}

void Vector2::multipleVector(float newVector[], float vector[], float m) {
	newVector[0] = vector[0] * m;
	newVector[1] = vector[1] * m;
}

void Vector2::normalized(float newVector[], float vector[]) {
	float leng = selfLength(vector);
	if (leng != 0) {
		newVector[0] = vector[0] / leng;
		newVector[1] = vector[1] / leng;
	}
	else {
		newVector[0] = 0;
		newVector[1] = 0;
	}
}

void Vector2::copy(float newVector[], float vector[]) {
	newVector[0] = vector[0];
	newVector[1] = vector[1];
}