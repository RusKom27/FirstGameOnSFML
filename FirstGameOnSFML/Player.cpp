#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Player
{
public:
	float x;
	float y;
	string tag;

	Player()
	{
		x = 0;
		y = 0;
	};

	Player(float X, float Y) {
		x = X;
		y = Y;
	};

};