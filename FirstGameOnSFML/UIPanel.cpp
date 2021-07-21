#include "UIPanel.h"

UIPanel::UIPanel() : UIElement()
{
}

UIPanel::~UIPanel()
{
}

UIPanel::UIPanel(Vector2f position_, Vector2f size_, Border border, String text_, float headerHeight) : UIElement(position_, size_, border, text_)
{
	closeButton = UIButton(Vector2f(size_.x - 30, 10), Vector2f(30, 30), Border::Thin, "x");
	
	headerRect = RectangleShape(Vector2f(size.x, headerHeight));
	setPosition(position);
	headerRect.setFillColor(Color(mainRect.getFillColor().r - 30, mainRect.getFillColor().g - 30, mainRect.getFillColor().b - 30));
}

void  UIPanel::setPosition(Vector2f position_) 
{
	position = position_;
	background.setPosition(position);
	headerRect.setPosition(Vector2f(position.x, position.y));
	mainRect.setPosition(Vector2f(position.x, position.y));
	closeButton.setPosition(Vector2f(position.x + size.x - closeButton.size.x - 5, position.y + 5));
	text.setPosition(Vector2f(position.x + (size.x / 2) - (text.getString().getSize() * text.getCharacterSize() / 2), position.y + 10));

	borders[0].setPosition(position);
	borders[1].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y));
	borders[2].setPosition(Vector2f(position.x, position.y + size.y - TILE_SIZE));
	borders[3].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y + size.y - TILE_SIZE));
	borders[4].setPosition(Vector2f(position.x, position.y));
	borders[5].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y));
	borders[6].setPosition(Vector2f(position.x, position.y + size.y - TILE_SIZE));
	borders[7].setPosition(Vector2f(position.x, position.y));
}

void UIPanel::close()
{
	delete this;
}

void UIPanel::eventHandle(Vector2f mouseCoords)
{
	if (closeButton.contains(mouseCoords))
		closeButton.click([] { cout << "d" << endl; });
}

void UIPanel::draw(RenderWindow& window)
{
	window.draw(mainRect);
	window.draw(background);
	window.draw(headerRect);
	closeButton.draw(window);
	
	for (int i = 4; i < 8; i++)
	{
		window.draw(borders[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		window.draw(borders[i]);
	}
	text.setFont(font);
	window.draw(text);
}