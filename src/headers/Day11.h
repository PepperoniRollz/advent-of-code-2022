#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_set>

struct Monkey {
	char operation;
	std::deque<unsigned long long> items;
	std::string operand;
	int test = 0;
	int ifTrue;
	int ifFalse;
	int numInspected = 0;
};

class Day11
{
public:
	Day11(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	std::ifstream inFile;
	std::string line;
	std::vector<Monkey*> parseInput();
	unsigned long long getModulus(std::vector<Monkey*> monkeys);
};
