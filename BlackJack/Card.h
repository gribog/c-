#pragma once
#include <iostream>
#include "Enums.h"

class Card
{
public:
	Card();
	Card(CardRank rank, CardSuit suit);
	~Card();
	void printCard();
	int getValue();
private:
	CardRank m_rank;
	CardSuit m_suit;
};

