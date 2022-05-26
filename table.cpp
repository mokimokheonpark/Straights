#include "table.h"
#include <iostream>

Table::Table(std::vector<Card*> c, std::vector<Card*> d, std::vector<Card*> h, std::vector<Card*> s) : c{ c }, d{ d }, h{ h }, s{ s } {}

std::vector<Card*> Table::getC() const {
	return c;
}

std::vector<Card*> Table::getD() const {
	return d;
}

std::vector<Card*> Table::getH() const {
	return h;
}

std::vector<Card*> Table::getS() const {
	return s;
}

void Table::addCardToFrontC(Card* card) {
	c.insert(c.begin(), card);
}

void Table::addCardToFrontD(Card* card) {
	d.insert(d.begin(), card);
}

void Table::addCardToFrontH(Card* card) {
	h.insert(h.begin(), card);
}

void Table::addCardToFrontS(Card* card) {
	s.insert(s.begin(), card);
}

void Table::addCardToBackC(Card* card) {
	c.push_back(card);
}

void Table::addCardToBackD(Card* card) {
	d.push_back(card);
}

void Table::addCardToBackH(Card* card) {
	h.push_back(card);
}

void Table::addCardToBackS(Card* card) {
	s.push_back(card);
}

void Table::clearC() {
	c.clear();
}

void Table::clearD() {
	d.clear();
}

void Table::clearH() {
	h.clear();
}

void Table::clearS() {
	s.clear();
}

void Table::printTable() const {
	std::cout << "Cards on the table:" << std::endl;
	std::cout << "Clubs: ";
	for (int i = 0; i < c.size(); i++) {
		std::cout << c[i]->getRank() << " ";
	}
	std::cout << std::endl;
	std::cout << "Diamonds: ";
	for (int i = 0; i < d.size(); i++) {
		std::cout << d[i]->getRank() << " ";
	}
	std::cout << std::endl;
	std::cout << "Hearts: ";
	for (int i = 0; i < h.size(); i++) {
		std::cout << h[i]->getRank() << " ";
	}
	std::cout << std::endl;
	std::cout << "Spades: ";
	for (int i = 0; i < s.size(); i++) {
		std::cout << s[i]->getRank() << " ";
	}
	std::cout << std::endl;
}