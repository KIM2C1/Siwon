/*
<MOTER POSITION>            <MOTER DRIVE POSITION>
FL-----FR                   ENB IN4 IN3 IN2 IN1 ENA | ENB IN4 IN3 IN2 IN1 ENA
|       |                     3   2   0   6   5   4 |  29  28  27  21  22  23
|       |                       <BR>    |   <FR>    |     <BL>        <FL>      
|       |
BL-----BR
*/

#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
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

 void state_value(str state) {
    if (state == 'ready') {
      OUT_FL_1 = OUT_FL_2 = OUT_FR_1 = OUT_FR_2 = OUT_BL_1 =  OUT_BL_2 = OUT_BR_1 = OUT_BR_2 = LOW;
      softPwmWrite(EN_FL, 0);
      softPwmWrite(EN_BL, 0);
      softPwmWrite(EN_FR, 0);
      softPwmWrite(EN_BR, 0);
    }
    else if (state == 'go') {
      OUT_FL_1 = OUT_FR_2 = OUT_BL_1 = OUT_BR_2 = LOW;
      OUT_FL_2 = OUT_FR_1 = OUT_BL_2 = OUT_BR_1 = HIGH;
      softPwmWrite(EN_FL, 100);
      softPwmWrite(EN_BL, 100);
      softPwmWrite(EN_FR, 100);
      softPwmWrite(EN_BR, 100);
    }
    else if (state == 'back') {
      OUT_FL_1 = OUT_FR_2 = OUT_BL_1 = OUT_BR_2 = HIGH;
      OUT_FL_2 = OUT_FR_1 = OUT_BL_2 = OUT_BR_1 = LOW;
      softPwmWrite(EN_FL, 100);
      softPwmWrite(EN_BL, 100);
      softPwmWrite(EN_FR, 100);
      softPwmWrite(EN_BR, 100);
    }
    else if (state == 'right') {
      OUT_FL_2 = OUT_FR_2 = OUT_BL_1 = OUT_BR_1 = HIGH;
      OUT_FL_1 = OUT_FR_1 = OUT_BL_2 = OUT_BR_2 = LOW;
      softPwmWrite(EN_FL, 100);
      softPwmWrite(EN_BL, 100);
      softPwmWrite(EN_FR, 100);
      softPwmWrite(EN_BR, 100);
    }
    else if (state == 'left') {
      OUT_FL_1 = OUT_FR_1 = OUT_BL_2 = OUT_BR_2 = HIGH;
      OUT_FL_2 = OUT_FR_2 = OUT_BL_1 = OUT_BR_1 = LOW;
      softPwmWrite(EN_FL, 100);
      softPwmWrite(EN_BL, 100);
      softPwmWrite(EN_FR, 100);
      softPwmWrite(EN_BR, 100);
    }
  }

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

  char input;

  while (1) {
    cout << "ready / go / back / right / left" << endl;
    cin >> input;
    state_value(input);
    sleep(0.3);
    digitalWrite(IN_FL_1, OUT_FL_1);
    digitalWrite(IN_FL_2, OUT_FL_2);
    digitalWrite(IN_BL_1, OUT_BL_1);
    digitalWrite(IN_BL_2, OUT_BL_2);

    digitalWrite(IN_FR_1, OUT_FR_1);
    digitalWrite(IN_FR_2, OUT_FR_2);
    digitalWrite(IN_BR_1, OUT_BR_1);
    digitalWrite(IN_BR_2, OUT_BR_2);
    sleep(5);
  }
  return 0;
}