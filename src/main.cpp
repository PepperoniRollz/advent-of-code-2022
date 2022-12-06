// advent-of-code-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DayOne.h"
#include "DayTwo.h"
#include "DayThree.h"
#include "DayFour.h"
#include "DayFive.h"
#include "DaySix.h"

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

	std::cout << "--- Day 5: Supply Stacks ---" << std::endl;
	DayFive d5("./src/data/day-5.txt");
	d5.partOneSolution();
	d5.partTwoSolution();

	std::cout << "--- Day 6: Tuning Trouble ---" << std::endl;
	DaySix d6("./src/data/day-6.txt");
	d6.partOneSolution();
	d6.partTwoSolution();
}