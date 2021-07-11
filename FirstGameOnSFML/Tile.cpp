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

	RectangleShape rect;

	

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
		rect.setSize(Vector2f(size, size));
		rect.setOutlineThickness(0.5f);
		rect.setOutlineColor(Color(200, 200, 200));
		rect.setPosition(x, y);
	};

};
