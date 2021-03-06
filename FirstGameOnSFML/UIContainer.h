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
private:
	Storage storage;
public:
	vector<UIButton> buttons;
	vector<UIElement> uiElements;
	vector<UIPanel> panels;
	vector<UIInventoryPanel> inventoryPanels;

	UIContainer() {}

	bool buttonsClickHandler(Vector2f mouseCoords)
	{
		for (UIPanel& panel : panels)
		{
			panel.eventHandle(mouseCoords);
		}

		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i].click(mouseCoords))
			{
				switch (buttons[i].buttonEvent)
				{
				case ButtonEvent::SetTileSet:
					inventoryPanels.push_back(UIInventoryPanel(Vector2f(10, 10), Vector2f(200, 600), Border::Thin, storage.maps[i], i, 50, 10, true));
					break;
				default:
					break;
				}
				return true;
			}
		}
		return false;
	}

	bool inventoryButtonsClickHandler(Vector2f mouseCoords, Vector2f& chosenTexture, int& chosenTileSet)
	{
		for (int i = inventoryPanels.size() - 1; i >= 0; i--)
		{
			if (inventoryPanels[i].eventHandle(mouseCoords, chosenTexture, chosenTileSet)) return true;
		}
		return false;
	}

	bool movePanels(Vector2f mouseCoords, Vector2f oldMouseCoords, bool leftMouse, bool rightMouse)
	{
		for (int i = panels.size() - 1; i >= 0; i--)
		{
			if (panels[i].contains(mouseCoords))
			{
				if (leftMouse)
				{
					panels[i].move(mouseCoords, oldMouseCoords);
				}
				return true;
			}
		}
		for (int i = inventoryPanels.size() - 1; i >= 0; i--)
		{
			if (inventoryPanels[i].contains(mouseCoords))
			{
				if (leftMouse)
				{
					inventoryPanels[i].move(mouseCoords, oldMouseCoords);
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
		for (UIElement& uiElement : uiElements)
		{
			uiElement.draw(window);
		}
		for (UIPanel& panel : panels)
		{
			panel.draw(window);
		}
		for (UIButton& button : buttons)
		{
			button.draw(window);
		}
		for (UIInventoryPanel& inventoryPanel : inventoryPanels)
		{
			inventoryPanel.draw(window);
		}
	}
};

