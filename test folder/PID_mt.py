import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

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

pwm_FL.ChangeDutyCycle(0)

OUT_FL_1 = 0
OUT_FL_2 = 1

GPIO.output(IN_FL_1,OUT_FL_1)
GPIO.output(IN_FL_2,OUT_FL_2)

pwm_FL.ChangeDutyCycle(100)
