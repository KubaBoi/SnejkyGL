#pragma once

#include <math.h>
#include <memory>

using namespace std;

#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 
{
private:
	float* norm1 = new float[3];
	float* norm2 = new float[3];

public:
	float x, y, z;

	Vector3();

	float selfLength(float vector[]); //velikost vektoru
	float distance(float point1[], float point2[]); //vzdalenost mezi body
	void newVector(float newVector[], float point1[], float point2[]); //vrati vektor od selfBodu do parBodu

	void moveVector(float vector1[], float vector2[]); //posune bod (soucet vektoru)
	float scalar(float vector1[], float vector2[]); //vrati skalarni soucin vektoru
	float angle(float vector1[], float vector2[]); //vrati uhel mezi vektory
	bool parallelVector(float vector1[], float vector2[]); //vrati true pokud jsou vektory rovnobezne
	bool equals(float vector1[], float vector2[]); //vrati true pokud jsou vektory stejne (velikost i smer)

	void reverseVector(float newVector[], float vector[]); //vrati obraceny vektor
	void setVectorLength(float newVector[], float vector[], float distance); //vrati vektor se stejnym smerem, ale distance velikosti
	void multipleVector(float newVector[], float vector[], float m); //vrati vynasobeny vektor
	void normalized(float newVector[], float vector[]); //vrati normalizovany vektor

	void copy(float newVector[], float vector[]);
};

#endif

