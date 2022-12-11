// advent-of-code-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DayOne.h"
#include "DayTwo.h"
#include "DayThree.h"
#include "DayFour.h"
#include "DayFive.h"
#include "DaySix.h"
#include "DaySeven.h"
#include "DayEight.h"
#include "DayNine.h"
#include <chrono>
void printTime(std::chrono::steady_clock::time_point, std::chrono::steady_clock::time_point);
std::chrono::steady_clock::time_point start, end;

int main() {
	std::cout << "--- Day 1: Calorie Counting ---" << std::endl;
	DayOne d1("./src/data/day-1.txt");
	start = std::chrono::high_resolution_clock::now();	d1.partOneSolution();
	d1.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 2: Rock Paper Scissors ---" << std::endl;
	DayTwo d2("./src/data/day-2.txt");
	start = std::chrono::high_resolution_clock::now();	d2.partOneSolution();
	d2.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 3: Rucksack Reorganization ---" << std::endl;
	DayThree d3("./src/data/day-3.txt");
	start = std::chrono::high_resolution_clock::now();
	d3.partOneSolution();
	d3.partTwoSolution();

	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);
	std::cout << "--- Day 4: Camp Cleanup ---" << std::endl;
	DayFour d4("./src/data/day-4.txt");
	start = std::chrono::high_resolution_clock::now();
	d4.partOneSolution();
	d4.partTwoSolution();

	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 5: Supply Stacks ---" << std::endl;
	DayFive d5("./src/data/day-5.txt");
	start = std::chrono::high_resolution_clock::now();
	d5.partOneSolution();
	d5.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 6: Tuning Trouble ---" << std::endl;
	DaySix d6("./src/data/day-6.txt");
	start = std::chrono::high_resolution_clock::now();
	d6.partTwoSolution();
	d6.partOneSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 7: No Space Left On Device ---" << std::endl;
	DaySeven d7("./src/data/day-7.txt");
	start = std::chrono::high_resolution_clock::now();
	d7.partOneSolution();
	d7.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 8: Treetop Tree House ---" << std::endl;
	DayEight d8("./src/data/day-8.txt");
	start = std::chrono::high_resolution_clock::now();
	d8.partOneSolution();
	d8.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 9: Rope Bridge ---" << std::endl;
	DayNine d9("./src/data/day-9.txt");
	start = std::chrono::high_resolution_clock::now();
	d9.partOneSolution();
	d9.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);
};

void printTime(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end) {
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "elapsed time: "
		<< duration.count() << "ms" << std::endl;
}