#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy(int X, int Y, Texture textures[], int countOfFrames, float animationSpeed);
};

