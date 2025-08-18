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
	velocity.setX(1);
	SDLGameObject::update();
}

void Player::clean()
{

}