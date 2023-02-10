x = list(input("문자열을 입력하시오:"))
a = 0
b = 0
c = 0
d = 0

for i in range(len(x)):
    if x[i].isupper() == True:
        a += 1
    elif x[i].islower() == True:
        b += 1
    elif x[i].isdigit() == True:
        c += 1
    else :
        d = len(x)-(a+b+c)

print("대문자 소문자, 숫자, 특수문자의 개수")
print(f"대문자 = {a}")
print(f"소문자 = {b}")
print(f"숫자 = {c}")
print(f"특수문자 = {d}")