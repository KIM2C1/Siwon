import time
from divide_file1 import MyStruct

QID = "92932111101485"
QSID = "1492932111101485005535"
QVFW = "VERFW:00072.00"
QVFW2 = "VERFW2:00000.00"
QPIRI = "220.0 22.7 220.0 60.0 22.7 5000 5000 48.0 48.0 48.0 55.5 55.5 3 40 040 1 0 0 9 01 0 0 54.0 0 1 000 2"
QFLAG = "EbcvxzDajkuy"
QPIGS = "000.0 00.0 218.8 59.9 0065 0015 001 374 53.20 000 089 0035 0000 000.0 00.00 00000 00010000 00 00 00000 010"
QPGSn = "0 00000000000000 P 00 000.0 00.00 000.0 00.00 0000 0000 000 00.0 000 000 000.0 000 00000 00000 000 00000000 0 0 000 000 00 00 000"
QMOD = "B"
QPIWS = "100001000000000000000000000000000000"
QDI = "230.0 50.0 0030 42.0 54.0 56.4 46.0 60 1 0 2 0 0 0 0 0 1 1 0 0 1 0 54.0 0 1 000 0"
QMCHGCR = "010 020 030 040 050 060 070 080 090 100 110 120 130 140"
QMUCHGCR = "002 010 020 030 040 050 060"
QOPM = "NAKss"

##############################################
QPIRI_list = list(QPIRI.split())
for i, key in enumerate(MyStruct.QPIRI):
    MyStruct.QPIRI[key] = QPIRI_list[i]


#for key, value in MyStruct.QPIRI.items():
    #print(f"{key}: {value}")

###############################################
QPIGS_list = list(QPIGS.split())
for i, key in enumerate(MyStruct.QPIGS):
    MyStruct.QPIGS[key] = QPIGS_list[i]


#for key, value in MyStruct.QPIGS.items():
    #print(f"{key}: {value}")

###############################################
QPGSn_list = list(QPGSn.split())
for i, key in enumerate(MyStruct.QPGSn):
    MyStruct.QPGSn[key] = QPGSn_list[i]


#for key, value in MyStruct.QPGSn.items():
    #print(f"{key}: {value}")

###############################################
QDI_list = list(QDI.split())
for i, key in enumerate(MyStruct.QDI):
    MyStruct.QDI[key] = QDI_list[i]


#for key, value in MyStruct.QDI.items():
    #print(f"{key}: {value}")

###############################################
## QFLAG Divide
data_D = 'EbcvxzDajkuy'
exclude_chars = ['E', 'D']
QFLAG_E = []
QFLAG_D = []
i = 0
temp = 0

while i < len(QFLAG):
    if data_D[i] == 'E':
        temp = 0
        i += 1
    elif data_D[i] == 'D':
        temp = 1
        i += 1
    
    if temp == 0:
        QFLAG_E.append(QFLAG[i])
    elif temp == 1:
        QFLAG_D.append(QFLAG[i])
    i += 1

def dic(test, test1):
    for key, value in test[test1].items():
            print(f"{key}: {value}")


ex_data = 'QPIRI', 'QPIGS', 'QPGSn', 'QDI'

while True:
    find_command = str(input("Select(Out is ESC): "))
    if find_command == 'QPIRI' and 'QPIGS' and 'QPGSn' and 'QDI':
        dic(MyStruct, find_command)
    elif find_command == 'QFLAG':
        print(QFLAG_E)
        print(QFLAG_D) 
    else:
        print(find_command)
