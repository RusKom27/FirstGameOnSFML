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
	float coolDown = 0;
public:
	bool gizmo = false;
	bool showFps = false;
	int fps = 0;

	void showFPS(RenderWindow& window, float elapsed);
	void EventHandle(Event& event);
};

