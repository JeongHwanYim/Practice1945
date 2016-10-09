#pragma once

#include <cmath>

struct Point2D
{
	float X;
	float Y;

	Point2D() : X(0), Y(0) {}
	Point2D(float _X, float _Y) : X(_X), Y(_Y) {}

	Point2D operator-() { return Point2D(-X, -Y); }
};

struct Vector2D
{
	float X;
	float Y;

	Vector2D() : X(1), Y(0) {}
	Vector2D(float _X, float _Y) : X(_X), Y(_Y) {}

	Vector2D operator-() { return Vector2D(-X, -Y); }
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

	// (Loc.X, Loc.Y) -> (Loc.X - diff.X, Loc.Y - diff.Y)
	inline void Translation(Point2D& Loc, const Vector2D& Vec, Point2D diff)
	{
		Loc.X += diff.X;
		Loc.Y += diff.Y;
	}

	inline void Rotation(const Point2D& Loc, Vector2D& Vec, Vector2D diff)
	{
		Vector2D tmp(Vec);

		Vec.X = tmp.X * diff.X + tmp.Y * diff.Y;
		Vec.Y = tmp.X * -diff.Y + tmp.Y * diff.X;
	}
}