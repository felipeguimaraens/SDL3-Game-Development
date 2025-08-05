#pragma once
#include <math.h>

class Vector2D
{
public:
	Vector2D(float x, float y): x_pos(x), y_pos(y) {}
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	float length();
private:
	float x_pos;
	float y_pos;
};

