x = input("문자열을 입력하세요: ")

for i in range(len(x)+1):
    print(x[:i])

for i in range(len(x)-1,-1,-1):
    print(x[:i])