#include "Debug.h"

void Debug::showFPS(RenderWindow& window, float elapsed)
{
	coolDown += elapsed;
	if (coolDown > 1)
	{
		fps = elapsed * 10000;
		coolDown = 0;
	}
	storage.showText(window, "FPS: " + to_string(fps),Vector2f(0,0), 20, Color(220, 220, 220));
}

void Debug::EventHandle(Event& event)
{
	if (event.key.code == Keyboard::F)
		showFps = !showFps;
}