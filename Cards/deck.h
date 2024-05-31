#ifndef deck_h
#define deck_h

#include "card.h"

const int DeckSize = 52;

struct tDeck {
	tCardPtr cards = new tCard[DeckSize];
	bool* drawn = new bool[DeckSize];
};

void initDeck(tDeck& deck);
void shuffle(tDeck& deck);
void destroy(tDeck& deck);
#endif // !deck_h