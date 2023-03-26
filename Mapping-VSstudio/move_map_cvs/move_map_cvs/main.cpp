#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <conio.h>

#include "MapManager.h"

using namespace std;

void out_range(int& pre_posX, int& pre_posY) {
    pre_posX = 404;
    pre_posY = 404;
}

int main() {
    int index = 0;

    int posX = MAP_SIZE / 2; // ���� ��ġ x ��ǥ
    int posY = MAP_SIZE / 2; // ���� ��ġ y ��ǥ

    int pre_posX = 404;
    int pre_posY = 404;

    int map_num = 0;

    char input; // ����� �Է��� ���� ����

    Map_Editor mapManager(3);

    while (true) { 

        //mapManager.print_NumMap(index, map_num);

        //print map_file
        cout << "--------map:0--------" << endl; //boundary line
        cout << "map_num: " << map_num << endl;
        read_map(mapManager, map_num, posX, posY, pre_posX, pre_posY);
        cout << "---------------------" << endl; //boundary line

        //posX, posY place
        cout << "posX: " << posX;
        cout << " | " << "pre_posX: " << pre_posX << endl;
        cout << "posY: " << posY;
        cout << " | " << "pre_posY: " << pre_posY << endl;

        //move_data
        input = _getch(); // getch() �Լ��� ����Ͽ� ����� �Է��� ����


        //ǥ�� ������ ����� Ŀ�� �̵� �ʿ�!!!
        pre_posX = posX;
        pre_posY = posY;


        // �Է¿� ���� ��ġ �̵�
        switch (input) {

        case 'w': // ���� �̵�
            if (posX >= 0) {
                if (mapManager.NumMap_data(index, posX - 1, posY) == 3) {
                    out_range(pre_posX, pre_posY);
                    break;
                }
                posX--;
            }

            if (map_num == 1 && posX < 0) {
                map_num = 0;
                posX = MAP_SIZE - 1;
            }
            break;


        case 'a': // ���� �̵�
            if (posY >= 0) {
                if (mapManager.NumMap_data(index, posX, posY - 1) == 3) {
                    out_range(pre_posX, pre_posY);
                    break;
                }
                posY--;
            }
            break;


        case 's': // �Ʒ��� �̵�
            if (posX <= MAP_SIZE - 1) {
                if (mapManager.NumMap_data(index, posX + 1, posY) == 3) {
                    out_range(pre_posX, pre_posY);
                    break;
                }
                posX++;

            }

            if (posX == MAP_SIZE) {
                map_num = 1;
                posX = 0;
            }
            break;


        case 'd': // ������ �̵�
            if (posY < MAP_SIZE - 1) {
                if (mapManager.NumMap_data(index, posX, posY + 1) == 3) {
                    out_range(pre_posX, pre_posY);
                    break;
                }
                posY++;
            }
            break;


        case 'q':
            exit(0);
            break; 
        }
    }

    

    /*
    // �� ������
    int arr[60][60] = { 0 };

    vector<vector<int>> map_data;

    for (int i = 0; i < 60; i++) {
        vector<int> row;

        for (int j = 0; j < 60; j++) {
            row.push_back(arr[i][j]);
        }

        map_data.push_back(row);
    }

    // ���� ����
    ofstream file_output("map_data.csv");

    // �� ������ ����
    for (int i = 0; i < map_data.size(); i++) {
        for (int j = 0; j < map_data[i].size(); j++) {
            file_output << map_data[i][j];

            if (j != map_data[i].size() - 1) {
                file_output << ",";
            }
        }

        file_output << endl;
    }

    // ���� �ݱ�
    file_output.close();

    cout << "�� �����͸� �����߽��ϴ�." << endl;

    // ���� ����
    ifstream file("map_data.csv");

    // �� ������ ������ ���� ����
    vector<vector<int>> map_data_save;


    // ���� �б�
    string line;
    while (getline(file, line)) {
        // ���ڿ� �Ľ�
        stringstream ss(line);
        vector<int> row;
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(stoi(cell));
        }

        map_data_save.push_back(row);
    }

    // ���� �ݱ�
    file.close();

    // �� ������ ���
    for (int i = 0; i < map_data_save.size(); i++) {
        for (int j = 0; j < map_data_save[i].size(); j++) {
            cout << map_data_save[i][j] << " ";
        }

        cout << endl;
    }
    */

    return 0;
}


