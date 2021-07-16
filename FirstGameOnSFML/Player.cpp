#include "Player.h"


Player::Player()
{
}

Player::Player(int X, int Y, Texture textures[], int countOfFrames, float animationSpeed) : Entity(X, Y, textures, countOfFrames, animationSpeed)
{
}

bool Player::EventHandle(Event& event, vector<Vector2i> collisions)
{
	if (event.key.code == Keyboard::D)
	{
		if (checkNearbyTiles(collisions, Vector2i(1, 0)))
			x += TILE_SIZE;
		return true;
	}
	else if (event.key.code == Keyboard::A)
	{
		if (checkNearbyTiles(collisions, Vector2i(-1, 0)))
			x -= TILE_SIZE;
		return true;
	}
	else if (event.key.code == Keyboard::W)
	{
		if (checkNearbyTiles(collisions, Vector2i(0, -1)))
			y -= TILE_SIZE;
		return true;
	}
	else if (event.key.code == Keyboard::S)
	{
		if (checkNearbyTiles(collisions, Vector2i(0, 1)))
			y += TILE_SIZE;
		return true;
	}
	else
	{
		return false;
	}
	
}
