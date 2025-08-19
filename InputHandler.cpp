#include "InputHandler.h"

InputHandler* InputHandler::instance = 0;

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
			std::cout << TheInputHandler::Instance()->getButtonState(0, 3) << "\n";
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
		if (event.type == SDL_EVENT_QUIT)
		{
			TheGame::Instance()->clean();
		}

		if (event.type == SDL_EVENT_JOYSTICK_AXIS_MOTION)
		{

			int whichOne = event.jaxis.which;
			std::cout << "Event captured!" << "\n";
			if (event.jaxis.axis == 0)
			{
				std::cout << event.jaxis.axis << "\n";
				if (event.jaxis.value > joystickDeadZone)
				{
					std::cout << event.jaxis.value << "\n";
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
				std::cout << event.jaxis.axis << "\n";
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
				std::cout << event.jaxis.axis << "\n";
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
				std::cout << event.jaxis.axis << "\n";
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
	
		if (event.type == SDL_EVENT_JOYSTICK_BUTTON_DOWN)
		{
			const SDL_JoystickID which = event.jbutton.which;
			std::cout << which << " | " << static_cast<int>(event.jbutton.button) << " | " << static_cast<int>(event.jbutton.down) << "\n";
			buttonStates[which - 1][static_cast<int>(event.jbutton.button)] = true; // For some reason the which is returning 1 for first controller.
			// Causing chaos. Also static_cast<int>() because my joystick was returning emojis for event.jbutton.button
		}

		if (event.type == SDL_EVENT_JOYSTICK_BUTTON_UP)
		{
			const SDL_JoystickID which = event.jbutton.which;
			std::cout << which << " | " << static_cast<int>(event.jbutton.button) << " | " << static_cast<int>(event.jbutton.down) << "\n";
			buttonStates[which - 1][static_cast<int>(event.jbutton.button)] = true;;
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