
#include <iostream>
#include "Tile.cpp"

using namespace sf;
using namespace std;

const int CELLS_COUNT_X = 19; // width / cellSize
const int CELLS_COUNT_Y = 16; // height / cellSize

class GameMap
{
private:
	

public:
	
	int width;
	int height;
	int cellSize;
	Tile cells[CELLS_COUNT_X][CELLS_COUNT_Y];

	GameMap() 
	{
		width = 900;
		height = 600;
		cellSize = 50;
		setGrid();
	};

	GameMap(int w, int h, int cS)
	{
		width = w;
		height = h;
		cellSize = cS;
		setGrid();
	};

	void setGrid()
	{
		int x = 0;
		int y = 0;
		for (int column = 0; column < CELLS_COUNT_X; column++)
		{
			for (int row = 0; row < CELLS_COUNT_Y; row++)
			{
				y = row * 50;
				cells[column][row] = Tile(x,y,cellSize);
			}
			x = column * 50;
		}
	}

};

