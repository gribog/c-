#include <iostream>
#include <string>
#include <array>
#include <random>
#include <Windows.h>

enum Mode
{
	MODE_NORMAL,
	MODE_DEBUG,
};

//this
Mode mode = MODE_NORMAL; //can be changed to debug
int delay = 1000;		//delay between turns

enum PlayerType
{
	PLAYER_DEALER,
	PLAYER_PLAYER1,
};

enum GameResult
{
	RESULT_LOOSE,
	RESULT_DRAW,
	RESULT_WIN,
};

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS,
};

enum CardSuit
{
	SUIT_CLUB,
	SUIT_DIAMOND,
	SUIT_HEART,
	SUIT_SPADE,
	MAX_SUITS,
};

struct Card
{
	CardRank rank;
	CardSuit suit;
	
};

void printCard(const Card &card)
{
	std::cout << "[";
	switch (card.rank)
	{
		case(RANK_2):			std::cout << "2"; break;
		case(RANK_3):			std::cout << "3"; break;
		case(RANK_4):			std::cout << "4"; break;
		case(RANK_5):			std::cout << "5"; break;
		case(RANK_6):			std::cout << "6"; break;
		case(RANK_7):			std::cout << "7"; break;
		case(RANK_8):			std::cout << "8"; break;
		case(RANK_9):			std::cout << "9"; break;
		case(RANK_10):			std::cout << "T"; break;
		case(RANK_JACK):		std::cout << "J"; break;
		case(RANK_QUEEN):		std::cout << "Q"; break;
		case(RANK_KING):		std::cout << "K"; break;
		case(RANK_ACE):			std::cout << "A"; break;
	}

	switch (card.suit)
	{
		case(SUIT_CLUB):		std::cout << "c"; break;
		case(SUIT_DIAMOND):		std::cout << "d"; break;
		case(SUIT_HEART):		std::cout << "h"; break;
		case(SUIT_SPADE):		std::cout << "s"; break;
	}
	std::cout << "]";
}

void prindDeck(const std::array<Card, MAX_RANKS * MAX_SUITS> &deck)
{
	int index = 0;
	for (const auto &card : deck)
	{
		printCard(card);
		std::cout << ' ';

		if (++index%MAX_RANKS == 0)
			std::cout << '\n';
	}
		
}

void swapTwoCards(Card &card1, Card &card2)
{
	Card temp = card1;
	card1 = card2;
	card2 = temp;
}

void shuffleDeck(std::array<Card, MAX_RANKS * MAX_SUITS> &deck)
{
	std::cout << "Shuffling the deck.";
	Sleep(delay / 2);
	std::cout << ".";
	Sleep(delay / 2);
	std::cout << ".";
	Sleep(delay / 2);
	std::cout << "\n";
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<> random_number(0, 51);

	int cardToSwapWith = 0;

	for (auto &card : deck)
	{
		cardToSwapWith = random_number(mersenne);

		if (mode == MODE_DEBUG)
		{
			std::cout << "\nSwapping card ";
			printCard(card);
			std::cout << " with card #" << cardToSwapWith << " :";
			printCard(deck[cardToSwapWith]);
			std::cout << '\n';
		}

		swapTwoCards(card, deck[cardToSwapWith]);
	}
}

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
		case(RANK_2): return 2;
		case(RANK_3): return 3;
		case(RANK_4): return 4;
		case(RANK_5): return 5;
		case(RANK_6): return 6;
		case(RANK_7): return 7;
		case(RANK_8): return 8;
		case(RANK_9): return 9;
		case(RANK_10):
		case(RANK_JACK):
		case(RANK_QUEEN):
		case(RANK_KING):
			return 10;
		case(RANK_ACE):
			return 11;
	}

	return 0;
		
}

char askPlayerAction()
{
	char choice;
	do
	{
		std::cout << "Press (h) to HIT or (s) to STAND: ";
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

char askPlayAgain()
{
	char choice;
	do
	{
		std::cout << "Play again (y/n)?: ";
		std::cin >> choice;
	} while (choice != 'y' && choice != 'n');

	return choice;
}

struct GameParticipant
{
	PlayerType Type;
	std::string Name;
	std::array<Card, 12> dealedCards;
	Card *dealToPtr = &dealedCards[0];
	int score{ 0 };
	int numberOfAces{ 0 };

	void dealCard(const Card *(&cardPtr))
	{
		*(this->dealToPtr) = *cardPtr; //copy card from deck to player's next dealed card

		this->score += getCardValue(*(this->dealToPtr)); //update score with dealed card

		if ((*(this->dealToPtr)).rank == RANK_ACE)
			++numberOfAces;

		++(this->dealToPtr);  //point to next empty space in holding cards
		++cardPtr; //point dealing cards to next in the deck
	}
	void printDealedCards()
	{
		Card *indexPtr = &dealedCards[0]; //start with first dealed card

		std::cout << this->Name << " has: \t";
		do {		
			printCard(*indexPtr);
			++indexPtr;
		} while (indexPtr < this->dealToPtr); //finish when reach last dealed card
	}
	void printLastDealedCard()
	{
		Sleep(delay);
		printCard(*(this->dealToPtr - 1));
		Sleep(delay);
	}
	void printScore()
	{
		Sleep(delay);
		std::cout << this->Name << "'s points: " << this->score << '\n';
	}
};

GameResult playBlackjack(const std::array<Card, MAX_RANKS * MAX_SUITS> &deck, std::string playerName)
{
	GameParticipant dealer;			//initialise dealer
	dealer.Type = PLAYER_DEALER;
	dealer.Name = "Dealer";

	GameParticipant player;			//initialise first player
	player.Type = PLAYER_PLAYER1;
	player.Name = playerName;


	const Card *cardPtr = &deck[0];

	std::cout << "The game is ready, deck is shuffled, lets start!\n";
	std::cout << player.Name << " is getting ";
	Sleep(delay/2);
	printCard(*cardPtr);
	Sleep(delay);
	player.dealCard(cardPtr);
	std::cout << '\n' << dealer.Name << " is getting ";
	Sleep(delay/2);
	printCard(*cardPtr);
	Sleep(delay);
	dealer.dealCard(cardPtr);
	std::cout << '\n' << player.Name << " is getting ";
	Sleep(delay/2);
	printCard(*cardPtr);
	Sleep(delay);
	player.dealCard(cardPtr);
	std::cout << '\n' << dealer.Name << " is getting [**]";
	Sleep(delay/2);
	dealer.dealCard(cardPtr);

	std::cout << '\n';
	player.printScore();

	while (player.score < 21 && askPlayerAction() != 's')
	{
		player.printDealedCards();
		player.dealCard(cardPtr);
		player.printLastDealedCard();


		if (player.score > 21)
		{
			if(player.numberOfAces > 0)
			{
				player.score -= 10;
				--player.numberOfAces;
			}
			else
			{
				std::cout << '\n';
				player.printScore();
				Sleep(delay);
				std::cout << player.Name << " is busted!\n";
				return RESULT_LOOSE;
			}

		}
		std::cout << '\n';
		player.printScore();
		
	}
		
	if (player.score == 21)
		{
			std::cout << player.Name << " has BlackJack!\n";
			Sleep(delay);
		}

	dealer.printDealedCards();
	std::cout << '\n';
	dealer.printScore();
	Sleep(delay);
		
	while (dealer.score < 17)
		{
			std::cout << "Dealer is getting one card\n";
			Sleep(delay);
			dealer.printDealedCards();
			dealer.dealCard(cardPtr);
			dealer.printLastDealedCard();
			if (dealer.score > 21)
			{
				if (dealer.numberOfAces > 0)
				{
					dealer.score -= 10;
					--dealer.numberOfAces;
				}
				else
				{
					std::cout << '\n';
					dealer.printScore();
					Sleep(delay);
					std::cout << "Dealer is busted!\n";
					return RESULT_WIN;
				}
			}
			std::cout << '\n';
			dealer.printScore();
			Sleep(delay);
		}
		
	if (dealer.score == 21)
		{
			std::cout << "Dealer has BlackJack!\n";
			Sleep(delay);
		}

		if (player.score > dealer.score)
			return RESULT_WIN;
		else if (player.score == dealer.score)
			return RESULT_DRAW;
		else
			return RESULT_LOOSE;


}

int main()
{
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	int playerBank = 1000, bet = 50;

	std::cout << "Lets play Blackjack, " << playerName << "! You have $" << playerBank<< ", bet is $" << bet << ".\n";
	Sleep(delay);

	std::array<Card, MAX_RANKS * MAX_SUITS> deck; //creating our deck

	int card = 0;
	for (int rank = 0; rank < MAX_RANKS; ++rank)  //initialising deck with cards
	for (int suit = 0; suit < MAX_SUITS; ++suit)
	{
		deck[card].rank = static_cast<CardRank>(rank);
		deck[card].suit = static_cast<CardSuit>(suit);
		++card;
	}

	do
	{
		shuffleDeck(deck);  //shuffling deck before starting game


		GameResult result = playBlackjack(deck, playerName); //play a game and return it's result

		switch (result)
		{
		case(RESULT_LOOSE):		std::cout << "You lost!\n";		playerBank -= bet; break;
		case(RESULT_DRAW):		std::cout << "It's a draw!\n";	break;
		case(RESULT_WIN):		std::cout << "You won!\n";		playerBank +=bet; break;
		default:				std::cout << "Undefined!\n";	break;
		}

		Sleep(delay);
		std::cout << playerName << " has: $" << playerBank << ".\n";
	} while (playerBank >= bet && askPlayAgain() != 'n');

	Sleep(delay);
	if (playerBank < bet)
		std::cout << "You've lost everything!\n";
	else
		std::cout << "You can withdraw $" << playerBank << '\n';

	return 0;
}