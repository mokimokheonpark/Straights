#ifndef __GAMEPLAY_H__
#define __GAMEPLAY_H__

#include "table.h"
#include "humanplayer.h"
#include "computerplayer.h"

class GamePlay {
	Deck shuffledDeck;
	Table table;
	std::vector<Player*> players;

public:
	GamePlay(Deck& shuffledDeck, Table& table);
	Deck getShuffledDeck() const;
	void invitePlayers();
	void legalPlay(Table& table, std::vector<Player*> players, int n);
	void game();
};

#endif