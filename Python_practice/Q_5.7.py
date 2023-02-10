
b = []

for a in range(100,1000):
    x = a//100
    n = a%100

    y = n//10

    z = n%10

    if(x*100 + y*10 + z == pow(x,3) + pow(y,3) + pow(z,3)):
        b.append(a)
       


print("세 자리의 암스트롱 수:",b)

