#pragma once
#include "Game.h"

Game* Game::instance = 0;

void Game::init(const char* title, int height, int width, int window_flags) {
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

	gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
}

void Game::render() {
	SDL_SetRenderDrawColor(gameRenderer, 0, 50, 0, 255);
	SDL_RenderClear(gameRenderer);

	for (std::vector <GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
	{
		gameObjects[i]->draw();
	}

	SDL_RenderPresent(gameRenderer);
}

SDL_Renderer* Game::getRenderer(){
	return gameRenderer;
}

void Game::draw() {
	for (std::vector <GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
	{
		gameObjects[i]->draw();
	}
}

void Game::update() {
	currentFrame = int(((SDL_GetTicks() / 100) % 6));
	for (std::vector <GameObject*>::size_type i = 0; i != gameObjects.size(); i++)
	{
		gameObjects[i]->update();
	}
}
void Game::handleEvents() {
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

void Game::clean() {
	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(gameRenderer);
	SDL_Quit();
}

bool Game::running() {
	return isRunning;
}

