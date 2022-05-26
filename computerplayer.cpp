#include "computerplayer.h"
#include <iostream>

ComputerPlayer::ComputerPlayer(Deck shuffledDeck) : shuffledDeck{ shuffledDeck } {}

std::string ComputerPlayer::getType() const {
	return type;
}

void ComputerPlayer::playCard() {
	std::cout << "Player" << playerNumber << " plays " << legalCards[0]->getRank() << legalCards[0]->getSuit() << "." << std::endl;
	for (int i = 0; i < playerCards.size(); i++) {
		if (Card::isEqual(*playerCards[i], *legalCards[0])) {
			playerCards.erase(playerCards.begin() + i);
			break;
		}
	}
}

void ComputerPlayer::discardCard() {
	std::cout << "Player" << playerNumber << " discards " << playerCards[0]->getRank() << playerCards[0]->getSuit() << "." << std::endl;
	discardedCards.push_back(playerCards[0]);
	playerCards.erase(playerCards.begin());
}