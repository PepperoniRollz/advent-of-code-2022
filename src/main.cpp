// advent-of-code-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Day01.h"
#include "Day02.h"
#include "Day03.h"
#include "Day04.h"
#include "Day05.h"
#include "Day06.h"
#include "Day07.h"
#include "Day08.h"
#include "Day09.h"
#include "Day10.h"
#include "Day11.h"
#include "Day12.h"

#include <chrono>
void printTime(std::chrono::steady_clock::time_point, std::chrono::steady_clock::time_point);
std::chrono::steady_clock::time_point start, end;

int main() {
	std::cout << "--- Day 1: Calorie Counting ---" << std::endl;
	Day01 d1("./src/data/day-1.txt");
	start = std::chrono::high_resolution_clock::now();	d1.partOneSolution();
	d1.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 2: Rock Paper Scissors ---" << std::endl;
	Day02 d2("./src/data/day-2.txt");
	start = std::chrono::high_resolution_clock::now();	d2.partOneSolution();
	d2.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 3: Rucksack Reorganization ---" << std::endl;
	Day03 d3("./src/data/day-3.txt");
	start = std::chrono::high_resolution_clock::now();
	d3.partOneSolution();
	d3.partTwoSolution();

	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);
	std::cout << "--- Day 4: Camp Cleanup ---" << std::endl;
	Day04 d4("./src/data/day-4.txt");
	start = std::chrono::high_resolution_clock::now();
	d4.partOneSolution();
	d4.partTwoSolution();

	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 5: Supply Stacks ---" << std::endl;
	Day05 d5("./src/data/day-5.txt");
	start = std::chrono::high_resolution_clock::now();
	d5.partOneSolution();
	d5.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 6: Tuning Trouble ---" << std::endl;
	Day06 d6("./src/data/day-6.txt");
	start = std::chrono::high_resolution_clock::now();
	d6.partTwoSolution();
	d6.partOneSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 7: No Space Left On Device ---" << std::endl;
	Day07 d7("./src/data/day-7.txt");
	start = std::chrono::high_resolution_clock::now();
	d7.partOneSolution();
	d7.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 8: Treetop Tree House ---" << std::endl;
	Day08 d8("./src/data/day-8.txt");
	start = std::chrono::high_resolution_clock::now();
	d8.partOneSolution();
	d8.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 9: Rope Bridge ---" << std::endl;
	Day09 d9("./src/data/day-9.txt");
	start = std::chrono::high_resolution_clock::now();
	d9.partOneSolution();
	d9.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 10: Cathode-Ray Tube ---" << std::endl;
	Day10 d10("./src/data/day-10.txt");
	start = std::chrono::high_resolution_clock::now();
	d10.partOneSolution();
	d10.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 11: Monkey in the Middle ---" << std::endl;
	Day11 d11("./src/data/day-11.txt");
	start = std::chrono::high_resolution_clock::now();
	d11.partOneSolution();
	d11.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);

	std::cout << "--- Day 11: Monkey in the Middle ---" << std::endl;
	Day12 d12("./src/data/day-12.txt");
	start = std::chrono::high_resolution_clock::now();
	d12.partOneSolution();
	d12.partTwoSolution();
	end = std::chrono::high_resolution_clock::now();
	printTime(start, end);
};

void printTime(std::chrono::steady_clock::time_point start, std::chrono::steady_clock::time_point end) {
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "elapsed time: "
		<< duration.count() << "ms" << std::endl;
}