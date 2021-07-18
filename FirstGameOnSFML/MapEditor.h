#pragma once
#include "Storage.h"
#include "GameMap.h"
#include "UIPanel.h"

class MapEditor
{
private:
	RenderWindow* window;
	GameMap* map;
	Storage storage;
	Vector2f mouseCoords = Vector2f(0, 0);
	Vector2f oldMouseCoords = Vector2f(0, 0);
	bool leftMousePressed = false;
	bool rightMousePressed = false;
	bool drawCollisions = false;
	Texture chosenBackTexture;
	Texture chosenFrontTexture;
	UIPanel panel;

public:
	MapEditor() 
	{
		map = new GameMap();
		map->buildEmptyMap();
		panel = UIPanel(WIDTH/2, 10, 410, 320);
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
				else if (event.type == Event::Resized)
				{
				}
				else if (event.type == Event::MouseMoved)
				{
					mouseCoords = Vector2f(Mouse::getPosition(*window));
					//mouseCoords = Vector2f(event.mouseMove.x, event.mouseMove.y);
				}
				else if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == Mouse::Left) leftMousePressed = true;
					if (event.mouseButton.button == Mouse::Right) rightMousePressed = true;
				}
				else if (event.type == Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == Mouse::Left) leftMousePressed = false;
					if (event.mouseButton.button == Mouse::Right) rightMousePressed = false;
				}
			}
			if (leftMousePressed)
			{
				if (storage.checkCollision(panel.headerRect.getPosition(), panel.headerRect.getSize(), mouseCoords, Vector2f(0,0)))
					panel.setPosition(
						panel.headerRect.getPosition().x - (oldMouseCoords.x - mouseCoords.x),
						panel.headerRect.getPosition().y - (oldMouseCoords.y - mouseCoords.y));
				else
					drawTiles();
				
			}
			if (rightMousePressed)
			{
				drawTiles();
			}

			oldMouseCoords = mouseCoords;
			printf("%f   %f\n", mouseCoords.x, mouseCoords.y);
		}
	}


	void drawTiles()
	{
		for (int i = 0; i < TILES_COUNT_X; i++)
		{
			for (int j = 0; j < TILES_COUNT_Y; j++)
			{
				if (storage.checkCollision(Vector2f(map->tiles[i][j].x, map->tiles[i][j].y), Vector2f(TILE_SIZE, TILE_SIZE), mouseCoords, Vector2f(0, 0)))
				{
					if (rightMousePressed)
						map->tiles[i][j].backSprite.setTexture(chosenBackTexture);
					if (leftMousePressed)
						map->tiles[i][j].backSprite.setTexture(chosenFrontTexture);
				}
			}
		}
	}

	void draw()
	{
		map->drawMap(*window);
		panel.draw(*window);
	}
};



