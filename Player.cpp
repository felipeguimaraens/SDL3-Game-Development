#pragma once
#include "Player.h"

Player::Player(const LoaderParams* Parameters) : SDLGameObject(Parameters) {

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	position.setX(position.getX() - 1);
	currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean()
{

}