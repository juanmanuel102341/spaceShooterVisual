#include "textSprite.h"

TextSprite::TextSprite()
{
	sdlManager = SDLManager::getInstance();
}

TextSprite::~TextSprite()
{
	free();
}

void TextSprite::updateText(std::string text)
{
	free();
	
	SDL_Color color = {255, 255, 255, 255};

	texture = sdlManager->loadTextureFromText(text, color);

	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void TextSprite::render(int x, int y, SDL_Rect* clip)
{
	if (!texture)
	{
		printf("There is not texture to render!");
		return;
	}

	x -= width / 2;
	y -= height / 2;

	SDL_Rect renderQuad = {x, y, width, height};
	
	if( clip != NULL )
	{ 
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	sdlManager->renderTexture(texture, clip, &renderQuad);
}


void TextSprite::free()
{
	if (texture)
		sdlManager->freeTexture(texture);
}
