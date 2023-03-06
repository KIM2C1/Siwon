x = int(input("소수 검사를 할 정수를 입력하시오: "))
out = "True"

for i in range(2, x):
    if x % i == 0:
        out = "False"

print("소수인가요? : ",out)
