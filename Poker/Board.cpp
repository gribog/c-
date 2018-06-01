#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

std::string Board::printStage()
{
	switch (m_stage)
	{
	case STAGE_PREFLOP: return "Preflop"; break;
	case STAGE_FLOP: return "Flop"; break;
	case STAGE_TURN: return "Turn"; break;
	case STAGE_RIVER: return "River"; break;
	default: return "Undefined";
	}
}

std::string Board::printCards()
{
	switch (m_stage)
	{
	case STAGE_PREFLOP: 
		std::cout << "No cards on the board.\n"; 
		return "No cards on the board.\n";
	case STAGE_FLOP: 
		if (m_cards.size() == 3)
		{
			std::cout << "Flop: " << m_cards.at(0).getStringCard() + m_cards.at(1).getStringCard() + m_cards.at(2).getStringCard() << '\n';
			return m_cards.at(0).getStringCard() + m_cards.at(1).getStringCard() + m_cards.at(2).getStringCard() + '\n';
		}
			
		else
		{
			std::cout << "Wrong cards number on the flop.\n"; 
			return "Wrong cards number on the flop.\n";
		}
	case STAGE_TURN: return "Turn"; break;
	case STAGE_RIVER: return "River"; break;
	default: return "Undefined";
	}
}