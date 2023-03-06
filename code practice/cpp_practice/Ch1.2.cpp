#include <iostream>

using namespace std;
int main()
{
    int number;
    cout<<"정수를 입력하시오: ";
    cin>>number;

    if(number%2==0)
    {
        cout<<"입력수는 짝수입니다."<<endl;
    }

    else
    {
        cout<<"입력수는 홀수입니다."<<endl;
    }

    return 0;
}