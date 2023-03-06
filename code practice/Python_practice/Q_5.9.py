x = []
y = 0
n = 0

while y != -99:
    y = int(input("정수를 입력하시오: "))
    if y != -99:
        x.append(str(y))
    n += 1
print(n-1,"개의 유효한 정수중 가장 큰 정수는", max(x), "이고, 가장 작은 정수는", min(x), "입니다.")