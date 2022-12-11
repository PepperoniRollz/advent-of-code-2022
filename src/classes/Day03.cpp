#include "Day03.h"
#include <map>
#include <unordered_set>

Day03::Day03(std::string filename) : _filename(filename) {}

void Day03::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	int sumPriorities = 0;

	inFile.open(_filename, std::ios_base::in);

	std::getline(inFile, line);
	std::map<char, int> map;
	for (int i = 0; i < line.length(); i++) {
		char item = line[i];
		if (i < line.length() / 2) {
			map.insert(std::pair<char, int>(item, charToPriority(item)));
		}
		else {
			if (map.count(item)) {
				sumPriorities += map.at(item);
				break;
			}
		}
	}
	std::cout << "Day 3-1: " << sumPriorities << std::endl;
}

void Day03::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	int sumPriorities = 0;
	int elfInGroup = 0;
	std::unordered_set<char> firstElfSack;
	std::unordered_set<char> secondElfSack;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		for (int i = 0; i < line.length(); i++) {
			char item = line[i];

			if (elfInGroup == 0) {
				firstElfSack.insert(item);
			}
			else if (elfInGroup == 1) {
				if (firstElfSack.count(item)) {
					secondElfSack.insert(item);
				}
			}
			else {
				if (secondElfSack.count(item)) {
					sumPriorities += charToPriority(item);
					firstElfSack.clear();
					secondElfSack.clear();
					break;
				}
			}
		}
		elfInGroup = (elfInGroup + 1) % 3;
	}
	std::cout << "Day 3-2: " << sumPriorities << std::endl;
}

int Day03::charToPriority(char c) {
	return islower(c) ? c - 96 : c - 38;
}