#include <iostream>

using namespace std;

int adder(int x, int y);
float adder(float x, float y);
char adder(char x, char y);
double adder(double x, double y);

int main()
{
    cout << adder(3.5, 5.5) << endl;
    cout << adder(3, 5) << endl;
    cout << adder((float)3.5, (float)5.5) << endl;
    cout << adder((char)65, (char)32) << endl;

    cout <<(char)32<<endl;

    return 0;
}

int adder(int x, int y)
{
    return x + y;
}
float adder(float x, float y)
{
    return x + y;
}
double adder(double x, double y)
{
    return x + y;
}
char adder(char x, char y)
{
    return x + y;
}