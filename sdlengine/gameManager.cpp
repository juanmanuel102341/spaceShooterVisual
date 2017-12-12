#include "gameManager.h"

#include <stdio.h>
#include <vector>
//#include"Nave.h"
//#include"Heroe.h"
const int SCREEN_FPS = 60;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

void GameManager::initialize()
{
	sdlManager = SDLManager::getInstance();
}
		
void GameManager::startGame(int width, int height)
{
	windowWidth = width;
	windowHeight = height;





	if (sdlManager->initSDL(windowWidth, windowHeight))
	{
		
		//Text
	
		
		timeTextSprite = new TextSprite();
		
		//Animation
		//animatedSprite = new AnimatedSprite("C:/resources/scottpilgrim.png", 8, 2);
		
	//	std::vector<int> frames = {0, 1, 2, 3, 4, 5, 6, 7};
		//animatedSprite->addAnimation("run", frames);
		//animatedSprite->playAnimation("run");
		
		//Sprite
	
		sprite_fondo = new Sprite("C:/resources/fondo.png");
		sprite_fondo_2 = new Sprite("C:/resources/fondo_2.png");
	//	currentSpriteFondo = sprite_fondo;
		//int _vida,int _ataque,int _velocidad,int _fireRate,int _posX,int _posy
		sdlManager->loadFont("C:/resources/font.ttf", 28);

		
		//timeText.str("");
		textSprite_vida = new TextSprite();
		score = new TextSprite();
		
	
		
		hero_01 = new Heroe(300,30,5,500,0,windowHeight/2);
		hero_01->dibujo();
		hero_01->posy -= hero_01->altoSprite / 2;
		vida_Text.str("");
		vida_Text << "VIDA: " << hero_01->vida;
		//timeTextSprite->updateText(timeText.str());
		textSprite_vida->updateText(vida_Text.str());
	
		scoreText.str("");
		scoreText << "NAVES: " << cantidad;
		score->updateText(scoreText.str());
		
		musica = musica->getInstance();
		musica->cargaSonidoAmbient();
	
		
	}

		
	countedFrames = 0;
	fpsTimer.start();

	oleada_time.start();
	numSpawn = rand() % 2500 + 1000;
	update();
}

void GameManager::update()
{
	while (!gameOver)
	{
		if (inicioTime.getTicks() >= 3000) {

			inicioActive = false;
			//inicioTime.stop();
		}
		checkEvents();

		averageFps = countedFrames / (fpsTimer.getTicks() / 1000.f );
		if (averageFps > 2000000)
			averageFps = 0;
		
		//Update animation
		//animatedSprite->update();
		
		//Update time Text
		
		updateScreen();
		
		countedFrames++;

		//If frame finished early
		frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICK_PER_FRAME)
		{
			SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
		}
	}
	//finJuego();
	//endGame();
}
void GameManager::finJuego() {
	
	gameOver = true;
	sdlManager->clearScreen();
	
	if (hero_01->vida <= 0) {
		perder_text = new TextSprite();
		perder_text->updateText("PERDISTE!!!!");
		perder_text->render(windowWidth / 2, windowHeight / 2, NULL);
	}else{
		win_text = new TextSprite();
		win_text->updateText("GANASTE!!!!");
		win_text->render(windowWidth / 2, windowHeight / 2, NULL);
	}
	ClearObjetos();
	sdlManager->updateScreen();

}
void GameManager::endGame()
{
	//sdlManager->close();
}

void GameManager::checkEvents()
{
	hero_01->movimiento();
	
	}

void GameManager::updateScreen()
{
	if (!gameOver2) {

		if (inicioActive)
		{
			textoInicio_01();
			sdlManager->updateScreen();
		}
		else {

			sdlManager->clearScreen();

			drawScene();

			sdlManager->updateScreen();
		}
		}
	else {
		finJuego();
	}
}

void GameManager::drawScene()
{

	//timeTextSprite->render(windowWidth / 2, 50, NULL);

	//animatedSprite->draw(0, 0);
	if (active_s1 == false) {
		sprite_fondo->render(posXfondo_1, 0, NULL);
		posXfondo_1 -= 1;
//		cout << "posx1 " << posXfondo_1<<endl;
	}
	if (active_s2 == false) {
	
		sprite_fondo_2->render(posXfondo_2, 0, NULL);
		posXfondo_2 -= 1;
		//cout << "posx 2 " << posXfondo_2<<endl;
	}
	vida_Text.str("");
	vida_Text << "VIDA: " << hero_01->vida;
	
	textSprite_vida->updateText(vida_Text.str());
	scoreText.str("");
	scoreText << "NAVES: " << cantidad;
	score->updateText(scoreText.str());



	textSprite_vida->render(100,20, NULL);
	score->render(600, 20, NULL);

hero_01->sprite->render(hero_01->posx,hero_01->posy, NULL);
hero_01->disparoMovimiento();
oleada_1();
Nave* auxEnemy=nullptr;
for (list<Nave*>::iterator it_aux = listaNaves_1.begin(); it_aux != listaNaves_1.end();) {
	
	auxEnemy = *it_aux;
	auxEnemy->sprite->render(auxEnemy->posx, auxEnemy->posy, NULL);
	
	auxEnemy->movimiento();
	//auxEnemy->tiempoDisparo.start();
	auxEnemy->ataque_01();//disparo creacion
	
	auxEnemy->disparoMovimiento();//disparo mov
	
	//auxEnemy->tiempoDisparo.start();
	auxEnemy->tiempoCiclo_disparo();//timer disparo
	
	if (contactoBullet_Enemy(auxEnemy)) {
		//cout << "contacto heroe"<<endl;
		hero_01->musica_wav->cargaSonidoImpacto();
		hero_01->vida -= auxEnemy->ataque;
		
		cout << "VIDA HEROE " << hero_01->vida;
	}

	
	
	if (contactoBulletNave(auxEnemy)) {
		auxEnemy->musica_wav->cargaSonidoImpacto();
		auxEnemy->vida -= hero_01->ataque;
	}
	if (auxEnemy->vida < 0) {
		
		auxEnemy->musica_wav->cargaSonidoExplosion();
		cout << "muerte enemigo pos" << endl;
		auxEnemy->posy = -auxEnemy->altoSprite;//lo saco de pantalla para q las balas "sigan viviendo"despues igual se elimina 
		auxEnemy->tiempoDisparo.stop();//paramos el tiempo para q para n siga disparando
		auxEnemy->disparo_bloqueo = true;//nos aseguramos via bloqueando booleando disparo 
		if (auxEnemy->listaBullet.size() <= 0&&auxEnemy->muerte==false) {
			//ahora si borramos
			cantidad++;
			auxEnemy->muerte = true;
		
		}
	}

	if (auxEnemy->posx <0||auxEnemy->muerte) {
		
		//cout << "destruccion enemigos" << endl;
		//it_aux++;
		
		it_aux = listaNaves_1.erase(it_aux);
		cout << "size enemy " << listaNaves_1.size();
	}
	else {
	
		++it_aux;
		
	}
	

	
}


//////////////////fondo////////////////
if (posXfondo_1 < -sprite_fondo->width/2&&active_s2) {
	//-800
	//cout << "aparece sprite 2" << endl;
	active_s2 = false;
	posXfondo_2 =790;//lo q falta recorrer 790, ahi apareces
	
	
}

if (posXfondo_2 < -800 && active_s1) {
	//0
	//le falta recorrer 800 
	//cout << "vuelve aparecer sprite 1"<<endl;
	active_s1 = false;
	posXfondo_1 = 790;
}



if (posXfondo_1 < -sprite_fondo->width) {
	//te desactivas en -1600
	//cout << "desaparece sprite 1!!!!" << endl;
	active_s1 = true;
}
//if(posXfondo_2)

if (posXfondo_2 < -sprite_fondo_2->width ) {
	//te desactivas en -1600
//	cout << "limite sprite 2!!!!" << endl;
	active_s2 = true;
}

if (cantidad >= condicionVictoria) {
	gameOver2 = true;
}
if (hero_01->vida <= 0) {
	gameOver2 = true;
}
}

void GameManager::creacionEscuadron_1() {
	
	//central
		Nave* enemigos;
		int rdisp = rand() % 4000 + 2500;
	    enemigos = new Enemigo_A(10, 10,2, rdisp, windowWidth,0);//se mueren de una
		enemigos->dibujo();
		
		int auxAncho = enemigos->anchoSprite;
		int auxAlto = enemigos->altoSprite;
	//	int ls = windowHeight - auxAlto * 3;
		//int li = auxAlto * 3;
		int numPosSpawn =windowHeight/2-auxAlto/2+rand() % 80+0 ;
		cout << "pos random y " << numPosSpawn<<endl;
	//	enemigos->posx += auxAncho/2;
		enemigos->posy = numPosSpawn;
		
		//int _vida, int _ataque, int _velocidad, int _fireRate, int _pos_x, int _pos_y
		
		listaNaves_1.push_back(enemigos);
		
		int pos_j_x = enemigos->posx;
		int pos_j_y = enemigos->posy;

		//1eras alas
		rdisp = rand() % 6000 + 3800;
		enemigos = new Enemigo_A(10, 10, 2, rdisp, pos_j_x+auxAncho,pos_j_y+auxAlto);
		enemigos->dibujo();
		listaNaves_1.push_back(enemigos);

		rdisp = rand() % 6000 + 3800;
		enemigos = new Enemigo_A(10, 10, 2, 1000, pos_j_x + auxAncho , pos_j_y -auxAlto);
		enemigos->dibujo();
		enemigos->disparo_bloqueo = true;//no dispare muchas balas
		listaNaves_1.push_back(enemigos);

		//2das alas
		rdisp = rand() % 8000 + 4800;
		enemigos = new Enemigo_A(10, 10, 2, rdisp, pos_j_x + auxAncho*2, pos_j_y + auxAlto*2);
		enemigos->dibujo();
		listaNaves_1.push_back(enemigos);


		rdisp = rand() % 9000 + 5800;
		enemigos = new Enemigo_A(10, 10, 2, rdisp, pos_j_x + auxAncho*2 , pos_j_y - auxAlto*2 );
		enemigos->dibujo();
		enemigos->disparo_bloqueo = true;
		listaNaves_1.push_back(enemigos);

}

void GameManager::creacionEscuadron_2() {
	Nave* enemigos;

	int rdisp = rand() % 3000 + 2500;
	//vida/ataque/velocidad/fire_rate/posx/posy
	enemigos = new Enemigo_B(50, 20, 2, rdisp, windowWidth, 0);//mueren por 2 disparos
	enemigos->dibujo();

	int auxAncho = enemigos->anchoSprite;
	int auxAlto = enemigos->altoSprite;
	int numPosSpawn = windowHeight / 2 - auxAlto / 2 + rand() % 50 + 0;
	
	enemigos->posy = numPosSpawn;
	enemigos->tiempoDisparo.start();
	listaNaves_1.push_back(enemigos);

	int pos_j_x = enemigos->posx;
	int pos_j_y = enemigos->posy;

	//1eras alas
	enemigos = new Enemigo_B(50, 20, 2, 1000, pos_j_x + auxAncho, pos_j_y + auxAlto);
	enemigos->disparo_bloqueo = true;//bloqueamos disparo muchas balas sn
	enemigos->dibujo();
	listaNaves_1.push_back(enemigos);

	enemigos = new Enemigo_B(50, 20, 2, 1600, pos_j_x + auxAncho, pos_j_y - auxAlto);
	enemigos->dibujo();
	enemigos->disparo_bloqueo = true;//idem
	listaNaves_1.push_back(enemigos);

	rdisp = rand() % 3000 + 2500;
	enemigos = new Enemigo_B(50, 20, 2, rdisp, pos_j_x + auxAncho*2, pos_j_y + auxAlto/2);
	enemigos->dibujo();
	listaNaves_1.push_back(enemigos);

}
void GameManager::creacionEscuadron_3() {
	Nave* enemigos;
	int rdisp = rand() % 2000+ 1800;
	//vida/ataque/velocidad/fire_rate/posx/posy
	enemigos = new Enemigo_C(70, 40, 2, rdisp, windowWidth, windowHeight / 2);//mueren al 3er disparo
	enemigos->dibujo();
	//cout << "posxbase  " << windowWidth;
	int auxAncho = enemigos->anchoSprite;
	int auxAlto = enemigos->altoSprite;
	int numPosSpawn = windowHeight / 2 - auxAlto / 2 + rand() % 30 + 0;
	enemigos->posy = numPosSpawn;
	listaNaves_1.push_back(enemigos);

	int pos_j_x = enemigos->posx;
	int pos_j_y = enemigos->posy;
	 rdisp = rand() % 2000 + 1800;
	enemigos = new Enemigo_C(70, 40, 2, rdisp, pos_j_x, pos_j_y + auxAlto+30);
	enemigos->dibujo();
	//enemigos->ataque_01();
	listaNaves_1.push_back(enemigos);
	enemigos = new Enemigo_C(70, 40, 2, 2500, pos_j_x, pos_j_y - auxAlto-30);
	enemigos->dibujo();
	listaNaves_1.push_back(enemigos);

}
void GameManager::oleada_1() {
	
	

	if (oleada_time.getTicks() > numSpawn) {
		

		if (contador_o_1 > 4) {
			creacionEscuadron_3();
			oleada_time.start();

			contador_o_1 = 0;

			numSpawn = rand() % 4500 + 3500;
		
		}else if (contador_o_1 > 3) {
			creacionEscuadron_2();
			oleada_time.start();
			numSpawn = rand() % 5000 + 4000;
			
		}
		else {
			cout << "num spawn " << numSpawn;
			creacionEscuadron_1();
			oleada_time.start();
			numSpawn = rand() % 5000 +4500;
			
		}
		contador_o_1++;
	}
}
bool GameManager::contactoBulletNave(Nave* _e) {

	for (list<Bullet*>::iterator it_aux = hero_01->listaBullet.begin(); it_aux != hero_01->listaBullet.end();it_aux++) {
		//cout << "tam ";
		Bullet* aux = *it_aux;
	
		if (aux->posX + aux->anchoSprite_b>=_e->posx)
		{

			//cout << "no igualdad en x" << endl;
			if (aux->posY <= _e->posy + _e->altoSprite&&aux->posY + aux->altoSprite_b >= _e->posy) {
				//cout << "igualdad " << endl;
				aux->muerte_bullet = true;

				return true;
			}
			else {
				return false;
			}
		}
	}
	
}
bool GameManager::contactoBullet_Enemy(Nave* _enemy) {
	//cout << "size enemy bala " << _enemy->listaBullet.size()<<endl;

	if (_enemy->listaBullet.size() > 0) {
		for (list<Bullet*>::iterator it_aux = _enemy->listaBullet.begin(); it_aux != _enemy->listaBullet.end(); it_aux++) {
			//cout << "tam ";
			Bullet* aux = *it_aux;
			//cout << "pos x heroe " << hero_01->posx;
			//cout << "pos x bala " << aux->posX << endl;
			if (aux->posX <= hero_01->posx+hero_01->anchoSprite)
			{

				//cout << "igualdad en x" << endl;
				//cout << "pos y bala " <<aux->posY<< endl;
				//cout << "pos y baja heroe " << hero_01->posy;
				//cout << "pos y alta heroe " << hero_01->posy+ hero_01->altoSprite;
				//cout << "pos x bala " << aux->posX<<endl;
				//cout << "pos x heroe " << hero_01->posx;

				bool chocoenY = aux->posY <= hero_01->posy + hero_01->altoSprite && aux->posY + aux->altoSprite_b >= hero_01->posy;
				if (chocoenY) {
					cout << "contacto !!!!!!!!!!!!!! a heroe " << endl;
					cout << "ataque " << _enemy->ataque;
					aux->muerte_bullet = true;

					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
}
void GameManager::textoInicio_01() {

	text_inicio = new TextSprite();

	cantidadText.str("");
	cantidadText << "MATA: " << condicionVictoria << " NAVES";
	text_inicio->updateText(cantidadText.str());
	text_inicio->render(windowWidth / 2, windowHeight / 2, NULL);
	
	
}
void GameManager::ClearObjetos() {
	musica->finMusica();
	hero_01->clearObjetos();
	delete hero_01;
	sprite_fondo = nullptr;
	sprite_fondo_2 = nullptr;
	timeTextSprite = nullptr;
	timeTextSprite = nullptr;
	text_inicio = nullptr;
	score = nullptr;
	listaNaves_1.erase(listaNaves_1.begin(), listaNaves_1.end());
	
	}

GameManager::GameManager()
{
	srand(time(NULL));

	inicioTime.start();

	
	initialize();
}

GameManager::~GameManager()
{
}
