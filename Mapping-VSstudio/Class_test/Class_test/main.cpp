#include <iostream>
#include "MapManager.h"

int main() {
    int num_maps = 3; // ����ڰ� �Է��ϴ� ���� ���� �����Ǵ� �� ����

    MapManager mapManager(num_maps);;

    // ��� �� ���
    for (int i = 0; i < num_maps; ++i) {
        mapManager.print_map(i);
        std::cout << std::endl;
    }

    return 0;
}
