#include "UIPanel.h"

UIPanel::UIPanel()
{
	int headerHeight = 30;
	headerRect = RectangleShape(Vector2f(100, headerHeight));
	headerRect.setPosition(Vector2f(50, 50));
	headerRect.setFillColor(Color(60, 40, 130));
	mainRect = RectangleShape(Vector2f(100, 100));
	mainRect.setPosition(Vector2f(50, 50));
	mainRect.setFillColor(Color(0, 255, 0));
}

UIPanel::UIPanel(int x_, int y_, float width_, float height_)
{
	x = x_;
	y = y_;
	width = width_;
	height = height_;

	borders[0] = Sprite(storage.UITiles[0][0]);
	borders[0].setPosition(Vector2f(x, y));

	borders[1] = Sprite(storage.UITiles[2][0]);
	borders[1].setPosition(Vector2f(x + width - TILE_SIZE, y));

	borders[2] = Sprite(storage.UITiles[0][2]);
	borders[2].setPosition(Vector2f(x , y + height));

	borders[3] = Sprite(storage.UITiles[2][2]);
	borders[3].setPosition(Vector2f(x + width - TILE_SIZE, y + height));


	borders[4] = Sprite(storage.UITiles[1][0]);
	borders[4].setPosition(Vector2f(x + TILE_SIZE, y));
	borders[4].setScale(Vector2f((width - TILE_SIZE * 2) / TILE_SIZE,1));

	borders[5] = Sprite(storage.UITiles[2][1]);
	borders[5].setPosition(Vector2f(x + width - TILE_SIZE, y + TILE_SIZE));
	borders[5].setScale(Vector2f(1, (height - TILE_SIZE) / TILE_SIZE));

	borders[6] = Sprite(storage.UITiles[1][2]);
	borders[6].setPosition(Vector2f(x + TILE_SIZE, y + height));
	borders[6].setScale(Vector2f((width - TILE_SIZE * 2) / TILE_SIZE, 1));

	borders[7] = Sprite(storage.UITiles[0][1]);
	borders[7].setPosition(Vector2f(x, y + TILE_SIZE));
	borders[7].setScale(Vector2f(1, (height - TILE_SIZE) / TILE_SIZE));
	
	headerRect = RectangleShape(Vector2f(width, headerHeight));
	headerRect.setPosition(Vector2f(x, y));
	headerRect.setFillColor(Color(170, 160, 130));
	mainRect = RectangleShape(Vector2f(width, height));
	mainRect.setPosition(Vector2f(x, y + headerHeight));
	mainRect.setFillColor(Color(199, 181, 155));
}

void UIPanel::setPosition(int x, int y)
{
	borders[0].setPosition(Vector2f(x, y));
	borders[1].setPosition(Vector2f(x + width - TILE_SIZE, y));
	borders[2].setPosition(Vector2f(x, y + height));
	borders[3].setPosition(Vector2f(x + width - TILE_SIZE, y + height));
	borders[4].setPosition(Vector2f(x + TILE_SIZE, y));
	borders[5].setPosition(Vector2f(x + width - TILE_SIZE, y + TILE_SIZE));
	borders[6].setPosition(Vector2f(x + TILE_SIZE, y + height));
	borders[7].setPosition(Vector2f(x, y + TILE_SIZE));
	headerRect.setPosition(Vector2f(x, y));
	mainRect.setPosition(Vector2f(x, y + headerHeight));
}

void UIPanel::draw(RenderWindow& window)
{
	
	window.draw(mainRect);
	window.draw(headerRect);
	for (int i = 0; i < 8; i++)
	{
		window.draw(borders[i]);
	}
	storage.showText(window, "Text", headerRect.getPosition().x + 30, headerRect.getPosition().y + 20, 20, Color::Cyan);
}