#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>


#define arraySize(a) (sizeof(a)/sizeof((a)[0]))

using namespace sf;
using namespace std;


const int WIDTH = 1200;
const int HEIGHT = 700;
const int TILE_SIZE = 50;
const int TILES_COUNT_X = WIDTH / TILE_SIZE;
const int TILES_COUNT_Y = HEIGHT / TILE_SIZE;


class Storage
{
public:
	
	Texture** backTextures;
	Texture** UITiles;
	Texture** frontTextures;

	Font font;
	
	Storage();

	bool checkCollision(Vector2f obj1, Vector2f obj1Size, Vector2f obj2, Vector2f obj2Size);
	Vector2f getLocalCoords(Vector2f obj1, Vector2f obj1Size, Vector2f obj2, Vector2f obj2Size);
	Image loadImage(string fileName);
	Image* loadImages(int filenames[]);
	void showText(RenderWindow& window, string txt, int x, int y, int fontSize, Color color);
	int getTexturesFromImage(Texture**& textures, Image image);
};