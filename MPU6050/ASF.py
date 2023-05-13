import time

start_time = time.time()

def getDT():
	global start_time
	end_time = time.time()
	dt = end_time - start_time
	start_time = end_time
	return dt

while (True):
	b = int(input())
	if b == 1:
		print(getDT())
	