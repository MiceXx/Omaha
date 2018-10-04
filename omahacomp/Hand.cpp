#include "Hand.h"

bool operator<(Card &a, Card &b)
{
	return a.getRank() > b.getRank();
}

Hand::Hand()
{
	this->_lo = INT_MAX;
	this->_hi = INT_MIN;
}


Hand::~Hand()
{
}

Hand::Hand(Card c1, Card c2, Card c3, Card c4) {
	this->_hand[0] = c1;
	this->_hand[1] = c2;
	this->_hand[2] = c3;
	this->_hand[3] = c4;
	this->_hand[4] = Card(0, 'X'); //Dummy
	this->_lo = INT_MAX;
	this->_hi = INT_MIN;
}

Hand::Hand(Card c1, Card c2, Card c3, Card c4, Card c5) {
	this->_hand[0] = c1;
	this->_hand[1] = c2;
	this->_hand[2] = c3;
	this->_hand[3] = c4;
	this->_hand[4] = c5;
	std::sort(_hand.begin(), _hand.end());
	this->_lo = getLowValue();
	this->_hi = getHighValue();
}

int Hand::getHi() {
	return this->_hi;
}
int Hand::getLo() {
	return this->_lo;
}

std::vector<Card> Hand::getHand() {
	return this->_hand;
}

std::string Hand::getHandStr() {
	std::string s = "";
	for (int i = 0; i < 5; i++) {
		int k = _hand[i].getRank();
		switch (k) {
		case 11:
			s += "J";
			break;
		case 12:
			s += "Q";
			break;
		case 13:
			s += "K";
			break;
		case 14:
			s += "A";
			break;
		default:
			s += std::to_string(k);
		}
	}
	return s;
}

Card Hand::getCard(int n) {
	if (n > 4 || n < 0) std::cout << "Hand index out of range:" << n << std::endl;
	return this->_hand[n];
}

Hand::Hand(std::string str) {
	std::unordered_map<std::string, int> rankMap{
	{"1", 1}, {"2", 2}, {"3", 3},
	{"4", 4}, {"5", 5}, {"6", 6},
	{"7", 7}, {"8", 8}, {"9", 9},
	{"T", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14} };
	std::stringstream ss(str);
	std::string seg;
	std::vector<std::string> inputList;
	while(std::getline(ss, seg, '-')){
		inputList.push_back(seg);
	}
	for (size_t i = 0; i < inputList.size(); i++) {
		std::string s = inputList[i];
		int len = s.size();
		char suit = s[len - 1];
		int rank = rankMap[s.substr(0, len - 1)];
		this->_hand[i] = Card{ rank, suit };
	}
}

void Hand::printHand() {
	for (int i = 0; i < 5; i++) {
		_hand[i].printCard();
		std::cout << "-";
	}
	std::cout << std::endl;
}

int Hand::getHighValue() {

	if (isFlush() && this->isStraight()) return 900;
	else if (isFourOfAKind()) return 800;
	else if (isFullHouse()) return 700;
	else if (isFlush()) return 600;
	else if (isStraight()) return 500;
	else if (isThreeOfAKind()) return 400;
	else if (isTwoPair()) return 300;
	else if (isPair()) return 200;
	else return 100;
}

int Hand::getLowValue() {
	int tot = 0;
	if (!isPair()) {
		if (_hand[0].getRank() <= 8) {	//NO ACE
			for (int i = 0; i < 5; i++) {
				tot = tot * 10 + _hand[i].getRank();
			}

			return tot;
		}
		else if (_hand[0].getRank() == 14 && _hand[1].getRank() <= 8) {	//FIRST CARD IS ACE
			for (int i = 1; i < 5; i++) {
				tot = tot * 10 + _hand[i].getRank();
			}
			tot = tot * 10 + 1;
			return tot;
		}
		else {
			return INT_MAX; //NO LOW AVAILABLE
		}
	}
		
	else return INT_MAX;	//NO LOW AVAILABLE
}

bool Hand::isFourOfAKind() {	// [0==1==2==3] OR [1==2==3==4]
	if ((_hand[0].getRank() == _hand[1].getRank() &&	
		_hand[1].getRank() == _hand[2].getRank() &&
		_hand[2].getRank() == _hand[3].getRank()) ||
		_hand[1].getRank() == _hand[2].getRank() &&
		_hand[2].getRank() == _hand[3].getRank() &&
		_hand[3].getRank() == _hand[4].getRank()) return true;
	return false;
}

bool Hand::isFullHouse() {	// [0==1  and 2==3==4] OR [0==1==2 and 3==4]
	if ((_hand[0].getRank() == _hand[1].getRank() &&	
		_hand[2].getRank() == _hand[3].getRank() &&
		_hand[3].getRank() == _hand[4].getRank()) ||
		(_hand[0].getRank() == _hand[1].getRank() &&
		_hand[1].getRank() == _hand[2].getRank() &&
		_hand[3].getRank() == _hand[4].getRank())) return true;
	return false;
}

bool Hand::isFlush() {
	for (int i = 1; i < 5; i++) {
		if (_hand[i-1].getSuit() != _hand[i].getSuit()) return false;
	}
	return true;
}

bool Hand::isStraight() {
	if (_hand[0].getRank() == 14 && _hand[1].getRank() == 5) {	//Ace as low card. Only possible straight is A 4 3 2 1
		for (int i = 2; i < 5; i++) {	//check 5 4 3 2
			if (_hand[i - 1].getRank() - _hand[i].getRank() != 1) return false;
		}
	}
	else {	//Ace as high card or no Ace
		for (int i = 1; i < 5; i++) {
			if (_hand[i - 1].getRank() - _hand[i].getRank() != 1) return false;
		}
	}
	return true;
}

bool Hand::isThreeOfAKind() {
	//// [0==1==2] OR [1==2==3] OR [2==3==4]
	if ((_hand[0].getRank() == _hand[1].getRank() && _hand[1].getRank() == _hand[2].getRank()) ||
		(_hand[1].getRank() == _hand[2].getRank() && _hand[2].getRank() == _hand[3].getRank()) ||
		(_hand[2].getRank() == _hand[3].getRank() && _hand[3].getRank() == _hand[4].getRank())) return true;
	return false;
}

bool Hand::isTwoPair() {
	std::unordered_set<int> set;
	bool firstPair = false;
	for (int i = 0; i < 5;i++ ) {
		int k = _hand[i].getRank();
		if (set.count(k)) {
			if (firstPair) return true;
			else firstPair = true;
		}
		set.insert(k);
	}
	return false;
}

bool Hand::isPair() {
	std::unordered_set<int> set;
	for (int i = 0; i < 5; i++) {
		int k = _hand[i].getRank();
		if (set.count(k)) return true;
		set.insert(k);
	}
	return false;
}
