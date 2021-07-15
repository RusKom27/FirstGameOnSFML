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
		//TODO �� ������ ������� 4 ����, ������� ������������ � ��������, ������� ������������ � ������� �������� � ���������
	}
	void update(float time);
};

