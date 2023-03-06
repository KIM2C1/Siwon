#문제 3.9

Avr_Speed=float(input("평균 시속(km/h)을 입력하세요: "))
Time_Speed=float(input("이동 시간(h)을 입력하세요: "))

a=float((Time_Speed-int(Time_Speed))*60)
b=float(a-int(a))*60

print("평균 시속: ",Avr_Speed, "km/h")
print("이동 시간: ",int(Time_Speed),"시간", int(a),"분", int(b),"초")
print("이동 거리: ",Avr_Speed*Time_Speed, "km/h")