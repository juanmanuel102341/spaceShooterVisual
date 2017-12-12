#include "sprite.h"

Sprite::Sprite(const char* path)
{
	sdlManager = SDLManager::getInstance();

	load(path);
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

Sprite::~Sprite()
{
	free();
}

void Sprite::load(const char* path)
{
	texture = sdlManager->loadTexture(path);
}

void Sprite::render(int x, int y, SDL_Rect* clip)
{
	if (!texture)
	{
		printf("There is not texture to render!");
		return;
	}

	SDL_Rect renderQuad = {x, y, width, height};
	
	if( clip != NULL )
	{ 
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	sdlManager->renderTexture(texture, clip, &renderQuad);
}


void Sprite::free()
{
	if (texture)
		sdlManager->freeTexture(texture);
}
