#include "Tile.h"

Tile::Tile() 
{
	x = 0;
	y = 0;
};

Tile::Tile(float X, float Y, float size) {
	x = X;
	y = Y;
	Rect.setSize(Vector2f(size, size));
	Rect.setPosition(x, y);

	frontSprite.setPosition(x, y);
	backSprite.setPosition(x, y);
};