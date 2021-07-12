#include "GameMap.h"

GameMap::GameMap() 
{
	width = 900;
	height = 600;
	cellSize = 50;
	setGrid();
};

GameMap::GameMap(float w, float h, float cS)
{
	width = w;
	height = h;
	cellSize = cS;
	setGrid();
};


void GameMap::setGrid()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < CELLS_COUNT_X; i++)
	{
		x = i * cellSize;
		for (int j = 0; j < CELLS_COUNT_Y; j++)
		{
			y = j * cellSize;
			cells[i][j] = Tile(x,y,cellSize);
			cells[i][j].backSprite.setTexture(storage.backTexture);
			cells[i][j].frontSprite.setTexture(storage.frontTexture);
		}
	}
}

void GameMap::drawGizmo(RenderWindow& window, int mouseX, int mouseY)
{
	for (int i = 0; i < CELLS_COUNT_X; i++)
	{
		for (int j = 0; j < CELLS_COUNT_Y; j++)
		{
			window.draw(cells[i][j].Rect);
			cells[i][j].Highlight();
			if (storage.checkCollision(Vector2i(cells[i][j].x, cells[i][j].y), cells[i][j].size, Vector2i(mouseX, mouseY), 0))
			{
				cells[i][j].Select();
			}
		}
	}
}

void GameMap::drawMap(RenderWindow &window)
{
	for (int i = 0; i < CELLS_COUNT_X; i++)
	{
		for (int j = 0; j < CELLS_COUNT_Y; j++)
		{
			window.draw(cells[i][j].backSprite);
			
			window.draw(cells[i][j].frontSprite);
			cells[i][j].frontSprite.setTexture(storage.frontTexture);
		}
	}
}