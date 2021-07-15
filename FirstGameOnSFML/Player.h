#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	Player(int X, int Y, Texture textures[], int countOfFrames, float animationSpeed);

	bool EventHandle(Event& event);
};

