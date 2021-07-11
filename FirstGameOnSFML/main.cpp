#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.cpp"
#include "Player.cpp"

using namespace sf;
using namespace std;

const int WIDTH = 900;
const int HEIGHT = 600;



int main()
{
	int px = 0, py = 0;

	Clock clock;

	ContextSettings settings;
	settings.antialiasingLevel = 0;

	RenderWindow window(VideoMode(900, 600), "SFML Works!", Style::Default, settings);
	window.setFramerateLimit(60);

	GameMap map(WIDTH, HEIGHT, 50);

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		cout << time << endl;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				return 0;
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
			}
		}
		window.clear(Color(25, 25, 25, 0));

		for (int i = 0; i < CELLS_COUNT_X; i++)
		{
			for (int j = 0; j < CELLS_COUNT_Y; j++)
			{
				window.draw(map.cells[i][j].rect);
				map.cells[i][j].rect.setFillColor(Color(255, 255, 255));
			}
		}
		map.cells[px][py].rect.setFillColor(Color(100, 0, 255));

		window.display();
	}

	return 0;
}