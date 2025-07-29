#pragma once
#include <iostream>
#include <string>
#include <SDL3/SDL.h>

class GameObject
{
public:
	void load(int x, int y, int width, int height, std::string texture);
	void draw(SDL_Renderer* Renderer);
	void update();
	void clean();
protected:
	std::string textureID;

	int currentFrame;
	int currentRow;

	int x_pos;
	int y_pos;

	int h;
	int w;
};

