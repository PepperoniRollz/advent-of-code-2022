#pragma once
#include <fstream>
#include<iostream>
class Day06 {
public:
	Day06(std::string);
	void partOneSolution();
	void partTwoSolution();
	void anotherOne();

private:
	std::string _filename;
	int getMarker(const std::string&, int);
	std::string _line;
};