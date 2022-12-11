#pragma once
#include <fstream>
#include <string>
#include<iostream>

enum class Direction {
	UP, LEFT, DOWN, RIGHT, TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT
};
struct Position {
	int x;
	int y;
	Position(int x, int y) : x(x), y(y) {};
	friend bool operator==(const Position& lhs, const Position& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }

	struct HashFunction
	{
		size_t operator()(const Position& position) const
		{
			size_t xHash = std::hash<int>()(position.x);
			size_t yHash = std::hash<int>()(position.y) << 1;
			return xHash ^ yHash;
		}
	};
};

struct Knot {
	Position position;
	Knot(int x, int y) : position(Position(x, y)) {}
};
class Day09
{
public:
	Day09(std::string);
	void partOneSolution();
	void partTwoSolution();
private:
	std::string _filename;
	Direction charToEnum(char c);
};
