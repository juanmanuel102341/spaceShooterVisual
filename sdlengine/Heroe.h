#ifndef HEROE_H
#define HEROE_H
//#include"Nave.h"
#include"singleton.h"
#include"Nave.h"
#include"sdlManager.h"

#include"Bullet.h"
class Heroe : public Nave 
  {
public:
	

	//list<Bullet*>listaBullet;
	Heroe(int _vida, int ataque, int velocidad,int _fireRate,int _posX, int _posY);
	virtual int ataque_01();
	virtual void dibujo();
	virtual void movimiento();
	virtual void muerte_01();
	
	void destruir();
	void teclas();
	private:
	  SDL_Event e;
	  SDLManager* sdlManager = nullptr;


};


#endif 