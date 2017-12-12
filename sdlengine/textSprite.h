#ifndef TEXT_SPRITE_H
#define TEXT_SPRITE_H

#include "sdlManager.h"
#include <string>

class TextSprite 
{
	protected:
		SDLManager* sdlManager;

		SDL_Texture* texture = NULL;
		
		int width = 0;
		int height = 0;
	
		void free();

	public:
		TextSprite();
		~TextSprite();
		
		void updateText(std::string text);

		void render(int x, int y, SDL_Rect* clip);
};

#endif
