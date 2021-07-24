#pragma once
#include "Storage.h"
#include "GameMap.h"
#include "UIContainer.h"
#include "UIInventoryPanel.h"
#include <boost/filesystem.hpp>
#include <iterator>
#include <set>


struct TileInfo
{
	string path;
	Vector2f frontTextureCoord;
	Vector2f backTextureCoord;
};

class MapEditor
{
private:
	View view;
	GameMap* map;
	Storage storage;
	Vector2f mouseCoords = Vector2f(0, 0);
	Vector2f oldMouseCoords = Vector2f(0, 0);
	bool leftMousePressed = false;
	bool rightMousePressed = false;
	bool drawCollisions = false;
	Texture chosenBackTexture;
	Texture chosenFrontTexture;
	UIContainer container;

public:
	RenderWindow* window;

	set<boost::filesystem::path> getDirContents(const string& dirName)
	{
		set<boost::filesystem::path> paths;
		copy(boost::filesystem::directory_iterator(dirName), boost::filesystem::directory_iterator(), inserter(paths, paths.end()));

		return paths;
	}

	MapEditor() 
	{
		map = new GameMap();
		map->buildEmptyMap();
		//container.createPanel(Vector2f(WIDTH / 2, 10), Vector2f(410, 200), Border::Thin, "TEST", true);
		container.createButton(Vector2f(WIDTH, 10), Vector2f(150, 60), Border::Thin, "OK", ButtonEvent::None);
		vector<string> maps = getTileMaps();
		
		UIInventoryPanel inventory = UIInventoryPanel(Vector2f(10, 10), Vector2f(200, 600), Border::Thin, maps[2], 50, true);
		container.panels.push_back(inventory);
	}

	void createWindow()
	{
		if (!window)
		{
			window = new RenderWindow(VideoMode::getFullscreenModes()[0], "Map Editor");
			window->setPosition(Vector2i(0, 0));
			View view = window->getDefaultView();
			view.setCenter(Vector2f(0, 0));
		}
	}

	vector<string> getTileMaps()
	{
		vector<string> maps;
		set<boost::filesystem::path> paths = getDirContents("Images\\");
		for (boost::filesystem::path path : paths)
		{
			maps.push_back(path.string());
		}
		return maps;
	}


	void drawTiles()
	{
		int x = static_cast<int>(mouseCoords.x) / TILE_SIZE;
		int y = static_cast<int>(mouseCoords.y) / TILE_SIZE;
		if (rightMousePressed)
			map->tiles[x][y].backSprite.setTexture(chosenBackTexture);
		if (leftMousePressed)
			map->tiles[x][y].backSprite.setTexture(chosenFrontTexture);
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
					view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
					view.setCenter(static_cast<float>(event.size.width) / 2, static_cast<float>(event.size.height) / 2);
					window->setView(view);
				}
				else if (event.type == Event::MouseMoved)
				{
					mouseCoords = Vector2f(Mouse::getPosition(*window));
				}
				else if (event.type == Event::MouseButtonPressed)
				{
					container.buttonsClickHandler(event, mouseCoords);
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
				
				if (container.movePanels(mouseCoords, oldMouseCoords))
				{

				}
				else
					drawTiles();
				
			}
			if (rightMousePressed)
			{
				drawTiles();
			}

			container.update(mouseCoords);
			oldMouseCoords = mouseCoords;
		}
	}

	void draw()
	{
		map->drawMap(*window);
		container.draw(*window);
	}
};



