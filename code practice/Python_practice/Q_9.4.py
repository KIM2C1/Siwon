a = list(input("a="))
b = list(input("b="))
str1 = []
str2 = []

for i in range(len(a)):
    str1.append(a[i])
    str1.append(b[i])

    str2.append(a[i])
    str2.append(b[len(b)-1-i])

#join list
def listJoin(index):
    result = ''.join(i for i in index)
    return result

print("new_str1=",listJoin(str1))
print("new_str2=",listJoin(str2))
