#include "gameplay.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
	vector<string> v = {
		"AC", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC",
		"AD", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD",
		"AH", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH",
		"AS", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS"
	};

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	if (argc > 1) {
		try {
			seed = stoi(string{ argv[1] });
		}
		catch (invalid_argument& e) {
			cerr << e.what() << endl;
			return 1;
		}
		catch (out_of_range& e) {
			cerr << e.what() << endl;
			return -1;
		}
	}
	default_random_engine rng(seed);
	shuffle(v.begin(), v.end(), rng);

	vector<Card> cards;
	for (int i = 0; i < v.size(); i++) {
		cards.push_back(Card(v[i].substr(0, 1), v[i].substr(1, 1)));
	}

	vector<Card*> cardptrs;
	for (int i = 0; i < cards.size(); i++) {
		cardptrs.push_back(&cards[i]);
	}

	Deck shuffledCards(cardptrs);

	vector<Card*> c;
	vector<Card*> d;
	vector<Card*> h;
	vector<Card*> s;
	Table tb(c, d, h, s);

	GamePlay gp(shuffledCards, tb);
	gp.invitePlayers();
	gp.game();

	return 0;
}