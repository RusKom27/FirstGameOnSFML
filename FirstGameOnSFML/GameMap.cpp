#include "GameMap.h"

GameMap::GameMap()
{
	setGrid();
	storage.getTexturesFromImage(backTextures, storage.loadImage("Images\\BackTileSet.png"));
	storage.getTexturesFromImage(frontTextures, storage.loadImage("Images\\FrontTileSet.png"));
};

void GameMap::setGrid()
{
	int x = 0;
	int y = 0;
	for (int i = 0; i < TILES_COUNT_X; i++)
	{
		x = i * TILE_SIZE;
		for (int j = 0; j < TILES_COUNT_Y; j++)
		{
			y = j * TILE_SIZE;
			tiles[i][j] = Tile(x,y,TILE_SIZE);
		}
	}
}

void GameMap::setPosition(Vector2f coords)
{
	int x = coords.x;
	int y = coords.y;
	for (int i = 0; i < TILES_COUNT_X; i++)
	{
		x = i * TILE_SIZE;
		for (int j = 0; j < TILES_COUNT_Y; j++)
		{
			y = j * TILE_SIZE;
			tiles[i][j].x = x;
			tiles[i][j].y = y;
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
	for (int i = 0; i < enemies.size(); i++)
	{
		window.draw(enemies[i].sprite);
	}
	window.draw(player.sprite);
}

void GameMap::buildEmptyMap()
{
	for (int i = 0; i < TILES_COUNT_X; i++)
	{
		for (int j = 0; j < TILES_COUNT_Y; j++)
		{
			tiles[i][j].backSprite.setTexture(backTextures[1][1]);
			tiles[i][j].frontSprite.setTexture(backTextures[0][6]);
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

	XMLElement* root = doc.FirstChildElement();
	XMLElement* row = root->FirstChildElement("row");
	
	while (row)
	{
		XMLElement* tile = row->FirstChildElement("tile");
		while (tile)
		{
			switch (tile->IntAttribute("back"))
			{
			case 1:
				tiles[i][j].backSprite.setTexture(backTextures[0][2]);
				break;
			default:
				tiles[i][j].backSprite.setTexture(backTextures[1][1]);
				break;
			}
			switch (tile->IntAttribute("front"))
			{
			case 1:
				enemies.push_back(Enemy(i, j, frontTextures[1], 3, 0.3));
				break;
			case 8:
				player = Player(i, j, frontTextures[8], 6, 0.3f);
				break;
			default:
				tiles[i][j].frontSprite.setTexture(backTextures[0][6]);
				break;
			}
			switch (tile->BoolAttribute("collision"))
			{
			case true:
				collisions.push_back(Vector2i(i * TILE_SIZE, j * TILE_SIZE));
				break;
			default:
				break;
			}
			tile = tile->NextSiblingElement("tile");
			j++;
		}
		row = row->NextSiblingElement("row");
		i++;
		j = 0;
	}
}

void GameMap::update(bool trigger)
{
	
	if (trigger)
	{
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].move();
		}
	}
	
}

