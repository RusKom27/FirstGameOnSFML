#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Storage.h"
#include "UIElement.h"
#include "UIButton.h"

using namespace sf;
using namespace std;

class UIPanel : public UIElement
{
public:
	RectangleShape headerRect;
	UIButton closeButton;

	UIPanel();

	~UIPanel();

	UIPanel(Vector2f position_, Vector2f size_, Border border, String text_, float headerHeight, bool draggable_);

	void eventHandle(Vector2f mouseCoords);
	
	void update(Vector2f mouseCoords);

	virtual void setAdditionalDraw(RenderWindow& window);

	void setAdditionalPosition();
};

