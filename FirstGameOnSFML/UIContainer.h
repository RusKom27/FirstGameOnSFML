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

	bool buttonsClickHandler(Event event, Vector2f mouseCoords, Vector2f& chosenTexture, int& chosenTileSet, vector<string> maps)
	{
		for (UIPanel& panel : panels)
		{
			panel.eventHandle(mouseCoords);
		}
		for (UIInventoryPanel& inventoryPanel : inventoryPanels)
		{
			if (inventoryPanel.eventHandle(mouseCoords, chosenTexture, chosenTileSet)) return true;
		}

		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i].click(mouseCoords))
			{
				switch (buttons[i].buttonEvent)
				{
				case ButtonEvent::SetTileSet:
					inventoryPanels.push_back(UIInventoryPanel(Vector2f(10, 10), Vector2f(200, 600), Border::Thin, maps[i], maps, i, 50, 10, true));
					break;
				default:
					break;
				}
				return true;
			}
		}
		return false;
	}

	bool movePanels(Vector2f mouseCoords, Vector2f oldMouseCoords, bool leftMouse, bool rightMouse)
	{
		for (UIPanel& panel : panels)
		{
			if (panel.contains(mouseCoords))
			{
				if (leftMouse)
				{
					panel.move(mouseCoords, oldMouseCoords);
				}
				return true;
			}
		}
		for (UIInventoryPanel& inventoryPanel : inventoryPanels)
		{
			if (inventoryPanel.contains(mouseCoords))
			{
				if (leftMouse)
				{
					inventoryPanel.move(mouseCoords, oldMouseCoords);
				}
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

