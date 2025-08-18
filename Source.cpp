#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>
#include "Game.h"

#include "vector2D.h"

Game* game = 0;

int main() {
	//Testing Vectors with print... yay
	Vector2D vec_01 = Vector2D(5, 10);
	Vector2D vec_02 = Vector2D(1, 2);
	std::cout << vec_01.getX() << "|" << vec_01.getY() << " " << &vec_01 << "\n";
	std::cout << vec_02.getX() << "|" << vec_02.getY() << " " << &vec_02 << "\n";
	Vector2D vec_03 = vec_01 - vec_02;
	std::cout << vec_03.getX() << "|" << vec_03.getY() << " " << &vec_03 << "\n";
	vec_02 -= vec_01;
	std::cout << vec_02.getX() << "|" << vec_02.getY() << " " << &vec_02 << "\n";
	
	std::cout << "Vec01:" << vec_01.getX() << "|" << vec_01.getY() << " " << &vec_01 << "\n";
	std::cout << "Vec01 length: " << vec_01.length() << "\n";
	vec_01.normalize();
	std::cout << "Vec01 normalized: " << vec_01.length() << "\n";
	return 0;

	try {
		TheGame::Instance()->init("SDL:Game Singleton", 800, 600, 0);

		// Game loop
		while (TheGame::Instance()->running()) {
			TheGame::Instance()->render();
			TheGame::Instance()->update();
			TheGame::Instance()->handleEvents();
			SDL_Delay(10);// cap framerate
		}
		
		TheGame::Instance()->clean();
		
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n" << "SDL error: " << SDL_GetError();
		return 1;
	}

	return 0;
}