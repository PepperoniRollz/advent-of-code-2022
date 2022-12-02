// advent-of-code-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DayOne.h"
#include "DayTwo.h"
namespace fs = std::filesystem;

int main() {
	DayOne d1("./src/data/day-one-part-one-data.txt");

	d1.partOneSolution();
	d1.partTwoSolution();

	//DayTwo d2(".\\data\\day-two-part-one-data.txt");
}