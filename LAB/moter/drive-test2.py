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
#pwm_FR = GPIO.PWM(EN_FR,255)
#pwm_FR.start(0)
OUT_FR_1 = 0
OUT_FR_2 = 0

#FL-MOTER
EN_FL = 21
IN_FL_1 = 20
IN_FL_2 = 16
GPIO.setup(EN_FL, GPIO.OUT)
GPIO.setup(IN_FL_1, GPIO.OUT)
GPIO.setup(IN_FL_2, GPIO.OUT)
#pwm_FL = GPIO.PWM(EN_FL,255)
#pwm_FL.start(0)
OUT_FL_1 = 0
OUT_FL_2 = 0

#RR-MOTER
EN_RR = 8
IN_RR_1 = 7
IN_RR_2 = 1
GPIO.setup(EN_RR, GPIO.OUT)
GPIO.setup(IN_RR_1, GPIO.OUT)
GPIO.setup(IN_RR_2, GPIO.OUT)
#pwm_RR = GPIO.PWM(EN_RR,255)
#pwm_RR.start(0)
OUT_RR_1 = 0
OUT_RR_2 = 0

#RL-MOTER
EN_RL = 11
IN_RL_1 = 9
IN_RL_2 = 10
GPIO.setup(EN_RL, GPIO.OUT)
GPIO.setup(IN_RL_1, GPIO.OUT)
GPIO.setup(IN_RL_2, GPIO.OUT)
#pwm_RL = GPIO.PWM(EN_RL,255)
#pwm_RL.start(0)
OUT_RL_1 = 0
OUT_RL_2 = 0

while 1:
    t = int(input(":"))
    EN_FL = EN_FR = EN_RL = EN_RR = 100

    GPIO.output(IN_FR_1,1)
    GPIO.output(IN_FR_2,0)

    GPIO.output(IN_FL_1,0)
    GPIO.output(IN_FL_2,1)

    GPIO.output(IN_RR_1,0)
    GPIO.output(IN_RR_2,1)

    GPIO.output(IN_RL_1,0)
    GPIO.output(IN_RL_2,1)
    time.sleep(5)
