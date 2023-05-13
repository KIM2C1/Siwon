#include "wiringpi.h"
#include <iostream>

#define pwmPinA 25             // 모터드라이버 ENA - GPIO핀 번호: 12
#define AIN1 24            // IN1 - GPIO핀 번호: 16
#define AIN2 23            // IN2 - GPIO핀 번호 : 25 
#define encPinA 22           // 보라색 (A) - GPIO핀 번호 : 23
#define encPinB 21           // 파랑색 (B) - GPIO핀 번호 : 24

int main() {
    wiringPiSetup();

    pinMode(encPinA, INPUT);

    pinMode(pwmPinA, OUTPUT); 
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    wiringpi.softPwmWrite(pwmPinA, 0, 100);
    wiringpi.softPwmWrite(pwmPinA, 50);

    wiringpi.digitalWrite(pwmPinA, LOW);
    wiringpi.digitalWrite(AIN1, LOW);
    wiringpi.digitalWrite(AIN2, HIGH);
    
    wiringpi.wiringPiISR(encPinA, INT_EDGE_BOTH, pulse.callback);

    while (1) {
        cout << "Pulse Count: " << pulse_count << endl;
    }

    return 0;
}
