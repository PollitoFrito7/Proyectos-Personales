#include "blackjack.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

#pragma comment(lib, "Winmm.lib")

// auxiliary function, chooses at random one card and flags it as dealt
int chooseCard(tDeck& deck) {
	int aux = 0;

	do {
		aux = rand() % DeckSize;
	} while (deck.drawn[aux] == true);

	deck.drawn[aux] = true;

	return aux;
} 
// auxiliary function, frees DM used by a player
void destroy(tPlayer& player) {
	destroy(player.hand);
	player.bank = 50;
	player.name = "croupier";
}
// auxiliary function, checks if the hand of a player is blackjack
bool isBlackjack(const tPlayer& player) {
	return player.hand.counter == 2 && sum(player) == 21;
}
// auxiliary function, counts the number of reactions on a file
int reactionCount(ifstream& file, string fileName) {
	int reactionCounter = 0;

	file.open(fileName);
	getline(file, fileName);
	while (fileName != "XXX") {
		reactionCounter++;
		getline(file, fileName);
	}
	file.close();

	return reactionCounter;
}
// auxiliary function, chooses a reaction at random
string randomReaction(ifstream& file, int numReactions, string fileName) {
	int randNum = rand() % numReactions + 1;

	file.open(fileName);
	for (int i = 0; i < randNum; i++)
		getline(file, fileName);
	file.close();
	
	return fileName;
}

int sum(tPlayer player) {
	int sum = 0;

	for (int i = 0; i < player.hand.counter; i++) {
		player.hand.cards[i]->number > 10? sum += 10 : sum += player.hand.cards[i]->number;
	}

	for (int i = 0; i < player.hand.counter; i++) {
		if (player.hand.cards[i]->number == 1 && sum + 10 <= 21)
			sum += 10;
	}

	return sum;
}

void init(tBJGame& game) {
	initDeck(game.deck);
	game.croupier.bank = 1000000;
	game.player1.bank = 500;
	game.split.bank = 0;

	cout << "What is your name, kid? ";
	cin >> game.player1.name;
	cout << "Is that so? Well, " << game.player1.name << ". Welcome to my fucking table." << endl << endl;
	cout << "-PRESS ANY KEY TO CONTINUE-";
	_getch();
	system("cls");
}

void betting(tBJGame& game) {
	cout << "YOUR MONEY: " << fixed << setprecision(2) << game.player1.bank << endl;
	cout << "Place your bet: ";
	cin >> game.bet;

	while (game.bet < 50 || game.bet > game.player1.bank) {
		//TODO// Replace with a response picked at random from a pool of responses
		cout << "Are you dumb? Place a valid bet or get the fuck out of my table: "; 
		cin >> game.bet;
	}
}

void display(const tBJGame& game) { 
	const int DashLine = 60;
	string aux = game.player1.name, handTitle, playerMoney;

	transform(aux.begin(), aux.end(), aux.begin(), toupper);

	handTitle = aux + "'S HAND:";
	playerMoney = aux + "'S MONEY: ";

	system("cls");
	for (int i = 0; i < DashLine; i++) {
		cout << "-";
	}

	cout << endl << "CROUPIER'S HAND:" << endl;
	display(game.croupier.hand);
	if (game.croupier.hand.counter != 0 && !game.croupier.hand.cards[0]->hidden)
		cout << "HAND VALUE: " << sum(game.croupier) << endl << endl;
	cout << endl;

	for (int i = 0; i < DashLine; i++) {
		cout << "-";
	}

	cout << endl << setw(18) << left << handTitle;
	cout << playerMoney << setw(10) << left << fixed << setprecision(2) << game.player1.bank;
	cout << "BET: " << fixed << setprecision(2) << game.bet << endl;
	display(game.player1.hand);
	cout << "HAND VALUE: " << sum(game.player1) << endl << endl;

	if (game.split.hand.counter != 0) {
		cout << "SPLIT HAND:" << endl;
		display(game.split.hand);
		cout << "SPLIT VALUE: " << sum(game.player1) << endl << endl;
	}

}

bool canInsurance(const tBJGame& game) {
	return game.player1.hand.counter == 2 && game.croupier.hand.cards[1]->number == 1;
}

bool canEven(const tBJGame& game) {
	return game.croupier.hand.cards[1]->number == 1 && game.player1.hand.counter == 2 && game.split.hand.counter == 0 && sum(game.player1) == 21;
}

bool canSplit(const tBJGame& game) {
	return game.bet * 2 <= game.player1.bank && game.player1.hand.counter == 2 && (game.player1.hand.cards[0]->number == game.player1.hand.cards[1]->number || (game.player1.hand.cards[0]->number >= 10 && game.player1.hand.cards[1]->number >= 10));
}

bool canSurrender(const tBJGame& game) {
	return game.player1.hand.counter == 2 && game.split.hand.counter == 0;
}

string menu(const tBJGame& game) {
	string idx = "moveongus";

	cout << "What's the move?" << endl;
	for (int i = 0; i < 60; i++) {
		cout << "-";
	}
	cout << endl;

	if (canInsurance(game))
		cout << "-INSURANCE-" << endl;
	if (canEven(game))
		cout << "-EVEN-" << endl;
	if (canSplit(game))
		cout << "-SPLIT-" << endl;
	cout << "-HIT-" << endl;
	cout << "-STAND-" << endl;
	if (canSurrender(game))
		cout << "-SURRENDER-" << endl;

	cout << "CHOOSE AN OPTION: ";
	cin >> idx;

	transform(idx.begin(), idx.end(), idx.begin(), toupper);

	while (((!canInsurance(game) && idx == "INSURANCE") || (!canEven(game) && idx == "EVEN") || (!canSplit(game) && idx == "SPLIT") || (!canSurrender(game) && idx == "SURRENDER")) || (idx != "INSURANCE" && idx != "EVEN" && idx != "SPLIT" && idx != "HIT" && idx != "STAND" && idx != "SURRENDER")) {
		cout << endl << "-THAT IS NOT A VALID OPTION-" << endl;

		if (canInsurance(game))
			cout << "-INSURANCE-" << endl;
		if (canEven(game))
			cout << "-EVEN-" << endl;
		if (canSplit(game))
			cout << "-SPLIT-" << endl;
		cout << "-HIT-" << endl;
		cout << "-STAND-" << endl;
		if (canSurrender(game))
			cout << "-SURRENDER-" << endl;

		cout << "CHOOSE AN OPTION: ";
		cin >> idx;

		transform(idx.begin(), idx.end(), idx.begin(), toupper);
	}

	return idx;
}

bool insurance(tBJGame& game) {
	double insuranceMoney = 0;

	cout << endl << "-INSURANCE MONEY MUST BE BETWEEN 0 (NOT INCLUDED) AND HALF THE ORIGINAL BET-" << endl << endl;
	cout << "Insurance? Really? For fuck's sake, tell me how big will the insurance be: ";
	cin >> insuranceMoney;

	while (insuranceMoney <= 0 || insuranceMoney > game.bet * 0.5) {
		cout << "Don't play with me, kid. How much insurance money? ";
		cin >> insuranceMoney;
	}

	game.croupier.hand.cards[0]->hidden = false;
	PlaySound(TEXT("flip_card.wav"), NULL, SND_ASYNC);
	display(game);
	Sleep(1000);

	if (sum(game.croupier) == 21) {
		PlaySound(TEXT("luigi_coño"), NULL, SND_ASYNC);
		cout << "I fucking despise insurances." << endl;
		game.player1.bank -= (game.bet - insuranceMoney * 2);
	}

	else {
		cout << "Free money, I guess. ";
		game.player1.bank -= insuranceMoney;
	}

	return sum(game.croupier) == 21;
}

void even(tBJGame& game) {
	PlaySound(TEXT("luigi_coño"), NULL, SND_ASYNC);
	cout << endl << "Boring as fuck." << endl;
	game.player1.bank += game.bet;
}

void split(tBJGame& game) {
	game.split.hand.cards[0] = game.player1.hand.cards[1];
	game.split.hand.counter++;
	game.player1.hand.cards[1] = new tCard;
	delete game.player1.hand.cards[1];
	game.player1.hand.counter--;
	game.player1.bank -= game.bet;
	game.split.bank += game.bet;
}

void surrender(tBJGame& game) {
	cout << endl << "You play like a fucking coward..." << endl;
	game.player1.bank -= game.bet * 0.5;

}

void hit(tBJGame& game, tPlayer& player) {
	int index = 0;

	if (game.player1.name == "win") {
		if (game.player1.name == player.name) {
			if (player.hand.counter == 0)
				add(player.hand, game.deck.cards[0]);
			else
				add(player.hand, game.deck.cards[12]);
		}

		else {
			if (player.hand.counter == 0)
				add(player.hand, game.deck.cards[8]);
			else
				add(player.hand, game.deck.cards[12]);
		}
	}

	else if (game.player1.name == "lose") {
		if (game.player1.name == player.name) {
			if (player.hand.counter == 0)
				add(player.hand, game.deck.cards[8]);
			else
				add(player.hand, game.deck.cards[12]);
		}

		else {
			if (player.hand.counter == 0)
				add(player.hand, game.deck.cards[0]);
			else
				add(player.hand, game.deck.cards[12]);
		}
	}

	else if (game.player1.name == "draw") {
		if (player.hand.counter == 0)
			add(player.hand, game.deck.cards[11]);
		else
			add(player.hand, game.deck.cards[12]);
	}

	else {
	index = chooseCard(game.deck);
	add(player.hand, game.deck.cards[index]);
	}

	if (player.name == "CROUPIER" && player.hand.counter == 1) {
		player.hand.cards[player.hand.counter - 1]->hidden = true;
	}

	PlaySound(TEXT("Sound_effects\\card_dealt"), NULL, SND_FILENAME | SND_ASYNC);
}

void dealing(tBJGame& game) {
	while (game.croupier.hand.counter < 2) {
		hit(game, game.player1);
		display(game);
		Sleep(1000); // 1000 = 1 second
		hit(game, game.croupier);
		display(game);
		Sleep(1000);
	}
}

void playing(tBJGame& game, string& move, string& splitMove, bool& insurancePaid) {
	bool playing = false;

	do {
		if (move != "STAND") {
			if (game.split.hand.counter != 0 && move != "STAND")
				cout << "-MAIN HAND-" << endl;

			move = menu(game);

			if (move == "INSURANCE") {
				insurancePaid = insurance(game);
			}

			else if (move == "EVEN") {
				even(game);
			}

			else if (move == "SPLIT") {
				split(game);
				display(game);
			}

			else if (move == "HIT") {
				hit(game, game.player1);
				display(game);
			}

			else if (move == "SURRENDER") {
				surrender(game);
			}
		}

		if (move == "STAND")
			cout << endl;		

		if (splitMove != "STAND" && move != "SPLIT" && game.split.hand.counter != 0) {	
			cout << "-SPLIT HAND-" << endl;
			splitMove = menu(game);

			if (splitMove == "HIT") {
				hit(game, game.split);
				display(game);
			}
		}

		playing = (sum(game.player1) <= 21 && !insurancePaid && move != "STAND" && move != "SURRENDER" && move != "EVEN") || game.split.hand.counter != 0 && (sum(game.split) <= 21 && splitMove != "STAND");

	} while (playing);
}

void showdown(tBJGame& game) {
	int croupierSum = 0, playerSum = 0, splitSum = 0;

	croupierSum = sum(game.croupier);
	playerSum = sum(game.player1);
	splitSum = sum(game.split);

	if (game.croupier.hand.cards[0]->hidden == true) {
		game.croupier.hand.cards[0]->hidden = false;
		PlaySound(TEXT("Sound_effects\\flip_card"), NULL, SND_FILENAME | SND_ASYNC);
		display(game);
		Sleep(1000);
	}

	while (croupierSum <= 16) {
		hit(game, game.croupier);
		display(game);
		Sleep(1000);
		croupierSum = sum(game.croupier);
	}
}

bool win(const tBJGame& game, const tPlayer& player) {
	int playerHandValue = sum(player);
	int croupierHandValue = sum(game.croupier);

	return (croupierHandValue > 21 && playerHandValue <= 21) || (playerHandValue <= 21 && playerHandValue > croupierHandValue);
}

bool loose(const tBJGame& game, const tPlayer& player) {
	int playerHandValue = sum(player);
	int croupierHandValue = sum(game.croupier);

	return (playerHandValue > 21) || (playerHandValue <= 21 && playerHandValue < croupierHandValue);
}

void distributeMoney(tBJGame& game, string move) {
	ifstream file;
	string reaction, soundEffect;
	int randNum = 0, numReactionsPW = 0, numReactionsPL = 0, numSoundsDraw = 0;

	numReactionsPW = reactionCount(file, "PlayerWinsReactions.txt");

	numReactionsPL = reactionCount(file, "PlayerLosesReactions.txt");

	numSoundsDraw = reactionCount(file, "DrawSounds.txt");

	// no split
	if (game.split.hand.counter == 0) {
		if (win(game, game.player1)) {
			reaction = randomReaction(file, numReactionsPW, "playerWinsReactions.txt");
			PlaySound(TEXT("Sound_effects\\luigi_coño"), NULL, SND_FILENAME | SND_ASYNC);
			cout << reaction << endl;
			isBlackjack(game.player1)? game.player1.bank += game.bet * 1.5 : game.player1.bank += game.bet;
		}

		else if (loose(game, game.player1)) {
			reaction = randomReaction(file, numReactionsPL, "playerLosesReactions.txt");
			PlaySound(TEXT("Sound_effects\\hihihiha"), NULL, SND_FILENAME | SND_ASYNC);
			cout << reaction << endl;
			game.player1.bank -= game.bet;
		}

		else {
			soundEffect = "Sound_effects\\";
			soundEffect += randomReaction(file, numSoundsDraw, "DrawSounds.txt");
			std::wstring stemp = std::wstring(soundEffect.begin(), soundEffect.end());
			LPCWSTR sw = stemp.c_str();
			cout << "Would you look at that, it is a draw." << endl;
			PlaySound((LPCWSTR)sw, NULL, SND_FILENAME | SND_ASYNC);

		}
	}

	// with split
	else {
		if (win(game, game.player1)) {
			cout << "Your main hand beat my ass!" << endl;
			PlaySound(TEXT("Sound_effects\\luigi_coño"), NULL, SND_FILENAME | SND_SYNC);
			isBlackjack(game.player1) ? game.player1.bank += game.bet * 1.5 : game.player1.bank += game.bet;
		}

		else if (loose(game, game.player1)) {
			cout << "your main hand was shit." << endl;
			PlaySound(TEXT("Sound_effects\\hihihiha"), NULL, SND_FILENAME | SND_SYNC);
			game.player1.bank -= game.bet;
		}

		else {
			soundEffect = "Sound_effects\\";
			soundEffect += randomReaction(file, numSoundsDraw, "DrawSounds.txt");
			std::wstring stemp = std::wstring(soundEffect.begin(), soundEffect.end());
			LPCWSTR sw = stemp.c_str();
			cout << "you better hope your split hand is better, I hate draws." << endl;
			PlaySound((LPCWSTR)sw, NULL, SND_FILENAME | SND_ASYNC);
		}

		if (win(game, game.split)) {
			cout << "That split was crazy good!" << endl;
			PlaySound(TEXT("Sound_effects\\luigi_coño"), NULL, SND_FILENAME | SND_SYNC);
			isBlackjack(game.split) ? game.player1.bank += game.bet * 1.5 : game.player1.bank += game.bet;
		}

		else if (loose(game, game.split)) {
			cout << "That split was crazy dumb!" << endl;
			PlaySound(TEXT("Sound_effects\\hihihiha"), NULL, SND_FILENAME | SND_SYNC);
			game.player1.bank -= game.bet;
		}

		else {
			soundEffect = "Sound_effects\\";
			soundEffect += randomReaction(file, numSoundsDraw, "DrawSounds.txt");
			std::wstring stemp = std::wstring(soundEffect.begin(), soundEffect.end());
			LPCWSTR sw = stemp.c_str();
			cout << "The split is a draw." << endl;
			PlaySound((LPCWSTR)sw, NULL, SND_FILENAME | SND_ASYNC);
		}
	}
}

void roundReset(tBJGame& game) {
	shuffle(game.deck);
	destroy(game.croupier.hand);
	destroy(game.player1.hand);
	destroy(game.split.hand);
}

void destroy(tBJGame& game) {
	destroy(game.deck);
	destroy(game.croupier);
	destroy(game.player1);
	destroy(game.split);
	game.bet = 0;
}