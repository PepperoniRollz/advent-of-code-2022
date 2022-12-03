// advent-of-code-2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DayOne.h"
#include "DayTwo.h"

int main() {
	DayOne d1("./src/data/day-one-part-one.txt");

	d1.partOneSolution();
	d1.partTwoSolution();

	DayTwo d2("./src/data/day-two-part-one.txt");
	d2.partOneSolution();
	d2.partTwoSolution();
}