#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"

using namespace sf;
using namespace std;

class UIPanel
{
private:
	Storage storage;
	float width = 0;
	float height = 0;
	float x = 0;
	float y = y;
	float headerHeight = 50;

public:
	RectangleShape mainRect;
	RectangleShape headerRect;
	Sprite borders[8];

	UIPanel();

	UIPanel(int x, int y, float width, float height);

	void draw(RenderWindow& window);

	void setPosition(int x, int y);
};

