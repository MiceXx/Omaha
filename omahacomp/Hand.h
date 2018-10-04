#ifndef Hand_h
#define Hand_h

#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "Card.h"

class Hand
{
public:
	Hand();
	Hand(Card c1, Card c2, Card c3, Card c4);
	Hand(Card c1, Card c2, Card c3, Card c4, Card c5);
	Hand(std::string str);
	~Hand();

	void printHand();
	std::vector<Card> getHand();
	std::string getHandStr();
	Card getCard(int n);
	int getHi();
	int getLo();

private:
	std::vector<Card>_hand = std::vector<Card>(5);
	int _hi;
	int _lo;

	int getHighValue();
	int getLowValue();
	bool isFourOfAKind();
	bool isFullHouse();
	bool isFlush();
	bool isStraight();
	bool isThreeOfAKind();
	bool isTwoPair();
	bool isPair();
};

#endif