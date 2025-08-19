#include "InputHandler.h"

InputHandler* TheInputHandler::Instance() {
	if (instance == 0)
	{
		instance = new InputHandler();
	}
	return instance;
}

void TheInputHandler::update ()
{
}

void TheInputHandler::clean()
{

}