#include"Heroe.h"
#include"Nave.h"


void Heroe::muerte_01() {

}
int Heroe::ataque_01(){
	return 0;
}
void Heroe::teclas() {

	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			direccionX = 1;
			//printf(velocidad);
			break;
		case SDLK_LEFT:
			direccionX = -1;
			break;
		case SDLK_UP:
			direccionY = -1;
			break;
		case SDLK_DOWN:
			direccionY = 1;
			break;
		case SDLK_SPACE:
			if (disparo_bloqueo == false) {
				musica_wav->cargaSonidoDisparo();
				Bullet* copiaBala = nullptr;
				cout << "disparo activo" << endl;
				disparo_bloqueo = true;
				tiempoDisparo.start();
				//posiciones/id= si es heroe=0, si es enemigo=1/velocidad bala/direccion
				copiaBala = new Bullet(posx, posy, 0, 35, 1);
				copiaBala->dibujo();
				copiaBala->posX += anchoSprite - copiaBala->anchoSprite_b - 5;
				copiaBala->posY += altoSprite / 2 - copiaBala->altoSprite_b / 2;

				listaBullet.push_back(copiaBala);
			}
			else {
				cout << "disparo bloqueado" << endl;
			}
			break;
		default:
			break;
		}
	}
	if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.sym)
		{
		case SDLK_RIGHT:
			direccionX = 0;
			//printf(velocidad);
			break;
		case SDLK_LEFT:
			direccionX = 0;
			break;
		case SDLK_UP:
			direccionY = 0;
			break;
		case SDLK_DOWN:
			direccionY = 0;
			break;

		default:
			break;
		}

	}
}
void Heroe::movimiento() {
	//60 ancho
	//70 alto
	tiempoCiclo_disparo();
	//if (posy < 0 || e.key.keysym.sym != SDLK_DOWN) {
		//if (posy + 70 > 600 || e.key.keysym.sym != SDLK_UP) {
	//&&

	if (posx >10 || e.key.keysym.sym == SDLK_RIGHT) {
		if (posx < 710 || e.key.keysym.sym == SDLK_LEFT) {
		
			posx += velocidad*direccionX;
		
		}
	
	}
	if (posy + 70 < 600 || e.key.keysym.sym == SDLK_UP) {
		if (posy > 0 || e.key.keysym.sym == SDLK_DOWN)
		{

				posy += velocidad*direccionY;

		}
	}
	
	while (sdlManager->getPollEvent(&e) != 0)
	{
		teclas();
		
		//printf("entrando even
	//	cout << "posy " << posy<<endl;
		
		}
		
	}
		//printf("entrando eventos heroe");
		
		
	

void Heroe::dibujo() {
	sprite = new Sprite("C:/resources/heroe.png");
	anchoSprite = sprite->width;
	altoSprite = sprite->height;
}

Heroe::Heroe(int _vida,int _ataque,int _velocidad,int _fireRate,int _posX,int _posy):Nave(vida, ataque, velocidad,fireRate,posx,posy) {
	vida = _vida;
	ataque = _ataque;
	posx = _posX;
	posy = _posy;
	direccionX = 0;
	direccionY = 0;
	velocidad = 5;
	fireRate = _fireRate;
	
}
