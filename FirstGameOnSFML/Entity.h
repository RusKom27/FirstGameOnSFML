#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animator.h"
#include "Storage.h"

using namespace sf;
using namespace std;


class Entity
{
private:
	Storage storage;
public:
	int x;
	int y;
	Sprite sprite;
	Texture* textures;
	Animator animator;

	Entity();

	Entity(int X, int Y, Texture* textures_, int countOfFrames, float animationSpeed);

	bool checkNearbyTiles(vector<Vector2i> coords, Vector2i axis);
	void update(float time);
};

