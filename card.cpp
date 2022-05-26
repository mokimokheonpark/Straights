#include "card.h"

Card::Card(const std::string rank, const std::string suit) : rank{ rank }, suit{ suit } {}

std::string Card::getRank() const {
	return rank;
}

std::string Card::getSuit() const {
	return suit;
}

bool Card::isEqual(const Card& c1, const Card& c2) {
	return (c1.rank == c2.rank && c1.suit == c2.suit);
}