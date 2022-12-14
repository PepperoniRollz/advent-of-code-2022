#include "Day11.h"
#include <cmath>

Day11::Day11(std::string filename) : _filename(filename) {
}

void Day11::partOneSolution() {
	std::vector<Monkey*> monkeys = parseInput();

	for (int round = 0; round < 20; round++) {
		for (int i = 0; i < monkeys.size(); i++) {
			Monkey* currentMonkey = monkeys[i];
			while (!currentMonkey->items.empty()) {
				uint64_t  currentItem = currentMonkey->items.front();

				int operand = currentMonkey->operand == "old" ? currentItem : stoi(currentMonkey->operand);
				currentItem = currentMonkey->operation == '*' ? currentItem * operand / 3 : (currentItem + operand) / 3;

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
	const uint64_t LCM = getLCM(monkeys);

	for (int round = 0; round < 10000; round++) {
		for (int i = 0; i < monkeys.size(); i++) {
			Monkey* currentMonkey = monkeys[i];
			while (!currentMonkey->items.empty()) {
				uint64_t currentItem = currentMonkey->items.front();
				uint64_t operand;

				operand = currentMonkey->operand == "old" ? currentItem : stoi(currentMonkey->operand);
				currentItem = currentMonkey->operation == '*' ? (currentItem * operand) % LCM : (currentItem + operand) % LCM;

				if (currentItem % currentMonkey->test == 0)
					monkeys[currentMonkey->ifTrue]->items.push_back(currentItem);
				else
					monkeys[currentMonkey->ifFalse]->items.push_back(currentItem);

				currentMonkey->items.pop_front();
				currentMonkey->numInspected++;
			}
		}
	}
	uint64_t max = 0;
	uint64_t second = 0;
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
uint64_t Day11::getLCM(std::vector<Monkey*> monkeys) {
	uint64_t lcm = 0;
	for (Monkey* m : monkeys) {
		lcm += m->test;
	}
	return lcm;
}