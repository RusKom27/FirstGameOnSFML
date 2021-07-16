#include "Entity.h"

Entity::Entity()
{
	textures = { };
	x = 0;
	y = 0;
}

Entity::Entity(int X, int Y, Texture* textures_, int countOfFrames, float animationSpeed)
{
	x = X * TILE_SIZE;
	y = Y * TILE_SIZE;
	textures = textures_;
	sprite = Sprite(textures[0]);
	sprite.setPosition(Vector2f(x, y));
	animator = Animator(textures, animationSpeed, countOfFrames);
}

void Entity::update(float time)
{
	sprite.setPosition(x, y);
	animator.animation(time, sprite);
}

bool Entity::checkNearbyTiles(vector<Vector2i> coords, Vector2i axis)
{
	int cx = x + TILE_SIZE / 2;
	int cy = y + TILE_SIZE / 2;

	for (int i = 0; i < coords.size(); i++)
	{
		Vector2i coord = Vector2i(coords[i].x + TILE_SIZE / 2, coords[i].y + TILE_SIZE / 2);

		if (axis.x < 0)
		{
			if (cx - TILE_SIZE == coord.x && coord.y == cy || x == 0) return false;
		}
		else if (axis.x > 0)
		{
			if (cx + TILE_SIZE == coord.x && coord.y == cy || x == WIDTH - TILE_SIZE) return false;
		}
		else if (axis.y < 0)
		{
			if (cy - TILE_SIZE == coord.y && coord.x == cx || y == 0) return false;
		}
		else if (axis.y > 0)
		{
			if (cy + TILE_SIZE == coord.y && coord.x == cx || y == HEIGHT - TILE_SIZE) return false;
		}
		else
		{
			return true;
		}
	}
}