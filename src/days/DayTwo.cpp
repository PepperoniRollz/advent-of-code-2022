#include "DayTwo.h"
#include <vector>

/*Appreciative of your help yesterday, one Elf gives you an encrypted strategy guide (your puzzle input) that they say will be sure to help you win.
"The first column is what your opponent is going to play: A for Rock, B for Paper, and C for Scissors. The second column--"
Suddenly, the Elf is called away to help with someone's tent.

The second column, you reason, must be what you should play in response: X for Rock, Y for Paper, and Z for Scissors.
Winning every time would be suspicious, so the responses must have been carefully chosen.
ASCII for A B C and X Y Z
65, 66, 67
88, 89, 90
rock paper scissors
0, 1, 2
The winner of the whole tournament is the player with the highest score.
Your total score is the sum of your scores for each round. The score for a single round is the score for the shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors)
plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).

Since you can't be sure if the Elf is trying to help you or trick you, you should calculate the score you would get if you were to follow the strategy guide.
*/

/*
The Elf finishes helping with the tent and sneaks back over to you.
"Anyway, the second column says how the round needs to end:
X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win. Good luck!"*/
DayTwo::DayTwo(std::string filename) : _filename(filename) {}

void DayTwo::partOneSolution() {
	std::ifstream inFile;
	std::string line;
	uint32_t opponent;
	uint32_t me;
	uint32_t score = 0;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		opponent = line[0] - 65;
		me = line[2] - 88;
		score += me + 1;

		if (me == opponent) {
			score += 3;
		}
		if (me == (opponent + 1) % 3) {
			score += 6;
		}
	}
	std::cout << "Day 2-1: " << score << std::endl;
}

void DayTwo::partTwoSolution() {
	std::ifstream inFile;
	std::string line;
	int32_t opponent;
	int32_t me;
	int32_t result;
	int32_t score = 0;

	inFile.open(_filename, std::ios_base::in);
	while (std::getline(inFile, line)) {
		opponent = line[0] - 65;
		result = line[2] - 88;

		if (result == 0) {
			me = opponent - 1 >= 0 ? opponent - 1 : 2;
		}
		else if (result == 1) {
			me = opponent;
			score += 3;
		}
		else if (result == 2) {
			me = (opponent + 1) % 3;
			score += 6;
		}
		score += me + 1;
	}
	std::cout << "Day 2-2: " << score << std::endl;
}