#include "DayThree.h"
#include <map>
#include <unordered_set>

DayThree::DayThree(std::string filename) : _filename(filename) {}

void DayThree::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	int sumPriorities = 0;

	inFile.open(_filename, std::ios_base::in);

	while (std::getline(inFile, line)) {
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
	}
	std::cout << "Day 3-1: " << sumPriorities << std::endl;
}

void DayThree::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	int sumPriorities = 0;
	int group = 0;
	std::unordered_set<char> setOne;
	std::unordered_set<char> setTwo;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		for (int i = 0; i < line.length(); i++) {
			char item = line[i];

			if (group == 0) {
				setOne.insert(item);
			}
			else if (group == 1) {
				if (setOne.count(item)) {
					setTwo.insert(item);
				}
			}
			else {
				if (setTwo.count(item)) {
					sumPriorities += charToPriority(item);
					setOne.clear();
					setTwo.clear();
					break;
				}
			}
		}
		group = (group + 1) % 3;
	}
	std::cout << "Day 3-2: " << sumPriorities;
}

int DayThree::charToPriority(char c) {
	return islower(c) ? c - 96 : c - 38;
}