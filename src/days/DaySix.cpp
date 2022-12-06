#include "DaySix.h"
#include <string>
#include <map>
DaySix::DaySix(std::string filename) {
	_filename = filename;
}

void DaySix::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	int marker;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		marker = getMarker(line, 4);
	}
	std::cout << "Day 6-1: " << marker << std::endl;
}

void DaySix::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	int marker;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		marker = getMarker(line, 14);
	}
	std::cout << "Day 6-2: " << marker;
}

int DaySix::getMarker(const std::string& input, int length) {
	std::map<char, int> map;
	int repeats = 0;
	for (int i = 0; i < length; i++) {
		if (map.count(input[i])) {
			map.at(input[i])++;
			repeats++;
		}
		else
			map.insert(std::pair<char, int>(input[i], 1));
	}

	if (repeats == 0) return length;

	for (int i = length; i < input.length(); i++) {
		map.at(input[i - length])--;
		if (map.at(input[i - length]) >= 1) repeats--;
		if (map.count(input[i])) {
			map.at(input[i])++;
			if (map.at(input[i]) > 1) repeats++;
		}
		else map.insert(std::pair<char, int>(input[i], 1));
		if (repeats == 0) return i + 1;
	}

	return -1;
}