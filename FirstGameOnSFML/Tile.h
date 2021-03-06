#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Tile
{
public:
	float x;
	float y;

	RectangleShape Rect;
	Sprite backSprite;
	Sprite frontSprite;

	Tile();

	Tile(float X, float Y, float size);
};