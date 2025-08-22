#pragma once
#include "Player.h"
#include <iostream>

Vector2D* vec = new Vector2D(0,0);

Player::Player(const LoaderParams* Parameters) : SDLGameObject(Parameters) {

}

void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{

	handleInput();

	currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::handleInput()
{
	// Keyboard
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		velocity.setY(-1);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		velocity.setY(1);
	}
	
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) 
	{
		velocity.setX(1);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		velocity.setX(-1);
	}

	// Joystick
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