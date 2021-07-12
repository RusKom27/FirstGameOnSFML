#include "Entity.h"
#include "Storage.h"

Entity::Entity()
{
	x = 0;
	y = 0;
}

Entity::Entity(int X, int Y)
{
	x = X;
	y = Y;
}

void Entity::draw(GameMap& map)
{
	map.cells[x][y].frontSprite.setTexture(storage.heroTexture);
}