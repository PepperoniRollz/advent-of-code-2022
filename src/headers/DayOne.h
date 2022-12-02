#pragma once
#include <fstream>
#include <string>
#include<iostream>
class DayOne {
public:
	DayOne(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
};
