#include "DaySeven.h"
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

DaySeven::DaySeven(std::string filename) {
	_filename = filename;
}

void DaySeven::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	Directory* homeDirectory = new Directory("/", 0);
	Directory* cwd = homeDirectory;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::stringstream check1(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(check1, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}

		/*for (std::string tok : tokens)
			std::cout << tok << " ";
		std::cout << std::endl;*/

		if (tokens[0] == "dir") {
			Directory* child = new Directory(tokens[1], cwd);
			cwd->subdirectories.push_back(child);
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
				for (Directory* sub : cwd->subdirectories) {
					if (sub->_directoryName == tokens[2]) {
						cwd = sub;
					}
				}
			}
		}
		else if (isdigit(tokens[0][0])) {
			cwd->_size += stoi(tokens[0]);
			//std::cout << "direcoty : " << cwd->_directoryName << "  bytes: " << cwd->_size << std::endl;
		}
	}

	getSizes(homeDirectory);
	drawDirectories(homeDirectory);
	int sum = 0;
	std::cout << "Day 7-1: " << sumDirectories(homeDirectory, sum) << std::endl;
}

void DaySeven::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	Directory* homeDirectory = new Directory("/", 0);
	Directory* cwd = homeDirectory;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::stringstream check1(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(check1, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}

		/*for (std::string tok : tokens)
			std::cout << tok << " ";
		std::cout << std::endl;*/

		if (tokens[0] == "dir") {
			Directory* child = new Directory(tokens[1], cwd);
			cwd->subdirectories.push_back(child);
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
				for (Directory* sub : cwd->subdirectories) {
					if (sub->_directoryName == tokens[2]) {
						cwd = sub;
					}
				}
			}
		}
		else if (isdigit(tokens[0][0])) {
			cwd->_size += stoi(tokens[0]);
			//std::cout << "direcoty : " << cwd->_directoryName << "  bytes: " << cwd->_size << std::endl;
		}
	}

	getSizes(homeDirectory);

	int size = 30000000 - (70000000 - homeDirectory->_size);
	size_t smallest = SIZE_MAX;
	smallest = getDeletedDirectorySize(homeDirectory, size, smallest);
	std::cout << "day 7 - 2: " << smallest;
}

size_t DaySeven::getSizes(Directory* cwd) {
	//std::cout << cwd->_directoryName << " before size: " << cwd->_size << std::endl;

	for (Directory* sub : cwd->subdirectories) {
		cwd->_size += getSizes(sub);
	}
	return cwd->_size;
}

void DaySeven::drawDirectories(Directory* cwd) {
	std::cout << "- " << cwd->_directoryName << " with size: " << cwd->_size << " with parent: ";
	if (cwd->_parent != nullptr) {
		std::cout << cwd->_parent->_directoryName;
	}
	else std::cout << "NO PARENT";
	std::cout << std::endl;

	for (Directory* sub : cwd->subdirectories) {
		std::cout << "- ";
		drawDirectories(sub);
	}
}

int DaySeven::sumDirectories(Directory* cwd, int& sum) {
	for (Directory* sub : cwd->subdirectories) {
		sum += sumDirectories(sub, sum);
	}
	//std::cout << "dir: " << cwd->_directoryName << " with size: " << cwd->_size << " with sum : " << sum << std::endl;

	if (cwd->_size <= 100000) {
		return cwd->_size;
	}
	else if (cwd->_directoryName == "/") {
		return sum;
	}
	else return 0;
}

int DaySeven::getDeletedDirectorySize(Directory* cwd, size_t size, size_t& smallest) {
	for (Directory* sub : cwd->subdirectories) {
		getDeletedDirectorySize(sub, size, smallest);
	}

	if (cwd->_size >= size && cwd->_size < smallest) {
		smallest = cwd->_size;
	}
	return smallest;
}