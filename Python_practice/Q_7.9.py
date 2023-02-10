x = list(input("문자열A: "))
y = list(input("문자열B: "))
overlap_count = 0

print(x)
print(y)

#overlap counting
for i in range(len(x)):
    if y[:i+1] == x[-(1+i):]:
        overlap_count = i+1

#del y[]
del y[:overlap_count]

#join x and y
def listJoin(index):
    result = ''.join(i for i in index)
    return result

#result
print("overlap 갯수:",overlap_count)
print(listJoin(x)+listJoin(y))

