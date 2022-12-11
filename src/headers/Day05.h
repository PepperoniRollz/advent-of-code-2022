#pragma once
#include <fstream>
#include <string>
#include<iostream>
#include<vector>
class Day05 {
public:
	Day05(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	std::vector<std::vector<char>> _stacks;
	const std::vector<char> _stack1{ 'Q', 'F','M','R','L','W','C', 'V' };
	const std::vector<char> _stack2{ 'D','Q','L' };
	const std::vector<char> _stack3{ 'P', 'S','R','G','W','C','N','B' };
	const std::vector<char> _stack4{ 'L', 'C','D','H','B','Q','G' };
	const std::vector<char> _stack5{ 'V', 'G','L','F','Z','S' };
	const std::vector<char> _stack6{ 'D', 'G','N','P' };
	const std::vector<char> _stack7{ 'D', 'Z','P','V','F','C','W' };
	const std::vector<char> _stack8{ 'C', 'P','D','M','S' };
	const std::vector<char> _stack9{ 'Z', 'N','W','T','V','M','P','C' };
	void resetStacks();
	void initStacks();
};
