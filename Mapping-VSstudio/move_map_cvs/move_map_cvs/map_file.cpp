#include <iostream>
#include "mapping.h"

//const int SIZE = 11;

int map_data(int index, int posX, int posY) {
	int outdata = map_list(index, posX, posY);

	return outdata;
}

void move_cursor(int row, int col) {
	std::cout << "\033[" << row << ";" << col << "H";
}

void print_map(int index) {
	if (index >= 0 && index <= 2) {
		std::cout << "Map " << index << ":" << std::endl;
		for (int i = 0; i < MAP_SIZE; ++i) {
			for (int j = 0; j < MAP_SIZE; ++j) {
				std::cout << map_list(index, i, j) << " ";
			}
			std::cout << std::endl;
		}
	}

	else {
		std::cout << "Invalid index." << std::endl;
	}
}

void read_map(int map_num, int posX, int posY, int pre_posX, int pre_posY) {
	
	int  index = map_num;

	//test field - make_wall
	for (int i = 0; i < MAP_SIZE; i++) {
		map_write(index, 0, i, 3);
		map_write(index, MAP_SIZE - 1, i, 3);
		/*map1[0][i] = 3;
		map1[SIZE - 1][i] = 3;*/
	}
	for (int i = 1; i < MAP_SIZE - 1; i++) {
		map_write(index, i, 0, 3);
		map_write(index, i, MAP_SIZE - 1, 3);
		/*map1[i][0] = 3;
		map1[i][SIZE - 1] = 3;*/
	}

	//display my position
	if (map_num == 0) {
		if (pre_posX != 404 && pre_posY != 404) {
			map_write(index, pre_posX, pre_posY, 0);
		}
		map_write(index, posX, posY, 1);
		move_cursor(1, 1);
	}
	else if (map_num == 1) {
		map_write(index, posX, posY, 1);
		map_write(index, pre_posX, pre_posY, 0);

	}

	print_map(index);

	
}

