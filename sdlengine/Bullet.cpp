#include"Bullet.h"

void Bullet::dibujo() {
	switch (id)
	{
	case 0:
		//bullet heroe
		sprite = new Sprite("C:/resources/bullet.png");
		anchoSprite_b = sprite->width;
		altoSprite_b = sprite->height;
		break;
	case 1:
		//bullet enemy
		sprite = new Sprite("C:/resources/bullet_e.png");
		anchoSprite_b = sprite->width;
		altoSprite_b = sprite->height;
		break;
	
	}
	
}
void Bullet::movimiento(){
	posX += velocidad*direccion;

}
void Bullet::muerte_01() {

}
Bullet::Bullet(int _posx,int _posy,int _id,int _velocidad,int _direccion)
{
	posX =_posx;
	posY = _posy;
	id = _id;
	velocidad = _velocidad;
	direccion = _direccion;
}