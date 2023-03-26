#include <iostream>
#include "MapManager.h"

//const int SIZE = 11;

//int map_data(int index, int posX, int posY) {
//	int outdata = map_list(index, posX, posY);
//
//	return outdata;
//}

void move_cursor(int row, int col) {
	std::cout << "\033[" << row << ";" << col << "H";
}


void read_map(Map_Editor& mapManager, int map_num, int posX, int posY, int pre_posX, int pre_posY) {
	
	int  index = map_num;

	//test field - make_wall
	for (int i = 0; i < MAP_SIZE; i++) {
		mapManager.NumMap_write(index, 0, i, 3);
		mapManager.NumMap_write(index, MAP_SIZE - 1, i, 3);
		/*map1[0][i] = 3;
		map1[SIZE - 1][i] = 3;*/
	}
	for (int i = 1; i < MAP_SIZE - 1; i++) {
		mapManager.NumMap_write(index, i, 0, 3);
		mapManager.NumMap_write(index, i, MAP_SIZE - 1, 3);
		/*map1[i][0] = 3;
		map1[i][SIZE - 1] = 3;*/
	}

	//display my position
	if (map_num == 0) {
		if (pre_posX != 404 && pre_posY != 404) {
			mapManager.NumMap_write(index, pre_posX, pre_posY, 0);
		}
		mapManager.NumMap_write(index, posX, posY, 1);
		move_cursor(1, 1);
	}
	else if (map_num == 1) {
		mapManager.NumMap_write(index, posX, posY, 1);
		mapManager.NumMap_write(index, pre_posX, pre_posY, 0);

	}

	mapManager.print_NumMap(index, map_num);

	
}

