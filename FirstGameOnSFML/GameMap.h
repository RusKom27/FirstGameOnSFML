#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tile.h"
#include "Storage.h"
#include "tinyxml2.h"

using namespace sf;
using namespace std;
using namespace tinyxml2;

class GameMap
{
private:
	Storage storage;
public:

	float width;
	float height;
	float tileSize;
	Tile tiles[TILES_COUNT_X][TILES_COUNT_Y];

	GameMap(float w, float h, float cS);

	void setGrid();

	void drawMap(RenderWindow& window);

	void loadMap(const char* name);
};