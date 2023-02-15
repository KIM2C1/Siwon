import time

buff = 1
buff2 = 1

while buff:
    x =int(input())

    if x == 1:
        print("1")
        time.sleep(3)
    if x == 2:
        print("2")
        time.sleep(3)
    if x == 3:
        break
print("종료")