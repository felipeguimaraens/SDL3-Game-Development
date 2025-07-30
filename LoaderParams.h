#pragma once
#include <string>

class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string textureID) : x_pos(x), y_pos(y), w(width), h(height), textureID(textureID) {}
	int getX() const { return x_pos; }
	int getY() const { return y_pos; }
	int getWidth() const { return w; }
	int getHeight() const { return h; }
	std::string getTexture() const { return textureID; }
private:
	int x_pos;
	int y_pos;

	int w;
	int h;

	std::string textureID;
};

