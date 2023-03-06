import copy
x = list(map(list,input("정수를 입력하시오: ")))
y = copy.deepcopy(x)
count = 0

x.reverse()
print(x[:])
print(y[:])
print(type(len(x)))

for i in range(len(x)):
    if(x[i] == y[i]):
        count += 1


if(count == len(x)):
    print("o")
else:
    print("x")