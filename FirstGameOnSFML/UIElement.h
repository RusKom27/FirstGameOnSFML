#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"

using namespace sf;
using namespace std;

enum Border { Thick, Thin, Outline };

class UIElement
{
private:
	Storage storage;
	Texture** borderTextures;
public:
	Vector2f size;
	Vector2f position;
	RectangleShape mainRect;
	Sprite background;
	bool closed = false;
	bool draggable = false;

	Font font;
	Text text;

	Sprite borders[8];

	UIElement();

	virtual ~UIElement();

	UIElement(Vector2f position_, Vector2f size_, Border border, String text_);

	void setBorder(Border border);

	void setPosition(Vector2f position_);

	virtual void setAdditionalPosition();

	void close();

	bool contains(Vector2f mouseCoords);

	void move(Vector2f mouseCoords, Vector2f oldMouseCoords);

	void setColor(Color color);

	void setBackgroundTexture(Texture& texture);

	virtual void setAdditionalDraw(RenderWindow& window);

	void draw(RenderWindow& window);
};

