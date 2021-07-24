#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"
#include "UIPanel.h"
#include "UIButton.h"

using namespace sf;
using namespace std;


class UIContainer
{
public:
	vector<UIButton> buttons;
	vector<UIPanel> panels;

	UIContainer() {}

	void createPanel(Vector2f position_, Vector2f size_, Border border_, string headerText_, bool draggable_)
	{
		UIPanel panel = UIPanel(position_, size_, border_, headerText_, TILE_SIZE, draggable_);
		panels.push_back(panel);
	}

	void createButton(Vector2f position_, Vector2f size_, Border border_, string text_, ButtonEvent buttonEvent_)
	{
		UIButton button = UIButton(position_, size_, border_, text_, buttonEvent_, false);
		buttons.push_back(button);
	}

	void buttonsClickHandler(Event event, Vector2f mouseCoords)
	{
		for (UIPanel& panel : panels)
		{
			panel.eventHandle(mouseCoords);
		}
		for (UIButton& button : buttons)
		{
			if (button.click(mouseCoords))
			{
				switch (button.buttonEvent)
				{
				case ButtonEvent::None:
					cout << "Click\n";
					break;
				default:
					break;
				}
			}
		}
	}

	bool movePanels(Vector2f mouseCoords, Vector2f oldMouseCoords)
	{
		for (UIPanel& panel : panels)
		{
			if (panel.contains(mouseCoords))
			{
				panel.move(mouseCoords, oldMouseCoords);
				return true;
			}
		}
		return false;
	}

	void update(Vector2f mouseCoords)
	{
		for (UIButton& button : buttons)
		{
			button.update(mouseCoords);
		}
		for (int i = 0; i < panels.size(); i++)
		{
			for (int j = 0; j < panels[i].buttons.size(); j++)
			{
				panels[i].buttons[j].update(mouseCoords);
			}
			if (panels[i].closed)
				panels.erase(panels.begin() + i);
		}
	}

	void draw(RenderWindow& window)
	{
		for (UIButton& button : buttons)
		{
			button.draw(window);
		}
		for (UIPanel& panel : panels)
		{
			panel.draw(window);
		}
	}
};

