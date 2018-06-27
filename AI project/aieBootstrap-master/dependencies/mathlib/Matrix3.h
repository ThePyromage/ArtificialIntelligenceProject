#pragma once
#include "Vector3.h"

struct Matrix3
{
	Matrix3();
	Matrix3(float f00, float f01, float f02, float f10, float f11, float f12, float f20, float f21, float f22);
	~Matrix3();

	Vector3 operator* (Vector3 rhs);
	Matrix3 operator* (Matrix3 rhs);

	Vector3& operator[] (int index);

	operator float*();

	void setRotateX(float rotation);
	void setRotateY(float rotation);
	void setRotateZ(float rotation);

	float m[9];
};