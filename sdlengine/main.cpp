#include "gameManager.h"

int main()
{
	GameManager* gameManager = GameManager::getInstance();

	gameManager->startGame(800,600);

	return 0;
}
