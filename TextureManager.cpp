#include "TextureManager.h"

std::map<std::string, SDL_Texture*> textureMap;
TextureManager* TextureManager::theInstance = 0;

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

void TextureManager::draw(std::string id, float x_pos, float y_pos, float width, float height, SDL_Renderer* textureRenderer, SDL_FlipMode flip)
{
	SDL_FRect sourceRect = {};
	SDL_FRect targetRect = {};

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = targetRect.w = width;
	sourceRect.h = targetRect.h = height;
	
	targetRect.x = x_pos;
	targetRect.y = y_pos;

	SDL_RenderTextureRotated(textureRenderer, textureMap[id], &sourceRect, &targetRect, 0.0, NULL, flip);
};

void TextureManager::drawFrame(std::string id, float x_pos, float y_pos, float width, float height, int currentRow, int currentFrame, SDL_Renderer* textureRenderer, SDL_FlipMode flip)
{
	SDL_FRect sourceRect = {};
	SDL_FRect targetRect = {};

	sourceRect.x = width * currentFrame;
	sourceRect.y = height * (currentRow - 1);
	sourceRect.w = targetRect.w = width;
	sourceRect.h = targetRect.h = height;

	targetRect.x = x_pos;
	targetRect.y = y_pos;

	SDL_RenderTextureRotated(textureRenderer, textureMap[id], &sourceRect, &targetRect, 0.0, NULL, flip);
}