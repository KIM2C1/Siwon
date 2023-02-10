import math

x1, y1, x2, y2 = map(int,input("x1, y1, x2, y2를 입력하시오: ").split())

distance = math.sqrt(pow(x2-x1,2)+pow(y2-y1,2))

print("(",x1,",",y1,") 과","(",x2,",",y2,")사이의 거리는",distance)
