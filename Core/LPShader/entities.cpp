#include "entities.h"

Vector2 Vector2::operator+(const Vector2& v)const {
	return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator*(float k)const {
	return Vector2(k * x, k * y);
}

double Vector2::operator*(const Vector2& v)const {
	return x * v.x + y * v.y;
}

void Pixel::SetColor(Channel tr, Channel tg, Channel tb) {
	r = tr % 256, g = tg % 256, b = tb % 256;
}

void Pixel::SetColor(Code c) {
	r = (c >> 16 & 0xFF), g = (c >> 8 & 0xFF), b = (c & 0xFF);
}

bool Pixel::operator==(const Pixel& c) {
	return r == c.r && g == c.g && b == c.b;
}

void Pixel::operator=(const Pixel& c) {
	r = c.r, g = c.g, b = c.b;
}

Pixel::operator Code() const {
	return r << 16 | g << 8 | b;
}
