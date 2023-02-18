import time

datasheet = [
    "QID",
    "QSID",
    "QVFW",
    "QVFW2",
    "QPIRI",
    "QFLAG",
    "QPIGS",
    "QPGSn",
    "QMOD",
    "QPIWS",
    "QMCHGCR",
    "QMUCHGCR",
    "QOPM"
]

#파일 초기 설정
f = open("listup.txt", 'w')
f.write("---------------TEST START---------------\n")
f.close()

trydata = int(input("테스트 횟수: "))
fault = 0

start_time = time.time()

f = open("listup.txt", 'a')
for test_number in range(trydata):
    for data_number in range(len(datasheet)):
        input_data = str(data_number+1) + ": " + datasheet[data_number] + "\t\t\t" + datasheet[data_number] + "\n"
        f.write(input_data)
        
        if datasheet[data_number] != datasheet[data_number]:
            fault += 1

    end_time = time.time()
    result = "-------------"+"ok:"+str(13-fault)+"/faile:"+str(fault)+"-------------\n"
    
    f.write(result)
    f.write("time:"+str(end_time - start_time)+"\n")
f.close()
