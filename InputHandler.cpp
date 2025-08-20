#include "InputHandler.h"

InputHandler* InputHandler::instance = 0;

InputHandler::InputHandler() {
	//Initialize mouse
	for (int i = 0; i < 3; i++) {
		mouseButtonStates.push_back(false);
	}
}

void InputHandler::initialiseJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
		SDL_JoystickID *joysticks_ids = SDL_GetJoysticks(&joystick_count);

		if (joysticks_ids)
		{
			std::cout << "Joysticks found: " << joystick_count << "\n";
			for(int i = 0; i < joystick_count; i ++)
			{
				SDL_Joystick* joy = SDL_OpenJoystick(joysticks_ids[i]);
				if (joy)
				{
					InputHandler::joysticks.push_back(joy);
					InputHandler::joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
					std::vector<bool> tempButtons;

					for (int j = 0; j < SDL_GetNumJoystickButtons(joy); j++)
					{
						tempButtons.push_back(false);
					}
					buttonStates.push_back(tempButtons);
				}
				else {
					std::cout << SDL_GetError();
				}
			}
			SDL_SetJoystickEventsEnabled(true); // SDL_JoystickEventState() - replaced with SDL_SetJoystickEventsEnabled() and SDL_JoystickEventsEnabled()
			InputHandler::JoysticksInitialised = true;

			std::cout << "Total joysticks connected: " << joystick_count << "\n";
			std::cout << "Successfully opened: " << joysticks.size() << "\n";
			for (size_t i = 0; i < joysticks.size(); i++) {
				std::cout << "Joystick " << i << " has "
					<< buttonStates[i].size() << " buttons\n";
			}
		}
		else {
			InputHandler::JoysticksInitialised = false;
		}
	}
}

int InputHandler::xvalue(int joy, int stick) 
{
	if (joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return joystickValues[joy].first->getX();
		}
		else if (stick == 2)
		{
			return joystickValues[joy].second->getX();
		}
	}
	return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
	if (joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return joystickValues[joy].first->getY();
		}
		else if (stick == 2)
		{
			return joystickValues[joy].second->getY();
		}
	}
	return 0;
}

bool InputHandler::getButtonState(int joy, int buttonNumber)
{
	return buttonStates[joy][buttonNumber];
}

void InputHandler::update ()
{
	

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		// Mouse events

		if (event.type == SDL_EVENT_MOUSE_MOTION)
		{
			mousePosition->setX(event.motion.x);
			mousePosition->setY(event.motion.y);
		}

		if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseButtonStates[LEFT] = true;
			}

			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				mouseButtonStates[MIDDLE] = true;
			}

			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				mouseButtonStates[RIGHT] = true;
			}
		}

		if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseButtonStates[LEFT] = false;
			}

			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				mouseButtonStates[MIDDLE] = false;
			}

			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				mouseButtonStates[RIGHT] = false;
			}
		}

		// Joystick events

		if (event.type == SDL_EVENT_JOYSTICK_AXIS_MOTION)
		{

			int whichOne = event.jaxis.which;
			if (event.jaxis.axis == 0)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					joystickValues[0].first->setX(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[0].first->setX(-1);
				}
				else
				{
					joystickValues[0].first->setX(0);
				}
			}

			if (event.jaxis.axis == 1)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					joystickValues[0].first->setY(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[0].first->setY(-1);
				}
				else
				{
					joystickValues[0].first->setY(0);
				}
			}

			if (event.jaxis.axis == 3)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					joystickValues[0].second->setX(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[0].second->setX(-1);
				}
				else
				{
					joystickValues[0].second->setX(0);
				}
			}

			if (event.jaxis.axis == 4)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					joystickValues[0].second->setY(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[0].second->setY(-1);
				}
				else
				{
					joystickValues[0].second->setY(0);
				}
			}

		}
	
		if (event.type == SDL_EVENT_JOYSTICK_BUTTON_DOWN)
		{
			// For some reason the which is returning 1 or 4 for first controller.
			// Causing chaos. Also static_cast<int>() because my joystick was returning emojis for event.jbutton.button
			//const SDL_JoystickID which = event.jbutton.which;

			//std::cout << whichOne << " | " << static_cast<int>(event.jbutton.button) << " | " << static_cast<int>(event.jbutton.down) << "\n";
			buttonStates[0][static_cast<int>(event.jbutton.button)] = true; 
		}

		if (event.type == SDL_EVENT_JOYSTICK_BUTTON_UP)
		{
			//std::cout << whichOne << " | " << static_cast<int>(event.jbutton.button) << " | " << static_cast<int>(event.jbutton.down) << "\n";
			buttonStates[0][static_cast<int>(event.jbutton.button)] = true;;
		}

		// General events

		if (event.type == SDL_EVENT_QUIT)
		{
			TheGame::Instance()->clean();
		}
	}
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition()
{
	return mousePosition;
}

void InputHandler::clean()
{
	if (InputHandler::JoysticksInitialised) {
		for (unsigned int i = 0; i < joystick_count; i++) {
			SDL_CloseJoystick(InputHandler::joysticks[i]);
		}
	}
}