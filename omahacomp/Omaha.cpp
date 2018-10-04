#include "Omaha.h"

/*
	HIGHCARD, 100
	ONEPAIR, 200
	TWOPAIR, 300
	THREEOFAKIND, 400
	STRAIGHT, 500
	FLUSH, 600
	FULLHOUSE, 700
	FOUROFAKIND, 800
 	STRAIGHTFLUSH 900
*/

Omaha::Omaha()
{
}

Omaha::Omaha(Hand handA, Hand handB, Board board)
{
	this->_handA = handA;
	this->_handB = handB;
	this->_board = board;
}

Omaha::~Omaha()
{
}

Hand Omaha::highHand(Hand hand) {	//Thinking of using brute force with all possible combination of hands (60 total)... Not the best method, but easiest given the time constraint
	Hand maxHand = Hand();
	for (int i = 0; i < 4; i++) {	//Loop hand
		for (int j = i + 1; j < 4; j++) {
			for (int ii = 0; ii < 5; ii++) {	//Loop Board
				for (int jj = ii + 1; jj < 5; jj++) {
					for (int kk = jj + 1; kk < 5; kk++) {
						Hand h = Hand(hand.getCard(i), hand.getCard(j), _board.getCard(ii), _board.getCard(jj), _board.getCard(kk));
						int k = compareHi(h, maxHand);
						if (k == 1) maxHand = h;
					}
				}
			}
		}
	}
	return maxHand;
}

Hand Omaha::lowHand(Hand hand) {
	Hand minHand = Hand();
	for (int i = 0; i < 4; i++) {	//Loop hand
		for (int j = i + 1; j < 4; j++) {
			for (int ii = 0; ii < 5; ii++) {	//Loop Board
				for (int jj = ii + 1; jj < 5; jj++) {
					for (int kk = jj + 1; kk < 5; kk++) {
						Hand h = Hand(hand.getCard(i), hand.getCard(j), _board.getCard(ii), _board.getCard(jj), _board.getCard(kk));
						if (h.getLo() != INT_MAX) {
							int k = compareLo(h, minHand);
							if (k == 2) minHand = h;
						}
					}
				}
			}
		}
	}
	return minHand;
}

std::string Omaha::Solve() {
	std::unordered_map<int, std::string> handRank = {
		{100,"High Card"}, {200, "One Pair"}, {300, "Two Pair"},
		{400, "3-of-a-kind"}, {500, "Straight"}, {600, "Flush"},
		{700, "Full House"}, {800, "4-of-a-Kind"}, {900, "Straight Flush"}
	};
	std::string answer = "";

	/****************************FIND THE HI WINNER**************************/
	Hand hiA = highHand(_handA);
	Hand hiB = highHand(_handB);
	int m = compareHi(hiA, hiB);
	Hand hiWinner;
	if (m == 1) {
		int k = hiA.getHi();
		answer = answer + "HandA Wins Hi (" + handRank[k] + ") ; ";
		hiWinner = hiA;
	}
	else if (m == 2) {
		int k = hiB.getHi();
		answer = answer + "HandB Wins Hi (" + handRank[k] + ") ; ";
		hiWinner = hiB;
	}
	else {
		int k = hiA.getHi();
		answer = answer + "Split Pot Hi (" + handRank[k] + ") ; ";
		hiWinner = hiA;
	}

	/***************************FIND THE Lo WINNER**************************/
	Hand loA = lowHand(_handA);
	Hand loB = lowHand(_handB);
	int n = compareLo(loA, loB);
	if (loB.getLo() == INT_MAX && loA.getLo() == INT_MAX)
		answer = answer + "No hand qualified for Low";
	else if ((loB.getLo() == INT_MAX && loA.getLo() != INT_MAX && compareHi(hiWinner, loA) == 0) || n == 2)
		answer = answer + "HandA Wins Lo (" + formatLoString(loA.getHandStr()) + ")";
	else if ((loA.getLo() == INT_MAX && loB.getLo() != INT_MAX && compareHi(hiWinner, loB) == 0) || n == 1)
		answer = answer + "HandB Wins Lo (" + formatLoString(loB.getHandStr()) + ")";
	else
		answer = answer + "Split Pot Lo (" + formatLoString(loA.getHandStr()) + ")";
	std::cout << answer << std::endl;
	return answer;
}


/*
	compareHi:
		Returns 1 if hand 1 is bigger
		Returns 2 if hand 2 is bigger
		Returns 0 if both hands are equal
		ONLY COMPARES HI VAL
*/
int Omaha::compareHi(Hand hand1, Hand hand2) {
	if (hand1.getHi() > hand2.getHi()) {
		return 1;
	}
	else if (hand2.getHi() > hand1.getHi()) {
		return 2;
	}
	else { //Hand Hi values are same

		for (int i = 0; i < 5; i++) {
			if (hand1.getCard(i).getRank() > hand2.getCard(i).getRank()) {
				return 1;
			}
			else if (hand2.getCard(i).getRank() > hand1.getCard(i).getRank()) {
				return 2;
			}
		}
		return 0;
	}
}

/*
	compareLo:
		Returns 1 if hand 1 is bigger
		Returns 2 if hand 2 is bigger
		Returns 0 if both hands are equal
		ONLY COMPARES LO VAL
*/
int Omaha::compareLo(Hand hand1, Hand hand2) {
	if (hand1.getLo() > hand2.getLo()) {
		return 1;
	}
	else if (hand2.getLo() > hand1.getLo()) {
		return 2;
	}
	else { //Hand Hi values are same

		for (int i = 0; i < 5; i++) {
			if (hand1.getCard(i).getRank() > hand2.getCard(i).getRank()) {
				return 1;
			}
			else if (hand2.getCard(i).getRank() > hand1.getCard(i).getRank()) {
				return 2;
			}
		}
		return 0;
	}
}

std::string Omaha::formatLoString(std::string str) {
	std::string outString = str;
	if (outString[0] == 'A') {
		for (int i = 0; i < 4; i++) {
			outString[i] = outString[i + 1];
		}
		outString[4] = 'A';
	}
	return outString;
}