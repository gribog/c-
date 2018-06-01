#pragma once
#include <string>
#include <vector>
#include "Enums.h"
#include "Card.h"
class Board
{
public:
	Board();
	~Board();
	void goToNextStage() { m_stage = static_cast<Stage>(static_cast<int>(m_stage) + 1); };
	std::string printStage();
	Stage getStage() { return m_stage; };
	void getCard(Card card) { m_cards.push_back(card); };
	std::string printCards();
private:
	Stage m_stage{ STAGE_PREFLOP };
	std::vector<Card> m_cards;
};

