#include "Deck.h"

Mode mode = MODE_NORMAL; 

Deck::Deck()
{
	this->init();
}


Deck::~Deck()
{
}

void Deck::printDeck()
{
	int index = 0;
	for (auto &card : m_cards)
	{
		card.printCard();
		if (++index % MAX_RANKS == 0) std::cout << '\n';
	}

}

Card* Deck::dealCard(Person &person)
{
	person.getCard(*m_nextCard);
	return m_nextCard++;
}

void Deck::shuffle()
{
	std::cout << "Shuffling the deck.\n";
	std::random_device rd;
	std::mt19937 mersenne(rd());
	std::uniform_int_distribution<> random_number(0, 51);
	
	int cardToSwapWith{ 0 };
	
	for (auto &card : m_cards)
	{
		cardToSwapWith = random_number(mersenne);
	
		if (mode == MODE_DEBUG)
		{
			std::cout << "Swapping card ";
			card.printCard();
			std::cout << " with card #" << cardToSwapWith << " :";
			m_cards[cardToSwapWith].printCard();
			std::cout << '\n';
		}
	
		Card temp = card;
		card = m_cards[cardToSwapWith];
		m_cards[cardToSwapWith] = temp;
	}

	m_nextCard = &m_cards[0];
}

void Deck::init()
{
	int index = 0;

	for (int suit = 0; suit < MAX_SUITS; ++suit)
	for (int rank = 0; rank < MAX_RANKS; ++rank)  	
	{
		m_cards[index] = Card (static_cast<CardRank>(rank), static_cast<CardSuit>(suit));
		++index;
	}
}

void Deck::deal(std::vector<Person> &players, Board &board)
{
	switch (board.getStage())
	{
	case STAGE_PREFLOP:
		for (auto player : players)
		{
			if (player.getStatus() == true)
				dealCard(player);
		}
		for (auto player : players)
		{
			if (player.getStatus() == true)
				dealCard(player);
		}
		break;
	case STAGE_FLOP:
		m_nextCard++;
		putCard(board);
		putCard(board);
		putCard(board);
		break;
	case STAGE_TURN:
		break;
	case STAGE_RIVER:
		break;
	}

}