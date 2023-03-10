"""
<MOTER POSITION>            <MOTER DRIVE POSITION>
RL-----RR                   ENB IN4 IN3 IN2 IN1 ENA | ENB IN4 IN3 IN2 IN1 ENA
|       |                    11   9  10   1  7    8 |  12  20  16   5   6  13
|       |                       <RL>    |   <RR>    |     <FL>        <FR>      
|       |
FL-----FR
"""

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#Moter Setup
#FR-MOTER
EN_FR = 13
IN_FR_1 = 6
IN_FR_2 = 5
GPIO.setup(EN_FR, GPIO.OUT)
GPIO.setup(IN_FR_1, GPIO.OUT)
GPIO.setup(IN_FR_2, GPIO.OUT)
pwm_FR = GPIO.PWM(EN_FR,100)
pwm_FR.start(0)
OUT_FR_1 = 0
OUT_FR_2 = 0

#FL-MOTER
EN_FL = 12
IN_FL_1 = 20
IN_FL_2 = 16
GPIO.setup(EN_FL, GPIO.OUT)
GPIO.setup(IN_FL_1, GPIO.OUT)
GPIO.setup(IN_FL_2, GPIO.OUT)
pwm_FL = GPIO.PWM(EN_FL,100)
pwm_FL.start(0)
OUT_FL_1 = 0
OUT_FL_2 = 0

#RR-MOTER
EN_RR = 8
IN_RR_1 = 7
IN_RR_2 = 1
GPIO.setup(EN_RR, GPIO.OUT)
GPIO.setup(IN_RR_1, GPIO.OUT)
GPIO.setup(IN_RR_2, GPIO.OUT)
pwm_RR = GPIO.PWM(EN_RR,100)
pwm_RR.start(0)
OUT_RR_1 = 0
OUT_RR_2 = 0

#RL-MOTER
EN_RL = 11
IN_RL_1 = 9
IN_RL_2 = 10
GPIO.setup(EN_RL, GPIO.OUT)
GPIO.setup(IN_RL_1, GPIO.OUT)
GPIO.setup(IN_RL_2, GPIO.OUT)
pwm_RL = GPIO.PWM(EN_RL,100)
pwm_RL.start(0)
OUT_RL_1 = 0
OUT_RL_2 = 0

#operation
buff = 1 

while buff:
    D, t, speed = map(int,input("방향(F=1/B=0), 주행시간, 속도(1~100%)를 입력하시오").split())
    
    pwm_FR.ChangeDutyCycle(speed)
    pwm_FL.ChangeDutyCycle(speed)
    pwm_RR.ChangeDutyCycle(speed)
    pwm_RL.ChangeDutyCycle(speed)

    if D == 1:
        #Forward
         OUT_FR_1 = OUT_FL_2 = OUT_RR_2 = OUT_RL_1 = 1
         OUT_FR_2 = OUT_FL_1 = OUT_RR_1 = OUT_RL_2 = 0
    elif D == 0:
        #Back
        OUT_FR_1 = OUT_FL_2 = OUT_RR_2 = OUT_RL_1 = 0
        OUT_FR_2 = OUT_FL_1 = OUT_RR_1 = OUT_RL_2 = 1

    print("Driving...")

    GPIO.output(IN_FR_1,OUT_FR_1)
    GPIO.output(IN_FR_2,OUT_FR_2)

    GPIO.output(IN_FL_1,OUT_FL_1)
    GPIO.output(IN_FL_2,OUT_FL_2)

    GPIO.output(IN_RR_1,OUT_RR_1)
    GPIO.output(IN_RR_2,OUT_RR_2)

    GPIO.output(IN_RL_1,OUT_RL_1)
    GPIO.output(IN_RL_2,OUT_RL_2)
    time.sleep(t)
    print("stop")

    pwm_FR.ChangeDutyCycle(0)
    pwm_FL.ChangeDutyCycle(0)
    pwm_RR.ChangeDutyCycle(0)
    pwm_RL.ChangeDutyCycle(0)

    buff = int(input("stop:0, keep:1 :"))
    print(buff)
print("POWER OFF")