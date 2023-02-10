fruit_list = ["banana","orange","kiwi","apple","melon"]
max_len = len(fruit_list[0])
x = []

#find max len
for i in range(len(fruit_list)):
    if max_len < len(fruit_list[i]):
        max_len = len(fruit_list[i])

#find max fruit
for i in range(len(fruit_list)):
    if(max_len == len(fruit_list[i])):
        x.append(fruit_list[i])

#del max fruit
for i in range(len(x)):
    fruit_list.remove(x[i])

#list join
def listJoin(index):
    result = ', '.join(i for i in index)
    return result

#result
print("가장 길이가 긴 문자열: ",listJoin(x))
print("fruit_list =",fruit_list)