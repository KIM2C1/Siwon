#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    //rand 함수는 난수 순서가 정해져있다.
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() % 101 << endl;
    cout << rand() % 101 << endl;
    cout << rand() % 101 + 100 << endl;
    cout << rand() % 101 + 100 << endl;

    //srand 함수는 rand함수가 갑을 가져올 위치를 지정할 수 있고 그 값을 seed라고 한다.
    srand(700);
    cout << rand() << endl;
    cout << rand() << endl;
    
    //seed 값이 항상 달라야 하므로 시간time을 이용한다.
    //time 함수는 1970년 1월 1일을 기준으로 지금까지 지난 시간을 반환하다.
    
    srand(time(0));
    cout << rand() << endl;
    cout << rand() << endl;

    return 0;
}