#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>

void GameObject::load(int x, int y, int width, int height, std::string texture) 
{
	x_pos = x;
	y_pos = y;
	w = width;
	h = height;
	textureID = texture;

	currentRow = 1;
	currentFrame = 1;
}

void GameObject::draw(SDL_Renderer* textureRenderer)
{
	TextureManager::Instance()->drawFrame(textureID, x_pos, y_pos, w, h, currentRow, currentFrame, textureRenderer);
}

void GameObject::update()
{
	x_pos += 1;
}

void GameObject::clean()
{
	std::cout << "Object destroyed.\n";
}