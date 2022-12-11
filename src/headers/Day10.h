#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Day10
{
public:
	Day10(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	void print(std::vector<std::vector<char>>);
	const std::string NOOP = "noop";
	const std::string ADD_X = "addx";
	std::ifstream inFile;
	std::string line;
	const int ROWS = 6;
	const int COLUMNS = 40;
};
