#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.h"
#include "Storage.h"
#include "Debug.h"

using namespace sf;
using namespace std;


int main()
{
	

	Clock clock;

	ContextSettings settings;
	settings.antialiasingLevel = 0;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML Works!", Style::Default, settings);
	window.setFramerateLimit(200);

	Storage storage;
	Debug debug;
	GameMap map(WIDTH, HEIGHT, 50);
	int px = 0, py = 0;
	int mouseX = 0, mouseY = 0;

	while (window.isOpen())
	{
		int time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = 1000000/time;


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				return 0;
			}
			if (event.type == Event::MouseMoved)
			{
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::D)
				{
					if (px != 17)
						px += 1;
				}
				else if (event.key.code == Keyboard::A)
				{
					if (px != 0)
						px -= 1;
				}
				else if (event.key.code == Keyboard::W)
				{
					if (py != 0)
						py -= 1;
				}
				else if (event.key.code == Keyboard::S)
				{
					if (py != 11)
						py += 1;
				}
				else if (event.key.code == Keyboard::G)
					debug.gizmo = !debug.gizmo;
				else if (event.key.code == Keyboard::F)
					debug.showFps = !debug.showFps;
			}
		}
		window.clear(Color(25, 25, 25, 0));

		map.drawGrid(window);

		window.draw(map.cells[px][py].frontSprite);
		map.cells[px][py].frontSprite.setTexture(storage.frontTexture);
		map.cells[px][py].x = px;
		map.cells[px][py].y = py;

		if (debug.gizmo)
			map.drawGizmo(window, mouseX, mouseY);

		if (debug.showFps)
			debug.showFPS(window, time);

		window.display();
	}

	return 0;
}