/*
재귀함수
재귀(recursive)자기 자신에게 되돌리는 것을 의미
재귀 함수 자기 자신을 호출하는 함수
*/

#include <iostream>

using namespace std;

void countNum(int num)
{
   if (num == 1)
   {
    cout << "Num : " << num << endl;
    return;
   }
   else
   {
    cout << "Num : " << num << endl;
    countNum(num - 1);
   }
}

int main()
{
    countNum(5);

    return 0;
}