#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>

// Always initialize pointers
SDL_Window* gameWindow = 0;
SDL_Renderer* gameRenderer = 0;

SDL_InitFlags gameInitFlags = SDL_INIT_VIDEO;

bool isRunning = false;

bool init(const char* title, int height, int width, int window_flags) {
	if (!SDL_Init(gameInitFlags)) {
		throw std::runtime_error("Unable to create window");
	}

	gameWindow = SDL_CreateWindow(title, height, width, window_flags); // 0 = No flags

	if (!gameWindow) {
		throw std::runtime_error("Unable to create window");
	}

	gameRenderer = SDL_CreateRenderer(gameWindow, NULL);

	if (!gameRenderer) {
		throw std::runtime_error("Unable to create renderer");
	}

	isRunning = true;

	return true;
}

void render() {
	SDL_SetRenderDrawColor(gameRenderer, 0, 0, 255, 255);
	SDL_RenderClear(gameRenderer);
	SDL_RenderPresent(gameRenderer);
}

int main() {
	try {

		init("SDL: Broken in functions", 800, 600, 0);

		while (isRunning) {
			render();
		}
		
		

		// To finish the program
		SDL_Delay(5000);
		SDL_Quit();
		
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n" << "SDL error: " << SDL_GetError();
		return 1;
	}

	return 0;
}