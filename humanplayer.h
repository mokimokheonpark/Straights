#ifndef __HUMANPLAYER_H__
#define __HUMANPLAYER_H__

#include "player.h"
#include "deck.h"

class HumanPlayer : public Player {
	Deck shuffledDeck;
	std::string type = "human";

public:
	HumanPlayer(Deck shuffledDeck);
	std::string getType() const override;
	void playCard() override;
	void discardCard() override;
};

#endif