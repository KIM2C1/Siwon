import time
import multiprocessing as mp
import ctypes
import "Cpp_python.cpp" 
lib = ctypes.CDLL('./add.so')

add = lib.add
add.restype = ctypes.c_int
add.argtypes = [ctypes.c_int, ctypes.c_int]

result = add(1,2)
print(result)