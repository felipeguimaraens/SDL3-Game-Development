#include "TextureManager.h"

std::map<std::string, SDL_Texture*> textureMap;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* textureRenderer)
{
	SDL_Surface* TempSurface = IMG_Load(fileName.c_str());

	if (TempSurface == 0) {
		return 0;
	}

	SDL_Texture* Texture = SDL_CreateTextureFromSurface(textureRenderer, TempSurface);
	SDL_DestroySurface(TempSurface);

	if(Texture != 0){
		textureMap[id] = Texture;
		return true;
	}

	return false;
};

void TextureManager::draw(std::string id, int x_pos, int y_pos, int width, int height, SDL_Renderer* textureRenderer, SDL_FlipMode flip)
{

};

void TextureManager::drawFrame(std::string id, int x_pos, int y_pos, int width, int height, int currentRow, int currentFrame, SDL_Renderer* textureRenderer, SDL_FlipMode flip)
{

}