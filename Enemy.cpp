#include "Enemy.h"
#include "TextureManager.h"

void Enemy::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* textureRenderer)
{
	TextureManager::Instance()->drawFrame(textureID, x_pos, y_pos, w, h, currentRow, currentFrame, textureRenderer);
}

void Enemy::update()
{
	y_pos += 1;
	x_pos += 1;

	currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean()
{
	GameObject::clean();
}