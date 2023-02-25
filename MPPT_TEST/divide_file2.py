import time
from divide_file1 import MyStruct

data_C = "220.0 22.7 220.0 60.0 22.7 5000 5000 48.0 48.0 48.0 55.5 55.5 3 40 040 1 0 0 9 01 0 0 54.0 0 1 000 2"

data_C_list = list(map(float, data_C.split()))

#print(data_C_list)

#print(MyStruct.QPIRI)

#keys = list(MyStruct.QPIRI.keys())

#for i in range(len(keys)):
    #MyStruct.QPIRI[keys[i]] = data_C_list[i]

for key, format_string in MyStruct.QPIRI.items():
    value_string = format_string % data_C_list.pop(0)
    MyStruct.QPIRI[key] = value_string

print("\n-----------------------------------------------------\n")

time.sleep(3)

for key, value in MyStruct.QPIRI.items():
    print(key, value)

"""
data_A = "100 200 300"
data_B = "400 500 600"

data_A_list = list(map(int, data_A.split()))
data_B_list = list(map(int, data_B.split()))

for i in range(3):
    print(data_A_list[i])
    print(data_B_list[i])

s = MyStruct(10, 20)

print(s.arg1)
print(s.arg2)
"""