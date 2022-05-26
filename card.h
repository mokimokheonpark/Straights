#ifndef __CARD_H__
#define __CARD_H__

#include <string>

class Card {
	const std::string rank;
	const std::string suit;

public:
	Card(const std::string rank, const std::string suit);
	std::string getRank() const;
	std::string getSuit() const;
	static bool isEqual(const Card& c1, const Card& c2);
};

#endif