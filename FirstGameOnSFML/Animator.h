#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Animator
{
public:
	float timer = 0;
	int frame = 0;
	Texture* textures;
	float speed;
	int countOfFrames;

	Animator();

	Animator(Texture* textures_, float speed_, int countOfFrames_);

	void animation(float timeElapsed, Texture& texture);
};

