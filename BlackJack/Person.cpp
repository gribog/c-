#include "Person.h"



Person::Person()
{
}

Person::Person(std::string name) : m_name{ name }
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