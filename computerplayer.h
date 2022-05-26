#ifndef __COMPUTERPLAYER_H__
#define __COMPUTERPLAYER_H__

#include "player.h"
#include "deck.h"

class ComputerPlayer : public Player {
	Deck shuffledDeck;
	std::string type = "computer";

public:
	ComputerPlayer(Deck shuffledDeck);
	std::string getType() const override;
	void playCard() override;
	void discardCard() override;
};

#endif