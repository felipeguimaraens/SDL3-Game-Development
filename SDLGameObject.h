#pragma once
#include <string>
#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* Params);
	virtual void draw();
	virtual void update();
	virtual void clean();
protected:
	/*int x_pos;
	int y_pos; replaced by vector*/
	Vector2D position;
	Vector2D velocity;

	int width;
	int height;

	int currentRow;
	int currentFrame;

	std::string textureID;
};

