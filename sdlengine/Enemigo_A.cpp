#include"Enemigo_A.h"


void Enemigo_A::movimiento() {
	posx -= velocidad;
}
void Enemigo_A::dibujo(){
	sprite= new Sprite("C:/resources/e_1.png");
	anchoSprite = sprite->width;
	altoSprite = sprite->height;

}



Enemigo_A::Enemigo_A (int _vida, int _ataque, int _velocidad, int _fireRate,int _posX,int _posY):Nave(vida, ataque, velocidad, fireRate,posx,posy) {

	posx = _posX;
	posy = _posY;
	direccionX = 0;
	direccionY = 0;
	velocidad =_velocidad;
	fireRate = _fireRate;
	vida = _vida;
	ataque = _ataque;


}
