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
	Vector2f buttonsCount;
	float whiteSpace;

	UIInventoryPanel(Vector2f position_, Vector2f size_, Border border, String text_, float headerHeight, float whiteSpace_, bool draggable_) : UIPanel(position_, size_, border, text_, headerHeight, draggable_)
	{
		whiteSpace = whiteSpace_;
		buttonsCount = storage.getTexturesFromImage(textures, storage.loadImage(text.getString()));
		size = Vector2f(buttonsCount.x * TILE_SIZE + buttonsCount.x * whiteSpace + whiteSpace, buttonsCount.y * TILE_SIZE + headerHeight + buttonsCount.y * whiteSpace + whiteSpace);
		mainRect.setSize(size);
		headerRect.setSize(Vector2f(size.x, headerHeight));
		setBorder(border);
		setButtons();
		setPosition(position);
		
	}

	void setAdditionalPosition()
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			for (int j = 0; j < buttons[i].size(); j++)
			{
				buttons[i][j].setPosition(Vector2f(position.x + i * TILE_SIZE + i * whiteSpace + whiteSpace, position.y + j * TILE_SIZE + headerRect.getSize().y + j * whiteSpace + whiteSpace));
				buttons[i][j].background.setTexture(textures[i][j]);
				//buttons[i][j].setBackgroundTexture(textures[i][j], false);
			}
		}
		headerRect.setPosition(Vector2f(position.x, position.y));
		text.setPosition(Vector2f(position.x + (headerRect.getSize().x / 2) - (text.getString().getSize() * 15 / 2), position.y + (headerRect.getSize().y / 2) - (25 / 2)));
		closeButton.setPosition(Vector2f(position.x + size.x - closeButton.size.x - 10, position.y + 10));
	}


	void setButtons()
	{
		int x = 0;
		int y = 0;

		for (int i = 0; i < buttonsCount.x; i++)
		{
			x = i * TILE_SIZE;

			buttons.push_back(vector<UIButton>());
			for (int j = 0; j < buttonsCount.y; j++)
			{
				y = j * TILE_SIZE;
				cout << i << "\t" << j << endl;
				buttons[i].push_back(UIButton(Vector2f(position.x + x + i * 2, position.y + y + j * 2), Vector2f(TILE_SIZE, TILE_SIZE), Border::Outline, "", ButtonEvent::None, true));
				
			}
		}

	}
};

