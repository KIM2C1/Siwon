x = list(input("문장을 입력하시오:"))
y = []

for i in range(len(x)):
    if x[i] == ",":
        y.append(",")
    elif x[i] == " ":
        y.append(" ")
    elif x[i] == ".":
        y.append(".")
    else:
        y.append(chr(ord(x[i])+3))

#join list
def listJoin(index):
    result = ''.join(i for i in index)
    return result

print(listJoin(y))

