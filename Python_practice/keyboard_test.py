import keyboard
import time

buff = 1
buff2 = 1
while buff:
    if keyboard.is_pressed("up") and buff2 == 1:
        print("1")
        time.sleep(0.5)
        buff2 = 0
    if keyboard.is_pressed("down") and buff2 == 1:
        print("2")
        time.sleep(0.5)
        buff2 = 0
    if keyboard.is_pressed("esc"):
        print("종료")
        buff = 0
        break
    buff2 = 1
print("asd")