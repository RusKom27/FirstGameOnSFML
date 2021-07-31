#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <functional>
#include "tinyxml2.h"
#include <boost/filesystem.hpp>
#include <iterator>
#include <set>

#define arraySize(a) (sizeof(a)/sizeof((a)[0]))

using namespace sf;
using namespace std;
using namespace tinyxml2;


const int WIDTH = 1200;
const int HEIGHT = 700;
const int TILE_SIZE = 50;
const int TILES_COUNT_X = WIDTH / TILE_SIZE;
const int TILES_COUNT_Y = HEIGHT / TILE_SIZE;


class Storage
{
public:
	Font font;
	vector<string> maps;
	
	Storage();

	bool checkCollision(Vector2f obj1, Vector2f obj1Size, Vector2f obj2, Vector2f obj2Size);
	Vector2f getLocalCoords(Vector2f obj1, Vector2f obj1Size, Vector2f obj2, Vector2f obj2Size);
	Image loadImage(string path);
	void showText(RenderWindow& window, string txt, Vector2f position, int fontSize, Color color);
	Vector2f getTexturesFromImage(Texture**& textures, Image image);
	float lerp(float a, float b, float f);
	set<boost::filesystem::path> getDirContents(const string& dirName);
};