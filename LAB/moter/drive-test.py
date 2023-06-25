import RPi.GPIO as GPIO
import time

#FR-MOTER
ENA = 13
IN1 = 6
IN2 = 5

#FL-MOTER
ENB = 21
IN3 = 20
IN4 = 16

#RR-MOTER
ENC = 8
IN5 = 7
IN6 = 1

#RL-MOTER
END = 11
IN7 = 9
IN8 = 10

state = 1
speed = 0

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO.setup(IN1, GPIO.OUT)
GPIO.setup(IN2, GPIO.OUT)
GPIO.setup(ENA, GPIO.OUT)

GPIO.setup(IN3, GPIO.OUT)
GPIO.setup(IN4, GPIO.OUT)
GPIO.setup(ENB, GPIO.OUT)

GPIO.setup(IN5, GPIO.OUT)
GPIO.setup(IN6, GPIO.OUT)
GPIO.setup(ENC, GPIO.OUT)

GPIO.setup(IN7, GPIO.OUT)
GPIO.setup(IN8, GPIO.OUT)
GPIO.setup(END, GPIO.OUT)

pwmB = GPIO.PWM(ENB,100)
pwmA = GPIO.PWM(ENA,100)
pwmC = GPIO.PWM(ENC,100)
pwmD = GPIO.PWM(END,100)

pwmB.start(0)
pwmA.start(0)
pwmC.start(0)
pwmD.start(0)


while state:
    print("working")
    speed = 100
    pwmA.ChangeDutyCycle(speed)
    pwmB.ChangeDutyCycle(speed)
    pwmC.ChangeDutyCycle(speed)
    pwmD.ChangeDutyCycle(speed)

    GPIO.output(IN1,1)
    GPIO.output(IN2,0)

    GPIO.output(IN3,0)
    GPIO.output(IN4,1)

    GPIO.output(IN5,0)
    GPIO.output(IN6,1)

    GPIO.output(IN7,1)
    GPIO.output(IN8,0)
    time.sleep(5)

    speed = 50
    pwmA.ChangeDutyCycle(speed)
    pwmB.ChangeDutyCycle(speed)
    pwmC.ChangeDutyCycle(speed)
    pwmD.ChangeDutyCycle(speed)
    time.sleep(1)

    GPIO.output(IN1,0)
    GPIO.output(IN2,1)

    GPIO.output(IN3,1)
    GPIO.output(IN4,0)

    GPIO.output(IN5,1)
    GPIO.output(IN6,0)

    GPIO.output(IN7,0)
    GPIO.output(IN8,1)

    time.sleep(5)
    pwmA.ChangeDutyCycle(0)
    pwmB.ChangeDutyCycle(0)
    pwmC.ChangeDutyCycle(0)
    pwmD.ChangeDutyCycle(0)
    state = 0

    print("stop")