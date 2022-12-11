#include "DayTwo.h"
#include <vector>
DayTwo::DayTwo(std::string filename) : _filename(filename) {}

void DayTwo::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	int opponent;
	int me;
	int score = 0;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		opponent = line[0] - 65;
		me = line[2] - 88;
		score += me + 1;

		if (tie(me, opponent)) {
			score += 3;
		}
		if (iWin(me, opponent)) {
			score += 6;
		}
	}
	std::cout << "Day 2-1: " << score << std::endl;
}

void DayTwo::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	int opponent;
	int me;
	int result;
	int score = 0;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		opponent = line[0] - 65;
		result = line[2] - 88;

		if (result == LOSE) {
			me = opponent - 1 >= 0 ? opponent - 1 : 2;
		}
		else if (result == DRAW) {
			me = opponent;
			score += 3;
		}
		else if (result == WIN) {
			me = (opponent + 1) % 3;
			score += 6;
		}
		score += me + 1;
	}
	std::cout << "Day 2-2: " << score << std::endl;
}

bool DayTwo::iWin(int me, int opponent) {
	return me == (opponent + 1) % 3;
}

bool DayTwo::tie(int me, int opponent) {
	return me == opponent;
}