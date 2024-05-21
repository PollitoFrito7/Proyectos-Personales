#include "deck.h"

void initDeck(tDeck& deck) {
	for (int i = 0; i < DeckSize; i++) {
		deck.drawn[i] = false;
		deck.cards[i].number = i % MaxCard + 1;

		if (i < MaxCard) {
			deck.cards[i].suit = hearts;
		}

		else if (i < 2 * MaxCard) {
			deck.cards[i].suit = diamonds;
		}

		else if (i < 3 * MaxCard) {
			deck.cards[i].suit = clubs;
		}

		else if (i < DeckSize) {
			deck.cards[i].suit = spades;
		}
	}
}

void shuffle(tDeck& deck) {
	for (int i = 0; i < DeckSize; i++) {
		deck.drawn[i] = false;
	}
}

void destroy(tDeck& deck) {
	delete[] deck.cards;
	delete[] deck.drawn;
}
