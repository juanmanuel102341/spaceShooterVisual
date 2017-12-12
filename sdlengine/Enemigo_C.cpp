#include"Enemigo_C.h"

void Enemigo_C::movimiento() {
	posx -= velocidad;
}
void Enemigo_C::dibujo(){
	sprite= new Sprite("C:/resources/e_3.png");
	anchoSprite = sprite->width;
	altoSprite = sprite->height;
}
Enemigo_C::Enemigo_C (int _vida, int _ataque, int _velocidad, int _fireRate,int _posX,int _posY):Nave(vida, ataque, velocidad, fireRate,posx,posy) {

	posx = _posX;
	posy = _posY;
	direccionX = 0;
	direccionY = 0;
	velocidad =_velocidad;
	fireRate = _fireRate;
	vida = _vida;
	ataque = _ataque;

}
