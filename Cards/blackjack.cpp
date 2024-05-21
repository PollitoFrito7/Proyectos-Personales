#include "blackjack.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <algorithm>
#include<windows.h>
using namespace std;

int chooseCard(tDeck deck) {
	int aux = 0;

	do {
		aux = rand() % DeckSize;
	} while (deck.drawn[aux] == true);

	deck.drawn[aux] = true;

	return aux;
}

void destroy(tPlayer player) {
	destroy(player.hand);
	player.bank = 50;
	player.name = "CRUPIER";
}

void init(tBJGame& game) {
	initDeck(game.deck);
	game.crupier.bank = 1000000;
	game.player1.bank = 500;

	cout << "What is your name, kid?" << endl;
	cin >> game.player1.name;
	cout << "Is that so? Well, " << game.player1.name << ". Welcome to my fucking table." << endl << endl;
	cout << "-PRESS ANY KEY TO CONTINUE-";
	_getch();
	system("cls");
}

void betting(tBJGame& game) {
	cout << "Place your bet: ";
	cin >> game.bet;

	while (game.bet < 50 || game.bet > game.player1.bank) {
		cout << "Are you dumb? Place a valid bet or get the fuck out of my table: ";
		cin >> game.bet;
	}
}

void display(const tBJGame& game) { //TODO// solve transform with auxiliary string
	string aux = game.player1.name;

	transform(aux.begin(), aux.end(), aux.begin(), toupper);

	system("cls");
	for (int i = 0; i < 50; i++) {
		cout << "-";
	}

	cout << endl << "CRUPIER'S HAND:" << endl;
	display(game.crupier.hand);
	cout << endl;

	for (int i = 0; i < 50; i++) {
		cout << "-";
	}

	cout << endl << aux << setw(20) << left << "'S HAND:";
	cout << "BET: " << fixed << setprecision(2) << game.bet << endl;
	display(game.player1.hand);
	cout << endl;
}

bool insurance(const tBJGame& game) {
	return ;
}

bool even(const tBJGame& game) {
	return false;
}

void hit(const tBJGame& game, tPlayer& player) {
	int index = 0;

	index = chooseCard(game.deck);

	add(player.hand, game.deck.cards[index]);
	if (player.name == "CRUPIER" && player.hand.counter == 1) {
		player.hand.cards[player.hand.counter - 1]->hidden = true;
	}
}

void dealing(tBJGame& game) {
	while (game.crupier.hand.counter < 2) {
		hit(game, game.player1);
		display(game);
		Sleep(1000);
		hit(game, game.crupier);
		display(game);
		Sleep(1000);
	}
}

void destroy(tBJGame& game) {
	destroy(game.deck);
	destroy(game.crupier);
	destroy(game.player1);
	game.bet = 0;
}
