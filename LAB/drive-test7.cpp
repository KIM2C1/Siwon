#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <wiringPi.h>

using namespace std;

int main() {
    wiringPiSetupGpio();

    pinMode(13, PWM_OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);

    struct termios old_tio, new_tio;

    // 터미널 설정 변경
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    char input;
    
    while (1) {
        cout << "Enter a character: ";
        if (read(STDIN_FILENO, &input, 1) == 1) {
            if (input == 'a') {
                cout << "1" << endl;
            }
            else if (input == 'b') {
                cout << "2" << endl;
            }
            else {
                cout << "Invalid input" << endl;
                break;
            }
        }
    }

    // 터미널 설정 복원
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

    return 0;
}

