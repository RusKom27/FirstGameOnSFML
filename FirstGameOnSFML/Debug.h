#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"

using namespace sf;
using namespace std;

class Debug
{
private:
	Storage storage;
	int coolDown = 0;
public:
	bool gizmo = false;
	bool showFps = false;
	int fps = 0;

	void showFPS(RenderWindow& window, int time);
};

