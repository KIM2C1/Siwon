#include <iostream>

using namespace std;

struct student {
	string name;
	int age;
	int number;
};

void PrintInfo(student s) {
	cout << "ÀÌ¸§: " << s.name << "\n³ªÀÌ: " << s.age << "\n¹øÈ£: " << s.number;
	cout << "\n-------------------\n";
}

int main() {
	student stu1 = { "Ã¶¼ö", 12, 1 };
	student stu2 = { "¿µÈñ", 15, 2 };

	PrintInfo(stu1);
	PrintInfo(stu2);

	return 0;
}