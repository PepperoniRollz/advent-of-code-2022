#include "DayOne.h"

DayOne::DayOne(std::string filename) : _filename(filename) {}

void DayOne::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	int maxCalories = 0;
	int totalCalories = 0;

	inFile.open(_filename, std::ios_base::in);

	while (std::getline(inFile, line)) {
		if (!line.empty()) {
			totalCalories += stoi(line);
			maxCalories = totalCalories > maxCalories ? totalCalories : maxCalories;
		}
		else totalCalories = 0;
	}
	std::cout << "Day 1-1: " << maxCalories << std::endl;
}

void DayOne::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	int first, second, third;
	first = second = third = INT32_MIN;
	int totalCalories = 0;

	inFile.open(_filename, std::ios_base::in);

	while (std::getline(inFile, line)) {
		if (!line.empty()) {
			totalCalories += stoi(line);
		}
		else {
			if (totalCalories > first) {
				first = totalCalories;
			}
			if (totalCalories > second && totalCalories < first) {
				second = totalCalories;
			}
			if (totalCalories > third && totalCalories < second) {
				third = totalCalories;
			}
			totalCalories = 0;
		}
	}
	std::cout << "Day 1-2: " << first + second + third << std::endl;
}