#include "InputHandler.h"

InputHandler* InputHandler::instance = 0;

void InputHandler::initialiseJoysticks()
{
	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
		SDL_GetJoysticks(&joystick_count);

		if (joystick_count > 0)
		{
			for(int i = 0; i < joystick_count; i ++)
			{
				SDL_Joystick* joy = SDL_OpenJoystick(i);
				if (!joy)
				{
					InputHandler::joysticks.push_back(joy);
					InputHandler::joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0)));
				}
				else {
					std::cout << SDL_GetError();
				}
			}
			SDL_SetJoystickEventsEnabled(true); // SDL_JoystickEventState() - replaced with SDL_SetJoystickEventsEnabled() and SDL_JoystickEventsEnabled()
			InputHandler::JoysticksInitialised = true;

			std::cout << "Initialised " << InputHandler::joysticks.size() << "| joystick(s)";
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

void InputHandler::update ()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			TheGame::Instance()->clean();
		}

		if (event.type == SDL_EVENT_JOYSTICK_AXIS_MOTION)
		{
			std::cout << "New event: " << event.type << "\n";
			int whichOne = event.jaxis.which;
			if (event.jaxis.axis == 0)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					std::cout << "jaxis.value: " << event.jaxis.value << "\n";
					joystickValues[whichOne].first->setX(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[whichOne].first->setX(-1);
				}
				else
				{
					joystickValues[whichOne].first->setX(0);
				}
			}

			if (event.jaxis.axis == 1)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					joystickValues[whichOne].first->setY(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[whichOne].first->setY(-1);
				}
				else
				{
					joystickValues[whichOne].first->setY(0);
				}
			}

			if (event.jaxis.axis == 3)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					joystickValues[whichOne].second->setX(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[whichOne].second->setX(-1);
				}
				else
				{
					joystickValues[whichOne].second->setX(0);
				}
			}

			if (event.jaxis.axis == 4)
			{
				if (event.jaxis.value > joystickDeadZone)
				{
					joystickValues[whichOne].second->setY(1);
				}
				else if (event.jaxis.value < joystickDeadZone)
				{
					joystickValues[whichOne].second->setY(-1);
				}
				else
				{
					joystickValues[whichOne].second->setY(0);
				}
			}

		}
	}
}

void InputHandler::clean()
{
	if (InputHandler::JoysticksInitialised) {
		for (unsigned int i = 0; i < joystick_count; i++) {
			SDL_CloseJoystick(InputHandler::joysticks[i]);
		}
	}
}