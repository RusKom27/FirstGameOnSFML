#include "GameMap.h"

GameMap::GameMap(float w, float h, float cS)
{
	width = w;
	height = h;
	tileSize = cS;
	setGrid();
};

void GameMap::setGrid()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < TILES_COUNT_X; i++)
	{
		x = i * tileSize;
		for (int j = 0; j < TILES_COUNT_Y; j++)
		{
			y = j * tileSize;
			tiles[i][j] = Tile(x,y,tileSize);
		}
	}
}

void GameMap::drawMap(RenderWindow &window)
{
	for (int i = 0; i < TILES_COUNT_X; i++)
	{
		for (int j = 0; j < TILES_COUNT_Y; j++)
		{
			window.draw(tiles[i][j].backSprite);
			
			window.draw(tiles[i][j].frontSprite);
		}
	}
}

void GameMap::loadMap(const char* name)
{

	int i = 0, j = 0;
	XMLDocument doc;
	XMLError eResult = doc.LoadFile(name);
	if (eResult == 0) cout << "Loaded map: " << name << endl;
	else cout << "Error "<< XMLError( eResult) <<": " << name << endl;

	//doc.Print();
	XMLElement* root = doc.FirstChildElement();
	XMLElement* row = root->FirstChildElement("row");
	
	while (row)
	{
		XMLElement* tile = row->FirstChildElement("tile");
		//printf("Row:%i\tBackId:\tFrontId:\tX:\tY:\n", i);
		while (tile)
		{
			//printf("\t%i\t%i\t\t%i\t%i\n", tile->IntAttribute("back"), tile->IntAttribute("front"), i, j);
			switch (tile->IntAttribute("back"))
			{
			case 1:
				tiles[i][j].backSprite.setTexture(storage.backTextures[0][2]);
				break;
			default:
				tiles[i][j].backSprite.setTexture(storage.backTextures[1][1]);
				break;
			}
			switch (tile->IntAttribute("front"))
			{
			case 1:
				break;
			default:
				tiles[i][j].frontSprite.setTexture(storage.backTextures[0][6]);
				break;
			}
			tile = tile->NextSiblingElement("tile");
			j++;
		}
		//printf("\n");
		row = row->NextSiblingElement("row");
		i++;
		j = 0;
	}
}


