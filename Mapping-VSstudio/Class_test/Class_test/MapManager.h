#pragma once

#include <iostream>
#include <vector>

const int MAP_SIZE = 11;

using namespace std;

class MapManager {
private:
	vector<vector<vector<int>>> maps;
public:
	MapManager(int num_maps);

	void print_map(int index);
};

