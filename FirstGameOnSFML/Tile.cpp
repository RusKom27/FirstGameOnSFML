#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Tile
{
public:
	float x;
	float y;
	float size;

	RectangleShape Rect;
	Sprite backSprite;
	Sprite frontSprite;
	

	Tile() 
	{
		x = 0;
		y = 0;
		size = 0;
	};

	Tile(float X, float Y, float Size) {
		x = X;
		y = Y;
		size = Size;
		Rect.setSize(Vector2f(size, size));
		Rect.setPosition(x, y);

		frontSprite.setPosition(x, y);
		backSprite.setPosition(x, y);

	};

};
