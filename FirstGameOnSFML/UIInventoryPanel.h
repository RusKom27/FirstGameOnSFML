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
	int tileSetId;
	Vector2f buttonsCount;
	float whiteSpace;
	vector<vector<UIButton>> buttons;

	UIInventoryPanel(Vector2f position_, Vector2f size_, Border border, String text_, int tileSetId_, float headerHeight, float whiteSpace_, bool draggable_) : UIPanel(position_, size_, border, text_, headerHeight, draggable_)
	{
		whiteSpace = whiteSpace_;
		tileSetId = tileSetId_;
		cout << "UIInventoryPanel\n";
		buttonsCount = storage.getTexturesFromImage(textures, storage.loadImage(storage.maps[tileSetId_]));
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
			}
		}
		headerRect.setPosition(Vector2f(position.x, position.y));
		text.setPosition(Vector2f(position.x + (headerRect.getSize().x / 2) - (text.getString().getSize() * 15 / 2), position.y + (headerRect.getSize().y / 2) - (25 / 2)));
		closeButton.setPosition(Vector2f(position.x + size.x - closeButton.size.x - 10, position.y + 10));
	}

	bool eventHandle(Vector2f mouseCoords, Vector2f& chosenTexture, int& chosenTileSet)
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
			return true;
		}
		for (int i = 0; i < buttons.size(); i++)
		{
			for (int j = 0; j < buttons[i].size(); j++)
			{
				if (buttons[i][j].click(mouseCoords))
				{
					switch (buttons[i][j].buttonEvent)
					{
					case ButtonEvent::SetTexture:
						chosenTexture = Vector2f(i,j);
						chosenTileSet = tileSetId;
						break;
					default:
						break;
					}
					return true;
				}
			}
		}
		return false;
	}

	void update(Vector2f mouseCoords)
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

	void setAdditionalDraw(RenderWindow& window)
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
				buttons[i].push_back(UIButton(Vector2f(position.x + x + i * 2, position.y + y + j * 2), Vector2f(TILE_SIZE, TILE_SIZE), Border::Outline, "", ButtonEvent::SetTexture, true));
				
			}
		}
	}
};

