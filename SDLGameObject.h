#pragma once
#include <string>
#include "LoaderParams.h"
#include "GameObject.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* Params);
	virtual void draw();
	virtual void update();
	virtual void clean();
protected:
	int x_pos;
	int y_pos;

	int width;
	int height;

	int currentRow;
	int currentFrame;

	std::string textureID;
};

