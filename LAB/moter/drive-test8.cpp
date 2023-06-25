/*
<MOTER POSITION>            <MOTER DRIVE POSITION>
RL-----RR                   ENB IN4 IN3 IN2 IN1 ENA | ENB IN4 IN3 IN2 IN1 ENA
|       |                    22  27  17  25  24  23 |  21  20  16   5   6  13
|       |                       <BR>    |   <FR>    |     <BL>        <FL>      
|       |
FL-----FR
*/

#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

// FL-MOTER
#define EN_FL 23
#define IN_FL_1 22
#define IN_FL_2 21
int OUT_FL_1 = LOW;
int OUT_FL_2 = LOW;

// BL-MOTER
#define EN_BL 29
#define IN_BL_1 28
#define IN_BL_2 27
int OUT_BL_1 = LOW;
int OUT_BL_2 = LOW;

// FR-MOTER
#define EN_FR 4
#define IN_FR_1 5
#define IN_FR_2 6
int OUT_FR_1 = LOW;
int OUT_FR_2 = LOW;

// BR-MOTER
#define EN_BR 3
#define IN_BR_1 2
#define IN_BR_2 0
int OUT_BR_1 = LOW;
int OUT_BR_2 = LOW;


int main() {

  // wiringPi 초기화
  wiringPiSetup();
  
  // FL-MOTER
  pinMode(EN_FL, OUTPUT);
  pinMode(IN_FL_1, OUTPUT);
  pinMode(IN_FL_2, OUTPUT);
  softPwmCreate(EN_FL, 0, 100);
  softPwmWrite(EN_FL, 0);

  // BL-MOTER
  pinMode(EN_BL, OUTPUT);
  pinMode(IN_BL_1, OUTPUT);
  pinMode(IN_BL_2, OUTPUT);
  softPwmCreate(EN_BL, 0, 100);
  softPwmWrite(EN_BL, 0);

  // FR-MOTER
  pinMode(EN_FR, OUTPUT);
  pinMode(IN_FR_1, OUTPUT);
  pinMode(IN_FR_2, OUTPUT);
  softPwmCreate(EN_FR, 0, 100);
  softPwmWrite(EN_FR, 0);

  // BR-MOTER
  pinMode(EN_BR, OUTPUT);
  pinMode(IN_BR_1, OUTPUT);
  pinMode(IN_BR_2, OUTPUT);
  softPwmCreate(EN_BR, 0, 100);
  softPwmWrite(EN_BR, 0);

  struct termios old_tio, new_tio;

  // 터미널 설정 변경
  tcgetattr(STDIN_FILENO, &old_tio);
  new_tio = old_tio;
  new_tio.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

  char input;

  while (1) {
    // FL-MOTER 전진
    OUT_FL_1 = LOW;
    OUT_FL_2 = HIGH;
    digitalWrite(IN_FL_1, OUT_FL_1);
    digitalWrite(IN_FL_2, OUT_FL_2);
    softPwmWrite(EN_FL, 100);
  
    // BL-MOTER 전진
    OUT_BL_1 = LOW;
    OUT_BL_2 = HIGH;
    digitalWrite(IN_BL_1, OUT_BL_1);
    digitalWrite(IN_BL_2, OUT_BL_2);
    softPwmWrite(EN_BL, 100);
  
    // FR-MOTER 전진
    OUT_FR_1 = HIGH;
    OUT_FR_2 = LOW;
    digitalWrite(IN_FR_1, OUT_FR_1);
    digitalWrite(IN_FR_2, OUT_FR_2);
    softPwmWrite(EN_FR, 100);
  
    // BR-MOTER 전진
    OUT_BR_1 = HIGH;
    OUT_BR_2 = LOW;
    digitalWrite(IN_BR_1, OUT_BR_1);
    digitalWrite(IN_BR_2, OUT_BR_2);
    softPwmWrite(EN_BR, 100);

    if (read(STDIN_FILENO, &input, 1) == 1) {
      if (input == 'a') {
          cout << "a" << endl;

          digitalWrite(IN_FL_1, LOW);
          digitalWrite(IN_FL_2, LOW);
          digitalWrite(IN_BL_1, LOW);
          digitalWrite(IN_BL_2, LOW);
          digitalWrite(IN_FR_1, LOW);
          digitalWrite(IN_FR_2, LOW);
          digitalWrite(IN_BR_1, LOW);
          digitalWrite(IN_BR_2, LOW);

          softPwmWrite(EN_FL, 0);
          softPwmWrite(EN_BL, 0);
          softPwmWrite(EN_FR, 0);
          softPwmWrite(EN_BR, 0);

          break;
      }
      else {
        cout << "Invalid input" << endl;
      }
    }
  }
  tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

  return 0;
}