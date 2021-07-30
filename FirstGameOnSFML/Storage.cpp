#include "Storage.h"


Storage::Storage()
{
	set<boost::filesystem::path> paths = getDirContents("Images\\");

	for (boost::filesystem::path path : paths)
	{
		maps.push_back(path.string());
	}
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

set<boost::filesystem::path> Storage::getDirContents(const string& dirName)
{
	set<boost::filesystem::path> paths;
	copy(boost::filesystem::directory_iterator(dirName), boost::filesystem::directory_iterator(), inserter(paths, paths.end()));

	return paths;
}


Image Storage::loadImage(string path)
{
	Image image;
	if (image.loadFromFile(path))
		cout << "Loaded " << path << endl;
	else
		cout << "ERROR loaded " << path << endl;
	return image;
}

void Storage::showText(RenderWindow& window, string txt, Vector2f position, int fontSize, Color color)
{
	Text text(txt, font, fontSize);

	text.setPosition(position);
	window.draw(text);
}

Vector2f Storage::getTexturesFromImage(Texture**& textures,Image image)
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
	return Vector2f(texturesCountX, texturesCountY);
}

float Storage::lerp(float a, float b, float f)
{
	return (a * (1.0f - f)) + (b * f);
}

