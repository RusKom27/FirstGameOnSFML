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
	static void (*customFunction)();

	UIButton();

	~UIButton();

	UIButton(Vector2f position_, Vector2f size_, Border border, String text_, void (*customFunction_)());

	void setAdditionalPosition();

	void click(Vector2f mouseCoords);

	void update(Vector2f mouseCoords);

	void setAdditionalDraw(RenderWindow& window);
};

