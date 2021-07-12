#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


const int WIDTH = 900;
const int HEIGHT = 600;
const int CELLS_COUNT_X = 18; // width / cellSize
const int CELLS_COUNT_Y = 13; // height / cellSize

class Storage
{
public:
	Texture backTexture;
	Texture frontTexture;
	Font font;
	
	Storage();

	bool checkCollision(Vector2i obj1, int obj1Size, Vector2i obj2, int obj2Size);
	void loadImage(Texture& texture, string fileName);
	void showText(RenderWindow& window, string txt, int x, int y, int fontSize, Color color);
	Texture* getTexturesFromImage();

	
};