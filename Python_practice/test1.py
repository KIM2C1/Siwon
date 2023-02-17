f = open("sample", 'w')
x = b'\r'
y = []
test = []
y.append(str(x))
z = ' '.join(i for i in y)
new = "1: 'b  Q ' b ' I ' b ' D ' b ' \ x d 6 ' b ' \ x e a ' b ' \ r '"


test.append(z)

print(new)
print(type(new))
f1 = new.replace("b ","")
f2 = f1.replace("'","")
print(f2)

if (x == b'\r'):
    print("ok")
    print(test)
