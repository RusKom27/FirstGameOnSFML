#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"
#include "UIPanel.h"
#include "UIButton.h"

using namespace sf;
using namespace std;

class UIInventoryPanel : public UIPanel
{
public:
	Texture** textures;
	UIButton** inventoryButtons;
	Vector2f buttonsCount;

	UIInventoryPanel(Vector2f position_, Vector2f size_, Border border, String text_, float headerHeight, bool draggable_) : UIPanel(position_, size_, border, text_, headerHeight, draggable_)
	{
		buttonsCount = storage.getTexturesFromImage(textures, storage.loadImage(text.getString()));
		size = Vector2f(buttonsCount.x * TILE_SIZE + 2 * TILE_SIZE, buttonsCount.y * TILE_SIZE + 2 * TILE_SIZE);
		mainRect.setSize(size);
		headerRect.setSize(Vector2f(size.x, headerHeight));
		setBorder(border);
		setPosition(position);
		setButtons();
	}

	void setButtons()
	{
		int x = 0;
		int y = 0;

		for (int i = 0; i < buttonsCount.x-1; i++)
		{
			x = i * TILE_SIZE;
			for (int j = 0; j < buttonsCount.y-1; j++)
			{
				y = j * TILE_SIZE;
				cout << i << "\t" << j << endl;
				inventoryButtons[i][j] = UIButton(Vector2f(position.x + x + i * 2, position.y + y + j * 2), Vector2f(TILE_SIZE, TILE_SIZE), Border::Outline, "", ButtonEvent::None, false);
			}
		}
	}

	void setSubDraw(RenderWindow& window)
	{
		for (int i = 0; i < buttonsCount.x; i++)
		{
			for (int j = 0; j < buttonsCount.y; j++)
			{
				inventoryButtons[i][j].draw(window);
				cout << "d\n";
			}
		}
	}
};

