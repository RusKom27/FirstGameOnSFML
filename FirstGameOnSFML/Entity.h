#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameMap.h"
#include "Animator.h"

using namespace sf;
using namespace std;


class Entity
{
private:
	Storage storage;
	
public:
	int x;
	int y;
	Texture texture;
	Texture* textures;
	Animator animator;

	Entity();

	Entity(int X, int Y, Texture* textures_, int countOfFrames, float animationSpeed);

	void draw(GameMap& map);

	void update(float time);
};

