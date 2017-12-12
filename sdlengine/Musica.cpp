#include"Musica.h"


void Musica::initialize() {
	sdlManager = SDLManager::getInstance();
}
void Musica::cargaSonidoAmbient() {

	music = sdlManager->loadMusic("C:/resources/ambient.wav");
	sdlManager->playMusic(music);
}
void Musica::cargaSonidoDisparo() {

	sound1 = sdlManager->loadSoundFx("C:/resources/shoot.wav");
	sdlManager->playSound(sound1);
}
void Musica::cargaSonidoExplosion() {
	sound2 = sdlManager->loadSoundFx("C:/resources/explosion.wav");
	sdlManager->playSound(sound2);
}
void Musica::cargaSonidoImpacto() {
	sound3 = sdlManager->loadSoundFx("C:/resources/impacto.wav");
	sdlManager->playSound(sound3);
}
void Musica::finMusica() {
	sdlManager->stopMusic();
	music = nullptr;
	sound1 = nullptr;
	sound2 = nullptr;
	sound3 = nullptr;
	sdlManager = nullptr;
	
}

Musica::Musica() {

}