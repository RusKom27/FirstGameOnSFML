#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.h"

using namespace sf;
using namespace std;


class Entity
{
private:
	Storage storage;
public:
	int x;
	int y;
	Texture texture;

	Entity();

	Entity(int X, int Y);

	void draw(GameMap& map);

	void update(int time);
};

