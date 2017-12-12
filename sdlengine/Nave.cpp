#include"Nave.h"

#include"Heroe.h"

void Nave::disparoMovimiento() {

	Bullet* aux = nullptr;

	for (list<Bullet*>::iterator it_aux =listaBullet.begin(); it_aux != listaBullet.end();) {
		//cout << "entrando";
		aux = *it_aux;
		aux->movimiento();
		aux->sprite->render(aux->posX, aux->posY, NULL);
		
		if (aux->posX > 800|| aux->muerte_bullet||aux->posX<-1) {
			//cout << "destruccion" << endl;
			//it_aux++;
			it_aux =listaBullet.erase(it_aux);
		}
		else {
			++it_aux;
		}
	}
}
void Nave::tiempoCiclo_disparo() {
	
	if (tiempoDisparo.getTicks() > fireRate&&tiempoDisparo.isStarted()) {
	
	//		cout << "tiempo disparo enemigo" << tiempoDisparo.getTicks() << endl;
		//cout << "tiempo cumplido disparo" << endl;
		
		disparo_bloqueo = false;
	
	}
}
void Nave::ataque_01() {
	
//	cout << "tiempo disparo enemy " << tiempoDisparo.getTicks();
//	cout << "bool disparo enemigo" << disparoActivo<<endl;
	if (disparo_bloqueo == false) {
		cout << "disparo enemigo" << endl;
		Bullet* copiaBullet;
		copiaBullet = new Bullet(0, 0,0,5,-1);
		
		copiaBullet->dibujo();
		copiaBullet->posX = posx;
		copiaBullet->posY = posy;
		tiempoDisparo.start();
	//	tiempoDisparo2.start();
	//	cout << "posx bala " << posx;
		listaBullet.push_back(copiaBullet);
		disparo_bloqueo = true;

	}
	//tiempoCiclo_disparo();
	
	//if (tiempoDisparo2.getTicks() > fireRate) {
		//cout << "e";
		//disparoActivo = false;

//	}
}

void Nave::clearObjetos() {

	sprite = nullptr;
	
		listaBullet.erase(listaBullet.begin(), listaBullet.end());
	

}
Nave::Nave(int _vida,int _ataque,int _velocidad,int _fireRate,int _pos_x,int _pos_y) {
	vida = _vida;
	ataque = _ataque;
	velocidad = _velocidad;
	fireRate = _fireRate;
	posx = _pos_x;
	posy = _pos_y;
	musica_wav = musica_wav->getInstance();
	//ataque_01();

}