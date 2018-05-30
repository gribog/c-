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




std::string getPlayerName()
{
	//max 15 char
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	return name;
}

void changeBetSize(Person &player)
{
	while(true)
	{
		std::cout << "Enter new bet size: ";
		int bet;
		std::cin >> bet;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again.\n";
		}
		else
		{			
			if (bet >= minBet && bet <= player.getBank())
			{
				player.setBet(bet);
				break;
			}
			else
				std::cout << "Your bet must be at least " << minBet << " and can't exceed " << player.getBank() << '\n';						
		}

		std::cin.ignore(32767, '\n');
	} 
}

bool play(Person &player, int &counter)
{
	if (player.getStatus() == false && counter > 0)
		return true;

	
	char choice;
	do
	{
		std::cout << "Press (d) to deal cards, (b) to change bet size or (q) to quit: ";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(32767, '\n');
	} while (choice != 'd' && choice != 'b' && choice != 'q');

	counter = 100;

	switch (choice)
	{
	case 'd': return true;
	case 'b': changeBetSize(player); return true;
	case 'q': std::cout << "See you next time!\n"; return false;
	}
	
}

void dealTwoCards(Deck &deck, std::vector<Person> &Players)
{
	std::cout << "Dealing cards.\n";

	for (std::vector<Person>::iterator person = Players.begin(); person != Players.end(); ++person)
	{
		if ((*person).getStatus() == false)
			continue;
		else
			deck.dealCard(*person);
	}
	for (std::vector<Person>::iterator person = Players.begin(); person != Players.end(); ++person)
	{
		if ((*person).getStatus() == false)
			continue;
		else
			deck.dealCard(*person);
	}
}

void printInfo(std::vector<Person> &Players)
{
	std::cout << "Name\t\t" <<		"Score\t" <<	"Cards\n";

	for (std::vector<Person>::iterator person = Players.begin(); person != Players.end(); ++person)
	{
		if ((*person).getStatus() == false)
			continue;
		else
		{
			std::cout << (*person).getName() << '\t';
			if ((*person).getName().length() < 9)	//extra tab for short names
				std::cout << '\t';
			if ((*person).getType() == PERSON_DEALER)
				std::cout << "??\t" << (*person).getStringOfCards().substr(0, 4) << "[**]\n";
			else
			{
				std::cout << (*person).getScore() << '\t'
					<< (*person).getStringOfCards() << '\n';
			}
		}
	}
}

void printResults(std::vector<Person> &Players)
{
	std::cout << "Name\t\t" << "Score\t" << "Cards\n";

	for (std::vector<Person>::iterator person = Players.begin(); person != Players.end(); ++person)
	{
		std::cout << (*person).getName() << '\t'; //print playrs name
		if ((*person).getName().length() < 9)	//extra tab for short names
			std::cout << '\t';

		if ((*person).getStatus() == false)
			std::cout << "Lost\n";
		else
		{
			if ((*person).getScore() > 21)			//print score
				std::cout << "Busted\t";
			else
				std::cout << (*person).getScore() << '\t';

			std::cout << (*person).getStringOfCards() << '\n'; //print cards
		}

	}
}

void askPlayerAction(Person &player, Deck &deck)
{
	char choice;
	do
	{	
		do
		{
			std::cout << player.getName() << ", your score is " << player.getScore() << ", press (h) to HIT or (s) to STAND: ";
			std::cin >> choice;
		} while (choice != 'h' && choice != 's');

		if (choice == 'h')
		{
			deck.dealCard(player);
			player.printDealedCard();
		}

	} while (choice != 's' && player.getScore() < 22);

	if (player.getScore() > 21)
		std::cout << player.getName() << " is busted!\n";
}

void computerAction(Person &computer, Deck &deck)
{
	switch (deck.getDealersFirstCard())
	{
	case 2:
	case 3:
		while (computer.getScore() < 13)
		{
			std::cout << computer.getName() << " is hitting one more card.\n";
			deck.dealCard(computer);
			computer.printDealedCard();
		}
		break;
	case 4:
	case 5:
	case 6:
		while (computer.getScore() < 12)
		{
			std::cout << computer.getName() << " is hitting one more card.\n";
			deck.dealCard(computer);
			computer.printDealedCard();
		}
		break;
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		while (computer.getScore() < 17)
		{
			std::cout << computer.getName() << " is hitting one more card.\n";
			deck.dealCard(computer);
			computer.printDealedCard();
		}
		break;
	}

	if (computer.getScore() > 21)
		std::cout << computer.getName() << " is busted!\n";
	else
		std::cout << computer.getName() << " decides to stand.\n";
}

void dealerTurn(Person &dealer, Deck &deck)
{
	std::cout << dealer.getName() << " has ";
	dealer.printCards();
	std::cout << " and total score is " << dealer.getScore() << '\n';

	while (dealer.getScore() < 17)
	{
		std::cout << dealer.getName() << " is hitting one more card.\n";
		deck.dealCard(dealer);
		dealer.printDealedCard();
	}

	if (dealer.getScore() > 21)
		std::cout << dealer.getName() << " is busted!\n";
	else
		std::cout << dealer.getName() << " decided to stand.\n";
}

void checkResult(Person &player, Person &dealer)
{
	if (player.getScore() > 21)											//player busted
		player.getWinnings(RESULT_LOOSE);

	else if (player.getScore() == 21 && player.getNumberOfCards() == 2)	//player has blackjack
	{
		if( dealer.getScore() == 21 && dealer.getNumberOfCards() == 2)	//dealer has blackjack too
			player.getWinnings(RESULT_DRAW);
		else
			player.getWinnings(RESULT_BLACKJACK);

	}
	else //player not busted and doesn't have blackjack
	{
		if(dealer.getScore() > 21)										//dealer busted
			player.getWinnings(RESULT_WIN);
		else if (player.getScore() > dealer.getScore())
			player.getWinnings(RESULT_WIN);
		else if (player.getScore() < dealer.getScore())
			player.getWinnings(RESULT_LOOSE);
		else 
			player.getWinnings(RESULT_DRAW);
	}



	//if (player.getScore() > 21 || (player.getScore() < dealer.getScore() && dealer.getScore() < 22) )
	//	player.getWinnings(RESULT_LOOSE);
	//else
	//{
	//	if (dealer.getScore() > 21 || player.getScore() > dealer.getScore())
	//		if (player.getScore() == 21 && player.getNumberOfCards() == 2 && (dealer.getScore() < 21 || dealer.getNumberOfCards() > 2))
	//			player.getWinnings(RESULT_BLACKJACK);

	//		player.getWinnings(RESULT_WIN);
	//	else
	//		player.getWinnings(RESULT_DRAW);
	//}
}

int main()
{

	Deck deck;
	std::vector<Person> Players;
	Players.push_back(Person("Dealer", PERSON_DEALER));
	Players.push_back(Person(getPlayerName(), PERSON_PLAYER));

	std::cout << "Enter number of opponents: ";
	int numOpponents{ 0 };
	std::cin >> numOpponents;
	for (int index = 1; index <= numOpponents; ++index)
		Players.push_back(Person("Computer" + std::to_string(index), PERSON_COMPUTER));
	std::cout << "Lets play Blackjack, " << Players.at(1).getName() << "! You have $" << Players.at(1).getBank() << ", minimum bet is $" << minBet << ".\n";

	int counter = 100;
	int round = 1;
	
	while (numOpponents >= 0 && play(Players.at(1), counter) )
	{
		std::cout << "********************ROUND " << round << "**************************\n";
		deck.shuffle();
		dealTwoCards(deck, Players);
		printInfo(Players);

		int numberOfActivePlayers = numOpponents + 1;
		
		for (std::vector<Person>::iterator person = Players.begin(); person != Players.end(); ++person)
		{
			if ((*person).getScore() == 21) //check if player has blackjack
			{
				std::cout << (*person).getName() << " has blackjack!\n";
				if ((*person).getType() == PERSON_DEALER) //if dealer has blackjack, immediately stop dealing
					break;
				else
					continue;
			}

			if ((*person).getStatus() == false)
				continue;
			else
			{
				if ((*person).getType() == PERSON_PLAYER)
					askPlayerAction(*person, deck);
				else if ((*person).getType() == PERSON_COMPUTER)
					computerAction((*person), deck);

				if ((*person).getScore() > 21)
					--numberOfActivePlayers;
			}

		}

		if (numberOfActivePlayers > 0)
		{
			dealerTurn(Players.at(0), deck);
		}

		printResults(Players);

		for (std::vector<Person>::iterator person = Players.begin() + 1; person != Players.end(); ++person)
		{
			if ((*person).getStatus() == false)
				continue;
			else
				checkResult(*person, Players.at(0));
		}

		for (std::vector<Person>::iterator person = Players.begin(); person != Players.end(); ++person)
		{
			if ((*person).getStatus() == false)
				continue;
			else
			{
				if ((*person).getBank() < 50)
				{
					(*person).disable();
					--numOpponents;
					counter = 0;
				}

				(*person).init();
			}

		}

		--counter;
		++round;

	}


	return 0;
}
