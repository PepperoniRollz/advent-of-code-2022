#pragma once
#include <fstream>
#include <string>
#include<iostream>
class Day03 {
public:
	Day03(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	int charToPriority(char c);
};
