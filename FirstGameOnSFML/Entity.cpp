#include "Entity.h"
#include "Storage.h"

Entity::Entity()
{
	x = 0;
	y = 0;
}

Entity::Entity(int X, int Y, Texture* textures_, int countOfFrames, float animationSpeed)
{
	texture = textures_[0];
	textures = textures_;
	animator = Animator(textures, animationSpeed, countOfFrames);
	x = X;
	y = Y;
}

void Entity::update(float time)
{
	animator.animation(time, texture);
}

void Entity::draw(GameMap& map)
{
	map.tiles[x][y].frontSprite.setTexture(texture);
}