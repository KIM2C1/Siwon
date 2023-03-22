#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <conio.h>

const int SIZE = 11; // 배열 크기 상수 선언
using namespace std;

int main() {

    int map1[SIZE][SIZE]; // 11x11 크기의 2차원 배열 생성
    int map2[SIZE][SIZE]; // 11x11 크기의 2차원 배열 생성
    int posX = SIZE / 2; // 시작 위치 x 좌표
    int posY = SIZE / 2; // 시작 위치 y 좌표
    char input; // 사용자 입력을 받을 변수

    
    while (true) { // 무한 반복
        // 배열 초기화
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                map1[i][j] = 0; // 모든 요소를 0으로 초기화
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                map2[i][j] = 0; // 모든 요소를 0으로 초기화
            }
        }
       

        // 현재 위치 표시
        map1[posX][posY] = 1;

        cout << "---------------------" << endl; //boundary line

        // 배열 출력
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << map1[i][j] << " ";
            }
            cout << endl;
        }

        cout << "---------------------" << endl; //boundary line

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << map2[i][j] << " ";
            }
            cout << endl;
        }

        cout << "---------------------" << endl; //boundary line

        // 사용자 입력 받기
        input = _getch(); // getch() 함수를 사용하여 사용자 입력을 받음

        // 입력에 따른 위치 이동
        switch (input) {
        case 'w': // 위쪽 이동
            if (posX > 0) posX--; // 맵 범위를 벗어나지 않도록 조건문으로 처리
            break;
        case 'a': // 왼쪽 이동
            if (posY > 0) posY--;
            break;
        case 's': // 아래쪽 이동
            if (posX < SIZE - 1) posX++;
            break;
        case 'd': // 오른쪽 이동
            if (posY < SIZE - 1) posY++;
            break;
        case 'q':
            exit(0);
            break;
        }

        // 화면 클리어
        system("cls"); // Windows에서는 "cls", Linux나 macOS에서는 "clear"를 사용하여 화면을 지움
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
