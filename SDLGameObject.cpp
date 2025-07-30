#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.cpp"

SDLGameObject::SDLGameObject(const LoaderParams* Parameters) : GameObject(Parameters) {
	x_pos = Parameters->getX();
	y_pos = Parameters->getY();
	width = Parameters->getWidth();
	height = Parameters->getHeight();
	textureID = Parameters->getTexture();

	currentRow = 1;
	currentFrame = 1;
}

void SDLGameObject::draw() {
	TextureManager::Instance()->drawFrame(textureID, x_pos, y_pos, width, height, currentRow, currentFrame, TheGame::Instance()->getRenderer());
}