"""
<MOTER POSITION>            <MOTER DRIVE POSITION>
RL-----RR                   ENB IN4 IN3 IN2 IN1 ENA | ENB IN4 IN3 IN2 IN1 ENA
|       |                    22  27  17  25  24  23 |  21  20  16   5   6  13
|       |                       <BR>    |   <FR>    |     <BL>        <FL>      
|       |
FL-----FR
"""

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#Moter Setup
#FL-MOTER
EN_FL = 13
IN_FL_1 = 6
IN_FL_2 = 5
GPIO.setup(EN_FL, GPIO.OUT)
GPIO.setup(IN_FL_1, GPIO.OUT)
GPIO.setup(IN_FL_2, GPIO.OUT)
pwm_FL = GPIO.PWM(EN_FL,100)
pwm_FL.start(0)
OUT_FL_1 = 0
OUT_FL_2 = 0

#BL-MOTER
EN_BL = 21
IN_BL_1 = 20
IN_BL_2 = 16
GPIO.setup(EN_BL, GPIO.OUT)
GPIO.setup(IN_BL_1, GPIO.OUT)
GPIO.setup(IN_BL_2, GPIO.OUT)
pwm_BL = GPIO.PWM(EN_BL,100)
pwm_BL.start(0)
OUT_BL_1 = 0
OUT_BL_2 = 0

#FR-MOTER
EN_FR = 23
IN_FR_1 = 24
IN_FR_2 = 25
GPIO.setup(EN_FR, GPIO.OUT)
GPIO.setup(IN_FR_1, GPIO.OUT)
GPIO.setup(IN_FR_2, GPIO.OUT)
pwm_FR = GPIO.PWM(EN_FR,100)
pwm_FR.start(0)
OUT_FR_1 = 0
OUT_FR_2 = 0

#BR-MOTER
EN_BR = 22
IN_BR_1 = 27
IN_BR_2 = 17
GPIO.setup(EN_BR, GPIO.OUT)
GPIO.setup(IN_BR_1, GPIO.OUT)
GPIO.setup(IN_BR_2, GPIO.OUT)
pwm_BR = GPIO.PWM(EN_BR,100)
pwm_BR.start(0)
OUT_BR_1 = 0
OUT_BR_2 = 0

buff = 1
"""
OUT_FL_1 = 0
OUT_FL_2 = 1

OUT_FR_1 = 1
OUT_FR_2 = 0

OUT_BR_1 = 1
OUT_BR_2 = 0

OUT_BL_1 = 0
OUT_BL_2 = 1
"""
OUT_FL_1 = 0
OUT_FL_2 = 1

OUT_FR_1 = 0
OUT_FR_2 = 1

OUT_BR_1 = 0
OUT_BR_2 = 1

OUT_BL_1 = 0
OUT_BL_2 = 1


while buff:
    #초기 스탑 설정
    pwm_FL.ChangeDutyCycle(0)
    pwm_BL.ChangeDutyCycle(0)
    pwm_FR.ChangeDutyCycle(0)
    pwm_BR.ChangeDutyCycle(0)

    pwm_FR.ChangeDutyCycle(100)
    pwm_BL.ChangeDutyCycle(100)
    pwm_FL.ChangeDutyCycle(100)
    pwm_BR.ChangeDutyCycle(100)

    GPIO.output(IN_FL_1,OUT_FL_1)
    GPIO.output(IN_FL_2,OUT_FL_2)

    GPIO.output(IN_BL_1,OUT_BL_1)
    GPIO.output(IN_BL_2,OUT_BL_2)

    GPIO.output(IN_FR_1,OUT_FR_1)
    GPIO.output(IN_FR_2,OUT_FR_2)

    GPIO.output(IN_BR_1,OUT_BR_1)
    GPIO.output(IN_BR_2,OUT_BR_2)

    time.sleep(0.65)

    pwm_FL.ChangeDutyCycle(0)
    pwm_BL.ChangeDutyCycle(0)
    pwm_FR.ChangeDutyCycle(0)
    pwm_BR.ChangeDutyCycle(0)
    break