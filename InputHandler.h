#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <iostream>
#include "Vector2D.h"
#include "Game.h"

class InputHandler
{
public:
	void update();
	void clean();
	void initialiseJoysticks();
	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);
	static InputHandler* instance;
	static InputHandler* Instance() {
		if (instance == 0) {
			instance = new InputHandler();
		}
		return instance;
	}
	~InputHandler() {}
	const int joystickDeadZone = 0;
private:
	InputHandler() {};
	int joystick_count;
	std::vector <SDL_Joystick*> joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> joystickValues;
	bool JoysticksInitialised;
} ;
typedef InputHandler TheInputHandler;

