#include "Person.h"



Person::Person()
{
}

Person::Person(std::string name, PersonType type) : m_name{ name }, m_type{type}
{
}


Person::~Person()
{
}


void Person::printCards()
{
	if (m_cards.size() == 0)
		std::cout << "No cards.\n";
	else
	{
		for (auto &card : m_cards)
			card.printCard();
	}

}

void Person::printDealedCard()
{
	if (m_cards.size() == 0)
		std::cout << "No dealed cards.\n";
	else
	{
		std::cout << m_name << " got ";
		m_cards.back().printCard();
		std::cout << '\n';

	}

}

std::string Person::getStringOfCards()
{
	std::string cards;

	if (m_cards.size() == 0)
		cards= "";
	else
	{
		for (auto &card : m_cards)
			cards += card.getStringCard();
	}

	return cards;
}

int Person::getScore()
{
	int score{ 0 };
	int numberOfAces{ 0 };

	for (auto &card : m_cards)
	{
		score += card.getValue();
		if (card.getValue() == 11) //card rank is Ace
			++numberOfAces;
	}
		

	while (score > 21 && numberOfAces > 0) //ace can be couted as 1 or 11
	{
		score -= 10;
		--numberOfAces;
	}

	return score;
}

void Person::getWinnings(GameResult result)
{
	switch (result)
	{
	case RESULT_WIN:
		m_bank += m_bet;
		std::cout << m_name << " won $" << m_bet << " and still have $" << m_bank << " left.\n";		
		break;
	case RESULT_LOOSE:
		m_bank -= m_bet;
		if(m_bank < 50)
			std::cout << m_name << " lost everything.\n";
		else
			std::cout << m_name << " lost $" << m_bet << " and still have $" << m_bank << " left.\n";
		break;
	case RESULT_DRAW:
		std::cout << m_name << " got $" << m_bet << " back and still have $" << m_bank << " left.\n";
		break;
	case RESULT_BLACKJACK:
		m_bank += static_cast<int>(m_bet * 1.5);
		std::cout << m_name << " won $" << static_cast<int>(m_bet * 1.5) << " and still have $" << m_bank << " left.\n";
		break;
	}
}