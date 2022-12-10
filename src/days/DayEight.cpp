#include "DayEight.h"
#include <vector>
#include <iostream>
#include <string>

DayEight::DayEight(std::string filename) : _filename(filename) {}

void DayEight::partOneSolution() {
	int numVisible = 0;
	std::vector<std::vector<Tree*>> forest = readInput();

	const int HEIGHT = forest.size();
	const int WIDTH = forest[0].size();

	//look right
	for (int i = 1; i < HEIGHT - 1; i++) {
		int edge = forest[i][0]->_height;
		int max = edge;
		for (int j = 1; j < WIDTH - 1; j++) {
			Tree* tree = forest[i][j];
			checkVisibility(tree, max, numVisible);
		}
	}
	//look left
	for (int i = 1; i < HEIGHT - 1; i++) {
		int edge = forest[i][WIDTH - 1]->_height;
		int max = edge;
		for (int j = WIDTH - 2; j > 0; j--) {
			Tree* tree = forest[i][j];
			checkVisibility(tree, max, numVisible);
		}
	}

	//look down
	for (int i = 1; i < WIDTH - 1; i++) {
		int edge = forest[0][i]->_height;
		int max = edge;
		for (int j = 1; j < HEIGHT - 1; j++) {
			Tree* tree = forest[j][i];
			checkVisibility(tree, max, numVisible);
		}
	}

	////look up
	for (int i = 1; i < WIDTH - 1; i++) {
		int edge = forest[HEIGHT - 1][i]->_height;

		int max = edge;
		for (int j = HEIGHT - 2; j > 0; j--) {
			Tree* tree = forest[j][i];
			checkVisibility(tree, max, numVisible);
		}
	}

	numVisible += 2 * (HEIGHT + WIDTH) - 4;
	std::cout << "Day 8-1: " << numVisible << std::endl;
}

void DayEight::partTwoSolution() {
	std::vector<std::vector<Tree*>> forest = readInput();

	const int HEIGHT = forest.size();
	const int WIDTH = forest[0].size();
	int maxScenicScore = INT_MIN;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			//look up
			Tree* currentTree = forest[i][j];
			int x = i;
			int y = j;
			int upVisible = 0;
			while (x > 0) {
				upVisible++;
				if (forest[x - 1][y]->_height >= currentTree->_height)
					break;
				x--;
			}

			//look down
			x = i;
			y = j;
			int downVisible = 0;
			while (x < HEIGHT - 1) {
				downVisible++;
				if (forest[x + 1][y]->_height >= currentTree->_height)
					break;
				x++;
			}

			//look left
			x = i;
			y = j;
			int leftVisible = 0;
			while (y > 0) {
				leftVisible++;
				if (forest[x][y - 1]->_height >= currentTree->_height)
					break;
				y--;
			}

			//look right
			x = i;
			y = j;
			int rightVisible = 0;
			while (y < WIDTH - 1) {
				rightVisible++;
				if (forest[x][y + 1]->_height >= currentTree->_height)
					break;
				y++;
			}

			int score = scenicScore(upVisible, downVisible, leftVisible, rightVisible);
			maxScenicScore = score > maxScenicScore ? score : maxScenicScore;
		}
	}

	std::cout << "Day 8-2: " << maxScenicScore << std::endl;
}

void DayEight::checkVisibility(Tree* tree, int& max, int& numVisible) {
	if (tree->_height > max) {
		max = tree->_height;
		if (!tree->_visible) {
			tree->_visible = true;
			numVisible++;
		}
	}
}
int DayEight::scenicScore(int up, int down, int left, int right) { return up * down * left * right; }

std::vector<std::vector<Tree*>> DayEight::readInput() {
	std::vector<std::vector<Tree*>> forest;
	std::ifstream inFile;
	std::string line;
	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		std::vector<Tree*> trees;
		for (char c : line) {
			trees.push_back(new Tree(c - '0', false));
		}
		forest.push_back(trees);
	}
	return forest;
}