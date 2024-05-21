#include "card.h"

#include <iostream>
using namespace std;

const int CardWidth = 10;
const char HWall = char(205), VWall = char(186), URCorner = char(187), ULCorner = char(201), LLCorner = char(200), LRCorner = char(188);

char suitChar(const tSuit& suit) {
	return char(int(suit) + 3);
}

char numDisplay(const int& num) {
	return num < 10 ? char(int('0') + num) : num == 10? 'T' : num == 11 ? 'J' : num == 12 ? 'Q' : 'K';
}

void displayTop(const tCard & card) {
	cout << ULCorner;
	for (int i = 0; i < CardWidth + 0.5 * CardWidth; i++) {
		cout << HWall;
	}
	cout << URCorner << endl;


	cout << VWall;

	for (int i = 0; i < CardWidth + 0.5 * CardWidth; i++) {
		if (i == 1) {
			card.hidden ? cout << "?" : cout << suitChar(card.suit);
		}

		else
			cout << " ";
	}
	cout << VWall << endl;

}

void displayBottom(const tCard& card) {
	cout << VWall;

	for (int i = 0; i < CardWidth + 0.5 * CardWidth; i++) {
		if (i == CardWidth + 0.5 * CardWidth - 2) {
			card.hidden ? cout << "?" : cout << suitChar(card.suit);
		}

		else
			cout << " ";
	}
	cout << VWall << endl;

	cout << LLCorner;
	for (int i = 0; i < CardWidth + 0.5 * CardWidth; i++) {
		cout << HWall;
	}
	cout << LRCorner << endl;
}

void display(const tCard& card) {
	displayTop(card);

	for (int i = 0; i < CardWidth - 2; i++) {
		cout << VWall;
		for (int j = 0; j < CardWidth + 0.5 * CardWidth; j++) {
			if ((i == 0 && j == 1) || (i == CardWidth - 3 && j == CardWidth + 0.5 * CardWidth - 2))
				card.hidden? cout << "?" : cout << numDisplay(card.number);

			else {
				cout << " ";
			}
		}
		cout << VWall << endl;
	}

	displayBottom(card);
}
