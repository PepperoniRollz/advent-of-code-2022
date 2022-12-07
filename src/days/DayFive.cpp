#include "DayFive.h"
#include <vector>
#include <sstream>
#include <string>
#include <deque>

/*[V]     [B]                     [C]
[C]     [N] [G]         [W]     [P]
[W]     [C] [Q] [S]     [C]     [M]
[L]     [W] [B] [Z]     [F] [S] [V]
[R]     [G] [H] [F] [P] [V] [M] [T]
[M] [L] [R] [D] [L] [N] [P] [D] [W]
[F] [Q] [S] [C] [G] [G] [Z] [P] [N]
[Q] [D] [P] [L] [V] [D] [D] [C] [Z]*/

DayFive::DayFive(std::string filename) {
	_filename = filename;
	initStacks();
}

void DayFive::partOneSolution() {
	std::ifstream inFile;
	std::string line;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}

		int pops = stoi(tokens.at(1));
		int from = stoi(tokens.at(3));
		int to = stoi(tokens.at(5));

		for (int i = 0; i < pops; i++) {
			_stacks.at(to - 1).push_back(_stacks.at(from - 1).back());
			_stacks.at(from - 1).pop_back();
		}
	}
	std::cout << "Day 5-1: ";
	for (auto stack : _stacks) {
		std::cout << stack.back();
	}
	std::cout << std::endl;
}

void DayFive::partTwoSolution() {
	resetStacks();
	std::ifstream inFile;
	std::string line;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}

		int pops = stoi(tokens.at(1));
		int from = stoi(tokens.at(3));
		int to = stoi(tokens.at(5));

		std::deque<char> intermediateStack;
		for (int i = 0; i < pops; i++) {
			intermediateStack.push_front(_stacks.at(from - 1).back());
			_stacks.at(from - 1).pop_back();
		}

		for (int i = 0; i < pops; i++) {
			_stacks.at(to - 1).push_back(intermediateStack.front());
			intermediateStack.pop_front();
		}
	}
	std::cout << "Day 5-2: ";
	for (auto stack : _stacks) {
		std::cout << stack.back();
	}
	std::cout << std::endl;
}

void DayFive::resetStacks() {
	_stacks.clear();
	initStacks();
}

void DayFive::initStacks() {
	_stacks.push_back(_stack1);
	_stacks.push_back(_stack2);
	_stacks.push_back(_stack3);
	_stacks.push_back(_stack4);
	_stacks.push_back(_stack5);
	_stacks.push_back(_stack6);
	_stacks.push_back(_stack7);
	_stacks.push_back(_stack8);
	_stacks.push_back(_stack9);
}