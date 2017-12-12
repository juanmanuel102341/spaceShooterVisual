#ifndef ENEMIGO_A_H
#define ENEMIGO_A_H
#include"Nave.h"
class Enemigo_A:public Nave
{
public:
	Enemigo_A(int _vida, int ataque, int velocidad, int _fireRate,int _posx,int _posy);
	virtual void dibujo();
	virtual void movimiento();
	//virtual void ataque_01();
	//virtual void muerte_01();
//	~Enemigo_A();
	
private:

};



#endif // !ENEMIGO_H
