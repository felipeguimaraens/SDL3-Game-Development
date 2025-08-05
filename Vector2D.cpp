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