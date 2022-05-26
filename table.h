#ifndef __TABLE_H__
#define __TABLE_H__

#include "card.h"
#include <vector>

class Table {
	std::vector<Card*> c;
	std::vector<Card*> d;
	std::vector<Card*> h;
	std::vector<Card*> s;
	
public:
	Table(std::vector<Card*> c, std::vector<Card*> d, std::vector<Card*> h, std::vector<Card*> s);

	std::vector<Card*> getC() const;
	std::vector<Card*> getD() const;
	std::vector<Card*> getH() const;
	std::vector<Card*> getS() const;

	void addCardToFrontC(Card* card);
	void addCardToFrontD(Card* card);
	void addCardToFrontH(Card* card);
	void addCardToFrontS(Card* card);

	void addCardToBackC(Card* card);
	void addCardToBackD(Card* card);
	void addCardToBackH(Card* card);
	void addCardToBackS(Card* card);

	void clearC();
	void clearD();
	void clearH();
	void clearS();

	void printTable() const;
};

#endif