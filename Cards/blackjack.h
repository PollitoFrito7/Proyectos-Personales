#ifndef blackjack_h
#define blackjack_h

#include "hand.h"
#include "card.h"
#include "deck.h"

#include <string>

struct tPlayer {
	tHand hand;
	double bank = 0;
	std::string name = "CROUPIER";
};

struct tBJGame {
	tDeck deck;
	tPlayer croupier;
	tPlayer player1;
	tPlayer split;
	double bet; 
};

int sum(tPlayer player);
void init(tBJGame& game);
void betting(tBJGame& game);
void display(const tBJGame& game);
bool canInsurance(const tBJGame& game);
bool canEven(const tBJGame& game);
bool canSplit(const tBJGame& game);
bool canSurrender(const tBJGame& game);
std::string menu(const tBJGame& game);
bool insurance(tBJGame& game);
void even(tBJGame& game);
void split(tBJGame& game);
void surrender(tBJGame& game);
void hit(tBJGame& game, tPlayer& player);
void dealing(tBJGame& game);
void playing(tBJGame& game, std::string& move, std::string& splitMove, bool& insurancePaid);
void showdown(tBJGame& game);
bool win(const tBJGame& game, const tPlayer& player);
bool loose(const tBJGame& game, const tPlayer& player);
void distributeMoney(tBJGame& game, std::string move);
void roundReset(tBJGame& game);
void destroy(tBJGame& game);

#endif // !blackjack_h