#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animator.h"
#include "Storage.h"

using namespace sf;
using namespace std;


class Entity
{
public:
	int x;
	int y;
	Sprite sprite;
	Texture* textures;
	Animator animator;

	Entity();

	Entity(int X, int Y, Texture* textures_, int countOfFrames, float animationSpeed);

	void checkNearbyTiles()
	{
		//TODO От игрока выходят 4 луча, которые контактируют с клетками, которые перебираются в массиве обьектов с коллизией
	}
	void update(float time);
};

