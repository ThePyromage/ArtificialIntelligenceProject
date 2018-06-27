#pragma once

struct Vector4
{
	Vector4();
	Vector4(float x, float y, float z, float w);
	~Vector4();

	Vector4 operator+(Vector4 rhs);
	Vector4 operator-(Vector4 rhs);
	Vector4 operator*(float rhs);

	float& operator[](int index);

	operator float*();

	float magnitude();
	void normalise();
	float dot(Vector4 rhs);
	Vector4 cross(Vector4 rhs);

	float x, y, z, w;
};

Vector4 operator*(float lhs, Vector4 rhs);