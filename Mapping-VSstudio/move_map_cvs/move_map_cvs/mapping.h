#pragma once

const int MAP_SIZE = 11;

void read_map(int map_num, int posX, int posY, int old_posX, int old_posY);

void map_write(int index, int i, int j, int obj);

int map_data(int index, int posX, int posY);

int map_list(int index, int i, int j);

