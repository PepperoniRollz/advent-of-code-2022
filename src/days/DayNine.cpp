#include "DayNine.h"
#include "math.h"
#include <unordered_set>
#include <sstream>
#include <string>
#include "RopeSimulator.h"

DayNine::DayNine(std::string filename) : _filename(filename) {}

void DayNine::partOneSolution() {
	std::ifstream inFile;
	std::string line;

	RopeSimulator simulator(2);
	simulator.visited.insert(simulator.rope[simulator.rope.size() - 1]->position);

	inFile.open(_filename, std::ios_base::in);

	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}
		Direction d = charToEnum(tokens[0][0]);

		simulator.start(d, std::stoi(tokens[1]));
	}
	std::cout << "Day 9-1: " << simulator.visited.size() << std::endl;
}

void DayNine::partTwoSolution() {
	std::ifstream inFile;
	std::string line;

	RopeSimulator simulator(10);
	simulator.visited.insert(simulator.rope[simulator.rope.size() - 1]->position);

	inFile.open(_filename, std::ios_base::in);

	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}
		Direction d = charToEnum(tokens[0][0]);

		simulator.start(d, std::stoi(tokens[1]));
	}
	std::cout << "Day 9-2: " << simulator.visited.size() << std::endl;
}

Direction DayNine::charToEnum(char c) {
	if (c == 'R')
		return Direction::RIGHT;
	else if (c == 'D')
		return Direction::DOWN;
	else if (c == 'L')
		return Direction::LEFT;
	else
		return Direction::UP;
}