#ifndef ENEMIGO_C_H
#define ENEMIGO_C_H
#include"Nave.h"
#include"Bullet.h"
class Enemigo_C:public Nave
{
public:
	
	Enemigo_C(int _vida, int ataque, int velocidad, int _fireRate,int _posx,int _posy);
	
	virtual void dibujo();
	virtual void movimiento();
	//virtual void ataque_01();
//	virtual void muerte_01();
//	~Enemigo_C();
	
private:

};



#endif // !ENEMIGO_H
