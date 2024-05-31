#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

// if this is not here sound explodes for some reason
#pragma comment(lib, "Winmm.lib") 

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "blackjack.h"
//TODO// SOUND IMPLEMENTED, FILL THAT SHIT UP WITH SFX
//TODO// impplement different pools of responses and sounds 
//TODO// implement a real play again feature
//TODO// implement a way to win the table
//TODO// fix the display of the hand (FUCK IOMANIP)
int main() {
	{
		tBJGame game;
		string move, splitMove;
		bool insurancePaid = false;
		
		char ok = 'n';

		srand(time(NULL));
		
		init(game);

		do {
			if (game.player1.bank >= 50) {
				betting(game);
				dealing(game);

				playing(game, move, splitMove, insurancePaid);

				if (sum(game.player1) <= 21 && move != "SURRENDER")
					showdown(game);

				if (!insurancePaid && move != "SURRENDER" && move != "EVEN")
				distributeMoney(game, move);


				cout << "PLAY AGAIN? ";
				cin >> ok;
				ok = toupper(ok);
				system("cls");
			}

			else {
				cout << "You poor already? Good. Now get the fuck out." << endl;
				ok = 'n';
			}
			
			if (ok == 'Y') {
				cout << "SHUFFLING...";
				move = "";
				splitMove = "";
				insurancePaid = false;
				roundReset(game);
				system("cls");
			}
		} while (ok == 'Y');
		destroy(game);
	}

	_CrtDumpMemoryLeaks(); // Memory leaks detection

	return 0;
}