#include "Player.h"


Player::Player(int X, int Y, Texture textures[], int countOfFrames, float animationSpeed) : Entity(X, Y, textures, countOfFrames, animationSpeed)
{

}

void Player::EventHandle(Event& event)
{
	if (event.key.code == Keyboard::D)
	{
		if (x != TILES_COUNT_X-1)
			x += 1;
	}
	else if (event.key.code == Keyboard::A)
	{
		if (x != 0)
			x -= 1;
	}
	else if (event.key.code == Keyboard::W)
	{
		if (y != 0)
			y -= 1;
	}
	else if (event.key.code == Keyboard::S)
	{
		if (y != TILES_COUNT_Y - 1)
			y += 1;
	}
}
