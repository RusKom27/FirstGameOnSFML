#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tile.h"
#include "Storage.h"
#include "tinyxml2.h"
#include "Enemy.h"
#include "Player.h"

using namespace sf;
using namespace std;
using namespace tinyxml2;

class GameMap
{
private:
	Storage storage;
public:
	vector<Enemy> enemies;
	Player player;

	Tile tiles[TILES_COUNT_X][TILES_COUNT_Y];

	GameMap();

	void setGrid();

	void drawMap(RenderWindow& window);

	void loadMap(const char* name);

	void update(bool trigger);
};