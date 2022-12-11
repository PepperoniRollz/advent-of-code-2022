#include "Day10.h"

Day10::Day10(std::string filename) : _filename(filename) {
	inFile.open(_filename, std::ios_base::in);
}

void Day10::partOneSolution() {
	int cycle = 1;
	int X = 1;
	int sum = 0;

	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}

		if (tokens[0] == ADD_X) {
			uint8_t waitPeriod = 0;
			while (waitPeriod < 2) {
				if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
					sum += cycle * X;
				waitPeriod++;
				cycle++;
			}
			X += stoi(tokens[1]);
		}
		else {
			if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220) {
				sum += cycle * X;
			}
			cycle++;
		}
	}
	inFile.close();
	std::cout << "Day 10-1: " << sum << std::endl;
}

void Day10::partTwoSolution() {
	int cycle = 1;
	int X = 1;
	int row = 0;
	int position = (cycle - 1) % 40;
	std::vector<std::vector<char> > monitor(ROWS, std::vector<char>(COLUMNS));

	inFile.open(_filename, std::ios_base::in);

	while (std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string intermediate;
		std::vector<std::string> tokens;

		while (std::getline(ss, intermediate, ' ')) {
			tokens.push_back(intermediate);
		}

		if (tokens[0] == ADD_X) {
			uint8_t waitPeriod = 0;
			while (waitPeriod < 2) {
				if (position + 1 == X || position - 1 == X || position == X)
					monitor[row][position] = '#';
				else monitor[row][position] = ' ';

				position = (position + 1) % 40;
				if (position % 40 == 0)
					row++;
				waitPeriod++;
				cycle++;
			}
			X += stoi(tokens[1]);
		}
		else {
			if (position + 1 == X || position - 1 == X || position == X)
				monitor[row][position] = '#';
			else monitor[row][position] = ' ';
			position = (position + 1) % 40;
			if (position % 40 == 0)
				row++;
			cycle++;
		}
	}

	std::cout << "Day 10-2: ";
	print(monitor);
	std::cout << std::endl;
}

void Day10::print(std::vector<std::vector<char>> monitor) {
	std::cout << std::endl;
	for (int i = 0; i < monitor.size(); i++) {
		for (int j = 0; j < monitor[i].size(); j++) {
			std::cout << monitor[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}