#pragma once
#include <array>
#include <random>
#include "Card.h"
#include "Person.h"
#include "Enums.h"

class Deck
{
public:
	Deck();
	~Deck();
	void printDeck();
	Card* dealCard(Person &person);
	void shuffle();
	int getDealersFirstCard() { return m_cards.at(0).getValue(); };
	
private:
	std::array<Card, MAX_RANKS * MAX_SUITS> m_cards;
	Card *m_nextCard = &m_cards[0];
	void init();
};

