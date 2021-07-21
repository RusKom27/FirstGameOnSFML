#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"
#include "UIElement.h"

using namespace sf;
using namespace std;

class UIButton : public UIElement
{
public:
	RectangleShape filter;

	UIButton() : UIElement()
	{

	}

	UIButton(Vector2f position_, Vector2f size_, Border border, String text_) : UIElement(position_, size_, border, text_)
	{
		filter = RectangleShape(mainRect.getSize());
		filter.setFillColor(Color(200, 200, 200, 0));
		setPosition(position);
	}

	void setPosition(Vector2f position_)
	{
		position = position_;
		background.setPosition(position);
		filter.setPosition(Vector2f(position.x, position.y));
		mainRect.setPosition(Vector2f(position.x, position.y));
		text.setPosition(Vector2f(position.x + (size.x / 2) - (static_cast<float>(text.getString().getSize()) * static_cast<float>(text.getCharacterSize()) / 2), position.y + (size.y / 2) - (static_cast<float>(text.getCharacterSize()) / 2)));

		borders[0].setPosition(position);
		borders[1].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y));
		borders[2].setPosition(Vector2f(position.x, position.y + size.y - TILE_SIZE));
		borders[3].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y + size.y - TILE_SIZE));
		borders[4].setPosition(Vector2f(position.x, position.y));
		borders[5].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y));
		borders[6].setPosition(Vector2f(position.x, position.y + size.y - TILE_SIZE));
		borders[7].setPosition(Vector2f(position.x, position.y));
	}

	void click(void(*function)())
	{
		function();
	}

	void update(Vector2f mouseCoords)
	{
		if (contains(mouseCoords))
			filter.setFillColor(Color(200, 200, 200, 100));
		else
			filter.setFillColor(Color(200, 200, 200, 0));
	}

	void draw(RenderWindow& window)
	{
		window.draw(mainRect);
		window.draw(background);
		window.draw(filter);
		text.setFont(font);
		window.draw(text);
		

		for (int i = 4; i < 8; i++)
		{
			window.draw(borders[i]);
		}
		for (int i = 0; i < 4; i++)
		{
			window.draw(borders[i]);
		}
		
	}
};

