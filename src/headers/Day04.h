#pragma once
#include <fstream>
#include <string>
#include<iostream>
#include<vector>

class Day04 {
public:
	Day04(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	bool contains(std::vector<int>);
	bool overlaps(std::vector<int>);
	void tokenizer(std::vector<int>& tokens, std::string line);
};