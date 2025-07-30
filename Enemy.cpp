#pragma once
#include "Enemy.h"

Enemy::Enemy(const LoaderParams* Parameters) : SDLGameObject(Parameters) {

}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	y_pos += 1;
	x_pos += 1;

	currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{

}