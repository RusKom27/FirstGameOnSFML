#pragma once
#include "Storage.h"
#include "GameMap.h"
#include "UIContainer.h"
#include "UIInventoryPanel.h"
#include <boost/filesystem.hpp>
#include <iterator>
#include <set>


class TileInfo
{
public:
	string path;
	Vector2f position;
	Sprite frontSprite;
	Vector2f frontTextureCoord;
	Sprite backSprite;
	Vector2f backTextureCoord;
	Texture** textures;

	TileInfo(string path_, Vector2f position_, Vector2f frontTextureCoord_, Vector2f backTextureCoord_, Texture** textures_)
	{
		path = path_;
		position = position_;
		frontTextureCoord = frontTextureCoord_;
		backTextureCoord = backTextureCoord_;
		frontSprite.setPosition(position);
		backSprite.setPosition(position);
		textures = textures_;
	}

	void update()
	{
		frontSprite.setTexture(textures[static_cast<int>(frontTextureCoord.x)][static_cast<int>(frontTextureCoord.y)]);
		backSprite.setTexture(textures[static_cast<int>(backTextureCoord.x)][static_cast<int>(backTextureCoord.y)]);
	}
};

class MapEditor
{
private:
	View view;
	vector<vector<TileInfo>> tileMap;
	//GameMap* map;
	Storage storage;
	vector<Texture**> textures;
	Vector2f mouseCoords = Vector2f(0, 0);
	Vector2f oldMouseCoords = Vector2f(0, 0);
	bool leftMousePressed = false;
	bool rightMousePressed = false;
	bool drawCollisions = false;
	vector<string> maps;
	Vector2f chosenTexture;
	string chosenTileSet;
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
		//map = new GameMap();
		//map->buildEmptyMap();


		maps = getTileMaps();
		createTileMap();
		for (int i = 0; i < maps.size(); i++)
		{
			container.buttons.push_back(UIButton(Vector2f(WIDTH, 60 * i), Vector2f(150, 60), Border::Thin, to_string(i), ButtonEvent::None, false));
		}
		UIInventoryPanel inventory = UIInventoryPanel(Vector2f(10, 10), Vector2f(200, 600), Border::Thin, maps[1], 50, 10, true);
		container.inventoryPanels.push_back(inventory);
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

	void createTileMap()
	{
		int x = 0;
		int y = 0;

		for (int i = 0; i < TILES_COUNT_X; i++)
		{
			x = i * TILE_SIZE;
			tileMap.push_back(vector<TileInfo>());
			for (int j = 0; j < TILES_COUNT_Y; j++)
			{
				y = j * TILE_SIZE;

				tileMap[i].push_back(TileInfo(maps[1],Vector2f(x,y), Vector2f(1,1), Vector2f(1,1), textures[1]));
				tileMap[i][j].backSprite.setTexture(textures[1][1][1]);
				tileMap[i][j].frontSprite.setTexture(textures[1][1][1]);
			}
		}
	}

	void drawTileMap()
	{
		for (int i = 0; i < tileMap.size(); i++)
		{
			for (int j = 0; j < tileMap[i].size(); j++)
			{
				tileMap[i][j].update();
				window->draw(tileMap[i][j].backSprite);
				window->draw(tileMap[i][j].frontSprite);
			}
		}
	}

	vector<string> getTileMaps()
	{
		set<boost::filesystem::path> paths = getDirContents("Images\\");
		
		for (boost::filesystem::path path : paths)
		{
			maps.push_back(path.string());
		}
		for (int i = 0; i < maps.size(); i++)
		{
			Texture** texture;
			textures.push_back(texture);
			storage.getTexturesFromImage(textures[i], storage.loadImage(maps[i]));
		}
		return maps;
	}


	void drawTiles()
	{
		int x = static_cast<int>(mouseCoords.x) / TILE_SIZE;
		int y = static_cast<int>(mouseCoords.y) / TILE_SIZE;
		if (rightMousePressed)
		{
			tileMap[x][y].backTextureCoord = chosenTexture;
			tileMap[x][y].path = chosenTileSet;
		}
			
			//map->tiles[x][y].backSprite.setTexture(chosenTexture);
		if (leftMousePressed)
		{
			tileMap[x][y].frontTextureCoord = chosenTexture;
			tileMap[x][y].path = chosenTileSet;
		}
			
			//map->tiles[x][y].frontSprite.setTexture(chosenTexture);
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
					container.buttonsClickHandler(event, mouseCoords, chosenTexture, chosenTileSet);
					if (event.mouseButton.button == Mouse::Left) leftMousePressed = true;
					if (event.mouseButton.button == Mouse::Right) rightMousePressed = true;
				}
				else if (event.type == Event::MouseButtonReleased)
				{
					if (event.mouseButton.button == Mouse::Left) leftMousePressed = false;
					if (event.mouseButton.button == Mouse::Right) rightMousePressed = false;
				}
			}
			if (container.movePanels(mouseCoords, oldMouseCoords, leftMousePressed, rightMousePressed)) {}
			else drawTiles();

			container.update(mouseCoords);
			oldMouseCoords = mouseCoords;
		}
	}

	void draw()
	{
		drawTileMap();

		container.draw(*window);
	}
};



