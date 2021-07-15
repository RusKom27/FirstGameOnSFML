#include "Animator.h"

Animator::Animator()
{
	speed = 0;
	countOfFrames = 0;
}

Animator::Animator(Texture* textures_, float speed_, int countOfFrames_)
{
	textures = textures_;
	speed = speed_;
	countOfFrames = countOfFrames_;
}

void Animator::animation(float timeElapsed, Sprite& sprite)
{
	timer += timeElapsed;
	if (timer > speed)
	{
		sprite.setTexture(textures[frame]);
		if (frame < countOfFrames)
			frame++;
		else
			frame = 0;
		timer = 0;
	}
}