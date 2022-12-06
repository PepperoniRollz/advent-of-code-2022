#pragma once
#include <fstream>
#include<iostream>
class DaySix {
public:
	DaySix(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	int getMarker(const std::string&, int);
};