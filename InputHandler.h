#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <iostream>
#include "Game.h"

class InputHandler
{
public:
	void update();
	void clean();
	void initialiseJoysticks();
	static InputHandler* instance;
	static InputHandler* Instance() {
		if (instance == 0) {
			instance = new InputHandler();
		}
		return instance;
	}
	~InputHandler() {}
private:
	InputHandler() {};
	int joystick_count;
	std::vector <SDL_Joystick*> joysticks;
	bool JoysticksInitialised;
} ;
typedef InputHandler TheInputHandler;

