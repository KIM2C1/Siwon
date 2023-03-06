x = list(input("문자열을 입력하시오: "))
y = []
z = []


for i in range(len(x)):
    if x[i].isupper() == True:
        y.append(x[i])
    else:
        z.append(x[i])

#join list
def listJoin(index):
    result = ''.join(i for i in index)
    return result

print(listJoin(z)+listJoin(y))