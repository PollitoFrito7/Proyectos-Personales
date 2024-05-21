#ifndef hand_h
#define hand_h

#include "card.h"
#include "deck.h"

const int MaxHand = 24;

typedef tCardPtr tCardArray[MaxHand];

struct tHand {
	tCardArray cards;
	int counter = 0;
};

void add(tHand& hand, const tCard& card);
void discard(tHand& hand, const int index);
void display(const tHand& hand);
void destroy(tHand& hand);

#endif // hand_h