#include "MapEditor.h"


TileInfo::TileInfo(Vector2f position_, Vector2f frontTextureCoord_, Vector2f backTextureCoord_, Texture** textures_)
{
	position = position_;
	frontTextureCoord = frontTextureCoord_;
	backTextureCoord = backTextureCoord_;
	frontSprite.setPosition(position);
	backSprite.setPosition(position);
	frontTextures = textures_;
	backTextures = textures_;
}

void TileInfo::update()
{
	frontSprite.setTexture(frontTextures[static_cast<int>(frontTextureCoord.x)][static_cast<int>(frontTextureCoord.y)]);
	backSprite.setTexture(backTextures[static_cast<int>(backTextureCoord.x)][static_cast<int>(backTextureCoord.y)]);
}

MapEditor::MapEditor()
{
	getTileMaps();
	createTileMap();
	for (int i = 0; i < storage.maps.size(); i++)
	{
		container.buttons.push_back(UIButton(Vector2f(WIDTH, 60 * i), Vector2f(60, 60), Border::Thin, to_string(i), ButtonEvent::SetTileSet, false));
	}
}

void MapEditor::createWindow()
{
	if (!window)
	{
		window = new RenderWindow(VideoMode::getFullscreenModes()[0], "Map Editor");
		window->setPosition(Vector2i(0, 0));
		View view = window->getDefaultView();
		view.setCenter(Vector2f(0, 0));
	}
}

void MapEditor::createTileMap()
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
			tileMap[i].push_back(TileInfo(Vector2f(x, y), Vector2f(3, 1), Vector2f(1, 1), textures[0]));
		}
	}
}

void MapEditor::drawTileMap()
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



void MapEditor::getTileMaps()
{
	for (int i = 0; i < storage.maps.size(); i++)
	{
		Texture** texture;
		textures.push_back(texture);
		storage.getTexturesFromImage(textures[i], storage.loadImage(storage.maps[i]));
	}
}


void MapEditor::drawTiles()
{
	int x = static_cast<int>(mouseCoords.x) / TILE_SIZE;
	int y = static_cast<int>(mouseCoords.y) / TILE_SIZE;

	if (x >= 0 && x < TILES_COUNT_X && y >= 0 && y < TILES_COUNT_Y)
	{
		if (rightMousePressed)
		{
			tileMap[x][y].backTextures = textures[chosenTileSetId];
			tileMap[x][y].backTextureCoord = chosenTexture;
			tileMap[x][y].tileSetId = chosenTileSetId;
		}
		if (leftMousePressed)
		{
			tileMap[x][y].frontTextures = textures[chosenTileSetId];
			tileMap[x][y].frontTextureCoord = chosenTexture;
			tileMap[x][y].tileSetId = chosenTileSetId;
		}
	}

}

void MapEditor::saveTileMap()
{
	set<boost::filesystem::path> paths = storage.getDirContents("Maps\\");
	XMLDocument doc;
	XMLElement* root = doc.RootElement();
	doc.InsertFirstChild(doc.NewElement("map"));
	doc.SaveFile("Maps\\Map_0_1.xml");
}

void MapEditor::update(float time)
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
				if (container.buttonsClickHandler(mouseCoords)) {}
				else if (container.inventoryButtonsClickHandler(mouseCoords, chosenTexture, chosenTileSetId)) {}
				else
				{
					if (event.mouseButton.button == Mouse::Left) leftMousePressed = true;
					if (event.mouseButton.button == Mouse::Right) rightMousePressed = true;
				}
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == Mouse::Left) leftMousePressed = false;
				if (event.mouseButton.button == Mouse::Right) rightMousePressed = false;
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::RControl)
					saveTileMap();
			}
		}
		if (container.movePanels(mouseCoords, oldMouseCoords, leftMousePressed, rightMousePressed)) {}
		else drawTiles();

		container.update(mouseCoords);
		oldMouseCoords = mouseCoords;
	}
}

void MapEditor::draw()
{
	drawTileMap();

	container.draw(*window);
}