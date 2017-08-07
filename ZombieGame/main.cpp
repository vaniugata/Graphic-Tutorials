#include <iostream>
#include "MainGame.h"

int main()
{
	MainGame* game = new MainGame();

	game->Run();

	delete game;

	return 0;
}