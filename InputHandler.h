#pragma once
#include <vector>
#include <SDL3/SDL.h>
#include <iostream>
#include "Vector2D.h"
#include "Game.h"

enum mouse_buttons
{
	LEFT  = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	void update();
	void clean();
	void initialiseJoysticks();
	bool getButtonState(int joy, int buttonNumber);
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
	std::vector<std::vector<bool>> buttonStates;
	std::vector<bool> mouseButtonStates;
	bool getMouseButtonState(int buttonNumber);
private:
	InputHandler();
	int joystick_count=0;
	std::vector <SDL_Joystick*> joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> joystickValues;
	bool JoysticksInitialised=0;
} ;
typedef InputHandler TheInputHandler;

