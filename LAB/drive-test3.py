"""
<MOTER POSITION>            <MOTER DRIVE POSITION>
RL-----RR                   ENB IN4 IN3 IN2 IN1 ENA | ENB IN4 IN3 IN2 IN1 ENA
|       |                    22  27  17  25  24  23 |  21  20  16   5   6  13
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
EN_FL = 21
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
EN_RR = 23
IN_RR_1 = 24
IN_RR_2 = 25
GPIO.setup(EN_RR, GPIO.OUT)
GPIO.setup(IN_RR_1, GPIO.OUT)
GPIO.setup(IN_RR_2, GPIO.OUT)
pwm_RR = GPIO.PWM(EN_RR,100)
pwm_RR.start(0)
OUT_RR_1 = 0
OUT_RR_2 = 0

#RL-MOTER
EN_RL = 17
IN_RL_1 = 27
IN_RL_2 = 22
GPIO.setup(EN_RL, GPIO.OUT)
GPIO.setup(IN_RL_1, GPIO.OUT)
GPIO.setup(IN_RL_2, GPIO.OUT)
pwm_RL = GPIO.PWM(EN_RL,100)
pwm_RL.start(0)
OUT_RL_1 = 0
OUT_RL_2 = 0

buff = 1

speed = int(input("속도(70~100)"))



while buff:

    pwm_FR.ChangeDutyCycle(0)
    pwm_FL.ChangeDutyCycle(0)
    pwm_RR.ChangeDutyCycle(0)
    pwm_RL.ChangeDutyCycle(0)
    
    print("1-왼쪽\n2-오른쪽\n3-앞\n4-뒤\n")
    x =int(input("입력: "))

    if x == 1: #왼쪽
        OUT_FR_1 = OUT_FL_2 = OUT_RR_2 = OUT_RL_1 = 1
        OUT_FR_2 = OUT_FL_1 = OUT_RR_1 = OUT_RL_2 = 0
        a = 0
        b = 100
        c = 43
        d = 100
    
    if x == 2: #오른쪽
        OUT_FR_1 = OUT_FL_2 = OUT_RR_2 = OUT_RL_1 = 1
        OUT_FR_2 = OUT_FL_1 = OUT_RR_1 = OUT_RL_2 = 0
        a = 100
        b = 0
        c = 100
        d = 43

    if x == 3: #앞
        OUT_FR_1 = OUT_FL_2 = OUT_RR_2 = OUT_RL_1 = 1
        OUT_FR_2 = OUT_FL_1 = OUT_RR_1 = OUT_RL_2 = 0
        a = speed 
        b = speed 
        c = speed 
        d = speed 

    if x == 4: #뒤
        OUT_FR_1 = OUT_FL_2 = OUT_RR_2 = OUT_RL_1 = 0
        OUT_FR_2 = OUT_FL_1 = OUT_RR_1 = OUT_RL_2 = 1
        a = speed 
        b = speed 
        c = speed 
        d = speed 

    if x == 5: #스탑
        print("종료")
        break
    
    """
    OUT_FR_1 = OUT_FL_2 = OUT_RR_2 = OUT_RL_1 = 1
    OUT_FR_2 = OUT_FL_1 = OUT_RR_1 = OUT_RL_2 = 0
    """
    
    pwm_FR.ChangeDutyCycle(a)
    pwm_FL.ChangeDutyCycle(b)
    pwm_RR.ChangeDutyCycle(c)
    pwm_RL.ChangeDutyCycle(d)

    GPIO.output(IN_FR_1,OUT_FR_1)
    GPIO.output(IN_FR_2,OUT_FR_2)

    GPIO.output(IN_FL_1,OUT_FL_1)
    GPIO.output(IN_FL_2,OUT_FL_2)

    GPIO.output(IN_RR_1,OUT_RR_1)
    GPIO.output(IN_RR_2,OUT_RR_2)

    GPIO.output(IN_RL_1,OUT_RL_1)
    GPIO.output(IN_RL_2,OUT_RL_2)

    time.sleep(3)

    pwm_FR.ChangeDutyCycle(0)
    pwm_FL.ChangeDutyCycle(0)
    pwm_RR.ChangeDutyCycle(0)
    pwm_RL.ChangeDutyCycle(0)
print("종료")