#include "Tile.h"

Tile::Tile() 
{
	x = 0;
	y = 0;
	size = 0;
};

Tile::Tile(float X, float Y, float Size) {
	x = X;
	y = Y;
	size = Size;
	Rect.setSize(Vector2f(size, size));
	Rect.setPosition(x, y);

	frontSprite.setPosition(x, y);
	backSprite.setPosition(x, y);
};