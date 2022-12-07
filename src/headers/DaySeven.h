#pragma once
#include <fstream>
#include<iostream>
#include<vector>

struct Directory {
	Directory(std::string directoryName, Directory* parent) : _directoryName(directoryName), _parent(parent), _size(0) {}

	std::vector<Directory*> subdirectories;
	Directory* _parent;
	size_t _size;
	std::string _directoryName;
};

class DaySeven {
public:
	DaySeven(std::string);
	void partOneSolution();
	void partTwoSolution();

private:
	std::string _filename;
	size_t adjustDirectorySizes(Directory*);
	void drawDirectories(Directory*);
	int sumDirectories(Directory*, int&);
	int getDeletedDirectorySize(Directory* cwd, size_t size, size_t& smallest);
	Directory* buildDirectory();
};