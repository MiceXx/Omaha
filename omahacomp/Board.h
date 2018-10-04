#ifndef Board_h
#define Board_h

#include <vector>
#include <sstream>
#include <unordered_map>
#include "Card.h"

class Board
{
public:
	Board();
	~Board();

	Board(Card c1, Card c2, Card c3, Card c4, Card c5);
	Board(std::string str);

	void printBoard();
	std::vector<Card> getBoard();
	Card getCard(int n);

private:
	std::vector<Card>_board = std::vector<Card>(5);
};


#endif