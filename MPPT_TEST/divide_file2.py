import time
from divide_file1 import MyStruct

data_C = "220.0 22.7 220.0 60.0 22.7 5000 5000 48.0 48.0 48.0 55.5 55.5 3 40 040 1 0 0 9 01 0 0 54.0 0 1 000 2"

data_C_list = list(data_C.split())
print(data_C_list)

for i, key in enumerate(MyStruct.QPIRI):
    MyStruct.QPIRI[key] = data_C_list[i]


for key, value in MyStruct.QPIRI.items():
    print(f"{key}: {value}")


## QFLAG Divide
data_D = 'EbcvxzDajkuy'
exclude_chars = ['E', 'D']
data_D_list_E = []
data_D_list_D = []
i = 0
temp = 0

while i < len(data_D):
    if data_D[i] == 'E':
        temp = 0
        i += 1
    elif data_D[i] == 'D':
        temp = 1
        i += 1
    
    if temp == 0:
        data_D_list_E.append(data_D[i])
    elif temp == 1:
        data_D_list_D.append(data_D[i])
    i += 1

print(data_D_list_E)
print(data_D_list_D) 
