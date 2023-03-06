#include <iostream>

using namespace std;

void swap(int& x, int& y);

int main()
{
    int x = 10;
    int y = 20;

    swap(x,y);
    cout<<x<<" "<<y<<endl;

    return 0;
}

//함수 파라미터 자료형에 참조기호&가 붙어있으면 메모리위치를 참조한다.
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
    return;
}