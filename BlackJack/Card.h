#pragma once
#include <iostream>
#include <string>
#include "Enums.h"

class Card
{
public:
	Card();
	Card(CardRank rank, CardSuit suit);
	~Card();
	void printCard();
	std::string getStringCard();
	int getValue();
private:
	CardRank m_rank;
	CardSuit m_suit;
};

