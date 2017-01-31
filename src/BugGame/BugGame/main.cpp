////////////////////////////////////
// Main
//
// Author: Triold, Name, Eugene
//
// **.01.17
////////////////////////////////////

////////////////////////////////////
// Includes
#include "LibsAndConstants.h"
#include "Game.h"
#include "Improvements.h"


PTR(Improvements);


int main()
{
	
	
	Game game;
		
	
	game.setupSystem();
	game.initialize();
	
	while (game.loop());
	
	game.shutdown();

	return 0;

} 

// ������� Tinaynox`�, �� ��������� ���������� � �������� ����� �� Pikabu!

//////////////////////////
//First Game by DFD Works
//         - January 2017.