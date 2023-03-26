#include <iostream>
#include "MapManager.h"

int main() {
    int num_maps = 3; // 사용자가 입력하는 값에 따라 생성되는 맵 개수

    MapManager mapManager(num_maps);;

    // 모든 맵 출력
    for (int i = 0; i < num_maps; ++i) {
        mapManager.print_map(i);
        std::cout << std::endl;
    }

    return 0;
}
