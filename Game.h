#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <stdexcept>
#include <vector>
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "LoaderParams.h"

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
	std::vector<GameObject*> gameObjects;
	Game() {};
public:
	static Game* instance;
	static Game* Instance() {
		if (instance == 0) {
			instance = new Game();
		}
		return instance;
	}
	~Game() {};
	void init(const char* title, int height, int width, int window_flags);
	void render();

	SDL_Renderer* getRenderer();
	void draw();
	void update();
	void handleEvents();
	void clean();
	bool running();
};

typedef Game TheGame;

