s = "English = 89, Science = 90, Math = 92, History = 80"

x = ""
a = 0
b = 0
sum = 0
avr = 0

x = s
while a != -1:
    a = x.find("=")
    if a != -1:
         sum += int(x[a+2:a+4])
         b += 1
         x = x.replace("=","-",1)
avr = sum / b

print(f"문장 s: {s}")
print(f"총점: {sum}")
print(f"평균점수: {avr}")
