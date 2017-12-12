#ifndef ENEMIGO_B_H
#define ENEMIGO_B_H
#include"Nave.h"
class Enemigo_B:public Nave
{
public:
	Enemigo_B(int _vida, int ataque, int velocidad, int _fireRate,int _posx,int _posy);
	virtual void dibujo();
	virtual void movimiento();
	//virtual void ataque_01();
	//virtual void muerte_01();
//	~Enemigo_B();
	
private:

};



#endif // !ENEMIGO_H
