#pragma once
#include <fstream>
#include <string>
#include<iostream>
class DayTwo {
public:
	DayTwo(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	bool tie(int, int);
	bool iWin(int, int);
	enum action { LOSE, DRAW, WIN };
};
