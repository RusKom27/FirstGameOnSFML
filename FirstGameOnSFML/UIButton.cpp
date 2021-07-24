#include "UIButton.h"

UIButton::UIButton() : UIElement() {}

UIButton::~UIButton() {}

UIButton::UIButton(Vector2f position_, Vector2f size_, Border border, String text_, ButtonEvent buttonEvent_, bool draggable_) : UIElement(position_, size_, border, text_, draggable_)
{
	buttonEvent = buttonEvent_;
	filter = RectangleShape(mainRect.getSize());
	filter.setFillColor(Color(200, 200, 200, 0));
	setPosition(position);
}

bool UIButton::click(Vector2f mouseCoords)
{
	if (contains(mouseCoords))
		return true;
	else
		return false;
}


void UIButton::setAdditionalPosition()
{
	filter.setPosition(Vector2f(position.x, position.y));
}

void UIButton::update(Vector2f mouseCoords)
{
	if (contains(mouseCoords))
		filter.setFillColor(Color(200, 200, 200, 100));
	else
		filter.setFillColor(Color(200, 200, 200, 0));
}

void UIButton::setAdditionalDraw(RenderWindow& window)
{
	window.draw(filter);
}