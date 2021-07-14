#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(int X, int Y, Texture textures[], int countOfFrames, float animationSpeed);

	void EventHandle(Event& event);
};

