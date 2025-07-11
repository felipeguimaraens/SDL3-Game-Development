#pragma once
#include <SDL3/SDL.h>
#include <stdexcept>


class Game
{
private:
	bool isRunning = false;
	SDL_Window* gameWindow = 0;
	SDL_Renderer* gameRenderer = 0;
	SDL_Texture* gameTexture = 0;
	SDL_InitFlags gameInitFlags = SDL_INIT_VIDEO | SDL_INIT_EVENTS;
	SDL_FRect sourceRect = {};
	SDL_FRect targetRect = {};
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

		// loading texture
		SDL_Surface* TempSurface = SDL_LoadBMP("assets/rider.bmp");
		gameTexture = SDL_CreateTextureFromSurface(gameRenderer, TempSurface);
		SDL_DestroySurface(TempSurface);

		// SDL_QueryTexture was replaced by SDL_GetTextureSize in SDL3
		SDL_GetTextureSize(gameTexture, &sourceRect.w, &sourceRect.h);

		sourceRect.x = 0;
		sourceRect.y = 0;
		targetRect.x = 50;
		targetRect.y = 50;
		targetRect.w = sourceRect.w;
		targetRect.h = sourceRect.h;

		isRunning = true;
	}

	void render() {
		SDL_SetRenderDrawColor(gameRenderer, 6, 0, 12, 255);
		SDL_RenderClear(gameRenderer);
		//SDL_RenderTexture(gameRenderer, gameTexture, NULL, NULL); - to full screen
		SDL_RenderTexture(gameRenderer, gameTexture, &sourceRect, &targetRect);
		SDL_RenderPresent(gameRenderer);
	}

	void update() {}
	void handleEvents() {
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_EVENT_QUIT:
				isRunning = false;
				break;
			default:
				break;
			}
		}
	}
	
	void clean() {
		SDL_DestroyWindow(gameWindow);
		SDL_DestroyRenderer(gameRenderer);
		SDL_Quit();
	}

	bool running() {
		return isRunning;
	}
};

