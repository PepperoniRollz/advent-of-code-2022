#include "RopeSimulator.h"
#include "Day09.h"
#include<unordered_set>
RopeSimulator::RopeSimulator(int ropeSize) {
	for (int i = 0; i < ropeSize; i++) this->rope.push_back(new Knot(0, 0));
}

bool RopeSimulator::isAdjacent(Knot* a, Knot* b) {
	return (abs(a->position.x - b->position.x) <= 1 && abs(a->position.y - b->position.y) <= 1);
};
Direction RopeSimulator::directionForTail(Knot* a, Knot* b) {
	int dx = a->position.x - b->position.x;
	int dy = a->position.y - b->position.y;

	if ((dx >= 2 && dy > 0) || (dx == 1 && dy == 2)) return Direction::TOPRIGHT;
	if ((dx <= -2 && dy > 0) || (dx == -1 && dy == 2)) return Direction::TOPLEFT;
	if ((dx <= -2 && dy < 0) || (dx == -1 && dy == -2)) return Direction::BOTTOMLEFT;
	if ((dx >= 2 && dy < 0) || (dx == 1 && dy == -2)) return Direction::BOTTOMRIGHT;
	if (dx == 2) return Direction::RIGHT;
	if (dy == 2) return Direction::UP;
	if (dx == -2) return Direction::LEFT;
	return Direction::DOWN;
}

void RopeSimulator::moveKnot(Direction d, Knot* k) {
	switch (d) {
	case Direction::UP: k->position.y++;
		break;
	case Direction::DOWN: k->position.y--;
		break;
	case Direction::LEFT: k->position.x--;
		break;
	case Direction::RIGHT:k->position.x++;
		break;
	case Direction::TOPLEFT: k->position.y++; k->position.x--;
		break;
	case Direction::TOPRIGHT: k->position.y++; k->position.x++;
		break;
	case Direction::BOTTOMLEFT: k->position.y--; k->position.x--;
		break;
	case Direction::BOTTOMRIGHT:k->position.x++; k->position.y--;
		break;
	};
};

void RopeSimulator::start(Direction direction, int spaces) {
	for (int i = 0; i < spaces; i++) {
		moveKnot(direction, this->rope[0]);
		for (int j = 1; j < rope.size(); j++) {
			if (!isAdjacent(rope[j - 1], rope[j])) {
				moveKnot(directionForTail(rope[j - 1], rope[j]), rope[j]);
				if (j == rope.size() - 1)
					visited.insert(rope[j]->position);
			}
		}
	}
}