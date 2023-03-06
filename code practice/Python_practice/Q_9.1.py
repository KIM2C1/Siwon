x, y, z = map(list,input("이름을 입력하시오: ").split())
print(x, y, z)

#join y
def listJoin(index):
    result = ''.join(i for i in index)
    return result

print("중간 이름은:", listJoin(y))