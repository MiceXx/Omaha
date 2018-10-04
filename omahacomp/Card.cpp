#include "Card.h"


Card::Card()
{
}

Card::~Card()
{
}

Card::Card(int rank, char suit) {
	this->_rank = rank;
	this->_suit = suit;
}

int Card::getRank() {
	return _rank;
}

char Card::getSuit(){
	return _suit;
}

void Card::printCard() {
	std::cout << _rank << _suit;
}