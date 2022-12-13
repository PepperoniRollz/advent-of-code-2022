#include "Day12.h"

Day12::Day12(std::string filename) : _filename(filename) {
}
int dist[150][150] = { 0 };
std::tuple<int, int> end;

void Day12::partOneSolution() {
	inFile.open(_filename);
	while (std::getline(inFile, line)) {
		std::vector<char> row;
		for (char c : line) {
			row.push_back(c);
		}
		map.push_back(row);
	}
	std::tuple<int, int> start;
	std::tuple<int, int> end;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'S') {
				start = std::make_tuple(i, j);
				map[i][j] = 'a';
			}
			else if (map[i][j] == 'E') {
				end = std::make_tuple(i, j);
				map[i][j] = 'z';
			}
		}
	}

	const int ROWS = map.size();
	const int COLS = map[0].size();
	std::deque<std::tuple<int, int>> q;
	std::set<std::tuple<int, int>> visited;
	q.push_back(start);
	visited.insert(start);
	int distance;

	while (!q.empty()) {
		std::tuple<int, int> cur = q.front();
		q.pop_front();
		int asd = q.size();
		auto [x, y] = cur;
		if (cur == end) {
			distance = dist[x][y];  break;
		}
		addChildren(map, cur, std::make_tuple(x - 1, y), ROWS, COLS, q, visited);
		addChildren(map, cur, std::make_tuple(x, y + 1), ROWS, COLS, q, visited);
		addChildren(map, cur, std::make_tuple(x + 1, y), ROWS, COLS, q, visited);
		addChildren(map, cur, std::make_tuple(x, y - 1), ROWS, COLS, q, visited);
	}

	std::cout << "Day 11-1: " << distance << std::endl;
}

void Day12::partTwoSolution() {
	std::cout << "Day 11-2: " << std::endl;
}

void Day12::addChildren(std::vector<std::vector<char>>& map,
	std::tuple<int, int> cur,
	std::tuple<int, int> nextNode,
	int ROWS,
	int COLS,
	std::deque <std::tuple<int, int>>& q,
	std::set<std::tuple<int, int>>& visited) {
	auto [i, j] = cur;
	auto [x, y] = nextNode;

	//std::cout << "current: " << i << "," << j << " x:" << x << " y : " << y << std::endl;

	if (x < 0 || x == ROWS || y < 0 || y == COLS || visited.count(nextNode) || map[x][y] > map[i][j] + 1) {
		return;
	}

	dist[x][y] = dist[i][j] + 1;
	visited.insert(nextNode);
	q.push_back(nextNode);
}