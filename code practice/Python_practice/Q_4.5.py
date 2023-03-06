import random

lotto = []
x = []
y = 0
z = 0

#복권 번호 생성 int
for i in range(3):
    lotto.append(random.randint(0,9))

print("생성된 로또번호", lotto)

#사용자 복권번호 입력 int
a, b ,c = map(int, input("세 복권번호를 입력하시오: ").split())

#list에 입력
x.append(a)
x.append(b)
x.append(c)
print("사용자 입력 번호", x)

for i in range(3):
    for n in range(3):
        if(lotto[i] == x[n]):
            y += 1
            x[n] = 10
            break


if(y == 3):
    print("상금 1억원")
elif(y == 2):
    print("상금 1천만원")
else:
    print("다음 기회에...")




