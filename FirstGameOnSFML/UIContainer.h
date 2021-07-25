#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"
#include "UIPanel.h"
#include "UIInventoryPanel.h"
#include "UIButton.h"

using namespace sf;
using namespace std;


class UIContainer
{
public:
	vector<UIButton> buttons;
	vector<UIPanel> panels;
	vector<UIInventoryPanel> inventoryPanels;

	UIContainer() {}

	void buttonsClickHandler(Event event, Vector2f mouseCoords)
	{
		for (UIPanel& panel : panels)
		{
			panel.eventHandle(mouseCoords);
		}
		for (UIInventoryPanel& inventoryPanel : inventoryPanels)
		{
			inventoryPanel.eventHandle(mouseCoords);
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
		for (UIInventoryPanel& inventoryPanel : inventoryPanels)
		{
			if (inventoryPanel.contains(mouseCoords))
			{
				inventoryPanel.move(mouseCoords, oldMouseCoords);
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
			panels[i].update(mouseCoords);
			if (panels[i].closed)
				panels.erase(panels.begin() + i);
		}
		for (int i = 0; i < inventoryPanels.size(); i++)
		{
			inventoryPanels[i].update(mouseCoords);
			if (inventoryPanels[i].closed)
				inventoryPanels.erase(inventoryPanels.begin() + i);
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
		for (UIInventoryPanel& inventoryPanel : inventoryPanels)
		{
			inventoryPanel.draw(window);
		}
	}
};

