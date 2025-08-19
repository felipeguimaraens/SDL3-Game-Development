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
	currentFrame = int(((SDL_GetTicks() / 100) % 6));
	acceleration.setY(0.10);
	SDLGameObject::update();
}

void Player::clean()
{

}