#include "Day04.h"
#include <vector>
#include <sstream>
#include <string>

Day04::Day04(std::string filename) : _filename(filename) {}

void Day04::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	int answer = 0;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::vector<int> assignments;
		tokenizer(assignments, line);
		if (contains(assignments)) {
			answer++;
		}
	}
	std::cout << "Day 4-1: " << answer << std::endl;
}

void Day04::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	int answer = 0;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::vector<int> assignments;
		tokenizer(assignments, line);
		if (overlaps(assignments)) {
			answer++;
		}
	}
	std::cout << "Day 4-2: " << answer << std::endl;
}

bool Day04::contains(std::vector<int> tokens) {
	return (tokens.at(0) >= tokens.at(2) && tokens.at(1) <= tokens.at(3)) ||
		(tokens.at(2) >= tokens.at(0) && tokens.at(3) <= tokens.at(1));
}

bool Day04::overlaps(std::vector<int> tokens) {
	return (tokens.at(0) <= tokens.at(2) && tokens.at(1) >= tokens.at(2))
		|| (tokens.at(0) <= tokens.at(3) && tokens.at(1) >= tokens.at(3))
		|| (tokens.at(2) <= tokens.at(0) && tokens.at(3) >= tokens.at(0))
		|| (tokens.at(2) <= tokens.at(1) && tokens.at(3) >= tokens.at(1));
}

void Day04::tokenizer(std::vector<int>& tokens, std::string line) {
	std::stringstream check1(line);
	std::string withoutCommas;
	std::string withoutHyphens;

	while (std::getline(check1, withoutCommas, ',')) {
		std::stringstream check2(withoutCommas);
		while (std::getline(check2, withoutHyphens, '-')) {
			tokens.push_back(stoi(withoutHyphens));
		}
	}
}