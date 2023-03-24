#include "mapping.h"

int map1[MAP_SIZE][MAP_SIZE] = { 0 };
int map2[MAP_SIZE][MAP_SIZE] = { 0 };
int map3[MAP_SIZE][MAP_SIZE] = { 0 };

int(*maps[3])[MAP_SIZE][MAP_SIZE] = { &map1, &map2, &map3 };

int map_list(int index, int i, int j) {
	return (*maps[index])[i][j];
}

void map_write(int index, int i, int j, int obj) {
	(*maps[index])[i][j] = obj;
}