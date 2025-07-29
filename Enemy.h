#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	void load(int x, int y, int width, int height, std::string texture);
	void draw(SDL_Renderer* Renderer);
	void update();
	void clean();
};

