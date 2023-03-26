#pragma once

#include <iostream>
#include <vector>

using namespace std;

const int MAP_SIZE = 11;

class Map_Editor {
private:
	vector<vector<vector<int>>> maps;

public:
	Map_Editor(int num_maps);

	void print_NumMap(int index, int num_maps);

	int NumMap_data(int index, int row, int col);

	void NumMap_write(int index, int row, int col, int obj);
};



void read_map(Map_Editor& mapManager, int map_num, int posx, int posy, int old_posx, int old_posy);


