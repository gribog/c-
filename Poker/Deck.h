#pragma once
#include <array>
#include <random>
#include <string>
#include "Card.h"
#include "Person.h"
#include "Enums.h"
#include "Board.h"


class Deck
{
public:
	Deck();
	~Deck();
	void printDeck();
	Card* dealCard(Person &person);
	void putCard(Board &board) { board.getCard(*m_nextCard); m_nextCard++; };
	void shuffle();
	void deal(std::vector<Person> &players, Board &board);
	
private:
	std::array<Card, MAX_RANKS * MAX_SUITS> m_cards;
	Card *m_nextCard = &m_cards[0];
	void init();
};

