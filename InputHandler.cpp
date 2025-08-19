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

void InputHandler::update ()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			TheGame::Instance()->clean();
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