#include "Entity.h"

Entity::Entity()
{
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