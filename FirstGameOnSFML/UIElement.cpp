#include "UIElement.h"

UIElement::UIElement() {}

UIElement::~UIElement() {}

UIElement::UIElement(Vector2f position_, Vector2f size_, Border border, String text_)
{
	position = position_;
	size = size_;
	font.loadFromFile("Fonts\\PixelFont.ttf");
	text = Text(text_, font, 20);
	text.setFillColor(Color(250, 250, 250));

	mainRect = RectangleShape(size);
	mainRect.setFillColor(Color(199, 181, 155, 200));
	setBorder(border);
	setPosition(position);
}

void UIElement::setBorder(Border border)
{
	switch (border)
	{
	case Thick:
		storage.getTexturesFromImage(borderTextures, storage.loadImage("UIBorders_Thick.png"));
		break;
	case Thin:
		storage.getTexturesFromImage(borderTextures, storage.loadImage("UIBorders_Thin.png"));
		break;
	case Outline:
		mainRect.setOutlineThickness(2.f);
		mainRect.setOutlineColor(Color(mainRect.getFillColor().r - 50, mainRect.getFillColor().g - 50, mainRect.getFillColor().b - 50));
		break;
	default:
		storage.getTexturesFromImage(borderTextures, storage.loadImage("UIBorders_Thin.png"));
		break;
	}
	if (border != Outline)
	{
		borders[0] = Sprite(borderTextures[0][0]);
		borders[1] = Sprite(borderTextures[2][0]);
		borders[2] = Sprite(borderTextures[0][2]);
		borders[3] = Sprite(borderTextures[2][2]);

		borders[4] = Sprite(borderTextures[1][0]);
		borders[5] = Sprite(borderTextures[2][1]);
		borders[6] = Sprite(borderTextures[1][2]);
		borders[7] = Sprite(borderTextures[0][1]);

		borders[4].setScale(Vector2f(size.x / TILE_SIZE, 1));
		borders[6].setScale(Vector2f(size.x / TILE_SIZE, 1));

		borders[5].setScale(Vector2f(1, size.y / TILE_SIZE));
		borders[7].setScale(Vector2f(1, size.y / TILE_SIZE));
	}
}

void UIElement::setAdditionalPosition() {}

void UIElement::setPosition(Vector2f position_)
{
	position = position_;
	background.setPosition(position);
	mainRect.setPosition(position);
	text.setPosition(Vector2f(position.x + (size.x / 2) - (text.getString().getSize() * 15 / 2), position.y + (size.y / 2) - (25 / 2)));

	borders[0].setPosition(position);
	borders[1].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y));
	borders[2].setPosition(Vector2f(position.x, position.y + size.y - TILE_SIZE));
	borders[3].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y + size.y - TILE_SIZE));
	borders[4].setPosition(Vector2f(position.x, position.y));
	borders[5].setPosition(Vector2f(position.x + size.x - TILE_SIZE, position.y));
	borders[6].setPosition(Vector2f(position.x, position.y + size.y - TILE_SIZE));
	borders[7].setPosition(Vector2f(position.x, position.y));

	setAdditionalPosition();
}

void UIElement::close()
{
	closed = true;
}

bool UIElement::contains(Vector2f mouseCoords)
{
	if (storage.checkCollision(position, size, mouseCoords, Vector2f(0, 0))) return true;
	else return false;
}

void UIElement::move(Vector2f mouseCoords, Vector2f oldMouseCoords)
{
	setPosition(Vector2f(position.x - (oldMouseCoords.x - mouseCoords.x), position.y - (oldMouseCoords.y - mouseCoords.y)));
}

void UIElement::setColor(Color color)
{
	mainRect.setFillColor(color);
}

void UIElement::setBackgroundTexture(Texture& texture)
{
	texture.setRepeated(true);
	background.setTexture(texture, true);
	background.setTextureRect(IntRect(Vector2i(position), Vector2i(size)));
}

void UIElement::additionalDraw(RenderWindow& window) {}

void UIElement::draw(RenderWindow& window)
{
	window.draw(mainRect);
	window.draw(background);
	
	additionalDraw(window);

	for (int i = 4; i < 8; i++)
	{
		window.draw(borders[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		window.draw(borders[i]);
	}
	text.setFont(font);
	window.draw(text);
}