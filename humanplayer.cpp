#include "humanplayer.h""
#include <iostream>

HumanPlayer::HumanPlayer(Deck shuffledDeck) : shuffledDeck{ shuffledDeck } {}

std::string HumanPlayer::getType() const {
	return type;
}

void HumanPlayer::playCard() {
	bool isValid = false;
	std::string input;
	while (!isValid) {
		std::cout << ">";
		std::getline(std::cin, input);
		if (input.length() == 7 && input.substr(0, 5) == "play ") {
			for (int i = 0; i < legalCards.size(); i++) {
				if (legalCards[i]->getRank() == input.substr(5, 1) && legalCards[i]->getSuit() == input.substr(6, 1)) {
					std::cout << "Player" << playerNumber << " plays " << legalCards[i]->getRank() << legalCards[i]->getSuit() << "." << std::endl;
					for (int j = 0; j < playerCards.size(); j++) {
						if (Card::isEqual(*playerCards[j], *legalCards[i])) {
							playerCards.erase(playerCards.begin() + j);
							break;
						}
					}
					legalCards.insert(legalCards.begin(), legalCards[i]);
					isValid = true;
					break;
				}
			}
			if (isValid == false) {
				std::cout << "This is not a legal play." << std::endl;
			}
		}
		else if (input.length() == 10 && input.substr(0, 8) == "discard ") {
			std::cout << "You have a legal play. You may not discard." << std::endl;
		}
		else if (input == "deck") {
			shuffledDeck.printDeck();
		}
		else if (input == "quit") {
			exit(0);
		}
		else if (input == "ragequit") {
			std::cout << "I couldn't implement ragequit... Please enter another command..." << std::endl;
		}
		else {
			std::cout << "Invalid command: " << "\"" << input << "\"" << std::endl;
		}
	}
}

void HumanPlayer::discardCard() {
	bool isValid = false;
	std::string input;
	while (!isValid) {
		std::cout << ">";
		std::getline(std::cin, input);
		if (input.length() == 7 && input.substr(0, 5) == "play ") {
			std::cout << "This is not a legal play." << std::endl;
		}
		else if (input.length() == 10 && input.substr(0, 8) == "discard ") {
			for (int i = 0; i < playerCards.size(); i++) {
				if (playerCards[i]->getRank() == input.substr(8, 1) && playerCards[i]->getSuit() == input.substr(9, 1)) {
					std::cout << "Player" << playerNumber << " discards " << playerCards[i]->getRank() << playerCards[i]->getSuit() << "." << std::endl;
					discardedCards.push_back(playerCards[i]);
					playerCards.erase(playerCards.begin() + i);
					isValid = true;
					break;
				}
			}
		}
		else if (input == "deck") {
			shuffledDeck.printDeck();
		}
		else if (input == "quit") {
			exit(0);
		}
		else if (input == "ragequit") {
			std::cout << "I couldn't implement ragequit... Please enter another command..." << std::endl;
		}
		else {
			std::cout << "Invalid command: " << "\"" << input << "\"" << std::endl;
		}
	}
}