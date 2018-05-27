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
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	return name;
}

//
//char askPlayerAction()
//{
//	char choice;
//	do
//	{
//		std::cout << "Press (h) to HIT or (s) to STAND: ";
//		std::cin >> choice;
//	} while (choice != 'h' && choice != 's');
//
//	return choice;
//}

//char askPlayAgain()
//{
//	char choice;
//	do
//	{
//		std::cout << "Play again (y/n)?: ";
//		std::cin >> choice;
//	} while (choice != 'y' && choice != 'n');
//
//	return choice;
//}


//GameResult playBlackjack(const std::array<Card, MAX_RANKS * MAX_SUITS> &deck, std::string playerName)
//{
//	GameParticipant dealer;			//initialise dealer
//	dealer.Type = PLAYER_DEALER;
//	dealer.Name = "Dealer";
//
//	GameParticipant player;			//initialise first player
//	player.Type = PLAYER_PLAYER;
//	player.Name = playerName;
//
//
//	const Card *cardPtr = &deck[0];
//
//	std::cout << "The game is ready, deck is shuffled, lets start!\n";
//	std::cout << player.Name << " is getting ";
//	Sleep(delay/2);
//	printCard(*cardPtr);
//	Sleep(delay);
//	player.dealCard(cardPtr);
//	std::cout << '\n' << dealer.Name << " is getting ";
//	Sleep(delay/2);
//	printCard(*cardPtr);
//	Sleep(delay);
//	dealer.dealCard(cardPtr);
//	std::cout << '\n' << player.Name << " is getting ";
//	Sleep(delay/2);
//	printCard(*cardPtr);
//	Sleep(delay);
//	player.dealCard(cardPtr);
//	std::cout << '\n' << dealer.Name << " is getting [**]";
//	Sleep(delay/2);
//	dealer.dealCard(cardPtr);
//
//	std::cout << '\n';
//	player.printScore();
//
//	while (player.score < 21 && askPlayerAction() != 's')
//	{
//		player.printDealedCards();
//		player.dealCard(cardPtr);
//		player.printLastDealedCard();
//
//
//		if (player.score > 21)
//		{
//			if(player.numberOfAces > 0)
//			{
//				player.score -= 10;
//				--player.numberOfAces;
//			}
//			else
//			{
//				std::cout << '\n';
//				player.printScore();
//				Sleep(delay);
//				std::cout << player.Name << " is busted!\n";
//				return RESULT_LOOSE;
//			}
//
//		}
//		std::cout << '\n';
//		player.printScore();
//		
//	}
//		
//	if (player.score == 21)
//		{
//			std::cout << player.Name << " has BlackJack!\n";
//			Sleep(delay);
//		}
//
//	dealer.printDealedCards();
//	std::cout << '\n';
//	dealer.printScore();
//	Sleep(delay);
//		
//	while (dealer.score < 17)
//		{
//			std::cout << "Dealer is getting one card\n";
//			Sleep(delay);
//			dealer.printDealedCards();
//			dealer.dealCard(cardPtr);
//			dealer.printLastDealedCard();
//			if (dealer.score > 21)
//			{
//				if (dealer.numberOfAces > 0)
//				{
//					dealer.score -= 10;
//					--dealer.numberOfAces;
//				}
//				else
//				{
//					std::cout << '\n';
//					dealer.printScore();
//					Sleep(delay);
//					std::cout << "Dealer is busted!\n";
//					return RESULT_WIN;
//				}
//			}
//			std::cout << '\n';
//			dealer.printScore();
//			Sleep(delay);
//		}
//		
//	if (dealer.score == 21)
//		{
//			std::cout << "Dealer has BlackJack!\n";
//			Sleep(delay);
//		}
//
//		if (player.score > dealer.score)
//			return RESULT_WIN;
//		else if (player.score == dealer.score)
//			return RESULT_DRAW;
//		else
//			return RESULT_LOOSE;
//
//
//}

int main()
{

	Deck deck;
	Person dealer("Dealer");
	Person player(getPlayerName());
	std::cout << "Lets play Blackjack, " << player.getName() << "! You have $" << player.getBank() << ", bet is $" << player.getBet() << ".\n";

	while (true)
	{
		std::cout << "Enter new bet amount to change it or press enter to play, otherwise (q) to quit:";
		std::string choice;
		std::cin >> choice;

		if (choice.length() == 0)
		{
			break;
		}
		else if (choice[0] == 'q')
		{
			exit(0);
		}
		else
		{
			try
			{
				int bet = std::stoi(choice);
				if (bet >= minBet && bet <= player.getBank())
				{
					player.setBet(bet);
					std::cin.ignore(32767, '\n');
					break;
				}
				else
				{
					std::cout << "Your bet must be at least " << minBet << " and can't exceed " << player.getBank() << '\n';
					std::cin.clear();
					std::cin.ignore(32767, '\n');
				}

			}
			catch (...)
			{
				std::cout << "Invalid input, try again\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
			}
			/*if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Invalid number. Please try again.\n";
			}
			else
			{
				std::cin.ignore(32767, '\n');
				return input;
			}*/
		}
		

	}

	std::cout << "Bet is: " << player.getBet() << '\n';

	//do
	//{
	//	shuffleDeck(deck);  //shuffling deck before starting game


	//	GameResult result = playBlackjack(deck, playerName); //play a game and return it's result

	//	switch (result)
	//	{
	//	case(RESULT_LOOSE):		std::cout << "You lost!\n";		playerBank -= bet; break;
	//	case(RESULT_DRAW):		std::cout << "It's a draw!\n";	break;
	//	case(RESULT_WIN):		std::cout << "You won!\n";		playerBank +=bet; break;
	//	default:				std::cout << "Undefined!\n";	break;
	//	}

	//	Sleep(delay);
	//	std::cout << playerName << " has: $" << playerBank << ".\n";
	//} while (playerBank >= bet && askPlayAgain() != 'n');

	//Sleep(delay);
	//if (playerBank < bet)
	//	std::cout << "You've lost everything!\n";
	//else
	//	std::cout << "You can withdraw $" << playerBank << '\n';td::array<Card, MAX_RANKS * MAX_SUITS> deck; //creating our deck


	return 0;
}
