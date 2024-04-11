a = int(input())
b = int(input())
c = int(input())

for i in range(0,a+2) :
    if i+1>a or 2*(i+1)>b or 4*(i+1) > c:
        print(7*i)
        break;