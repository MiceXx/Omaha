#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

std::vector<Card> Board::getBoard() {
	return _board;
}

Card Board::getCard(int n) {
	if (n > 4 || n < 0) std::cout << "Board index out of range:" << n << std::endl;
	return this->_board[n];
}

Board::Board(Card c1, Card c2, Card c3, Card c4, Card c5) {
	this->_board[0] = c1;
	this->_board[1] = c2;
	this->_board[2] = c3;
	this->_board[3] = c4;
	this->_board[4] = c5;
}

Board::Board(std::string str) {
	std::unordered_map<std::string, int> rankMap{
		{"1", 1}, {"2", 2}, {"3", 3},
		{"4", 4}, {"5", 5}, {"6", 6},
		{"7", 7}, {"8", 8}, {"9", 9},
		{"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14} };
	std::stringstream ss(str);
	std::string seg;
	std::vector<std::string> inputList;
	while (std::getline(ss, seg, '-')) {
		inputList.push_back(seg);
	}
	for (size_t i = 0; i < inputList.size(); i++) {
		std::string s = inputList[i];
		int len = s.size();
		char suit = s[len - 1];
		int rank = rankMap[s.substr(0, len - 1)];
		this->_board[i] = Card{ rank, suit };
	}
}

void Board::printBoard() {
	for (int i = 0; i < 5; i++) {
		_board[i].printCard();
		std::cout << "-";
	}
	std::cout << std::endl;
}
