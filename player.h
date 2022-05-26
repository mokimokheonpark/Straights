#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "card.h"
#include <vector>

class Player {
protected:
	std::vector<Card*> playerCards;
	std::vector<Card*> legalCards;
	std::vector<Card*> discardedCards;
	int savedScore = 0;
	int playerScore = 0;
	int playerNumber = 0;

public:
	std::vector<Card*> getPlayerCards() const;

	std::vector<Card*> getLegalCards() const;
	void clearLegalCards();

	std::vector<Card*> getDiscardedCards() const;
	void clearDiscardedCards();

	int getSavedScore() const;
	void setSavedScore(int n);

	int getPlayerScore() const;
	void setPlayerScore(std::vector<Card*> discardedCards);
	void resetPlayerScore();

	void setPlayerNumber(int n);

	void addPlayerCard(Card* c);
	void addLegalCard(Card* c);
	
	void printPlayerCards() const;
	void printLegalCards() const;

	virtual std::string getType() const = 0;
	virtual void playCard() = 0;
	virtual void discardCard() = 0;
};

#endif