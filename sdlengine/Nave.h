#ifndef NAVE_H
#define NAVE_H
//#include"gameManager.h"
//#include"Heroe.h"
#include<iostream>
using namespace std;
#include"sprite.h"
#include"timer.h"
#include<algorithm>
#include<list>
#include"Bullet.h"
#include"Musica.h"
class Nave
{
public:
	int vida=0;
	int ataque=0;
	bool muerte=false;
	int velocidad=0;
	int direccionX;
	int direccionY;
	int posx=0;
	int posy=0;
	int velocidadBala;
	int fireRate;
	bool disparo_bloqueo = false;
	int anchoSprite = 0;
	int altoSprite = 0;
	int acumTiempo;
	Musica* musica_wav;

	list<Bullet*>listaBullet;
	Timer tiempoDisparo;
	//Timer tiempoDisparo2;
	Sprite* sprite;
	Sprite* sprite_disparo;

	Nave(int _vida,int _ataque,int _velocidad,int _fireRate,int _posX,int _posY);
	virtual void dibujo()=0;
	virtual void movimiento()=0;
	void ataque_01();
//	virtual void muerte_01()=0;
	void tiempoCiclo_disparo();
	void disparoMovimiento();
	void clearObjetos();

private:

};




#endif // !NAVE_H

