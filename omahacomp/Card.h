#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>

class Card
{
public:
	Card();
	Card(int rank, char suit);
	~Card();

	int getRank();
	char getSuit();
	void printCard();
	
private:
	int _rank;
	char _suit;
};

#endif
