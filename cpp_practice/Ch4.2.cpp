#include <iostream>

using namespace std;

int main() {
	int x = 10;
	int* x_ptr;
	x_ptr = &x;

	cout << "x값:" << x << endl;
	cout << "x의 주소값" << &x << endl;
	cout << "x_ptr의 값" << x_ptr << endl;
	cout << "x_ptr이 가르키는 값" << *x_ptr << endl;

	return 0;
}