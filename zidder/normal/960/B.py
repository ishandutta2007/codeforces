n,k1,k2=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
d=[abs(a[i]-b[i]) for i in range(n)]
d=sorted(d)[::-1]
k=k1+k2
while k>0:
    if d[0]==0:
        break
    if k>0:
        d[0]-=1
        k-=1
        d=sorted(d)[::-1]
print(sum([i**2 for i in d])+k%2)