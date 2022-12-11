#pragma once
#pragma once
#include <fstream>
#include <string>
#include<iostream>
#include<vector>
#include<fstream>

struct Tree {
	Tree(int height, bool visible) : _height(height), _visible(visible) {}
	bool _visible;
	int _height;
};

class Day08 {
public:
	Day08(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	void checkVisibility(Tree*, int&, int&);
	int scenicScore(int, int, int, int);
	std::vector<std::vector<Tree*>> readInput();
};