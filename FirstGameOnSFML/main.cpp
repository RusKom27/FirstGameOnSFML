#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.cpp"
#include "Player.cpp"

using namespace sf;
using namespace std;

const int WIDTH = 900;
const int HEIGHT = 600;

bool checkCollision(Vector2i obj1, int obj1Size, Vector2i obj2, int obj2Size) 
{
	if (obj1.x < obj2.x + obj2Size && obj1.y < obj2.y + obj2Size && obj1.x + obj1Size > obj2.x && obj1.y + obj1Size > obj2.y)
		return true;
	else
		return false;
}

int main()
{
	int px = 0, py = 0;
	bool gizmo = false;

	Clock clock;

	ContextSettings settings;
	settings.antialiasingLevel = 0;

	RenderWindow window(VideoMode(900, 600), "SFML Works!", Style::Default, settings);
	window.setFramerateLimit(60);

	GameMap map(WIDTH, HEIGHT, 50);

	Mouse mouse;
	int mouseX = 0, mouseY = 0;


	Texture backTexture;
	Texture frontTexture;
	backTexture.loadFromFile("Images\\Tile1.png");
	frontTexture.loadFromFile("Images\\Hero.png");

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


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
					gizmo = !gizmo;
			}
		}
		window.clear(Color(25, 25, 25, 0));

		for (int i = 0; i < CELLS_COUNT_X; i++)
		{
			for (int j = 0; j < CELLS_COUNT_Y; j++)
			{
				if (gizmo)
				{
					window.draw(map.cells[i][j].Rect);
					map.cells[i][j].Rect.setOutlineColor(Color(200, 200, 200));
					map.cells[i][j].Rect.setOutlineThickness(0.6f);
					if (checkCollision(Vector2i(map.cells[i][j].x, map.cells[i][j].y), map.cells[i][j].size, Vector2i(mouseX, mouseY), 0))
					{
						map.cells[i][j].Rect.setOutlineColor(Color(255, 0, 0));
						map.cells[i][j].Rect.setOutlineThickness(2.f);
					}
				}
				
				
				window.draw(map.cells[i][j].backSprite);
				map.cells[i][j].backSprite.setTexture(backTexture);
				
				
			}
		}
		window.draw(map.cells[px][py].frontSprite);
		map.cells[px][py].frontSprite.setTexture(frontTexture);
		map.cells[px][py].x = px;
		map.cells[px][py].y = py;

		window.display();
	}

	return 0;
}