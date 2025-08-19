#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* parameters);
	void draw();
	void update();
	void clean();
	void handleInput();	
};

