#pragma once
#include "Player.h"
#include "TextureManager.h"
#include <iostream>

void Player::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* textureRenderer)
{
	TextureManager::Instance()->drawFrame(textureID, x_pos, y_pos, w, h, currentRow, currentFrame, textureRenderer, SDL_FLIP_HORIZONTAL);
}

void Player::update()
{
	x_pos -= 1;
}

void Player::clean()
{
	GameObject::clean();
}