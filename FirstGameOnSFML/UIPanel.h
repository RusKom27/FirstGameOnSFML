#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class UIPanel
{
public:
	RectangleShape rect;

	UIPanel();

	UIPanel(int x, int y, int width, int height);

	void draw(RenderWindow& window);
};

