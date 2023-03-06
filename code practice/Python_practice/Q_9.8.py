x = list(input("문장을 입력하시오: "))
y = []
z = x

buff = []
buff1 = ""
a = 0
b = 0

En = []
Di = []
EnDi = []

#join list
def listJoin(index):
    result = ''.join(i for i in index)
    return result

#filtering
for i in range(len(x)):
    if z[i]==" ":
        y.append(z[a:i])
        a=i+1
        b = i+1

y.append(z[b:-1])

#dividing
print(y)
for i in range(len(y)):
    buff = y[i]
    if buff[-1]==".":
        buff.remove(".")

    buff1 = listJoin(buff)

    if buff1.isalpha() == True:
        En.append(buff1)
        En.append(" ")

    elif buff1.isdigit() == True:
        Di.append(buff1)
        Di.append(" ")
    else:
        EnDi.append(buff1)
        EnDi.append(" ")


#result
print("영문 단어 =",listJoin(En))
print("숫자 =",listJoin(Di))
print("영문자+숫자 =",listJoin(EnDi))
