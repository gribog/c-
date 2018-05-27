#pragma once
#include <string>
#include <vector>
#include <cassert>
#include "Enums.h"
#include "Card.h"
class Person
{
public:
	Person();
	Person(std::string name);
	~Person();
	std::string getName() { return m_name; };
	void getCard(Card card) { m_cards.push_back(card); };
	void printCards();
	int getScore();
	void init() { m_cards.clear(); };
	int getBank() { return m_bank; };
	int getBet() { return m_bet; };
	void setBet(int bet) { m_bet = bet ; };
private:
	PersonType m_type;
	std::string m_name;
	std::vector<Card> m_cards;
	int m_bank = 1000;
	int m_bet = 50;
};

