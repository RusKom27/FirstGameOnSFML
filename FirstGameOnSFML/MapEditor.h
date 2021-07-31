#pragma once

#include "Storage.h"
#include "UIContainer.h"
#include "UIInventoryPanel.h"



class TileInfo
{
public:
	int tileSetId;
	Vector2f position;
	Sprite frontSprite;
	Vector2f frontTextureCoord;
	Sprite backSprite;
	Vector2f backTextureCoord;
	Texture** frontTextures;
	Texture** backTextures;

	TileInfo(Vector2f position_, Vector2f frontTextureCoord_, Vector2f backTextureCoord_, Texture** textures_);

	void update();
};

class MapEditor
{
private:
	View view;
	UIContainer container;
	Storage storage;

	vector<vector<TileInfo>> tileMap;
	vector<Texture**> textures;

	Vector2f mouseCoords = Vector2f(0, 0);
	Vector2f oldMouseCoords = Vector2f(0, 0);
	bool leftMousePressed = false;
	bool rightMousePressed = false;
	bool drawCollisions = false;
	Vector2f chosenTexture;
	int chosenTileSetId;
	
public:
	RenderWindow* window;

	MapEditor();

	void createWindow();

	void createTileMap();

	void drawTileMap();

	void getTileMaps();

	void drawTiles();

	void saveTileMap();

	void update(float time);

	void draw();
};



