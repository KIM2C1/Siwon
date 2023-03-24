#include <iostream>

const int SIZE = 11;

int map1[SIZE][SIZE] = { 0 };
int map2[SIZE][SIZE] = { 0 };
int map3[SIZE][SIZE] = { 0 };

int(*maps[3])[SIZE][SIZE] = { &map1, &map2, &map3 };

int map_data(int posX, int posY) {
	int outdata = map1[posX][posY];

	return outdata;
}

void move_cursor(int row, int col) {
	std::cout << "\033[" << row << ";" << col << "H";
}

void print_map(int index) {
	if (index >= 0 && index <= 2) {
		std::cout << "Map " << index << ":" << std::endl;
		for (int i = 0; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				std::cout << (*maps[index])[i][j] << " ";
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
	for (int i = 0; i < SIZE; i++) {
		map1[0][i] = 3;
		map1[SIZE - 1][i] = 3;
	}
	for (int i = 1; i < SIZE - 1; i++) {
		map1[i][0] = 3;
		map1[i][SIZE - 1] = 3;
	}

	//display my position
	if (map_num == 0) {
		if (pre_posX != 404 && pre_posY != 404) {
			map1[pre_posX][pre_posY] = 0;
		}
		map1[posX][posY] = 1;
		move_cursor(1, 1);
	}
	else if (map_num == 1) {
		map2[posX][posY] = 1;
		map2[pre_posX][pre_posY] = 0;
	}

	//print map_inf
	print_map(index);

	
}

