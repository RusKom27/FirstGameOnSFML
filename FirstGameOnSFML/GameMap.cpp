
#include <iostream>
#include "Tile.cpp"

using namespace sf;
using namespace std;

const int CELLS_COUNT_X = 18; // width / cellSize
const int CELLS_COUNT_Y = 13; // height / cellSize

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
			x = column * 50;
			for (int row = 0; row < CELLS_COUNT_Y; row++)
			{
				y = row * 50;
				cells[column][row] = Tile(x,y,cellSize);
			}
			
		}
	}

};

