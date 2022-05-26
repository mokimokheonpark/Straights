#include "gameplay.h"
#include <iostream>
#include <cassert>

GamePlay::GamePlay(Deck& shuffledDeck, Table& table) : shuffledDeck{ shuffledDeck }, table{ table } {}

Deck GamePlay::getShuffledDeck() const {
	return shuffledDeck;
}

void GamePlay::invitePlayers() {
	std::string player;
	int i = 1;
	while (i < 5) {
		std::cout << "Is Player" << i << " a human (h) or a computer (c)?" << std::endl;
		std::getline(std::cin, player);
		assert(player == "h" || player == "c");
		if (player == "h") {
			Player* pptr = new HumanPlayer(shuffledDeck);
			pptr->setPlayerNumber(i);
			players.push_back(pptr);
		}
		else {
			Player* pptr = new ComputerPlayer(shuffledDeck);
			pptr->setPlayerNumber(i);
			players.push_back(pptr);
		}
		i++;
	}
}

void GamePlay::legalPlay(Table& table, std::vector<Player*> players, int n) {
	players[n]->clearLegalCards();
	for (int i = 0; i < players[n]->getPlayerCards().size(); i++) {
		std::string r = players[n]->getPlayerCards()[i]->getRank();
		std::string s = players[n]->getPlayerCards()[i]->getSuit();
		if ((r == "7") ||
			((s == "C") && (!table.getC().empty()) &&
				(((r == "A") && (table.getC().front()->getRank() == "2")) ||
					((r == "2") && (table.getC().front()->getRank() == "3")) ||
					((r == "3") && (table.getC().front()->getRank() == "4")) ||
					((r == "4") && (table.getC().front()->getRank() == "5")) ||
					((r == "5") && (table.getC().front()->getRank() == "6")) ||
					((r == "6") && (table.getC().front()->getRank() == "7")) ||
					((r == "8") && (table.getC().back()->getRank() == "7")) ||
					((r == "9") && (table.getC().back()->getRank() == "8")) ||
					((r == "T") && (table.getC().back()->getRank() == "9")) ||
					((r == "J") && (table.getC().back()->getRank() == "T")) ||
					((r == "Q") && (table.getC().back()->getRank() == "J")) ||
					((r == "K") && (table.getC().back()->getRank() == "Q")))) ||
			((s == "D") && (!table.getD().empty()) &&
				(((r == "A") && (table.getD().front()->getRank() == "2")) ||
					((r == "2") && (table.getD().front()->getRank() == "3")) ||
					((r == "3") && (table.getD().front()->getRank() == "4")) ||
					((r == "4") && (table.getD().front()->getRank() == "5")) ||
					((r == "5") && (table.getD().front()->getRank() == "6")) ||
					((r == "6") && (table.getD().front()->getRank() == "7")) ||
					((r == "8") && (table.getD().back()->getRank() == "7")) ||
					((r == "9") && (table.getD().back()->getRank() == "8")) ||
					((r == "T") && (table.getD().back()->getRank() == "9")) ||
					((r == "J") && (table.getD().back()->getRank() == "T")) ||
					((r == "Q") && (table.getD().back()->getRank() == "J")) ||
					((r == "K") && (table.getD().back()->getRank() == "Q")))) ||
			((s == "H") && (!table.getH().empty()) &&
				(((r == "A") && (table.getH().front()->getRank() == "2")) ||
					((r == "2") && (table.getH().front()->getRank() == "3")) ||
					((r == "3") && (table.getH().front()->getRank() == "4")) ||
					((r == "4") && (table.getH().front()->getRank() == "5")) ||
					((r == "5") && (table.getH().front()->getRank() == "6")) ||
					((r == "6") && (table.getH().front()->getRank() == "7")) ||
					((r == "8") && (table.getH().back()->getRank() == "7")) ||
					((r == "9") && (table.getH().back()->getRank() == "8")) ||
					((r == "T") && (table.getH().back()->getRank() == "9")) ||
					((r == "J") && (table.getH().back()->getRank() == "T")) ||
					((r == "Q") && (table.getH().back()->getRank() == "J")) ||
					((r == "K") && (table.getH().back()->getRank() == "Q")))) ||
			((s == "S") && (!table.getS().empty()) &&
				(((r == "A") && (table.getS().front()->getRank() == "2")) ||
					((r == "2") && (table.getS().front()->getRank() == "3")) ||
					((r == "3") && (table.getS().front()->getRank() == "4")) ||
					((r == "4") && (table.getS().front()->getRank() == "5")) ||
					((r == "5") && (table.getS().front()->getRank() == "6")) ||
					((r == "6") && (table.getS().front()->getRank() == "7")) ||
					((r == "8") && (table.getS().back()->getRank() == "7")) ||
					((r == "9") && (table.getS().back()->getRank() == "8")) ||
					((r == "T") && (table.getS().back()->getRank() == "9")) ||
					((r == "J") && (table.getS().back()->getRank() == "T")) ||
					((r == "Q") && (table.getS().back()->getRank() == "J")) ||
					((r == "K") && (table.getS().back()->getRank() == "Q"))))) {

			players[n]->addLegalCard(players[n]->getPlayerCards()[i]);
		}
	}
}

void GamePlay::game() {
	bool checkEighty = false;
	while (!checkEighty) {
		for (int i = 0, j = 0; i < getShuffledDeck().getDeck().size(); i++) {
			players[j]->addPlayerCard(getShuffledDeck().getDeck()[i]);
			if (((i + 1) % 13) == 0) {
				j++;
			}
		}

		int firstPlayer;
		Card c("7", "S");
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				if (Card::isEqual(c, *(players[i]->getPlayerCards()[j]))) {
					firstPlayer = i + 1;
				}
			}
		}
		std::cout << "A new round begins. It's Player" << firstPlayer << "'s turn to play." << std::endl;

		int k = firstPlayer - 1;
		for (int i = 0; i < 13; i++) {
			for (int j = 0; j < 4; j++) {
				legalPlay(table, players, k);
				if (players[k]->getType() == "human") {
					table.printTable();
					players[k]->printPlayerCards();
					players[k]->printLegalCards();
				}

				if (!players[k]->getLegalCards().empty()) {
					players[k]->playCard();
					std::string r = players[k]->getLegalCards()[0]->getRank();
					std::string s = players[k]->getLegalCards()[0]->getSuit();
					if ((r == "A") || (r == "2") || (r == "3") || (r == "4") || (r == "5") || (r == "6")) {
						if (s == "C") {
							table.addCardToFrontC(players[k]->getLegalCards()[0]);
						}
						else if (s == "D") {
							table.addCardToFrontD(players[k]->getLegalCards()[0]);
						}
						else if (s == "H") {
							table.addCardToFrontH(players[k]->getLegalCards()[0]);
						}
						else {
							table.addCardToFrontS(players[k]->getLegalCards()[0]);
						}
					}
					else {
						if (s == "C") {
							table.addCardToBackC(players[k]->getLegalCards()[0]);
						}
						else if (s == "D") {
							table.addCardToBackD(players[k]->getLegalCards()[0]);
						}
						else if (s == "H") {
							table.addCardToBackH(players[k]->getLegalCards()[0]);
						}
						else {
							table.addCardToBackS(players[k]->getLegalCards()[0]);
						}
					}
				}
				else {
					players[k]->discardCard();
				}

				if (k == 3) {
					k = 0;
				}
				else {
					k++;
				}
			}
		}

		for (int i = 0; i < players.size(); i++) {
			players[i]->setPlayerScore(players[i]->getDiscardedCards());
			std::cout << "Player" << i + 1 << "'s discards: ";
			for (int j = 0; j < players[i]->getDiscardedCards().size(); j++) {
				std::cout << players[i]->getDiscardedCards()[j]->getRank() << players[i]->getDiscardedCards()[j]->getSuit() << " ";
			}
			std::cout << std::endl;
			int s = players[i]->getSavedScore();
			int p = players[i]->getPlayerScore();
			std::cout << "Player" << i + 1 << "'s score: " << s << " + " << p << " = " << s + p << std::endl;
			if (s + p >= 80) {
				checkEighty = true;
			}
		}

		if (checkEighty) {
			int minimum = players[0]->getSavedScore() + players[0]->getPlayerScore();
			for (int i = 1; i < players.size(); i++) {
				if (players[i]->getSavedScore() + players[i]->getPlayerScore() < minimum) {
					minimum = players[i]->getSavedScore() + players[i]->getPlayerScore();
				}
			}
			for (int i = 0; i < players.size(); i++) {
				if (players[i]->getSavedScore() + players[i]->getPlayerScore() == minimum) {
					std::cout << "Player" << i + 1 << " wins!" << std::endl;
				}
			}
		}
		else {
			for (int i = 0; i < players.size(); i++) {
				players[i]->setSavedScore(players[i]->getSavedScore() + players[i]->getPlayerScore());
				players[i]->resetPlayerScore();
				players[i]->clearDiscardedCards();
			}
			table.clearC();
			table.clearD();
			table.clearH();
			table.clearS();
		}
	}

	for (int i = 0; i < players.size(); i++) {
		delete players[i];
	}
}