#include "Debug.h"

void Debug::showFPS(RenderWindow& window, int time)
{
	coolDown += time;
	if (coolDown > 5000)
	{
		if (time != 0)
		{
			fps = time;
			coolDown = 0;
		}
	}
	storage.showText(window, "FPS: " + to_string(fps), 800, 0, 20, Color(220, 220, 220));
}

void Debug::EventHandle(Event& event)
{
	if (event.key.code == Keyboard::G)
		gizmo = !gizmo;
	else if (event.key.code == Keyboard::F)
		showFps = !showFps;
}