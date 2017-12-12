#ifndef MUSICA_H
#define MUSICA_H
#include"singleton.h"
#include"sdlManager.h"

class Musica:public Singleton<Musica>
{
public:
	Musica();
	//~Musica();
	Mix_Music* music;
	Mix_Chunk* sound1;
	Mix_Chunk* sound2;
	Mix_Chunk* sound3;
	
	void cargaSonidoAmbient();
	void cargaSonidoDisparo();
	void cargaSonidoExplosion();
	void cargaSonidoImpacto();
	void finMusica();
private:
	SDLManager* sdlManager = nullptr;
	virtual void initialize();
};


#endif // !MUSICA_H

