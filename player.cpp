#include "player.h"
#include <iostream>

std::vector<Card*> Player::getPlayerCards() const {
	return playerCards;
}

std::vector<Card*> Player::getLegalCards() const {
	return legalCards;
}

void Player::clearLegalCards() {
	legalCards.clear();
}

std::vector<Card*> Player::getDiscardedCards() const {
	return discardedCards;
}

void Player::clearDiscardedCards() {
	discardedCards.clear();
}

int Player::getSavedScore() const {
	return savedScore;
}

void Player::setSavedScore(int n) {
	savedScore = n;
}

int Player::getPlayerScore() const {
	return playerScore;
}

void Player::setPlayerScore(std::vector<Card*> discardedCards) {
	std::vector<int> score;
	for (int i = 0; i < discardedCards.size(); i++) {
		if (discardedCards[i]->getRank() == "A") {
			score.push_back(1);
		}
		else if (discardedCards[i]->getRank() == "2") {
			score.push_back(2);
		}
		else if (discardedCards[i]->getRank() == "3") {
			score.push_back(3);
		}
		else if (discardedCards[i]->getRank() == "4") {
			score.push_back(4);
		}
		else if (discardedCards[i]->getRank() == "5") {
			score.push_back(5);
		}
		else if (discardedCards[i]->getRank() == "6") {
			score.push_back(6);
		}
		else if (discardedCards[i]->getRank() == "7") {
			score.push_back(7);
		}
		else if (discardedCards[i]->getRank() == "8") {
			score.push_back(8);
		}
		else if (discardedCards[i]->getRank() == "9") {
			score.push_back(9);
		}
		else if (discardedCards[i]->getRank() == "T") {
			score.push_back(10);
		}
		else if (discardedCards[i]->getRank() == "J") {
			score.push_back(11);
		}
		else if (discardedCards[i]->getRank() == "Q") {
			score.push_back(12);
		}
		else if (discardedCards[i]->getRank() == "K") {
			score.push_back(13);
		}
	}

	int sum = 0;
	for (int i = 0; i < score.size(); i++) {
		sum += score[i];
	}

	playerScore = sum;
}

void Player::resetPlayerScore() {
	playerScore = 0;
}

void Player::setPlayerNumber(int n) {
	playerNumber = n;
}

void Player::addPlayerCard(Card* c) {
	playerCards.push_back(c);
}

void Player::addLegalCard(Card* c) {
	legalCards.push_back(c);
}

void Player::printPlayerCards() const {
	std::cout << "Your Hand: ";
	for (int i = 0; i < playerCards.size(); i++) {
		std::cout << playerCards[i]->getRank() << playerCards[i]->getSuit() << " ";
	}
	std::cout << std::endl;
}

void Player::printLegalCards() const {
	std::cout << "Legal Plays: ";
	for (int i = 0; i < legalCards.size(); i++) {
		std::cout << legalCards[i]->getRank() << legalCards[i]->getSuit() << " ";
	}
	std::cout << std::endl;
}