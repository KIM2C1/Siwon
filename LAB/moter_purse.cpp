#include "wiringPi.h"
#include <softPwm.h>
#include <iostream>

#define pwmPinA 25             // 모터드라이d버 ENA - GPIO핀 번호: 12
#define AIN1 24            // IN1 - GPIO핀 번호: 16
#define AIN2 23            // IN2 - GPIO핀 번호 : 25 
#define encPinA 22           // 보라색 (A) - GPIO핀 번호 : 23
#define encPinB 21           // 파랑색 (B) - GPIO핀 번호 : 24

volatile int pulse_count = 0;

void pulse_callback() {
    std::cout<<"A"<<std::endl;
}

int main() {
    int count = 0;
    wiringPiSetup();

    pinMode(encPinA, INPUT);
    pullUpDnControl(encPinA, PUD_UP);
    pinMode(pwmPinA, OUTPUT); 
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    softPwmCreate(pwmPinA, 0, 100);     
    softPwmWrite(pwmPinA, 50);

    digitalWrite(pwmPinA, LOW);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    
    wiringPiISR(6, INT_EDGE_BOTH, &pulse_callback);

    while (1) {
        
        //std::cout << "Pulse Count: " << pulse_count << std::endl;
        //delay(100);

        //if (pulse_count == 20)
        if (digitalRead(encPinA) == HIGH) {
            if (digitalRead(encPinA) == LOW) {
                count += 1;
                std::cout<<count<<std::endl;
            }
        }
        if (count >= 26) {
            softPwmWrite(pwmPinA, 0);
        }
    }

    return 0;
}
