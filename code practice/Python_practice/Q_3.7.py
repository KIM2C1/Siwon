#문제 3.7

x=int(input("세 자리 정수를 입력하시오 :"))

a=x//100
b=x%100//10
c=x%10

print("백의 자리: ",a)
print("십의 자리: ",b)        
print("일의 자리: ",c)    