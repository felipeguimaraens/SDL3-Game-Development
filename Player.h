#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	void draw()
	{
		GameObject::draw();
	}
	void update() {
		GameObject::update();
		x_pos = 10;
		y_pos = 20;
	}
	void clean() {
		GameObject::clean();
	}
};

