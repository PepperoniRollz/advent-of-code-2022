#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <set>

class Day12 {
public:
	Day12(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	std::string line;
	std::ifstream inFile;
	std::vector<std::vector<char>> map;
	void addChildren(std::vector<std::vector<char>>& map,
		std::tuple<int, int> cur,
		std::tuple<int, int> nextNode,
		int ROWS,
		int COLS,
		std::deque <std::tuple<int, int>>& q,
		std::set<std::tuple<int, int>>& visited);
};