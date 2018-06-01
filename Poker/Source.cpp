#include <iostream>
#include <string>
#include <array>
#include <random>
#include <Windows.h>

#include "Enums.h"
#include "Card.h"
#include "Deck.h"
#include "Person.h"
#include "Board.h"

int delay = 1000;
int minBet = 50;





int main()
{

	Deck deck;
	std::vector<Person> players;
	players.push_back(Person("Dealer", PERSON_DEALER));
	players.push_back(Person("Anton", PERSON_PLAYER));
	Board board;

	deck.shuffle();
	deck.deal(players, board);
	board.printStage();
	board.printCards();
	board.goToNextStage(); //go to flop

	deck.deal(players, board);
	board.printStage();
	board.printCards();

	return 0;
}
