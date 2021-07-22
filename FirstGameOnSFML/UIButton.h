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

	UIButton() : UIElement() {}

	~UIButton() {}

	UIButton(Vector2f position_, Vector2f size_, Border border, String text_) : UIElement(position_, size_, border, text_)
	{
		filter = RectangleShape(mainRect.getSize());
		filter.setFillColor(Color(200, 200, 200, 0));
		setPosition(position);
	}

	void setAdditionalPosition()
	{
		filter.setPosition(Vector2f(position.x, position.y));
	}

	void update(Vector2f mouseCoords)
	{
		if (contains(mouseCoords))
			filter.setFillColor(Color(200, 200, 200, 100));
		else
			filter.setFillColor(Color(200, 200, 200, 0));
	}

	void additionalDraw(RenderWindow& window) 
	{
		window.draw(filter);
	}
};

