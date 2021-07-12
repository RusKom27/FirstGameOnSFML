#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tile.h"
#include "Storage.h"

using namespace sf;
using namespace std;



class GameMap
{
private:
	Storage storage;
public:

	float width;
	float height;
	float cellSize;
	Tile cells[CELLS_COUNT_X][CELLS_COUNT_Y];

	GameMap();

	GameMap(float w, float h, float cS);

	void setGrid();

	void drawGizmo(RenderWindow& window, int mouseX, int mouseY);

	void drawGrid(RenderWindow& window);
};