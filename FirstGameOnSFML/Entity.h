#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Entity
{
public:
	int x;
	int y;
	
	Entity();

	Entity(int X, int Y);
};

