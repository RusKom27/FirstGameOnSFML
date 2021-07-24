#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"
#include "UIElement.h"

using namespace sf;
using namespace std;

enum ButtonEvent
{
	None,
	Close
};


class UIButton : public UIElement
{
public:
	RectangleShape filter;
	ButtonEvent buttonEvent;

	UIButton();

	~UIButton();

	UIButton(Vector2f position_, Vector2f size_, Border border, String text_, ButtonEvent buttonEvent_, bool draggable_);

	void setAdditionalPosition();

	bool click(Vector2f mouseCoords);

	void update(Vector2f mouseCoords);

	void setAdditionalDraw(RenderWindow& window);
};

