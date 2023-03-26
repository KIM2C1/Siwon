
#include <iostream>
//#include <vector>

#include "MapManager.h"

using namespace std;

MapManager::MapManager(int num_maps) {
    maps.resize(num_maps, vector<vector<int>>(MAP_SIZE, vector<int>(MAP_SIZE, 0)));
}

void MapManager::print_map(int index) {
    std::cout << "Map " << index << ":" << std::endl;
    for (const auto& row : maps[index]) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}