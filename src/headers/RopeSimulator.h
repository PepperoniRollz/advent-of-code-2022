#pragma once
#include "Day09.h"
#include<vector>
#include<unordered_set>

class RopeSimulator
{
public:
	RopeSimulator(int ropeSize);
	std::unordered_set<Position, Position::HashFunction> visited;
	std::vector<Knot*> rope;
	void start(Direction direction, int spaces);

private:
	void moveKnot(Direction d, Knot* b);
	Direction directionForTail(Knot* a, Knot* b);
	bool isAdjacent(Knot*, Knot*);
};
