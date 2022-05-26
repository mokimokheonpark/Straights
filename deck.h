#ifndef __DECK_H__
#define __DECK_H__

#include "card.h"
#include <vector>

class Deck {
	std::vector<Card*> deck;

public:
	Deck(std::vector<Card*> deck);
	std::vector<Card*> getDeck() const;
	void printDeck() const;
};

#endif