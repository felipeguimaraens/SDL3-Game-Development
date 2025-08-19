#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>
#include "Game.h"

#include "vector2D.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

Game* game = 0;

int main() {
	Uint32 frameStart, frameTime;

	try {
		TheGame::Instance()->init("SDL:Game Singleton", 800, 600, 0);

		// Game loop
		while (TheGame::Instance()->running()) {
			frameStart = SDL_GetTicks();

			TheGame::Instance()->render();
			TheGame::Instance()->update();
			TheGame::Instance()->handleEvents();
			
			frameTime = SDL_GetTicks() - frameStart; //delta frame
			
			// Wait the difference if frame run faster than pre-set of 1000ms / 60
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
		
		TheGame::Instance()->clean();
		
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n" << "SDL error: " << SDL_GetError();
		return 1;
	}

	return 0;
}