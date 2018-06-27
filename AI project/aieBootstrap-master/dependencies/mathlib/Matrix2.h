#pragma once
#include "Vector2.h"

struct Matrix2
{
	Matrix2();
	Matrix2(float f00, float f01, float f10, float f11);
	~Matrix2();

	Vector2 operator* (Vector2 rhs);
	Matrix2 operator* (Matrix2 rhs);

	Vector2& operator[] (int index);

	operator float*();

	void setRotate(float rotation);

	float m[4];
};