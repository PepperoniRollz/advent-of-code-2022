#include "DayFour.h"
#include <vector>
#include <sstream>
#include <string>
#include <unordered_set>

DayFour::DayFour(std::string filename) : _filename(filename) {}

void DayFour::partOneSolution() {
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

void DayFour::partTwoSolution() {
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

bool DayFour::contains(std::vector<int> tokens) {
	return (tokens.at(0) >= tokens.at(2) && tokens.at(1) <= tokens.at(3)) ||
		(tokens.at(2) >= tokens.at(0) && tokens.at(3) <= tokens.at(1));
}

bool DayFour::overlaps(std::vector<int> tokens) {
	bool overlaps = false;
	std::unordered_set<int> set;
	for (int i = tokens.at(0); i <= tokens.at(1); i++) {
		set.insert(i);
	}
	for (int i = tokens.at(2); i <= tokens.at(3); i++) {
		if (set.count(i)) { return true; }
	}
	set.clear();
	for (int i = tokens.at(2); i <= tokens.at(3); i++) {
		set.insert(i);
	}
	for (int i = tokens.at(0); i <= tokens.at(1); i++) {
		if (set.count(i)) { return true; }
		return overlaps;
	}
}

void DayFour::tokenizer(std::vector<int>& tokens, std::string line) {
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