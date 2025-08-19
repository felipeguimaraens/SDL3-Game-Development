#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoaderParams* Parameters) : GameObject(Parameters), position(Parameters->getX(), Parameters->getY()), velocity(0, 0), acceleration(0, 0) {

	width = Parameters->getWidth();
	height = Parameters->getHeight();
	textureID = Parameters->getTexture();

	currentRow = 1;
	currentFrame = 1;
}

void SDLGameObject::draw() {
	TextureManager::Instance()->drawFrame(textureID, (float)position.getX(), (float)position.getY(), width, height, currentRow, currentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update() {
	velocity += acceleration;
	position += velocity;
}

void SDLGameObject::clean() {

}