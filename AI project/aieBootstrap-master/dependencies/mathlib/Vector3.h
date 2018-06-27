#pragma once

struct Vector3
{
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	Vector3 operator+(Vector3 rhs);
	Vector3 operator-(Vector3 rhs);
	Vector3 operator*(float rhs);

	float& operator[](int index);

	operator float*();

	float magnitude();
	void normalise();
	float dot(Vector3 rhs);
	Vector3 cross(Vector3 rhs);

	float x, y, z;
};

Vector3 operator*(float lhs, Vector3 rhs);