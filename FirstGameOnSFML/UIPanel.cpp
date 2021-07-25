#include "UIPanel.h"

UIPanel::UIPanel() : UIElement() {}

UIPanel::~UIPanel() { }

UIPanel::UIPanel(Vector2f position_, Vector2f size_, Border border, String text_, float headerHeight, bool draggable_) : UIElement(position_, size_, border, text_, draggable_)
{
	closeButton = (UIButton(Vector2f(0, 0), Vector2f(30, 30), Border::Outline, "x", ButtonEvent::Close, false));

	headerRect = RectangleShape(Vector2f(size.x, headerHeight));
	setPosition(position);
	headerRect.setFillColor(Color(mainRect.getFillColor().r - 30, mainRect.getFillColor().g - 30, mainRect.getFillColor().b - 30));
}

void UIPanel::setAdditionalPosition()
{
	headerRect.setPosition(Vector2f(position.x, position.y));
	text.setPosition(Vector2f(position.x + (headerRect.getSize().x / 2) - (text.getString().getSize() * 15 / 2), position.y + (headerRect.getSize().y / 2) - (25 / 2)));
	closeButton.setPosition(Vector2f(position.x + size.x - closeButton.size.x - 10, position.y + 10));
}

void UIPanel::update(Vector2f mouseCoords)
{
	closeButton.update(mouseCoords);
	for (vector<UIButton>& row : buttons)
	{
		for (UIButton& button : row)
		{
			button.update(mouseCoords);
		}
	}
}


void UIPanel::eventHandle(Vector2f mouseCoords)
{

	if (closeButton.click(mouseCoords))
	{
		switch (closeButton.buttonEvent)
		{
		case ButtonEvent::Close:
			close();
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < buttons.size(); i++)
	{
		for (int j = 0; j < buttons[i].size(); j++)
		{
			if (buttons[i][j].click(mouseCoords))
			{
				switch (buttons[i][j].buttonEvent)
				{
				case ButtonEvent::Close:
					close();
					break;
				case ButtonEvent::None:
					cout << i << "\t" << j << endl;
					break;
				default:
					break;
				}
			}
		}
	}

	
}

void UIPanel::setAdditionalDraw(RenderWindow& window)
{
	window.draw(headerRect);
	closeButton.draw(window);
	for (vector<UIButton>& row : buttons)
	{
		for (UIButton& button : row)
		{
			button.draw(window);
		}
			
	}
}