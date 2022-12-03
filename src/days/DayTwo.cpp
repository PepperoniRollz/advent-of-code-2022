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

		if (me == opponent) {
			score += 3;
		}
		if (me == (opponent + 1) % 3) {
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

		if (result == 0) {
			me = opponent - 1 >= 0 ? opponent - 1 : 2;
		}
		else if (result == 1) {
			me = opponent;
			score += 3;
		}
		else if (result == 2) {
			me = (opponent + 1) % 3;
			score += 6;
		}
		score += me + 1;
	}
	std::cout << "Day 2-2: " << score << std::endl;
}