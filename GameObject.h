#pragma once
#include <iostream>

class GameObject
{
public:
	void draw() {
		std::cout << "Object: Draw!" << "\n";
	}
	void update() {
		std::cout << "Object: Update!" << "\n";
	}
	void clean() {
		std::cout << "Object: Clean!" << "\n";
	}
protected:
	int x_pos = 0;
	int y_pos = 0;
};

