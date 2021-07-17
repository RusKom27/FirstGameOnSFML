#include "UIPanel.h"

UIPanel::UIPanel()
{
	rect = RectangleShape(Vector2f(100, 100));
	rect.setPosition(Vector2f(50, 50));
	rect.setFillColor(Color(0, 255, 0, 0.5f));
	rect.setOutlineThickness(1.f);
	rect.setOutlineColor(Color::White);
}

UIPanel::UIPanel(int x, int y, int width, int height)
{
	rect = RectangleShape(Vector2f(width, height));
	rect.setPosition(Vector2f(x, y));
	rect.setFillColor(Color(50, 20, 100));
	rect.setOutlineThickness(1.f);
	rect.setOutlineColor(Color::White);
}

void UIPanel::draw(RenderWindow& window)
{
	window.draw(rect);
}