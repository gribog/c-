#include <iostream>
#include <string>
#include <array>
#include <random>
#include <Windows.h>

#include "Enums.h"
#include "Card.h"
#include "Deck.h"
#include "Person.h"

int delay = 1000;
int minBet = 50;





int main()
{

	Deck deck;
	std::vector<Person> Players;
	Players.push_back(Person("Dealer", PERSON_DEALER));
	Players.push_back(Person("Anton", PERSON_PLAYER));

	


	return 0;
}
