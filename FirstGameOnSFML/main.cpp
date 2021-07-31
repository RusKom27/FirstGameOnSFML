#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.h"
#include "Storage.h"
#include "Debug.h"
#include "MapEditor.h"


int main()
{
	Clock clock;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML RPG", Style::Default);
	View view = window.getDefaultView();
	view.setCenter(0,0);
	view.setSize(static_cast<float>(WIDTH / 1.5f), static_cast<float>(HEIGHT / 1.5f));
	window.setPosition(Vector2i(1500, 0));
	window.setFramerateLimit(60);

	Storage storage;
	Debug debug;
	GameMap map;
	MapEditor mapEditor;
	map.loadMap("Maps\\Map_0.0.xml");

	int px = 0, py = 0;
	int mouseX = 0, mouseY = 0;

	float time = 0;
	
	mapEditor.createWindow();
	
	while (window.isOpen())
	{
		
		time = clock.getElapsedTime().asSeconds();

		Event event;
		
		if (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				return 0;
			}
			else if (event.type == Event::Resized)
			{
				view.setSize(static_cast<float>(event.size.width) / 1.5f, static_cast<float>(event.size.height) / 1.5f);
				//view.setCenter(static_cast<float>(event.size.width) / 2, static_cast<float>(event.size.height) / 2);
				window.setView(view);
			}
			else if (event.type == Event::MouseMoved)
			{
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}
			else if (event.type == Event::KeyPressed)
			{
				map.update(map.player.EventHandle(event, map.collisions));
				debug.EventHandle(event);
				if (event.key.code == Keyboard::M)
					mapEditor.createWindow();
			}
		}
		
		window.clear(Color(25, 25, 25, 0));

		mapEditor.update(time);
		map.player.update(time);

		view.setCenter(map.player.x + TILE_SIZE / 2, map.player.y + TILE_SIZE / 2);
		window.setView(view);

		map.drawMap(window);

		if (debug.showFps)
			debug.showFPS(window, time);
		clock.restart();
		window.display();
	}


	return 0;
}