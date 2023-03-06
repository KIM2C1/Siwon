#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream fout;
    fout.open("file.txt");
    for(int i=0; i<=10; i++) {
        fout << i << "\n";
    }
    fout << endl;
    fout.close();

    ifstream fin;
    fin.open("file.txt");
    int num;
    int sum = 0;
    for (int i=0; i<=10; i++) {
        fin >> num;
        sum += num;
    }
    cout << "합계 : " << sum << endl;
    //fin.close();

    return 0;
}