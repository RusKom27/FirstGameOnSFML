#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.h"
#include "Storage.h"
#include "Debug.h"
#include "Entity.h"

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

	Entity hero(0, 2);

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
					if (hero.x != 17)
						hero.x += 1;
				}
				else if (event.key.code == Keyboard::A)
				{
					if (hero.x != 0)
						hero.x -= 1;
				}
				else if (event.key.code == Keyboard::W)
				{
					if (hero.y != 0)
						hero.y -= 1;
				}
				else if (event.key.code == Keyboard::S)
				{
					if (hero.y != 11)
						hero.y += 1;
				}
				debug.EventHandle(event);
			}
		}
		window.clear(Color(25, 25, 25, 0));
		
		map.drawMap(window);

		hero.draw(map);

		if (debug.gizmo)
			map.drawGizmo(window, mouseX, mouseY);

		if (debug.showFps)
			debug.showFPS(window, time);

		window.display();
	}

	return 0;
}