// advent-of-code-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DayOne.h"
#include "DayTwo.h"
#include "DayThree.h"
#include "DayFour.h"

int main() {
	std::cout << "--- Day 1: Calorie Counting ---" << std::endl;
	DayOne d1("./src/data/day-1.txt");
	d1.partOneSolution();
	d1.partTwoSolution();

	std::cout << "--- Day 2: Rock Paper Scissors ---" << std::endl;
	DayTwo d2("./src/data/day-2.txt");
	d2.partOneSolution();
	d2.partTwoSolution();

	std::cout << "--- Day 3: Rucksack Reorganization ---" << std::endl;
	DayThree d3("./src/data/day-3.txt");
	d3.partOneSolution();
	d3.partTwoSolution();

	std::cout << "--- Day 4: Camp Cleanup ---" << std::endl;
	DayFour d4("./src/data/day-4.txt");
	d4.partOneSolution();
	d4.partTwoSolution();
}