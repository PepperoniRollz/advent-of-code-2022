#pragma once
#include <fstream>
#include<iostream>
#include<vector>

struct Directory {
	Directory(std::string directoryName, Directory* parent) : _directoryName(directoryName), _parent(parent), _size(0) {}
	std::vector<Directory*> _subdirectories;
	Directory* _parent;
	size_t _size;
	std::string _directoryName;
};

class Day07 {
public:
	Day07(std::string);
	void partOneSolution();
	void partTwoSolution();

private:
	std::string _filename;
	size_t adjustDirectorySizes(Directory*);
	void printDirectories(Directory*);
	int sumDirectories(Directory*, int&);
	int getDeletedDirectorySize(Directory* cwd, size_t size, size_t& smallest);
	Directory* buildDirectory();
};