#include "Day12.h"
#include <algorithm>

Day12::Day12(std::string filename) : _filename(filename) {
}
std::tuple<int, int> end;

void Day12::partOneSolution() {
	std::vector<std::vector<char>> map;
	std::deque<std::tuple<int, int>> q;
	std::set<std::tuple<int, int>> visited;
	std::vector<std::tuple<int, int>> startingPositions;
	std::tuple<int, int> start;
	std::tuple<int, int> end;

	inFile.open(_filename);
	while (std::getline(inFile, line)) {
		std::vector<char> row;
		for (char c : line) {
			row.push_back(c);
		}
		map.push_back(row);
	}
	const int ROWS = map.size();
	const int COLS = map[0].size();

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

	q.push_back(start);
	visited.insert(start);
	int distance;
	std::vector<std::vector<int> > dist(
		500,
		std::vector<int>(500, 0));
	while (!q.empty()) {
		std::tuple<int, int> cur = q.front();
		q.pop_front();
		int asd = q.size();
		auto [x, y] = cur;
		if (cur == end) {
			distance = dist[x][y];  break;
		}
		addChildren(map, cur, std::make_tuple(x - 1, y), ROWS, COLS, q, visited, dist);
		addChildren(map, cur, std::make_tuple(x, y + 1), ROWS, COLS, q, visited, dist);
		addChildren(map, cur, std::make_tuple(x + 1, y), ROWS, COLS, q, visited, dist);
		addChildren(map, cur, std::make_tuple(x, y - 1), ROWS, COLS, q, visited, dist);
	}

	std::cout << "Day 11-1: " << distance << std::endl;
	inFile.close();
}

void Day12::partTwoSolution() {
	std::vector<std::vector<char>> map;
	std::vector<std::tuple<int, int>> startingPositions;
	std::tuple<int, int> start;
	std::tuple<int, int> end;
	int shortest = INT_MAX;

	inFile.open(_filename);
	while (std::getline(inFile, line)) {
		std::vector<char> row;
		for (char c : line) {
			row.push_back(c);
		}
		map.push_back(row);
	}
	const int ROWS = map.size();
	const int COLS = map[0].size();

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 'S' || map[i][j] == 'a') {
				startingPositions.push_back(std::make_tuple(i, j));
				map[i][j] = 'a';
			}
			if (map[i][j] == 'E') {
				end = std::make_tuple(i, j);
				map[i][j] = 'z';
			}
		}
	}

	for (std::tuple<int, int> startPos : startingPositions) {
		std::deque<std::tuple<int, int>> q;
		std::set<std::tuple<int, int>> visited;
		q.push_back(startPos);
		visited.insert(startPos);
		int shortestPath = INT_MAX;
		std::vector<std::vector<int> > dist(
			ROWS,
			std::vector<int>(COLS, 0));

		while (!q.empty()) {
			std::tuple<int, int> cur = q.front();
			q.pop_front();
			auto [x, y] = cur;

			if (cur == end) {
				shortest = dist[x][y] < shortest ? dist[x][y] : shortest;
				break;
			}

			addChildren(map, cur, std::make_tuple(x - 1, y), ROWS, COLS, q, visited, dist);
			addChildren(map, cur, std::make_tuple(x, y + 1), ROWS, COLS, q, visited, dist);
			addChildren(map, cur, std::make_tuple(x + 1, y), ROWS, COLS, q, visited, dist);
			addChildren(map, cur, std::make_tuple(x, y - 1), ROWS, COLS, q, visited, dist);
		}
	}
	std::cout << "Day 11-2: " << shortest << std::endl;
}

void Day12::addChildren(std::vector<std::vector<char>>& map,
	std::tuple<int, int> cur,
	std::tuple<int, int> nextNode,
	int ROWS,
	int COLS,
	std::deque <std::tuple<int, int>>& q,
	std::set<std::tuple<int, int>>& visited,
	std::vector<std::vector<int>>& dist
) {
	auto [i, j] = cur;
	auto [x, y] = nextNode;

	if (x < 0 || x == ROWS || y < 0 || y == COLS || visited.count(nextNode) || map[x][y] > map[i][j] + 1) {
		return;
	}
	dist[x][y] = dist[i][j] + 1;
	visited.insert(nextNode);
	q.push_back(nextNode);
}