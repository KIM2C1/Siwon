x = ('A','B','C')
y = ('1','2')
z = (1,2)

add1 = []
add2 = []

for n in range(3):
    for m in range(2):
        add1.append(x[n] + y[m])
        add2.append(x[n] + str(z[m]))

print(add1[:])
print(add2[:])