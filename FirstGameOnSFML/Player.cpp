#include "Player.h"


Player::Player()
{
}

Player::Player(int X, int Y, Texture textures[], int countOfFrames, float animationSpeed) : Entity(X, Y, textures, countOfFrames, animationSpeed)
{
}

bool Player::EventHandle(Event& event)
{
	if (event.key.code == Keyboard::D)
	{
		if (x/TILE_SIZE != TILES_COUNT_X - 1)
			x += TILE_SIZE;
		return true;
	}
	if (event.key.code == Keyboard::A)
	{
		if (x / TILE_SIZE != 0)
			x -= TILE_SIZE;
		return true;
	}
	if (event.key.code == Keyboard::W)
	{
		if (y / TILE_SIZE != 0)
			y -= TILE_SIZE;
		return true;
	}
	if (event.key.code == Keyboard::S)
	{
		if (y / TILE_SIZE != TILES_COUNT_Y - 1)
			y += TILE_SIZE;
		return true;
	}
	printf("%i\t%i\n",x * 50, y * 50);
}
