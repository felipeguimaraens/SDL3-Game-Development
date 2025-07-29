#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

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
	GameObject* go;
	GameObject* player;
	GameObject* enemy;
	std::vector<GameObject*> gameObjects;
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
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", gameRenderer)) {
			throw std::runtime_error("Singleton: TheTextureManager won't load");
		}

		isRunning = true;

		go = new GameObject();
		player = new Player();
		enemy = new Enemy();

		go->load(100, 100, 128, 82, "animate");
		player->load(300, 300, 128, 82, "animate");
		enemy->load(0, 0, 128, 82, "animate");

		gameObjects.push_back(go);
		gameObjects.push_back(player);
		gameObjects.push_back(enemy);
	}

	void render() {
		SDL_SetRenderDrawColor(gameRenderer, 0, 50, 0, 255);
		SDL_RenderClear(gameRenderer);

		for (std::vector <GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
		{
			gameObjects[i]->draw(gameRenderer);
		}

		SDL_RenderPresent(gameRenderer);
	}

	void draw() { 
		for (std::vector <GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
		{
			gameObjects[i]->draw(gameRenderer);
		}
	}

	void update() {
		currentFrame = int(((SDL_GetTicks() / 100) % 6));
		for (std::vector <GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
		{
			gameObjects[i]->update();
		}
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

