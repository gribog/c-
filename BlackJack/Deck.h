#pragma once
#include <array>
#include <random>
#include "Card.h"
#include "Enums.h"

class Deck
{
public:
	Deck();
	~Deck();
	void printDeck();
	Card* dealCard();
	void shuffle();
	
private:
	std::array<Card, MAX_RANKS * MAX_SUITS> m_cards;
	Card *nextCard = &m_cards[0];
	void init();
};

