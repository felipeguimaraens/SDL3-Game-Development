#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>
#include "Game.h"

// Always initialize pointers
Game* game = 0;

bool isRunning = false;

int main() {
	try {

		game = new Game();
		
		game->init("SDL: New game class", 800, 600, 0);
		game->render();

		/* Future game loop:
		while (isRunning) {
			game->render();
			game->update();
			game->handleEvents();
		}
		
		game->clean();*/

		SDL_Delay(5000);
		SDL_Quit();
		
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n" << "SDL error: " << SDL_GetError();
		return 1;
	}

	return 0;
}