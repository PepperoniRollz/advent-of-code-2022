#include "DayFive.h"
#include <vector>
#include <sstream>
#include <string>

DayFive::DayFive(std::string filename) : _filename(filename) {}

void DayFive::partOneSolution() {
	std::ifstream inFile;
	std::string line;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
	}
	std::cout << "Day 5-1: " << std::endl;
}

void DayFive::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
	}
	std::cout << "Day 5-2: " << std::endl;
}