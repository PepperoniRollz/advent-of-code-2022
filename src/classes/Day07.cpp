#include "Day07.h"
#include <vector>
#include <sstream>
#include <string>

Day07::Day07(std::string filename) {
	_filename = filename;
}

void Day07::partOneSolution() {
	Directory* homeDirectory = buildDirectory();
	adjustDirectorySizes(homeDirectory);
	int sum = 0;
	std::cout << "Day 7-1: " << sumDirectories(homeDirectory, sum) << std::endl;
}

void Day07::partTwoSolution() {
	Directory* homeDirectory = buildDirectory();
	adjustDirectorySizes(homeDirectory);

	int size = 30000000 - (70000000 - homeDirectory->_size);
	size_t smallest = SIZE_MAX;
	smallest = getDeletedDirectorySize(homeDirectory, size, smallest);
	std::cout << "day 7-2: " << smallest << std::endl;
}

size_t Day07::adjustDirectorySizes(Directory* cwd) {
	for (Directory* sub : cwd->_subdirectories) {
		cwd->_size += adjustDirectorySizes(sub);
	}
	return cwd->_size;
}

void Day07::printDirectories(Directory* cwd) {
	std::cout << "- " << cwd->_directoryName << " with size: " << cwd->_size << " with parent: ";
	if (cwd->_parent != nullptr) {
		std::cout << cwd->_parent->_directoryName;
	}
	else std::cout << "NO PARENT";
	std::cout << std::endl;

	for (Directory* sub : cwd->_subdirectories) {
		std::cout << "- ";
		printDirectories(sub);
	}
}

int Day07::sumDirectories(Directory* cwd, int& sum) {
	for (Directory* sub : cwd->_subdirectories) {
		sum += sumDirectories(sub, sum);
	}
	if (cwd->_size <= 100000) {
		return cwd->_size;
	}
	else if (cwd->_directoryName == "/") {
		return sum;
	}
	else return 0;
}

int Day07::getDeletedDirectorySize(Directory* cwd, size_t size, size_t& smallest) {
	for (Directory* sub : cwd->_subdirectories) {
		getDeletedDirectorySize(sub, size, smallest);
	}

	if (cwd->_size >= size && cwd->_size < smallest) {
		smallest = cwd->_size;
	}
	return smallest;
}

Directory* Day07::buildDirectory() {
	std::ifstream inFile;
	std::string line;
	Directory* homeDirectory = new Directory("/", nullptr);
	Directory* cwd = homeDirectory;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}
		if (tokens[0] == "dir") {
			Directory* child = new Directory(tokens[1], cwd);
			cwd->_subdirectories.push_back(child);
		}
		else if (tokens[0] == "$") {
			if (tokens[1] == "cd" && tokens[2] == "..") {
				cwd = cwd->_parent;
			}
			else if (tokens[1] == "cd" && tokens[2] == "/") {
				cwd = homeDirectory;
			}
			else if (tokens[1] == "ls") {
				continue;
			}
			else {
				for (Directory* sub : cwd->_subdirectories) {
					if (sub->_directoryName == tokens[2]) {
						cwd = sub;
					}
				}
			}
		}
		else if (isdigit(tokens[0][0])) {
			cwd->_size += stoi(tokens[0]);
		}
	}
	return homeDirectory;
}