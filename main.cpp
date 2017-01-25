#include "LibsAndConstants.h"
#include "Game.h"

int main()
{
	Game game;

	game.setupSystem();
	game.initialize();

	while( game.loop() );

	game.shutdown();

	return 0;
}

// Спасибо Tinaynox`у, за суперские адекватные и полезные уроки на Pikabu!

//////////////////////////
//First Game by DFD Works
//         - January 2017.