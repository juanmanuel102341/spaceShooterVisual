#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "singleton.h"
#include "sdlManager.h"
#include "animatedSprite.h"
#include "textSprite.h"
#include "sprite.h"
#include "timer.h"
#include <sstream>

#include"Nave.h"
#include"Heroe.h"
#include<iostream>
#include<list>
#include <stdlib.h>
#include <time.h> 
using namespace std;
#include<algorithm>
#include"Enemigo_A.h"
#include"Enemigo_B.h"
#include"Enemigo_C.h"
#include"Musica.h"
class GameManager : public Singleton<GameManager>
{
	private:
		
		bool gameOver = false;
		bool gameOver2 = false;
		int windowWidth = 0;
		int windowHeight = 0;
		int cantidad=0;
		int condicionVictoria = 5;
		//SDL_Event e;

		SDLManager* sdlManager = nullptr;

		//AnimatedSprite* animatedSprite;
		TextSprite* textSprite_vida;
		TextSprite* score;
		TextSprite* perder_text;
		TextSprite* win_text;
		TextSprite* text_inicio;
		//Sprite* sprite;
		Heroe* hero_01;
		
		list<Nave*>listaNaves_1;
		

		TextSprite* timeTextSprite;
		std::stringstream vida_Text;
		std::stringstream scoreText;
		std::stringstream cantidadText;
		Timer fpsTimer;
		Timer capTimer;
		Timer oleada_time;
		Timer inicioTime;


		Sprite* sprite_fondo;
		Sprite* sprite_fondo_2;
		//Sprite* currentSpriteFondo;

		bool active_s1=false;
		bool active_s2=true;
		bool inicioActive = true;
		float posXfondo_1 = 0;
		float posXfondo_2 = 0;

		int countedFrames = 0;
		int frameTicks = 0;
		
		int numSpawn ;
		int contador_o_1 = 0;
		float averageFps = 0;
		Musica* musica;
	public:
		
		GameManager();
		~GameManager();
	

		virtual void initialize();
		
		void startGame(int width, int height);

		void update();
		void checkEvents();
		void updateScreen();

		void endGame();
		void finJuego();
		void drawScene();
		void creacionEscuadron_1();
		void creacionEscuadron_2();
		void creacionEscuadron_3();
		void oleada_1();
		void ClearObjetos();
		void textoInicio_01();

		

		bool contactoBulletNave(Nave* e);
		bool contactoBullet_Enemy(Nave*_enemy);
};

#endif //GAME_MANAGER_H
