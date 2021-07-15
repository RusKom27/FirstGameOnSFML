#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	Enemy(int X, int Y, Texture textures[], int countOfFrames, float animationSpeed);

	void move();
};

