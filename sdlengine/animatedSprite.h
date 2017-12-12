#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include <vector>
#include <map>

class AnimatedSprite : public Sprite
{
	private:

		struct Animation
		{
		public:
			size_t currentFrame;
			std::vector<SDL_Rect*> frames;
			void updateFrame();
		};

		std::vector<SDL_Rect*> framesRects;
		int framesAmount;

		int frameWidth;
		int frameHeight;

		int textureFramesWidth;
		int textureFramesHeight;

		std::map<size_t, Animation> animations;

		Animation currentAnimation;

	public:
		AnimatedSprite(const char* path, int fWidth, int fHeight);
		~AnimatedSprite();

		void addAnimation(std::string name, std::vector<int> frames);

		void playAnimation(std::string name);

		void draw(int x, int y);

		void update();
};
#endif
