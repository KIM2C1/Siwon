/*
<MOTER POSITION>            <MOTER DRIVE POSITION>
RL-----RR                   ENB IN4 IN3 IN2 IN1 ENA | ENB IN4 IN3 IN2 IN1 ENA
|       |                    22  27  17  25  24  23 |  21  20  16   5   6  13
|       |                       <BR>    |   <FR>    |     <BL>        <FL>      
|       |
FL-----FR
*/

#include <iostream>
#include <wiringPi.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main()
{
    wiringPiSetup();
    pinMode(0, OUTPUT);

    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    fd_set set;
    struct timeval timeout;
    int rv;

    while (1)
    {
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);

        timeout.tv_sec = 0;
        timeout.tv_usec = 0;

        rv = select(STDIN_FILENO + 1, &set, NULL, NULL, &timeout);

        if (rv == -1)
        {
            // Error occurred in select()
        }
        else if (rv == 0)
        {
            // Timeout occurred in select()
        }
        else
        {
            char c;
            read(STDIN_FILENO, &c, 1);

            if (c == 'q')
            {
                break;
            }
            else if (c == '1')
            {
                cout << "1" << endl;
                //digitalWrite(0, HIGH);
            }
            else if (c == '0')
            {
                cout << "0" << endl;
                //digitalWrite(0, LOW);
            }
        }

        delay(100);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return 0;
}
