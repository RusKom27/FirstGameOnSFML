#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.h"
#include "Storage.h"
#include "Debug.h"
#include "Player.h"


using namespace sf;
using namespace std;

int main()
{
	Clock clock;

	ContextSettings settings;
	settings.antialiasingLevel = 0;

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML Works!", Style::Default, settings);
	window.setPosition(Vector2i(1500, 0));
	window.setFramerateLimit(60);


	Entity* entities;

	Storage storage;
	Debug debug;
	GameMap map(WIDTH, HEIGHT, TILE_SIZE);
	map.loadMap("Maps\\Map_0.0.xml");

	Texture heroTextures[] = { 
		storage.backTextures[0][0], 
		storage.backTextures[1][0], 
		storage.backTextures[2][0], 
		storage.backTextures[3][0], 
		storage.backTextures[4][0] };

	Player hero(0, 2, heroTextures, 4, 0.5);
	
	int px = 0, py = 0;
	int mouseX = 0, mouseY = 0;

	float time = 0;


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
			else if (event.type == Event::MouseMoved)
			{
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}
			else if (event.type == Event::KeyPressed)
			{
				hero.EventHandle(event);
				debug.EventHandle(event);
			}
		}
		window.clear(Color(25, 25, 25, 0));
		
		map.drawMap(window);
		hero.update(time);
		hero.draw(map);


		if (debug.showFps)
			debug.showFPS(window, time);
		clock.restart();
		window.display();
	}


	return 0;
}