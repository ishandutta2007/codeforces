n,T = (input().split())
n=int(n)
T=int(T)
a = list(map(int,input().split()))
for i in range(0,n) :
    T -= (86400-a[i])
    if T<=0 :
        print(i+1)
        break