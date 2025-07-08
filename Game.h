#pragma once
#include <SDL3/SDL.h>
#include <stdexcept>


class Game
{
private:
	bool isRunning = false;
	SDL_Window* gameWindow = 0;
	SDL_Renderer* gameRenderer = 0;
	SDL_InitFlags gameInitFlags = SDL_INIT_VIDEO;
public:
	Game(){}
	~Game(){}
	void init(const char* title, int height, int width, int window_flags) {
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
	}

	void render() {
		SDL_SetRenderDrawColor(gameRenderer, 255, 255, 0, 255);
		SDL_RenderClear(gameRenderer);
		SDL_RenderPresent(gameRenderer);
	}
	void update() {}
	void handleEvents() {}
	void clean() {}
	bool running() {
		return isRunning;
	}
};

