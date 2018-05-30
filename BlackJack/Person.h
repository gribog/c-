#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "Enums.h"
#include "Card.h"
class Person
{
public:
	Person();
	Person(std::string name, PersonType type);
	~Person();
	std::string getName() { return m_name; };
	void getCard(Card card) { m_cards.push_back(card); };
	void printCards();
	std::string getStringOfCards();
	PersonType getType() { return m_type; };
	void printDealedCard();
	int getScore();
	void init() { m_cards.clear(); };
	int getBank() { return m_bank; };
	int getBet() { return m_bet; };
	void setBet(int bet) { m_bet = bet ; };
	void getWinnings(GameResult result);
	void disable() { m_active = false; };
	bool getStatus() { return m_active; };
	int getNumberOfCards() { return static_cast<int>(m_cards.size()); };
private:
	PersonType m_type;
	std::string m_name;
	std::vector<Card> m_cards;
	int m_bank = 1000;
	int m_bet = 50;
	bool m_active{ true };
};

