#pragma once
#include "Player.h"

Vector2D* vec = new Vector2D(0,0);

Player::Player(const LoaderParams* Parameters) : SDLGameObject(Parameters) {

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	vec = TheInputHandler::Instance()->getMousePosition();
	velocity.setX(0);
	velocity.setY(0);
	handleInput();

	velocity = (*vec - position) / 100;

	currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->xvalue(0, 1) > 0 || TheInputHandler::Instance()->xvalue(0, 1) < 0)
	{
		velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 1));
	}

	if (TheInputHandler::Instance()->yvalue(0, 1) > 0 || TheInputHandler::Instance()->yvalue(0, 1) < 0)
	{
		velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 1));
	}

	if (TheInputHandler::Instance()->xvalue(0, 2) > 0 || TheInputHandler::Instance()->xvalue(0, 2) < 0)
	{
		velocity.setX(1 * TheInputHandler::Instance()->xvalue(0, 2));
	}

	if (TheInputHandler::Instance()->yvalue(0, 2) > 0 || TheInputHandler::Instance()->yvalue(0, 2) < 0)
	{
		velocity.setY(1 * TheInputHandler::Instance()->yvalue(0, 2));
	}

}

void Player::clean()
{

}