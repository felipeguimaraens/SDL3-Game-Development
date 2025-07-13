#pragma once
#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <map>

class TextureManager {
public:
	bool load(std::string fileName, std::string id, SDL_Renderer* textureRenderer);
	void draw(std::string id, int x_pos, int y_pos, int width, int height, SDL_Renderer* textureRenderer, SDL_FlipMode flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x_pos, int y_pos, int width, int height, int currentRow, int currentFrame, SDL_Renderer* textureRenderer, SDL_FlipMode flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture*> textureMap;
};

	



	




