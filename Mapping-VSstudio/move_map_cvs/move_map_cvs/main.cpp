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

    int posX = MAP_SIZE / 2; // 시작 위치 x 좌표
    int posY = MAP_SIZE / 2; // 시작 위치 y 좌표

    int pre_posX = 404;
    int pre_posY = 404;

    int map_num = 0;

    char input; // 사용자 입력을 받을 변수

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
        input = _getch(); // getch() 함수를 사용하여 사용자 입력을 받음


        //표기 데이터 지우는 커서 이동 필요!!!
        pre_posX = posX;
        pre_posY = posY;


        // 입력에 따른 위치 이동
        switch (input) {

        case 'w': // 위쪽 이동
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


        case 'a': // 왼쪽 이동
            if (posY >= 0) {
                if (mapManager.NumMap_data(index, posX, posY - 1) == 3) {
                    out_range(pre_posX, pre_posY);
                    break;
                }
                posY--;
            }
            break;


        case 's': // 아래쪽 이동
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


        case 'd': // 오른쪽 이동
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
    // 맵 데이터
    int arr[60][60] = { 0 };

    vector<vector<int>> map_data;

    for (int i = 0; i < 60; i++) {
        vector<int> row;

        for (int j = 0; j < 60; j++) {
            row.push_back(arr[i][j]);
        }

        map_data.push_back(row);
    }

    // 파일 생성
    ofstream file_output("map_data.csv");

    // 맵 데이터 저장
    for (int i = 0; i < map_data.size(); i++) {
        for (int j = 0; j < map_data[i].size(); j++) {
            file_output << map_data[i][j];

            if (j != map_data[i].size() - 1) {
                file_output << ",";
            }
        }

        file_output << endl;
    }

    // 파일 닫기
    file_output.close();

    cout << "맵 데이터를 저장했습니다." << endl;

    // 파일 열기
    ifstream file("map_data.csv");

    // 맵 데이터 저장할 벡터 생성
    vector<vector<int>> map_data_save;


    // 파일 읽기
    string line;
    while (getline(file, line)) {
        // 문자열 파싱
        stringstream ss(line);
        vector<int> row;
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(stoi(cell));
        }

        map_data_save.push_back(row);
    }

    // 파일 닫기
    file.close();

    // 맵 데이터 출력
    for (int i = 0; i < map_data_save.size(); i++) {
        for (int j = 0; j < map_data_save[i].size(); j++) {
            cout << map_data_save[i][j] << " ";
        }

        cout << endl;
    }
    */

    return 0;
}


