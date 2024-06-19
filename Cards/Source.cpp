#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <curses.h>
using namespace std;

// if this is not here sound explodes for some reason
#pragma comment(lib, "Winmm.lib") 

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "blackjack.h"

int main() {
	{
		tBJGame game;
		string move, splitMove;
		bool insurancePaid = false;
		
		char ok = 'n';

		srand(time(NULL));
		
		initscr();
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


				cout << "Are you ready to play another round?" << endl;
				cout << "YOUR RESPONSE [Y/N]: ";
				cin >> ok;
				ok = toupper(ok);
				system("cls");
			}

			else {
				cout << "You poor already? Good. Now get the fuck out." << endl;
				_getch();
				ok = 'n';
			}
			
			if (game.player1.bank != 0 && ok == 'Y') {
				cout << "SHUFFLING...";
				move = "";
				splitMove = "";
				insurancePaid = false;
				roundReset(game);
				system("cls");
			}
		} while (ok == 'Y');
		destroy(game);
		endwin();
	}

	_CrtDumpMemoryLeaks(); // Memory leaks detection

	return 0;
}