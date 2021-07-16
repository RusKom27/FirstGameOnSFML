#pragma once
#include "Storage.h"
#include "GameMap.h"

class MapEditor
{
private:
	RenderWindow* window;
	GameMap* map;
	Storage storage;
	int mouseX = 0;
	int mouseY = 0;
	bool leftMousePressed = false;
	bool rightMousePressed = false;
	bool drawCollisions = false;
	Texture* chosenBackTexture;
	Texture* chosenFrontTexture;

public:
	MapEditor() 
	{
		map = new GameMap();
		map->buildEmptyMap();
	}

	void createWindow()
	{
		if (!window)
		{
			window = new RenderWindow(VideoMode(WIDTH + 150, HEIGHT), "Map Editor");
			window->setPosition(Vector2i(0, 0));
		}
	}

	void update(float time)
	{
		if (window)
		{
			window->clear(Color(25, 25, 25, 0));
			draw();
			window->display();
			Event event;
			if (window->pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window->close();
					window = NULL;
				}
				if (event.type == Event::MouseMoved)
				{
					mouseX = event.mouseMove.x;
					mouseY = event.mouseMove.y;
				}
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left) leftMousePressed = true;
					if (event.mouseButton.button == Mouse::Right) rightMousePressed = true;
				}
				if (event.type == Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == Mouse::Left) leftMousePressed = false;
					if (event.mouseButton.button == Mouse::Right) rightMousePressed = false;
				}
			}
			drawTiles();
		}
	}

	void drawTiles()
	{
		for (int i = 0; i < TILES_COUNT_X; i++)
		{
			for (int j = 0; j < TILES_COUNT_Y; j++)
			{
				if (storage.checkCollision(Vector2i(map->tiles[i][j].x, map->tiles[i][j].y), TILE_SIZE, Vector2i(mouseX, mouseY), 0))
				{
					if (rightMousePressed)
						map->tiles[i][j].backSprite.setTexture(storage.backTextures[1][1]);
					if (leftMousePressed)
						map->tiles[i][j].backSprite.setTexture(storage.backTextures[0][0]);
				}
			}
		}
	}

	void draw()
	{
		map->drawMap(*window);
	}
};

