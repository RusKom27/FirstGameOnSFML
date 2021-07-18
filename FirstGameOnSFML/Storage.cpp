#include "Storage.h"


Storage::Storage()
{
	getTexturesFromImage(backTextures, loadImage("BackTileSet.png"));
	getTexturesFromImage(frontTextures, loadImage("FrontTileSet.png"));
	getTexturesFromImage(UITiles, loadImage("UITiles.png"));
	font.loadFromFile("Fonts\\PixelFont.ttf");
};

bool Storage::checkCollision(Vector2f obj1, Vector2f obj1Size, Vector2f obj2, Vector2f obj2Size)
{
	if (obj1.x < obj2.x + obj2Size.x && obj1.y < obj2.y + obj2Size.y && obj1.x + obj1Size.x > obj2.x && obj1.y + obj1Size.y > obj2.y)
		return true;
	else
		return false;
}

Vector2f Storage::getLocalCoords(Vector2f obj1, Vector2f obj1Size, Vector2f obj2, Vector2f obj2Size)
{
	return Vector2f(0,0);
}


Image Storage::loadImage(string fileName)
{
	Image image;
	image.loadFromFile("Images\\" + fileName);
	return image;
}

Image* Storage::loadImages(int filenames[])
{
	for (int i = 0; i < arraySize(filenames); i++)
	{
		cout << i << endl;
	}
	Image* images = new Image[3];
	return images;
}

void Storage::showText(RenderWindow& window, string txt, int x, int y, int fontSize, Color color)
{
	Text text(txt, font, fontSize);
	text.setPosition(x, y);
	window.draw(text);
}

int Storage::getTexturesFromImage(Texture**& textures,Image image)
{
	int texturesCountX = image.getSize().x / TILE_SIZE;
	int texturesCountY = image.getSize().y / TILE_SIZE;
	textures = new Texture*[texturesCountX];
	for (int i = 0; i < texturesCountX; i++)
	{
		textures[i] = new Texture[texturesCountY];
		for (int j = 0; j < texturesCountY; j++)
		{
			textures[i][j].loadFromImage(image, IntRect(TILE_SIZE * i, TILE_SIZE * j, TILE_SIZE, TILE_SIZE));
		}
	}
	return texturesCountX * texturesCountY;
}

