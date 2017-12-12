#include "animatedSprite.h"
#include "utils.h"


AnimatedSprite::AnimatedSprite(const char* path, int fWidth, int fHeight) : Sprite(path)
{
	frameWidth = fWidth;
	frameHeight = fHeight;

	textureFramesWidth = width / frameWidth;
	textureFramesHeight = height / frameHeight;;

	framesAmount =  textureFramesWidth * textureFramesHeight;

	for (int i = 0; i < frameHeight; i++)
	{
		for (int j = 0; j < frameWidth; j++)
		{
			SDL_Rect* rect = new SDL_Rect();

			rect->x = j * textureFramesWidth;
			rect->y = i * textureFramesHeight;
			rect->w = textureFramesWidth;
			rect->h = textureFramesHeight;

			framesRects.push_back(rect);
		}
	}
}

void AnimatedSprite::addAnimation(std::string name, std::vector<int> frames)
{
	Animation animation;

	animation.currentFrame = 0;
	
	for (size_t i = 0; i < frames.size(); i++)
	{
		animation.frames.push_back(framesRects[frames[i]]);
		animation.frames.push_back(framesRects[frames[i]]);
		animation.frames.push_back(framesRects[frames[i]]);
		animation.frames.push_back(framesRects[frames[i]]);
	}

	animations[hashFn(name)] = animation;
}

void AnimatedSprite::playAnimation(std::string name)
{
	size_t key = hashFn(name);

	if (animations.find(key) == animations.end())
	{
		printf("Animation %s does not exists", name.c_str());
		return;
	}

	currentAnimation = animations[key];
}

void AnimatedSprite::draw(int x, int y)
{
	render(x, y, currentAnimation.frames[currentAnimation.currentFrame]);
}

void AnimatedSprite::update()
{
	currentAnimation.updateFrame();
}

void AnimatedSprite::Animation::updateFrame()
{
	currentFrame++;

	if (currentFrame >= frames.size())
	{
		currentFrame = 0;
	}
}
