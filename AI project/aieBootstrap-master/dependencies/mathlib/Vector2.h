#pragma once

struct Vector2
{
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2 operator+(Vector2 rhs);
	Vector2 operator-(Vector2 rhs);
	Vector2 operator*(float rhs);

	float& operator[](int index);

	operator float*();

	float magnitude();
	void normalise();
	float dot(Vector2 rhs);

	float x, y;
};

Vector2 operator*(float lhs, Vector2 rhs);