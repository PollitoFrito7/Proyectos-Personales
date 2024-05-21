#ifndef blackjack_h
#define blackjack_h

#include "hand.h"
#include "card.h"
#include "deck.h"

#include <string>

struct tPlayer {
	tHand hand;
	double bank = 0;
	std::string name = "CRUPIER";
};

struct tBJGame {
	tDeck deck;
	tPlayer crupier;
	tPlayer player1;
	double bet; 
};

void init(tBJGame& game);
void betting(tBJGame& game);
void display(const tBJGame& game);
bool insurance(const tBJGame& game);
bool even(const tBJGame& game);
void hit(const tBJGame& game, tPlayer& player);
void dealing(tBJGame& game); // display all hands and bet //TODO// Implement a sleep() functionality
void destroy(tBJGame& game);

#endif // !blackjack_h

