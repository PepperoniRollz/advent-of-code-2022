#pragma once
#include <fstream>
#include <string>
#include<iostream>
class DayThree {
public:
	DayThree(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	int charToPriority(char c);
};
