//해더와 cpp는 추후 공부 필요
//디폴트 파라미터와 static

#include <iostream>

using namespace std;

int adder(int x, int y);
void staticTest();

int main()
{
    int x;
    int y;

    cin >> x >> y;

    cout << adder(x, y) << endl;
    cout << "test" << endl; //?

    return 0;
}

int adder(int x, int y = 1) // y값을 입력하지 않으면 초기값 1로 계산 근데 y에 값이 들어올때 까지 입력을 받는다.
{
    return x + y;
}

void staticTest()
{
    int local_count = 0;
    static int static_count = 0;
    local_count++;
    static_count++;
    
    cout << "local_count:" << local_count << endl;
    cout << "static_count:" << static_count << endl;
}