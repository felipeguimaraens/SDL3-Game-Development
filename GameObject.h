#pragma once
#include <iostream>
#include <string>
#include <SDL3/SDL.h>

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* Parameters) {}
	virtual ~GameObject() {}
};

