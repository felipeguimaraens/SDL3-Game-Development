#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>
#include "TextureManager.h"


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
	int currentFrame = 0;
	TextureManager textureManager;
public:
	Game() {}
	~Game() {}
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
		textureManager.load("assets/animate-alpha.png", "animate", gameRenderer);

		isRunning = true;
	}

	void render() {
		SDL_SetRenderDrawColor(gameRenderer, 124, 0, 124, 255);
		SDL_RenderClear(gameRenderer);
		textureManager.draw("animate", 0, 0, 128, 82, gameRenderer);
		textureManager.drawFrame("animate", 300, 300, 128, 82, 1, currentFrame, gameRenderer);
		SDL_RenderTextureRotated(gameRenderer, gameTexture, &sourceRect, &targetRect, 0.0, NULL, SDL_FLIP_HORIZONTAL);
		SDL_RenderPresent(gameRenderer);
	}

	void update() {
		currentFrame = int(((SDL_GetTicks() / 100) % 6));
	}
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

