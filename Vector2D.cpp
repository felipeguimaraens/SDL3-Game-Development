#include "Vector2D.h"

float Vector2D::getX() { 
	return x_pos; 
}
float Vector2D::getY() {
	return y_pos; 
}
void Vector2D::setX(float x) {
	x_pos = x; 
}
void Vector2D::setY(float y) {
	y_pos = y; 
}

float Vector2D::length() {
	return sqrt(x_pos * x_pos + y_pos * y_pos);
}

Vector2D Vector2D::operator+(const Vector2D& v2) {
	return Vector2D(x_pos + v2.x_pos, y_pos + v2.y_pos);
}

Vector2D& Vector2D::operator+=(const Vector2D& v2) {
	x_pos += v2.x_pos;
	y_pos += v2.y_pos;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& v2) {
	return Vector2D(x_pos - v2.x_pos, y_pos - v2.y_pos);
}

Vector2D& Vector2D::operator-=(const Vector2D& v2) {
	x_pos -= v2.x_pos;
	y_pos -= v2.y_pos;
	return *this;
}

Vector2D Vector2D::operator*(float scalar) {
	return Vector2D(x_pos * scalar, y_pos * scalar);
}

Vector2D& Vector2D::operator*=(float scalar) {
	x_pos *= scalar;
	y_pos *= scalar;
	return *this;
}

Vector2D Vector2D::operator/(float scalar) {
	return Vector2D(x_pos / scalar, y_pos / scalar);
}

Vector2D& Vector2D::operator/=(float scalar) {
	x_pos /= scalar;
	y_pos /= scalar;
	return *this;
}