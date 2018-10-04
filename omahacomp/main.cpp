#include <string>
#include <sstream>
#include <fstream>

#include "Hand.h"
#include "Board.h"
#include "Card.h"
#include "Omaha.h"
//#include "PokerConstants.h"


int main() {
	std::ifstream infile("input.txt");
	std::ofstream outfile("output.txt");

	std::string line;

	while (std::getline(infile, line)) {
		std::cout << "*********************************************" << std::endl; //Remove
		std::cout << "Input: " << line << std::endl; //Remove

		std::stringstream ss(line);
		std::string seg;
		std::vector<std::string> inputList;
		while (std::getline(ss, seg, ' ')) {
			inputList.push_back(seg);
		}
		std::string s1 = inputList[0];
		Hand hand1 = Hand(s1.substr(s1.find("HandA:") + 6));
		std::string s2 = inputList[1];
		Hand hand2 = Hand(s2.substr(s2.find("HandB:") + 6));
		std::string s3 = inputList[2];
		Board board = Board(s3.substr(s3.find("Board:") + 6));

		Omaha omaha = Omaha(hand1, hand2, board);
		std::string answer = omaha.Solve();
		outfile << answer << "\n";

	}
	outfile.close();

	return 0;

}