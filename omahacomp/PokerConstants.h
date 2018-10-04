#ifndef PokerConstants_h
#define PokerConstants_h

enum HandType
{
	HIGHCARD,		//100
	ONEPAIR,		//200
	TWOPAIR,		//300
	THREEOFAKIND,	//400
	STRAIGHT,		//500
	FLUSH,			//600
	FULLHOUSE,		//700
	FOUROFAKIND,	//800
	STRAIGHTFLUSH	//900
};

enum CardSuit
{
	INVALIDSUIT,
	CLUB,
	SPADE,
	HEART,
	DIAMOND
};

enum CardRank
{
	INVALIDNUMBER,
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE
};

#endif