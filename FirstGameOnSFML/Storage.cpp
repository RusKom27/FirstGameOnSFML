#include "Storage.h"


Storage::Storage()
{
	loadImage(backTexture, "Tile1.png");
	loadImage(frontTexture, "EmptyTile.png");
	loadImage(heroTexture, "Hero.png");
	font.loadFromFile("Fonts\\PixelFont.ttf");
};

bool Storage::checkCollision(Vector2i obj1, int obj1Size, Vector2i obj2, int obj2Size)
{
	if (obj1.x < obj2.x + obj2Size && obj1.y < obj2.y + obj2Size && obj1.x + obj1Size > obj2.x && obj1.y + obj1Size > obj2.y)
		return true;
	else
		return false;
}

void Storage::loadImage(Texture& texture, string fileName)
{
	texture.loadFromFile("Images\\" + fileName);
}

void Storage::showText(RenderWindow& window, string txt, int x, int y, int fontSize, Color color)
{
	Text text(txt, font, fontSize);
	text.setPosition(x, y);
	window.draw(text);
}

Texture* Storage::getTexturesFromImage()
{
	Texture m[10];
	return m;
}

