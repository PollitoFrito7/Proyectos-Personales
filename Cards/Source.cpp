#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h> 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "blackjack.h"

int main() {
	{
		tBJGame game;

		srand(time(NULL));

		init(game);

		betting(game);
		dealing(game);
		
		destroy(game);
	}

	_CrtDumpMemoryLeaks(); // Memory leaks detection

	return 0;
}