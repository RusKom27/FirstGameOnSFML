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
		UIPanel panel = UIPanel(position_, size_, border_, headerText_, TILE_SIZE);
		panel.draggable = draggable_;
		panels.push_back(panel);
	}

	void createButton(Vector2f position_, Vector2f size_, Border border_, string text_)
	{
		UIButton button = UIButton(position_, size_, border_, text_, [] { cout << "OK\n"; });
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
			//button.click();
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
	}

	void update(Vector2f mouseCoords)
	{
		for (UIButton& button : buttons)
		{
			button.update(mouseCoords);
		}
		for (int i = 0; i < panels.size(); i++)
		{
			panels[i].closeButton.update(mouseCoords);
			if (panels[i].closed)
				panels.erase(panels.begin() + i);
		}
		for (UIPanel& panel : panels)
		{
			
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

