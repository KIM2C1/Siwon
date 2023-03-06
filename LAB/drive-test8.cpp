#include <wiringPi.h>
#include <softPwm.h>

// FL-MOTER
#define EN_FL 23
#define IN_FL_1 27
#define IN_FL_2 22
int OUT_FL_1 = LOW;
int OUT_FL_2 = LOW;

// BL-MOTER
#define EN_BL 4
#define IN_BL_1 5
#define IN_BL_2 6
int OUT_BL_1 = LOW;
int OUT_BL_2 = LOW;

// FR-MOTER
#define EN_FR 1
#define IN_FR_1 24
#define IN_FR_2 25
int OUT_FR_1 = LOW;
int OUT_FR_2 = LOW;

// BR-MOTER
#define EN_BR 16
#define IN_BR_1 26
#define IN_BR_2 27
int OUT_BR_1 = LOW;
int OUT_BR_2 = LOW;

int main(void)
{
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

  // FL-MOTER 전진
  OUT_FL_1 = HIGH;
  OUT_FL_2 = LOW;
  digitalWrite(IN_FL_1, OUT_FL_1);
  digitalWrite(IN_FL_2, OUT_FL_2);
  softPwmWrite(EN_FL, 50);

  // BL-MOTER 전진
  OUT_BL_1 = HIGH;
  OUT_BL_2 = LOW;
  digitalWrite(IN_BL_1, OUT_BL_1);
  digitalWrite(IN_BL_2, OUT_BL_2);
  softPwmWrite(EN_BL, 50);

  // FR-MOTER 전진
  OUT_FR_1 = HIGH;
  OUT_FR_2 = LOW;
  digitalWrite(IN_FR_1, OUT_FR_1);
  digitalWrite(IN_FR_2, OUT_FR_2);
  softPwmWrite(EN_FR, 50);

  // BR-MOTER 전진
  OUT_BR_1 = HIGH;
  OUT_BR_2 = LOW;
  digitalWrite(IN_BR_1, OUT_BR_1);
  digitalWrite(IN_BR_2, OUT_BR_2);
  softPwmWrite(EN_BR, 50);

  return 0;
}