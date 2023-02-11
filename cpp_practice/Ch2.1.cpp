    #include <iostream>

    using namespace std;

    /*
    함수 정의부를 메인 함수위에 입력 할 수 있지만 메인 함수가 밑으로 많이 밀리게 되므로 선언만하고 정의는 밑에다 적는다
    */

    int adder(int x, int y); //함수 선언부

    int main()  //메인 함수
    {
        int x, y, z;
        cin >> x >> y;

        z = adder(x,y);
        cout << z << endl;

        return 0;
    }

    int adder(int a, int b) // 함수 정의부
    {
        return a+b;
    }

    