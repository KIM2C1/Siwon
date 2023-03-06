buff = [0] * 40  # 40개의 0으로 이루어진 리스트를 생성합니다.
buff[38] = 123   # 39번째 인덱스에 123 값을 할당합니다.

buff[0] = 1

print(buff)

while (find_end): #읽은 데이터 만큼 반복
            term = 0
            data = ser.read()
            print("받은값:",data)
            buff.append(data)
            term += 1
            if (buff[38]=='X'):
                find_end = 0