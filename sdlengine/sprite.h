#ifndef SPRITE_H
#define SPRITE_H

#include "sdlManager.h"

class Sprite
{
	protected:
		SDLManager* sdlManager;

		SDL_Texture* texture;

		
	
		void load(const char* path);
		void free();

	public:
		int width = 0;
		int height = 0;
		Sprite(const char* path);
		~Sprite();
		
		void render(int x, int y, SDL_Rect* clip);
};
#endif
