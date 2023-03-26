#include <iostream>
#include "MapManager.h"

using namespace std;


//create map
Map_Editor::Map_Editor(int num_maps) {
	maps.resize(num_maps, vector < vector<int>>(MAP_SIZE, vector<int>(MAP_SIZE, 0)));
}

//Print NumMap
void Map_Editor::print_NumMap(int index, int num_maps) {
	if (index >= 0 && index <= num_maps) {
		cout << "Map " << index << ":" << endl;
		for (int i = 0; i < MAP_SIZE; ++i) {
			for (int j = 0; j < MAP_SIZE; ++j) {
				cout << maps[index][i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	else {
		std::cout << "Invalid index." << std::endl;
	}
}

//return NumMap_date
int Map_Editor::NumMap_data(int index, int row, int col) {
	return maps[index][row][col];
}

//Write date in NumMap
void Map_Editor::NumMap_write(int index, int row, int col, int obj) {
	maps[index][row][col] = obj;
}


//int map_list(int index, int i, int j) {
//	return (*maps[index])[i][j];
//}

//void map_write(int index, int i, int j, int obj) {
//	(*maps[index])[i][j] = obj;
//}