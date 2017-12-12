#ifndef BULLET_H
#define BULLET_H

#include"sprite.h"

class Bullet
{
public:
	int posX;
	int posY;
	int velocidad;
	int direccion;
	int anchoSprite_b;
	int altoSprite_b;
	bool muerte_bullet = false;
	int id=0;
	Sprite* sprite;
	

	Bullet(int posX, int posY,int _id,int _velocidad,int _direccion);
//	~Bullet();

	 void dibujo();
	 void movimiento();
	void muerte_01();
	

private:

};





#endif // !BULLET_H

