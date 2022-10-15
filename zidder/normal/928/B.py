n,k=map(int,input().split())
a=list(map(int,input().split()))
b=[min(1+k,n)]*n
for i in range(1,n):
    x = a[i] - 1
    if x==-1:
        b[i]=min(i,k)+1+min(n-i-1,k)
    else:
        b[i]=b[x]+min(k+1,i-(x+min(k,n-x-1)))+min(n-i-1,k)
print(*b)