#include "hand.h"

#include <iostream>
using namespace std;

void add(tHand& hand, const tCard& card) {
	hand.cards[hand.counter] = new tCard(card);
	hand.counter++;
}

void discard(tHand& hand, const int index) {
	for (int i = index; i < hand.counter; i++) {
		hand.cards[i - 1] = hand.cards[i];
	}

	hand.cards[hand.counter - 1] = new tCard;
	delete hand.cards[hand.counter - 1];
	hand.counter--;
}

void display(const tHand& hand) {
	for (int i = 0; i < hand.counter; i++) {
		display(*hand.cards[i]);
	}
}

void destroy(tHand& hand) {
	for (int i = 0; i < hand.counter; i++) {
		delete hand.cards[i];
	}

	hand.counter = 0;
}
