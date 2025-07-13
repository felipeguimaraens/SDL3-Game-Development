#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>
#include "Game.cpp"

// Always initialize pointers
Game* game = 0;

int main() {
	try {

		game = new Game();
		
		game->init("SDL: New game class", 800, 600, 0);

		// Game loop
		while (game->running()) {
			game->render();
			game->update();
			game->handleEvents();
		}
		
		game->clean();
		
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n" << "SDL error: " << SDL_GetError();
		return 1;
	}

	return 0;
}