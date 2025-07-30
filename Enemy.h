#pragma once
#include "SDLGameObject.h"
#include "LoaderParams.h"

class Enemy : public SDLGameObject
{
public:
	Enemy(const LoaderParams* parameters);
	void draw();
	void update();
	void clean();
};

