#pragma once
#include "Vector4.h"

struct Matrix4
{
	Matrix4();
	Matrix4(float f00, float f01, float f02, float f03, float f10, float f11, float f12, float f13, float f20, float f21, float f22, float f23, float f30, float f31, float f32, float f33);
	~Matrix4();

	Vector4 operator* (Vector4 rhs);
	Matrix4 operator* (Matrix4 rhs);

	Vector4& operator[] (int index);

	operator float*();

	void setRotateX(float rotation);
	void setRotateY(float rotation);
	void setRotateZ(float rotation);

	float m[16];
};