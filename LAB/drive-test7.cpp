#include <iostream>
#include <termios.h>
#include <unistd.h>

int main() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    std::cout << "Please enter a b c:" << std::endl;

    char c;
    std::cin >> c;
    std::cout << c;
    std::cin >> c;
    std::cout << c;
    std::cin >> c;
    std::cout << c;

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}

