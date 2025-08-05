#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>
#include "Game.h"

Game* game = 0;

int main() {
	try {
		TheGame::Instance()->init("SDL:Game Singleton", 800, 600, 0);

		// Game loop
		while (TheGame::Instance()->running()) {
			TheGame::Instance()->render();
			TheGame::Instance()->update();
			TheGame::Instance()->handleEvents();
			SDL_Delay(10);// cap framerate
		}
		
		TheGame::Instance()->clean();
		
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n" << "SDL error: " << SDL_GetError();
		return 1;
	}

	return 0;
}