#ifndef Ranker_h
#define Ranker_h

#include <iostream>
#include "Hand.h"
#include "Board.h"

class Omaha
{
public:
	Omaha();
	Omaha(Hand hand1, Hand hand2, Board board);
	~Omaha();

	std::string Solve();

private:
	Board _board;
	Hand _handA;
	Hand _handB;

	/*
	highHand:
		Finds the highest possible hand that can be made from the current hand and the board
		RETURNS the highest hand and the rank
*/
	Hand highHand(Hand hand);

	/*
		lowHand:
			Finds the lowest possible hand that can be made from the current hand and the board
			RETURNS the lowest hand and the rank
	*/
	Hand lowHand(Hand hand);

	/*
	compareHi:
		Returns 1 if hand 1 is bigger
		Returns 2 if hand 2 is bigger
		Returns 0 if both hands are equal
		ONLY COMPARES Hi VAL
	*/
	int compareHi(Hand hand1, Hand hand2);

	/*
	compareLo:
		Returns 1 if hand 1 is bigger
		Returns 2 if hand 2 is bigger
		Returns 0 if both hands are equal
		ONLY COMPARES LO VAL
	*/
	int compareLo(Hand hand1, Hand hand2);

	std::string formatLoString(std::string s);
};

#endif