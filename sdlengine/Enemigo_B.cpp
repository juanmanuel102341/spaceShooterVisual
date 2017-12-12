#include"Enemigo_B.h"


void Enemigo_B::movimiento() {
	posx -= velocidad;
}
void Enemigo_B::dibujo(){
	sprite= new Sprite("C:/resources/e_2.png");
	anchoSprite = sprite->width;
	altoSprite = sprite->height;
}

Enemigo_B::Enemigo_B (int _vida, int _ataque, int _velocidad, int _fireRate,int _posX,int _posY):Nave(vida, ataque, velocidad, fireRate,posx,posy) {

	posx = _posX;
	posy = _posY;
	direccionX = 0;
	direccionY = 0;
	velocidad =_velocidad;
	fireRate = _fireRate;
	vida = _vida;
	ataque = _ataque;

}
