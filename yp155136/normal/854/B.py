n,k = map(int,input().split())
if k==0 :
    print(0,0)
elif k==n :
    print(0,0)
else :
    print(1,min(n-k,k*2))