#include "DaySix.h"
#include <string>
#include <map>
#include <unordered_set>

DaySix::DaySix(std::string filename) {
	_filename = filename;
	std::ifstream inFile;
	inFile.open(_filename, std::ios_base::in);
	std::getline(inFile, _line);
}

void DaySix::partOneSolution() {
	int marker = getMarker(_line, 4);
	std::cout << "Day 6-1: " << marker << std::endl;
}

void DaySix::partTwoSolution() {
	int marker = getMarker(_line, 14);

	std::cout << "Day 6-2: " << marker << std::endl;
}

int DaySix::getMarker(const std::string& input, int length) {
	int iterations = 0;
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