s = "Korea is awesome! I REALLY LOVE KOREA."
a = 0
b = 0

x = s.upper()

while a != -1:
    a = x.find("KOREA")
    if a != -1:
        x = x.replace("KOREA","",1)
        b += 1
        
print(f"s = {s}")
print(f"Korea의 출현 횟수: {b}")