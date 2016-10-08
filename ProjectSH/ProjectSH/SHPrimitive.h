#pragma once

#include <cmath>

struct Point2D
{
	int X;
	int Y;

	Point2D() : X(0), Y(0) {}
	Point2D(int _X, int _Y) : X(_X), Y(_Y) {}
};

struct Vector2D
{
	float X;
	float Y;

	Vector2D() : X(1), Y(0) {}
	Vector2D(float _X, float _Y) : X(_X), Y(_Y) {}
};

namespace SH
{
	//return : scala
	inline float Normalize2D(float& x, float& y)
	{
		float scala = _STD sqrt(x*x + y*y);
		x /= scala;
		y /= scala;

		return scala;
	}
}