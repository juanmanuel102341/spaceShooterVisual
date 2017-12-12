#include "sdlManager.h"

void SDLManager::initialize()
{

}

bool SDLManager::initSDL(int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Create window
	window = SDL_CreateWindow("SDL Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

	if(window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
	{
		printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
		return false;
	}

	SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
		return false;
	}
	
	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0)
	{
		printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	return true;
}

void SDLManager::close()
{
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	SDL_DestroyWindow(window);
	window = NULL;
	
	IMG_Quit();
	SDL_Quit();
};

		
SDL_Texture* SDLManager::loadTexture(const char* path)
{
	SDL_Texture* imageTexture = NULL;
	SDL_Surface* imageSurface = IMG_Load(path);
	
	if (imageSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, IMG_GetError());
	}
	else
	{
		imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
		
		if (imageTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		SDL_FreeSurface(imageSurface);
	}

	return imageTexture;
}

SDL_Texture* SDLManager::loadTextureFromText(std::string textureText, SDL_Color textColor) 
{ 
	if (ttfFont == NULL)
	{
		printf("TTF Font not loadded! SDL_ttf Error: %s\n", TTF_GetError());
	}

	SDL_Texture* texture = NULL;
	SDL_Surface* surface = TTF_RenderText_Solid(ttfFont, textureText.c_str(), textColor);

	if (surface == NULL) 
	{ 
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	} 
	else 
	{ 
		//Create texture from surface pixels 
		texture = SDL_CreateTextureFromSurface(renderer, surface); 

		if (texture == NULL) 
		{ 
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError()); 
		} 

		SDL_FreeSurface(surface); 
	} 

	return texture; 
} 

void SDLManager::freeTexture(SDL_Texture* texture)
{
	SDL_DestroyTexture(texture);
}

int SDLManager::getPollEvent(SDL_Event* event)
{
	return SDL_PollEvent(event);
}

void SDLManager::clearScreen()
{
	SDL_RenderClear(renderer);
}

void SDLManager::renderTexture(SDL_Texture* texture, SDL_Rect* sourceRect, SDL_Rect* destinyRect)
{
	SDL_RenderCopy(renderer, texture, sourceRect, destinyRect);
}

void SDLManager::updateScreen()
{
	SDL_RenderPresent(renderer);
}

void SDLManager::loadFont(const char* path, int size)
{
	ttfFont = TTF_OpenFont(path, size);
}
		
Mix_Music* SDLManager:: loadMusic(const char* path)
{
	Mix_Music* music = NULL;
	
	music = Mix_LoadMUS(path);
	
	if (music == NULL)
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	return music;
}

Mix_Chunk* SDLManager:: loadSoundFx(const char* path)
{
	Mix_Chunk* sound = NULL;
	
	sound = Mix_LoadWAV(path);
	
	if (sound == NULL)
	{
		printf( "Failed to load beat sound! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	return sound;
}


void SDLManager::playMusic(Mix_Music* music)
{
	Mix_PlayMusic(music, -1);
}

void SDLManager::stopMusic()
{
	Mix_HaltMusic();
}

void SDLManager::playSound(Mix_Chunk* sound)
{
	Mix_PlayChannel(-1, sound, 0);
}

