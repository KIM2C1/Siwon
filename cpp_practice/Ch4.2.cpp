#include <iostream>

using namespace std;

int main() {
	int x = 10;
	int* x_ptr;
	x_ptr = &x;

	cout << "x��:" << x << endl;
	cout << "x�� �ּҰ�" << &x << endl;
	cout << "x_ptr�� ��" << x_ptr << endl;
	cout << "x_ptr�� ����Ű�� ��" << *x_ptr << endl;

	return 0;
}