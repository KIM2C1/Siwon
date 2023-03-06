x = int(input("숫자를 입력하세요: "))

for i in range(x,0,-1):

    print(" "*(i-1),end="") #end는 마지막에 추가작성 가능
    print("*"*(x-(i-1)))
    