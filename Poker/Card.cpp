#include "Card.h"

Card::Card()
{
}

Card::Card(CardRank rank, CardSuit suit) : m_rank{ rank }, m_suit{ suit }
{
}


Card::~Card()
{
}

void Card::printCard()
{
	std::cout << "[";
	switch (m_rank)
	{
	case(RANK_2):			std::cout << "2"; break;
	case(RANK_3):			std::cout << "3"; break;
	case(RANK_4):			std::cout << "4"; break;
	case(RANK_5):			std::cout << "5"; break;
	case(RANK_6):			std::cout << "6"; break;
	case(RANK_7):			std::cout << "7"; break;
	case(RANK_8):			std::cout << "8"; break;
	case(RANK_9):			std::cout << "9"; break;
	case(RANK_10):			std::cout << "T"; break;
	case(RANK_JACK):		std::cout << "J"; break;
	case(RANK_QUEEN):		std::cout << "Q"; break;
	case(RANK_KING):		std::cout << "K"; break;
	case(RANK_ACE):			std::cout << "A"; break;
	}

	switch (m_suit)
	{
	case(SUIT_CLUB):		std::cout << "c"; break;
	case(SUIT_DIAMOND):		std::cout << "d"; break;
	case(SUIT_HEART):		std::cout << "h"; break;
	case(SUIT_SPADE):		std::cout << "s"; break;
	}
	std::cout << "]";
}

std::string Card::getStringCard()
{
	std::string card = "[";
	switch (m_rank)
	{
	case(RANK_2):			card += "2"; break;
	case(RANK_3):			card += "3"; break;
	case(RANK_4):			card += "4"; break;
	case(RANK_5):			card += "5"; break;
	case(RANK_6):			card += "6"; break;
	case(RANK_7):			card += "7"; break;
	case(RANK_8):			card += "8"; break;
	case(RANK_9):			card += "9"; break;
	case(RANK_10):			card += "T"; break;
	case(RANK_JACK):		card += "J"; break;
	case(RANK_QUEEN):		card += "Q"; break;
	case(RANK_KING):		card += "K"; break;
	case(RANK_ACE):			card += "A"; break;
	}

	switch (m_suit)
	{
	case(SUIT_CLUB):		card += "c"; break;
	case(SUIT_DIAMOND):		card += "d"; break;
	case(SUIT_HEART):		card += "h"; break;
	case(SUIT_SPADE):		card += "s"; break;
	}
	card += "]";
	return card;
}

int Card::getValue()
{
	switch (m_rank)
	{
			case(RANK_2):	return 2;
			case(RANK_3):	return 3;
			case(RANK_4):	return 4;
			case(RANK_5):	return 5;
			case(RANK_6):	return 6;
			case(RANK_7):	return 7;
			case(RANK_8):	return 8;
			case(RANK_9):	return 9;
			case(RANK_10):
			case(RANK_JACK):
			case(RANK_QUEEN):
			case(RANK_KING):
							return 10;
			case(RANK_ACE):
							return 11;
	}
		
	return 0;
}