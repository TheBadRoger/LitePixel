#pragma once
#include "prestats.h"

class Vector2 {
public:
	float x, y;

	Vector2() : x(0), y(0) {};
	Vector2(float tx, float ty) : x(tx), y(ty) {};
	Vector2 operator+(const Vector2& v)const;
	Vector2 operator*(float k)const;
	double operator*(const Vector2& v)const;
};

class LPS_API Pixel {
public:
	Channel r, g, b;

	Pixel() : r(0), g(0), b(0) {};
	Pixel(Channel tr, Channel tg, Channel tb) : r(tr & 0xFF), g(tg & 0xFF), b(tb & 0xFF) {};
	Pixel(Code c) : r((c >> 16) & 0xFF), g((c >> 8) & 0xFF), b(c & 0xFF) {};

	void SetColor(Channel tr, Channel tg, Channel tb);
	void SetColor(Code c);
	bool operator==(const Pixel& c);
	void operator=(const Pixel& c);
	operator Code() const;
};
