#ifndef SDL_MANAGER_H
#define SDL_MANAGER_H

#include "singleton.h"
#include "utils.h"

#if __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#else
#include <SDL.h>
#undef main
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#endif

class SDLManager : public Singleton<SDLManager>
{
	private:

		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;

		Color backgroundColor; 
		
		TTF_Font* ttfFont = NULL;

	public:

		virtual void initialize();

		bool initSDL(int width, int height);

		SDL_Texture* loadTexture(const char* path);
		SDL_Texture* loadTextureFromText(std::string textureText, SDL_Color textColor);
		void freeTexture(SDL_Texture* texture);

		void close();

		int getPollEvent(SDL_Event* event);

		void clearScreen();

		void renderTexture(SDL_Texture* texture, SDL_Rect* srcRect = nullptr, SDL_Rect* dstRect = nullptr);

		void updateScreen();

		void loadFont(const char* path, int size);

		Mix_Music* loadMusic(const char* path);
		Mix_Chunk* loadSoundFx(const char* path);

		void playMusic(Mix_Music* music);
		void stopMusic();
		void playSound(Mix_Chunk* sound);
};
#endif //SDL_MANAGER_H
