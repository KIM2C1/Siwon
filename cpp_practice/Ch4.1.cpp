#include <iostream>

using namespace std;

struct student {
	string name;
	int age;
	int number;
};

void PrintInfo(student s) {
	cout << "�̸�: " << s.name << "\n����: " << s.age << "\n��ȣ: " << s.number;
	cout << "\n-------------------\n";
}

int main() {
	student stu1 = { "ö��", 12, 1 };
	student stu2 = { "����", 15, 2 };

	PrintInfo(stu1);
	PrintInfo(stu2);

	return 0;
}