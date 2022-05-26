#include "deck.h"
#include <iostream>

Deck::Deck(std::vector<Card*> deck) : deck{ deck } {}

std::vector<Card*> Deck::getDeck() const {
	return deck;
}

void Deck::printDeck() const {
	for (int i = 0; i < deck.size(); i++) {
		std::cout << deck[i]->getRank() << deck[i]->getSuit() << " ";
		if (((i + 1) % 13) == 0) {
			std::cout << std::endl;
		}
	}
}