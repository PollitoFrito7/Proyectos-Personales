#ifndef card_h
#define card_h

const int MaxCard = 13;

enum tSuit {hearts, diamonds, clubs, spades};

struct tCard {
	int number = 13;
	tSuit suit = hearts;
	bool hidden = false;
};

typedef tCard* tCardPtr;

void display(const tCard& card);

#endif // !card_h