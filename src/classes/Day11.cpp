#include "Day11.h"
#include <cmath>
#include <unordered_set>

Day11::Day11(std::string filename) : _filename(filename) {
}

void Day11::partOneSolution() {
	std::vector<Monkey*> monkeys = parseInput();

	for (int round = 0; round < 20; round++) {
		for (int i = 0; i < monkeys.size(); i++) {
			Monkey* currentMonkey = monkeys[i];
			while (!currentMonkey->items.empty()) {
				unsigned long long  currentItem = currentMonkey->items.front();
				int operand;

				if (currentMonkey->operand == "old") {
					operand = currentItem;
				}
				else {
					operand = stoi(currentMonkey->operand);
				}

				switch ((char)currentMonkey->operation) {
				case '*':
					currentItem *= operand;
					break;
				case'+':
					currentItem += operand;
					break;
				}

				currentItem /= 3;

				if (currentItem % currentMonkey->test == 0) {
					monkeys[currentMonkey->ifTrue]->items.push_back(currentItem);
				}
				else {
					monkeys[currentMonkey->ifFalse]->items.push_back(currentItem);
				}
				currentMonkey->items.pop_front();
				currentMonkey->numInspected++;
			}
		}
	}
	int max = 0;
	int second = 0;
	for (Monkey* m : monkeys) {
		if (m->numInspected > max) { second = max;  max = m->numInspected; }
		else if (m->numInspected < max && m->numInspected > second) second = m->numInspected;
	}

	std::cout << "Day 11-1: " << max << "*" << second << "=" << max * second << std::endl;
}

void Day11::partTwoSolution() {
	std::vector<Monkey*> monkeys = parseInput();
	const unsigned long long MODULUS = getModulus(monkeys);

	for (int round = 0; round < 10000; round++) {
		for (int i = 0; i < monkeys.size(); i++) {
			Monkey* currentMonkey = monkeys[i];
			while (!currentMonkey->items.empty()) {
				unsigned long long  currentItem = currentMonkey->items.front();
				unsigned long long  operand;

				if (currentMonkey->operand == "old") {
					operand = currentItem;
				}
				else {
					operand = stoi(currentMonkey->operand);
				}

				switch ((char)currentMonkey->operation) {
				case '*':
					currentItem = (currentItem * operand) % MODULUS;

					break;
				case'+':
					currentItem = (currentItem + operand) % MODULUS;
					break;
				}
				if (currentItem % currentMonkey->test == 0) {
					monkeys[currentMonkey->ifTrue]->items.push_back(currentItem);
				}
				else {
					monkeys[currentMonkey->ifFalse]->items.push_back(currentItem);
				}

				currentMonkey->items.pop_front();
				currentMonkey->numInspected++;
			}
		}
	}
	unsigned long long max = 0;
	unsigned long long second = 0;
	for (Monkey* m : monkeys) {
		if (m->numInspected > max) { second = max;  max = m->numInspected; }
		else if (m->numInspected < max && m->numInspected > second) second = m->numInspected;
	}
	std::cout << "Day 11-2: " << max << "*" << second << "=" << max * second << std::endl;
}

std::vector<Monkey*> Day11::parseInput() {
	std::vector<Monkey*> monkeys;
	int monkeyIndex = -1;
	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			if (!intermediate.empty())
				tokens.push_back(intermediate);
		}
		if (tokens.empty() || tokens[0] == "Monkey")
			continue;
		else if (tokens[0] == "Starting") {
			monkeys.push_back(new Monkey());
			monkeyIndex++;
			for (int i = 2; i < tokens.size(); i++) {
				int item = tokens[i].find(',') != -1 ? stoi(tokens[i].substr(0, tokens[i].size() - 1)) : stoi(tokens[i]);
				monkeys[monkeyIndex]->items.push_back(item);
			}
		}
		else if (tokens[0] == "Operation:") {
			monkeys[monkeyIndex]->operation = tokens[tokens.size() - 2][0];
			monkeys[monkeyIndex]->operand = tokens[tokens.size() - 1];
		}
		else if (tokens[0] == "Test:") {
			monkeys[monkeyIndex]->test = stoi(tokens[tokens.size() - 1]);
		}
		else if (tokens[1] == "true:") {
			monkeys[monkeyIndex]->ifTrue = stoi(tokens[tokens.size() - 1]);
		}
		else if (tokens[1] == "false:") {
			monkeys[monkeyIndex]->ifFalse = stoi(tokens[tokens.size() - 1]);
		}
	}
	inFile.close();
	return monkeys;
}
unsigned long long Day11::getModulus(std::vector<Monkey*> monkeys) {
	unsigned long long modulus = 0;
	for (Monkey* m : monkeys) {
		modulus += m->test;
	}
	return modulus;
}